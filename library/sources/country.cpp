#include "headers/country.h"

using std::vector;
using std::string;

NationalFactory::NationalFactory(int base_exp) :
    base_exp(base_exp) {

}

Country::Country(int tag, LandProvince* capital, const string& name, NationalFactory* factory) :
    tag(tag),
    name(name),
    capital(capital),
    provinces(),
    factory(factory) {

}

Country::~Country() {
  if (factory != nullptr) {
    delete factory;
  }
  for (LandProvince* province : provinces) {
    if (province != nullptr) {
      delete province;
    }
  }
}

const string& Country::Name() const {
  return name;
}

const vector<LandProvince*>& Country::ProvincesList() const {
  return provinces;
}

void Country::AnnexProvince(LandProvince* province, Country* former_owner) {
  if (former_owner != nullptr) {
    former_owner->provinces.erase(std::find(former_owner->provinces.begin(), former_owner->provinces.end(), province));
  }
  provinces.push_back(province);
}

const NationalFactory* Country::Factory() const {
  return factory;
}

LandProvince* Country::Capital() {
  return capital;
}
