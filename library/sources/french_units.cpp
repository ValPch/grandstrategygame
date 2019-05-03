#include "headers/french_units.h"

using std::vector;
using std::string;

FrenchAxeman::FrenchAxeman(int health, int exp) :
    LightInfantry(health, exp) {

}

string FrenchAxeman::Name() const {
  return "Axeman";
}

FrenchMaceman::FrenchMaceman(int health, int exp) :
    HeavyInfantry(health, exp) {

}

string FrenchMaceman::Name() const {
  return "Maceman";
}

FrenchPiqueneer::FrenchPiqueneer(int health, int exp) :
    Pikeman(health, exp) {

}

string FrenchPiqueneer::Name() const {
  return "Piqueneer";
}

FrenchArcher::FrenchArcher(int health, int exp) :
    Archer(health, exp) {

}

string FrenchArcher::Name() const {
  return "Archer";
}

FrenchLightCrossbowman::FrenchLightCrossbowman(int health, int exp) :
    Crossbowman(health, exp) {

}

string FrenchLightCrossbowman::Name() const {
  return "Light Crossbowman";
}

FrenchMusketeer::FrenchMusketeer(int health, int exp) :
    Arquebusier(health, exp) {

}

string FrenchMusketeer::Name() const {
  return "Musketeer";
}

FrenchBarque::FrenchBarque(int health, int exp) :
    LightShip(health, exp) {

}

string FrenchBarque::Name() const {
  return "Barque";
}

FrenchWarship::FrenchWarship(int health, int exp) :
    HeavyShip(health, exp) {

}

string FrenchWarship::Name() const {
  return "Warship";
}

FrenchXebec::FrenchXebec(int health, int exp) :
    Galeass(health, exp) {

}

string FrenchXebec::Name() const {
  return "Xebec";
}

FrenchUnitFactory::FrenchUnitFactory(int base_exp) :
    NationalFactory(base_exp) {

}

FrenchAxemenFactory::FrenchAxemenFactory(int base_health, int base_exp) :
    LightInfFactory(base_health, base_exp) {

}

FrenchMacemenFactory::FrenchMacemenFactory(int base_health, int base_exp) :
    HeavyInfFactory(base_health, base_exp) {

}

FrenchPiqueneersFactory::FrenchPiqueneersFactory(int base_health, int base_exp) :
    PikemenFactory(base_health, base_exp) {

}

FrenchArchersFactory::FrenchArchersFactory(int base_health, int base_exp) :
    ArchersFactory(base_health, base_exp) {

}

FrenchLightCrossbowmenFactory::FrenchLightCrossbowmenFactory(int base_health, int base_exp) :
    CrossbowmenFactory(base_health, base_exp) {

}

FrenchMusketeersFactory::FrenchMusketeersFactory(int base_health, int base_exp) :
    ArquebusiersFactory(base_health, base_exp) {

}

FrenchBarquesFactory::FrenchBarquesFactory(int base_health, int base_exp) :
    LightShipsFactory(base_health, base_exp) {

}

FrenchWarshipsFactory::FrenchWarshipsFactory(int base_health, int base_exp) :
    HeavyShipsFactory(base_health, base_exp) {

}

FrenchXebecsFactory::FrenchXebecsFactory(int base_health, int base_exp) :
    GaleassesFactory(base_health, base_exp) {

}

LightInfFactory* FrenchUnitFactory::CreateLightInfFactory() const {
  return new FrenchAxemenFactory(1000, base_exp);
}

HeavyInfFactory* FrenchUnitFactory::CreateHeavyInfFactory() const {
  return new FrenchMacemenFactory(2000, base_exp);
}

PikemenFactory* FrenchUnitFactory::CreatePikemenFactory() const {
  return new FrenchPiqueneersFactory(1500, base_exp);
}

ArchersFactory* FrenchUnitFactory::CreateArchersFactory() const {
  return new FrenchArchersFactory(500, base_exp);
}

CrossbowmenFactory* FrenchUnitFactory::CreateCrossbowmenFactory() const {
  return new FrenchLightCrossbowmenFactory(750, base_exp);
}

ArquebusiersFactory* FrenchUnitFactory::CreateArquebusiersFactory() const {
  return new FrenchMusketeersFactory(1000, base_exp);
}

LightShipsFactory* FrenchUnitFactory::CreateLightShipsFactory() const {
  return new FrenchBarquesFactory(1500, base_exp);
}

HeavyShipsFactory* FrenchUnitFactory::CreateHeavyShipsFactory() const {
  return new FrenchWarshipsFactory(5000, base_exp);
}

GaleassesFactory* FrenchUnitFactory::CreateGaleassesFactory() const {
  return new FrenchXebecsFactory(1000, base_exp);
}

FrenchAxeman* FrenchAxemenFactory::Create() {
  return new FrenchAxeman(base_health, base_exp);
}

FrenchMaceman* FrenchMacemenFactory::Create() {
  return new FrenchMaceman(base_health, base_exp);
}

FrenchPiqueneer* FrenchPiqueneersFactory::Create() {
  return new FrenchPiqueneer(base_health, base_exp);
}

FrenchArcher* FrenchArchersFactory::Create() {
  return new FrenchArcher(base_health, base_exp);
}

FrenchLightCrossbowman* FrenchLightCrossbowmenFactory::Create() {
  return new FrenchLightCrossbowman(base_health, base_exp);
}

FrenchMusketeer* FrenchMusketeersFactory::Create() {
  return new FrenchMusketeer(base_health, base_exp);
}

FrenchBarque* FrenchBarquesFactory::Create() {
  return new FrenchBarque(base_health, base_exp);
}

FrenchWarship* FrenchWarshipsFactory::Create() {
  return new FrenchWarship(base_health, base_exp);
}

FrenchXebec* FrenchXebecsFactory::Create() {
  return new FrenchXebec(base_health, base_exp);
}
