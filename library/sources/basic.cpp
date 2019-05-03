#include "headers/basic.h"
#include <exception>
#include <algorithm>

using std::vector;
using std::string;

Unit::Unit(int health, int exp) :
    health(health),
    exp(exp) {

}

UnitFactory::UnitFactory(int base_health, int base_exp) :
    base_health(base_health),
    base_exp(base_exp) {

}

void UnitFactory::UpgradeTraining(int diff) {
  base_exp += diff;
}

void UnitFactory::UpgradeArmor(int diff) {
  base_health += diff;
}

Province::Province(const string& name, Province::Terrain terrain) :
    name(name),
    terrain(terrain) {

}

const std::list<Province*>& Province::NeighboursList() {
  return neighbours;
}

Province::Terrain Province::LocalTerrain() const {
  return terrain;
}

LandProvince::LandProvince() :
    factory(nullptr) {

}

LandProvince::~LandProvince() {
  if (factory != nullptr) {
    delete factory;
  }
  for (Unit* unit : garrison) {
    delete unit;
  }
}

const string& Province::Name() const {
  return name;
}

void LandProvince::AddFactory(UnitFactory* factory) {
  this->factory = factory;
}

void LandProvince::Occupy(int occupant) {
  this->occupant = occupant;
}

void LandProvince::DestroyFactory() {
  delete factory;
}

LandProvince::Culture LandProvince::LocalCulture() const {
  return culture;
}

LandProvince::Religion LandProvince::LocalReligion() const {
  return religion;
}

int LandProvince::LocalTax() const {
  return tax;
}

bool LandProvince::IsCoastal() const {
  return is_coastal;
}

const std::vector<Unit*>& LandProvince::LocalGarrison() const {
  return garrison;
}

void LandProvince::Produce() {
  garrison.push_back(factory->Create());
}

vector<Unit*> LandProvince::RaiseGarrison() {
  vector<Unit*> raised = std::move(garrison);
  return raised;
}

int LandProvince::Owner() const {
  return owner;
}

int LandProvince::Occupant() const {
  return occupant;
}

LandProvinceBuilder::~LandProvinceBuilder() {
  if (current != nullptr) {
    delete current;
  }
}

void LandProvinceBuilder::New() {
  current = new LandProvince;
}

void LandProvinceBuilder::AddName(const string& name) {
  current->name = name;
}

void LandProvinceBuilder::AddOwner(int owner) {
  current->owner = owner;
}

void LandProvinceBuilder::AddOccupant(int occupant) {
  current->occupant = occupant;
}

void LandProvinceBuilder::AddTerrain(Province::Terrain terrain) {
  current->terrain = terrain;
}

void LandProvinceBuilder::AddCulture(LandProvince::Culture culture) {
  current->culture = culture;
}

void LandProvinceBuilder::AddReligion(LandProvince::Religion religion) {
  current->religion = religion;
}

void LandProvinceBuilder::MakeCoastal() {
  current->is_coastal = true;
}

void LandProvinceBuilder::SetTax(int base_tax) {
  current->tax = base_tax;
}

void LandProvinceBuilder::SetFactory(UnitFactory* factory) {
  current->factory = factory;
}

void LandProvinceBuilder::AddBorder(Province* first, Province* second) {
  first->neighbours.push_back(second);
  second->neighbours.push_back(first);
}

LandProvince* LandProvinceBuilder::Result() {
  auto temp = current;
  current = nullptr;
  return temp;
}

SeaProvince::SeaProvince(const string& name) :
    Province(name, Sea) {

}

Army::Army(const vector<Unit*>& units, Province* location) :
    units(units),
    location(location) {

}

Army::~Army() {
  for (Unit* unit : units) {
    if (unit != nullptr) {
      delete unit;
    }
  }
}

void Army::AddUnit(Unit* unit) {
  units.push_back(unit);
}

const std::vector<Unit*>& Army::UnitList() const {
  return units;
}

Province* Army::Location() const {
  return location;
}

void Army::Move(Province* province) {
  location = province;
}
