#include "headers/init_france.h"

using std::vector;
using std::list;

Country* InitFrance(int tag) {
  FranceInitializer initializer;

  initializer.InitParis();
  initializer.InitAlencon();
  initializer.InitNormandie();
  initializer.InitChampagne();
  initializer.InitNemours();
  initializer.InitOrleanais();
  initializer.InitPoitou();
  initializer.InitBerry();
  initializer.InitBourbon();
  initializer.InitLimousin();
  initializer.InitGascogne();
  initializer.InitArmagnac();
  initializer.InitToulouse();
  initializer.InitLanguedoc();
  initializer.InitBorders();

  auto provinces = std::move(initializer.provinces);

  Country* france = new Country(tag, provinces[0], "France", new FrenchUnitFactory(50));
  for (LandProvince* province : provinces) {
    france->AnnexProvince(province, nullptr);
  }
  return france;
}

void FranceInitializer::InitParis() { // 0
  builder.New();
  builder.AddName("Paris");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(30);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitAlencon() { // 1
  builder.New();
  builder.AddName("Alencon");
  builder.AddCulture(LandProvince::Norman);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(10);
  builder.MakeCoastal();
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitNormandie() { // 2
  builder.New();
  builder.AddName("Normandie");
  builder.AddCulture(LandProvince::Norman);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(12);
  builder.MakeCoastal();
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitChampagne() { // 3
  builder.New();
  builder.AddName("Champagne");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(15);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitNemours() { // 4
  builder.New();
  builder.AddName("Nemours");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(10);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitOrleanais() { // 5
  builder.New();
  builder.AddName("Orleanais");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(20);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitPoitou() { // 6
  builder.New();
  builder.AddName("Poitou");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(8);
  builder.MakeCoastal();
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitBerry() { // 7
  builder.New();
  builder.AddName("Berry");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(10);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitBourbon() { // 8
  builder.New();
  builder.AddName("Bourbon");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(15);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitLimousin() { // 9
  builder.New();
  builder.AddName("Limousin");
  builder.AddCulture(LandProvince::French);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(6);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitGascogne() { // 10
  builder.New();
  builder.AddName("Gascogne");
  builder.AddCulture(LandProvince::Gascon);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(20);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitArmagnac() { // 11
  builder.New();
  builder.AddName("Armagnac");
  builder.AddCulture(LandProvince::Gascon);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(10);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitToulouse() { // 12
  builder.New();
  builder.AddName("Toulouse");
  builder.AddCulture(LandProvince::Occitan);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(12);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitLanguedoc() { // 13
  builder.New();
  builder.AddName("Languedoc");
  builder.AddCulture(LandProvince::Occitan);
  builder.AddReligion(LandProvince::Catholic);
  builder.SetTax(5);
  provinces.push_back(builder.Result());
}

void FranceInitializer::InitBorders() {
  LandProvinceBuilder::AddBorder(provinces[0], provinces[1]);
  LandProvinceBuilder::AddBorder(provinces[0], provinces[2]);
  LandProvinceBuilder::AddBorder(provinces[0], provinces[3]);
  LandProvinceBuilder::AddBorder(provinces[0], provinces[4]);
  LandProvinceBuilder::AddBorder(provinces[0], provinces[5]);

  LandProvinceBuilder::AddBorder(provinces[1], provinces[2]);
  LandProvinceBuilder::AddBorder(provinces[1], provinces[5]);

  LandProvinceBuilder::AddBorder(provinces[3], provinces[4]);

  LandProvinceBuilder::AddBorder(provinces[4], provinces[5]);
  LandProvinceBuilder::AddBorder(provinces[4], provinces[7]);

  LandProvinceBuilder::AddBorder(provinces[5], provinces[6]);
  LandProvinceBuilder::AddBorder(provinces[5], provinces[7]);

  LandProvinceBuilder::AddBorder(provinces[6], provinces[9]);
  LandProvinceBuilder::AddBorder(provinces[6], provinces[10]);

  LandProvinceBuilder::AddBorder(provinces[7], provinces[8]);
  LandProvinceBuilder::AddBorder(provinces[7], provinces[9]);

  LandProvinceBuilder::AddBorder(provinces[8], provinces[12]);
  LandProvinceBuilder::AddBorder(provinces[8], provinces[13]);

  LandProvinceBuilder::AddBorder(provinces[9], provinces[10]);
  LandProvinceBuilder::AddBorder(provinces[9], provinces[11]);
  LandProvinceBuilder::AddBorder(provinces[9], provinces[12]);

  LandProvinceBuilder::AddBorder(provinces[10], provinces[11]);

  LandProvinceBuilder::AddBorder(provinces[11], provinces[12]);

  LandProvinceBuilder::AddBorder(provinces[12], provinces[13]);
}
