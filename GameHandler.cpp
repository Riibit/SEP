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

GameHandler() 
{
}

void setInterfaceParameters(std::vector<std::string>* interface_parameters); 
{
  interface_parameters_ = interface_parameters;
}

void setInterfaceCommand(std::string command_name) 
{
  command_name_ = command_name;
}

void resolveCommand(std::string command_name_)
{
  /*try
  {
    throw checkCorrectness();
  }
  catch (int i)
  {
    
  }
*/

  Command* new_command = new Command(command_name);
  new_command -> execute(&GameHandler game, interface_parameters_);
  delete new_command;
  
}
/*
int checkCorrectness()
{

}

void resolveError()
{
  
}*/