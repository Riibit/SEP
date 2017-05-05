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
#include "CmdSetWeather.h"

using std::unique_ptr;

GameHandler::GameHandler() 
{
  game_quit_ = false;
  // TODO:  possibly add out of mem exception handling later
  commands_.push_back(unique_ptr<Command>(new CmdEcho()));
  commands_.push_back(unique_ptr<Command>(new CmdBalance()));
  commands_.push_back(unique_ptr<Command>(new CmdQuote()));
  commands_.push_back(unique_ptr<Command>(new CmdRecipe()));
  commands_.push_back(unique_ptr<Command>(new CmdQuit()));
  commands_.push_back(unique_ptr<Command>(new CmdSetWeather()));
  // initialize player resources
  player_.lemons = LEMONS_INITIAL_VALUE;
  player_.sugar = SUGAR_INITIAL_VALUE;
  player_.money = MONEY_INITIAL_VALUE;
}

GameHandler::~GameHandler()
{
}

int GameHandler::play()
{
  int return_value = 0;
  unique_ptr<Interface> interface_instance;
  interface_instance = unique_ptr<Interface>(new Interface(this));
  while(1) 
  {
    interface_instance -> runPrompt();
    return_value = resolveCommand();
    delete command_name_;
    delete interface_parameters_;
    if (game_quit_)
    {
      break;
    }
  }
  return return_value;
}

void GameHandler::setInterfaceParameters(std::vector<std::string>* 
  interface_parameters)
{
  interface_parameters_ = interface_parameters;
}

void GameHandler::setInterfaceCommand(std::string* command_name) 
{
  command_name_ = command_name;
}

int GameHandler::resolveCommand()
{
  int return_value = 0;
  unsigned int command_index;
  for (command_index = 0; command_index < commands_.size(); ++command_index)
  {
    if (!(commands_[command_index] -> getName().compare(*command_name_)))
    {
      if (commands_[command_index] -> 
        correctParameterCount(interface_parameters_ -> size()))
      {
        return_value = commands_[command_index] -> 
          execute(*this, *interface_parameters_);
      }
      else
      {
        std::cout << commands_[command_index] -> getErrorMessage() << std::endl;
      }
      break;
    }
  }
  return return_value;
}

void GameHandler::endOfLife()
{
  game_quit_ = true;
}

void GameHandler::setWeather(EnvironmentalCondition::Cover cover, 
  EnvironmentalCondition::Rank precipitation, float temperature, 
  EnvironmentalCondition::Rank wind)
{
  condition_ = unique_ptr<EnvironmentalCondition>(new EnvironmentalCondition(
    cover, precipitation, temperature, wind));
}

void GameHandler::setWeather(EnvironmentalCondition* condition)
{
  // Memory management  
  condition_ = condition;
}