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

#include "GameHandler.h"


//------------------------------------------------------------------------
// main function
// Creates a new game instance and executes the interface.
//
// @return return_value Returns the corresponding return value.
int main(int argc, char **argv)
{
  int return_value = 0;
  GameHandler game;
  return_value = game.initialize(argc, argv);
  if (return_value)
  {
    return return_value;
  }
  return_value = game.play();
  return return_value;
}

/*
Daily Goals:

-Donnerstag
  Produce (Basic/Aufbau implementierung)
  Stock (implementierung)
  Balance/Cash (implementierung)
-Freitag
  Play (implementierung) !!!
  setWeather (connect)
  realsticWeather / forcast
-Samstag
  Save/Load (implementierung) Milan???
-Sonntag
  Save/Load -"-
-Montag
  Error-Handling
  Valgrind
  Verbleibendes
-Dienstag
  Alles Verbleibendes
-Mittwoch
  CS
  Verbleibendes
-Donnerstag
  Frustsaufen


*/