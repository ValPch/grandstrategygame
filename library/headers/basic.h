#pragma once
#include <iostream>
#include <vector>
#include <list>

class Unit {
  public:
    Unit(int health, int exp);
    virtual std::string Name() const = 0;
    virtual ~Unit() = default;

  protected:
    int health;
    int exp;
};

class UnitFactory {
  public:
    UnitFactory(int base_health, int base_exp);
    virtual ~UnitFactory() = default;

    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
    virtual Unit* Create() = 0;

  protected:
    int base_health;
    int base_exp;
};

class Province {

  friend class LandProvinceBuilder;

  public:
    enum Terrain {Grasslands, Farmlands, Hills, Mountains, Forest, Drylands, Steppes, Savannah, Jungle, Marsh, Sea};

    Province() = default;
    Province(const std::string& name, Terrain terrain);
    virtual ~Province() = default;

    const std::string& Name() const;
    const std::list<Province*>& NeighboursList();
    Terrain LocalTerrain() const;

  protected:
    std::string name;
    std::list<Province*> neighbours;
    Terrain terrain;
};

class LandProvince : public Province {

  friend class LandProvinceBuilder;

  public:
    enum Culture {French, Norman, Occitan, Gascon, English};
    enum Religion {Catholic, Protestant};

    LandProvince();
    ~LandProvince();

    void AddFactory(UnitFactory* factory);
    void DestroyFactory();
    void Occupy(int occupant);
    Culture LocalCulture() const;
    Religion LocalReligion() const;
    int LocalTax() const;
    bool IsCoastal() const;
    const std::vector<Unit*>& LocalGarrison() const;
    void Produce();
    std::vector<Unit*> RaiseGarrison();
    int Owner() const;
    int Occupant() const;


  private:
    int owner;
    int occupant;
    Culture culture;
    Religion religion;
    bool is_coastal;
    int tax;
    UnitFactory* factory;
    std::vector<Unit*> garrison;

};

class SeaProvince : public Province {
  public:
    SeaProvince(const std::string& name);
    ~SeaProvince() = default;
};

class LandProvinceBuilder {
  public:
    ~LandProvinceBuilder();
    void New();
    void AddName(const std::string& name);
    void AddOwner(int owner);
    void AddOccupant(int occupant);
    void AddTerrain(Province::Terrain terrain);
    void AddCulture(LandProvince::Culture culture);
    void AddReligion(LandProvince::Religion religion);
    void MakeCoastal();
    void SetTax(int base_tax);
    void SetFactory(UnitFactory* factory);
    static void AddBorder (Province* first, Province* second);
    LandProvince* Result();

  private:
    LandProvince* current;
};

class Army {
  public:
    Army() = default;
    Army(const std::vector<Unit*>& units, Province* location);
    ~Army();

    void AddUnit(Unit* unit);
    const std::vector<Unit*>& UnitList() const;
    Province* Location() const;
    void Move(Province* province);

  private:
    std::vector<Unit*> units;
    Province* location;
};
