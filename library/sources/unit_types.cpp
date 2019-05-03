#include "headers/unit_types.h"

MeleeInfantry::MeleeInfantry (int health, int exp) :
    Unit(health, exp) {

}

LightInfantry::LightInfantry (int health, int exp) :
    MeleeInfantry(health, exp) {

}

HeavyInfantry::HeavyInfantry (int health, int exp) :
    MeleeInfantry(health, exp) {

}

Pikeman::Pikeman (int health, int exp) :
    MeleeInfantry(health, exp) {

}

RangedInfantry::RangedInfantry(int health, int exp) :
    Unit(health, exp) {

}

Archer::Archer (int health, int exp) :
    RangedInfantry(health, exp) {

}

ArchersFactory::ArchersFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

Crossbowman::Crossbowman (int health, int exp) :
    RangedInfantry(health, exp) {

}

CrossbowmenFactory::CrossbowmenFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

Arquebusier::Arquebusier (int health, int exp) :
    RangedInfantry(health, exp) {

}

ArquebusiersFactory::ArquebusiersFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

Ship::Ship(int health, int exp) :
    Unit(health, exp) {

}

LightShip::LightShip (int health, int exp) :
    Ship(health, exp) {

}

HeavyShip::HeavyShip (int health, int exp) :
    Ship(health, exp) {

}

Galeass::Galeass (int health, int exp) :
    Ship(health, exp) {

}

LightInfFactory::LightInfFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

HeavyInfFactory::HeavyInfFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

PikemenFactory::PikemenFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

LightShipsFactory::LightShipsFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

HeavyShipsFactory::HeavyShipsFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}

GaleassesFactory::GaleassesFactory(int base_health, int base_exp) :
    UnitFactory(base_health, base_exp) {

}
