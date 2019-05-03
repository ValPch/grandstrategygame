#pragma once
#include "headers/unit_types.h"
#include <algorithm>

class NationalFactory {
  public:
    NationalFactory(int base_exp);
    virtual ~NationalFactory() = default;
    virtual LightInfFactory* CreateLightInfFactory() const = 0;
    virtual HeavyInfFactory* CreateHeavyInfFactory() const = 0;
    virtual PikemenFactory* CreatePikemenFactory() const = 0;
    virtual ArchersFactory* CreateArchersFactory() const = 0;
    virtual CrossbowmenFactory* CreateCrossbowmenFactory() const = 0;
    virtual ArquebusiersFactory* CreateArquebusiersFactory() const = 0;
    virtual LightShipsFactory* CreateLightShipsFactory() const = 0;
    virtual HeavyShipsFactory* CreateHeavyShipsFactory() const = 0;
    virtual GaleassesFactory* CreateGaleassesFactory() const = 0;

  protected:
    int base_exp;
};

class Country {
  public:
    Country(int tag, LandProvince* capital, const std::string& name, NationalFactory* factory);
    ~Country();

    const std::string& Name() const;
    const std::vector<LandProvince*>& ProvincesList() const;
    void AnnexProvince(LandProvince* province, Country* former_owner);
    const NationalFactory* Factory() const;
    LandProvince* Capital();

  private:
    int tag;
    std::string name;
    LandProvince* capital;
    std::vector<LandProvince*> provinces;
    NationalFactory* factory;
};
