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

#include <string>
#include <iostream>
#include "GameHandler.h"
#include "ReturnValues.h"

static const std::string OUT_OF_MEMORY = "[ERR] Out of memory.";


//------------------------------------------------------------------------------
// main function
// Creates a new game instance and executes the interface.
//
// @return return_value Returns the corresponding return value.
//
int main(int argc, char **argv)
{
  int return_value = 0;
  try
  {
    GameHandler game;
    return_value = game.initialize(argc, argv);
    if (!return_value)
    {
      return_value = game.play();
    }
  }
  catch(const std::bad_alloc& exception)
  {
    return_value = RETURN_OUT_OF_MEMORY;
  }
  if(return_value == RETURN_OUT_OF_MEMORY)
  {
    std::cout << OUT_OF_MEMORY << std::endl;
  }
  return return_value;
}