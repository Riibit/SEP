//------------------------------------------------------------------------------
// main.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include <iostream>

#include "GameHandler.h"

int main()
{
  GameHandler *game;
  game = new GameHandler();
  game->runInterface();

  return 0;
}

