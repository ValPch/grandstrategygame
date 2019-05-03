#include <iostream>
#include <algorithm>
#include "library/headers/game.h"
#include "tester/tests.h"

using std::cout;
using std::endl;
using std::vector;

void TestCountries() {
  cout << "Testing country creation..." << endl;
  Game engine;
  engine.InitializeFrance();
  engine.SetPlayer(0);
  Country* country = engine.player.country;
  assert(country->Name() == "France");
  vector<LandProvince*> provinces = country->ProvincesList();
  assert(provinces.size() == 14);
  assert(country->Capital()->Name() == "Paris");
  assert(std::find(provinces.begin(), provinces.end(), country->Capital()) != provinces.end());
  cout << "Test passed." << endl;
}

void TestProvinces() {
  cout << "Testing provinces creation..." << endl;
  LandProvinceBuilder builder;

  builder.New();
  builder.MakeCoastal();
  builder.AddCulture(LandProvince::English);
  builder.AddReligion(LandProvince::Protestant);
  builder.AddTerrain(Province::Farmlands);
  builder.AddName("London");
  LandProvince* london = builder.Result();

  SeaProvince* channel = new SeaProvince("English Channel");

  builder.New();
  builder.AddCulture(LandProvince::Norman);
  builder.AddReligion(LandProvince::Catholic);
  builder.AddTerrain(Province::Farmlands);
  builder.AddOccupant(0);
  builder.AddOwner(0);
  builder.AddName("Normandie");
  builder.MakeCoastal();
  LandProvince* normandie = builder.Result();

  LandProvinceBuilder::AddBorder(london, channel);
  LandProvinceBuilder::AddBorder(channel, normandie);

  assert(channel->Name() == "English Channel");

  auto nlist = channel->NeighboursList();

  assert(nlist.size() == 2 && nlist.begin() != ++nlist.begin());

  assert(london->LocalCulture() != normandie->LocalCulture());
  assert(london->LocalReligion() != normandie->LocalReligion());
  assert(london->LocalTerrain() == normandie->LocalTerrain());

  assert(london->IsCoastal() && normandie->IsCoastal());

  assert(normandie->Occupant() == 0);
  normandie->Occupy(1);
  assert(normandie->Occupant() == 1);

  assert(normandie->Owner() == 0);

  delete london;
  delete channel;
  delete normandie;

  cout << "Test passed." << endl;
}

void TestFactories() {
  cout << "Testing factories..." << endl;

  Game engine;
  engine.InitializeFrance();
  engine.SetPlayer(0);
  Country* france = engine.player.country;
  const NationalFactory* factory_nationale = france->Factory();
  france->Capital()->AddFactory(factory_nationale->CreatePikemenFactory());

  for(int i = 0; i < 10; ++i) {
    france->Capital()->Produce();
  }

  assert(france->Capital()->LocalGarrison().size() == 10);

  for(int i = 0; i < 10; ++i) {
    assert(france->Capital()->LocalGarrison()[i]->Name() == "Piqueneer");
  }

  france->Capital()->DestroyFactory();

  for (Unit* unit : france->Capital()->RaiseGarrison()) {
    delete unit;
  }

  france->Capital()->AddFactory(factory_nationale->CreateArquebusiersFactory());

  for(int i = 0; i < 5; ++i) {
    france->Capital()->Produce();
  }

  assert(france->Capital()->LocalGarrison().size() == 5);

  for(int i = 0; i < 5; ++i) {
    assert(france->Capital()->LocalGarrison()[i]->Name() == "Musketeer");
  }

  cout << "Test passed." << endl;
}

void TestArmies() {
  cout << "Testing armies..." << endl;

  Game engine;
  engine.InitializeFrance();
  engine.SetPlayer(0);
  Country* france = engine.player.country;
  const NationalFactory* factory_nationale = france->Factory();
  france->Capital()->AddFactory(factory_nationale->CreatePikemenFactory());
  for (int i = 0; i < 100; ++i) {
    france->Capital()->Produce();
  }

  Army* FirstInfantryArmy = new Army(france->Capital()->RaiseGarrison(), france->Capital());
  assert(FirstInfantryArmy->UnitList().size() == 100);
  FirstInfantryArmy->AddUnit(new FrenchArcher(0, 0));
  assert(FirstInfantryArmy->UnitList().size() == 101);

  assert(FirstInfantryArmy->Location() == france->Capital());
  FirstInfantryArmy->Move(france->ProvincesList()[1]);
  assert(FirstInfantryArmy->Location()->Name() == "Alencon");

  delete FirstInfantryArmy;
  cout << "Test passed." << endl;
}
