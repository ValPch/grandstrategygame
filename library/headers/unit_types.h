#pragma once
#include "headers/basic.h"

class MeleeInfantry : public Unit {
  public:
    MeleeInfantry(int health, int exp);
    ~MeleeInfantry() = default;
};

class LightInfantry : public MeleeInfantry {
  public:
    LightInfantry(int health, int exp);
    ~LightInfantry() = default;
};

class LightInfFactory : public UnitFactory {
  public:
    LightInfFactory(int base_health, int base_exp);
    ~LightInfFactory() = default;
    virtual LightInfantry* Create() = 0;
};

class HeavyInfantry : public MeleeInfantry {
  public:
    HeavyInfantry(int health, int exp);
    ~HeavyInfantry() = default;
};

class HeavyInfFactory : public UnitFactory {
  public:
    HeavyInfFactory(int base_health, int base_exp);
    ~HeavyInfFactory() = default;
    virtual HeavyInfantry* Create() = 0;
};

class Pikeman : public MeleeInfantry {
  public:
    Pikeman(int health, int exp);
    ~Pikeman() = default;
};

class PikemenFactory : public UnitFactory {
    public:
    PikemenFactory(int base_health, int base_exp);
    ~PikemenFactory() = default;
    virtual Pikeman* Create() = 0;
};

class RangedInfantry : public Unit {
  public:
    RangedInfantry(int health, int exp);
    ~RangedInfantry() = default;
};

class Archer : public RangedInfantry {
  public:
    Archer(int health, int exp);
    ~Archer() = default;
};

class ArchersFactory : public UnitFactory {
  public:
    ArchersFactory(int base_health, int base_exp);
    ~ArchersFactory() = default;
    virtual Archer* Create() = 0;
};

class Crossbowman : public RangedInfantry {
  public:
    Crossbowman(int health, int exp);
    ~Crossbowman() = default;
};

class CrossbowmenFactory : public UnitFactory {
  public:
    CrossbowmenFactory(int base_health, int base_exp);
    ~CrossbowmenFactory() = default;
    virtual Crossbowman* Create() = 0;
};

class Arquebusier : public RangedInfantry {
  public:
    Arquebusier(int health, int exp);
    ~Arquebusier() = default;
};

class ArquebusiersFactory : public UnitFactory {
  public:
    ArquebusiersFactory(int base_health, int base_exp);
    ~ArquebusiersFactory() = default;
    virtual Arquebusier* Create() = 0;
};

class Ship : public Unit {
  public:
    Ship(int health, int exp);
    ~Ship() = default;
};

class HeavyShip : public Ship {
  public:
    HeavyShip(int health, int exp);
    ~HeavyShip() = default;
};

class HeavyShipsFactory : public UnitFactory {
  public:
    HeavyShipsFactory(int base_health, int base_exp);
    ~HeavyShipsFactory() = default;
    virtual HeavyShip* Create() = 0;
};

class LightShip : public Ship {
  public:
    LightShip(int health, int exp);
    ~LightShip() = default;
};

class LightShipsFactory : public UnitFactory {
  public:
    LightShipsFactory(int base_health, int base_exp);
    ~LightShipsFactory() = default;
    virtual LightShip* Create() = 0;
};

class Galeass : public Ship {
  public:
    Galeass(int health, int exp);
    ~Galeass() = default;
};

class GaleassesFactory : public UnitFactory {
  public:
    GaleassesFactory(int base_health, int base_exp);
    ~GaleassesFactory() = default;
    virtual Galeass* Create() = 0;
};
