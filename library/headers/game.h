#pragma once
#include "headers/unit_types.h"
#include "headers/init_france.h"
#include <vector>

class Game {

  public:
    Game() = default;
    ~Game();

    struct Player {

      Player() = default;
      ~Player() = default;

      Country* country;
    };

    Player player;
    void SetPlayer(int tag);

    void InitializeFrance();

  private:
    std::vector<Country*> countries;
};

