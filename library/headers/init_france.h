#pragma once
#include "headers/basic.h"
#include "headers/unit_types.h"
#include "headers/french_units.h"

Country* InitFrance(int tag);

class FranceInitializer {
  public:
    void InitParis();
    void InitAlencon();
    void InitNormandie();
    void InitChampagne();
    void InitNemours();
    void InitOrleanais();
    void InitPoitou();
    void InitBerry();
    void InitBourbon();
    void InitLimousin();
    void InitGascogne();
    void InitArmagnac();
    void InitToulouse();
    void InitLanguedoc();
    void InitBorders();

    std::vector<LandProvince*> provinces;
  private:
    LandProvinceBuilder builder;

};

