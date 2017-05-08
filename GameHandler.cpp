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
#include "Parse.h"
#include "CmdEcho.h"
#include "CmdBalance.h"
#include "CmdQuote.h"
#include "CmdRecipe.h"
#include "CmdQuit.h"
#include "ExceptionDataType.h"

using std::unique_ptr;

const std::string GameHandler::ERR_PROGRAM_START = 
  "[ERR] Wrong usage: ./basic <price_lemonade> <price_lemon> <price_sugar>";

GameHandler::GameHandler() 
{
  game_quit_ = false;
  // TODO:  possibly add out of mem exception handling later
  commands_.push_back(unique_ptr<Command>(new CmdEcho()));
  commands_.push_back(unique_ptr<Command>(new CmdBalance()));
  commands_.push_back(unique_ptr<Command>(new CmdQuote()));
  commands_.push_back(unique_ptr<Command>(new CmdRecipe()));
  commands_.push_back(unique_ptr<Command>(new CmdQuit()));
  // initialize player resources
  player_.lemons = LEMONS_INITIAL_VALUE;
  player_.sugar = SUGAR_INITIAL_VALUE;
  player_.money = MONEY_INITIAL_VALUE;
}

GameHandler::~GameHandler()
{
}

GameHandler::initialize(int argc, char *parameters[])
{
  if (argc != 3)
  {
    return 2;
  }
  Parse parser;
  std::string argument_1(parameters[0]);
  std::string argument_2(parameters[1]);
  std::string argument_3(parameters[2]);
  try
  {
    price_lemonade_ = parser.parseInteger(argument_1);
    price_lemon_ = parser.parseInteger(argument_2);
    price_sugar_ = parser.parseInteger(argument_3);
  }
  catch(const ExceptionDataType& exception)
  {
    cout << ERR_PROGRAM_START << endl;
    return 2;
  }
  return 0;
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

void GameHandler::setResourceLemon(unsigned int lemon_value)
{
  player_.lemons = lemon_value;
}

void GameHandler::setResourceSugar(unsigned int sugar_value)
{
  player_.sugar = sugar_value;
}

void GameHandler::setResourceMoney(unsigned int money_value)
{
  player_.money = money_value;
}


unsigned int GameHandler::getResourceLemon()
{
  return player_.lemons;
}

unsigned int GameHandler::getResourceSugar()
{
  return player_.sugar;
}

unsigned int GameHandler::getResourceMoney()
{
  return player_.money;
}


unsigned int GameHandler::getPriceLemonade()
{
  return price_lemonade_;
}

unsigned int GameHandler::getPriceLemon()
{
  return price_lemon_;
}

unsigned int GameHandler::getPriceSugar()
{
  return price_sugar_;
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