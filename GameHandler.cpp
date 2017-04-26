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

#include <iostream>
#include "GameHandler.h"
#include "Interface.h"
#include "CmdEcho.h"
#include "CmdBalance.h"
#include "CmdQuote.h"
#include "CmdRecipe.h"
#include "CmdQuit.h"

using std::unique_ptr;

GameHandler::GameHandler() 
{
  commands_.push_back(unique_ptr<Command>(new CmdEcho()));
  commands_.push_back(unique_ptr<Command>(new CmdBalance()));
  commands_.push_back(unique_ptr<Command>(new CmdQuote()));
  commands_.push_back(unique_ptr<Command>(new CmdRecipe()));
  commands_.push_back(unique_ptr<Command>(new CmdQuit()));
}

void GameHandler::runInterface()
{
  unique_ptr<Interface> interface_instance;
  interface_instance = unique_ptr<Interface>(new Interface(this));
  while(1) 
  {
    interface_instance -> runPrompt();
    resolveCommand();
    delete command_name_;
    delete interface_parameters_;
  }
}

void GameHandler::setInterfaceParameters(std::vector<std::string>* interface_parameters)
{
  interface_parameters_ = interface_parameters;
}

void GameHandler::setInterfaceCommand(std::string* command_name) 
{
  command_name_ = command_name;
}

void GameHandler::resolveCommand()
{
  /*try
  {
    throw checkCorrectness();
  }
  catch (int i)
  {
    
  }
*/
  unsigned int command_index;
  for (command_index = 0; command_index < commands_.size(); ++command_index)
  {
    if (!(commands_[command_index] -> getName().compare(*command_name_)))
    {
      commands_[command_index] -> execute(*this, *interface_parameters_);
    }
  }
}
/*
int checkCorrectness()
{

}

void resolveError()
{
  
}*/