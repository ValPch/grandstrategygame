#pragma once
#include "headers/unit_types.h"
#include "headers/country.h"

class FrenchUnitFactory : public NationalFactory {
  public:
    FrenchUnitFactory(int base_exp);
    ~FrenchUnitFactory() = default;

    LightInfFactory* CreateLightInfFactory() const;
    HeavyInfFactory* CreateHeavyInfFactory() const;
    PikemenFactory* CreatePikemenFactory() const;
    ArchersFactory* CreateArchersFactory() const;
    CrossbowmenFactory* CreateCrossbowmenFactory() const;
    ArquebusiersFactory* CreateArquebusiersFactory() const;
    LightShipsFactory* CreateLightShipsFactory() const;
    HeavyShipsFactory* CreateHeavyShipsFactory() const;
    GaleassesFactory* CreateGaleassesFactory() const;
};

class FrenchAxeman : public LightInfantry {
  public:
    FrenchAxeman(int health, int exp);
    std::string Name() const;
    ~FrenchAxeman() = default;
};

class FrenchMaceman : public HeavyInfantry {
  public:
    FrenchMaceman(int health, int exp);
    std::string Name() const;
    ~FrenchMaceman() = default;
};

class FrenchPiqueneer : public Pikeman {
  public:
    FrenchPiqueneer(int health, int exp);
    std::string Name() const;
    ~FrenchPiqueneer() = default;
};

class FrenchArcher : public Archer {
  public:
    FrenchArcher(int health, int exp);
    std::string Name() const;
    ~FrenchArcher() = default;
};

class FrenchLightCrossbowman : public Crossbowman {
  public:
    FrenchLightCrossbowman(int health, int exp);
    std::string Name() const;
    ~FrenchLightCrossbowman() = default;
};

class FrenchMusketeer : public Arquebusier {
  public:
    FrenchMusketeer(int health, int exp);
    std::string Name() const;
    ~FrenchMusketeer() = default;
};

class FrenchBarque : public LightShip {
  public:
    FrenchBarque(int health, int exp);
    std::string Name() const;
    ~FrenchBarque() = default;
};

class FrenchWarship : public HeavyShip {
  public:
    FrenchWarship(int health, int exp);
    std::string Name() const;
    ~FrenchWarship() = default;
};

class FrenchXebec : public Galeass {
  public:
    FrenchXebec(int health, int exp);
    std::string Name() const;
    ~FrenchXebec() = default;
};

class FrenchAxemenFactory : public LightInfFactory {
  public:
    FrenchAxemenFactory(int base_health, int base_exp);
    ~FrenchAxemenFactory() = default;

    FrenchAxeman* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchMacemenFactory : public HeavyInfFactory {
  public:
    FrenchMacemenFactory(int base_health, int base_exp);
    ~FrenchMacemenFactory() = default;

    FrenchMaceman* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchPiqueneersFactory : public PikemenFactory {
  public:
    FrenchPiqueneersFactory(int base_health, int base_exp);
    ~FrenchPiqueneersFactory() = default;

    FrenchPiqueneer* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchArchersFactory : public ArchersFactory {
  public:
    FrenchArchersFactory(int base_health, int base_exp);
    ~FrenchArchersFactory() = default;

    FrenchArcher* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchLightCrossbowmenFactory : public CrossbowmenFactory {
  public:
    FrenchLightCrossbowmenFactory(int base_health, int base_exp);
    ~FrenchLightCrossbowmenFactory() = default;

    FrenchLightCrossbowman* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchMusketeersFactory : public ArquebusiersFactory {
  public:
    FrenchMusketeersFactory(int base_health, int base_exp);
    ~FrenchMusketeersFactory() = default;

    FrenchMusketeer* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchBarquesFactory : public LightShipsFactory {
  public:
    FrenchBarquesFactory(int base_health, int base_exp);
    ~FrenchBarquesFactory() = default;

    FrenchBarque* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchWarshipsFactory : public HeavyShipsFactory {
  public:
    FrenchWarshipsFactory(int base_health, int base_exp);
    ~FrenchWarshipsFactory() = default;

    FrenchWarship* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};

class FrenchXebecsFactory : public GaleassesFactory {
  public:
    FrenchXebecsFactory(int base_health, int base_exp);
    ~FrenchXebecsFactory() = default;

    FrenchXebec* Create();
    void UpgradeTraining(int diff);
    void UpgradeArmor(int diff);
};
