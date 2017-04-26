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
#include "Interface.h"
#include "CmdEcho.h"
#include <iostream>
GameHandler::GameHandler() 
{
}

void GameHandler::runInterface()
{
  Interface* interface_instance = new Interface(this);
  while(1) 
  {
    interface_instance -> runPrompt();
    resolveCommand();
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

  CmdEcho exe(*command_name_);
  exe.execute(*this, *interface_parameters_);
  
}
/*
int checkCorrectness()
{

}

void resolveError()
{
  
}*/