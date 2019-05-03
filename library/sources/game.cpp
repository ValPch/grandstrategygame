#include "headers/game.h"
#include <vector>

using std::vector;

Game::~Game() {
  for (Country* ctr : countries) {
    if (ctr != nullptr) {
      delete ctr;
    }
  }
}

void Game::InitializeFrance() {
  countries.push_back(InitFrance(countries.size()));
}

void Game::SetPlayer(int tag) {
  player.country = countries[tag];
}
