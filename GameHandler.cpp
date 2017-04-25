//------------------------------------------------------------------------------
//GameHandler.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "GameHandler.h"

const GameHandler::ECHO = "echo";
const GameHandler::BALANCE = "balance";
const GameHandler::RECIPE = "recipe";

GameHandler() 
{
}

void resolveCommand(std::string command_name)
{
  Command new_command = new Command(command_name);
  new_command.execute();
}