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

void setInterfaceParameters(std::vector<std::string>* interface_parameters); 
{
  interface_parameters_ = interface_parameters;
}

void setInterfaceCommand(std::string command_name) 
{
  command_name_ = command_name
}

void resolveCommand(std::string command_name_)
{
  Command new_command = new Command(command_name);
  new_command.execute(&GameHandler game, interface_parameters_);
}