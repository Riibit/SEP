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

#define AUFBAU

#include <iostream>
#include "GameHandler.h"
#include "Interface.h"
#include "Parse.h"
#include "CmdSetWeather.h"
#include "CmdEcho.h"
#include "CmdPlay.h"
#include "CmdBalance.h"
#include "CmdQuote.h"
#include "CmdRecipe.h"
#include "CmdBuy.h"
#include "CmdQuit.h"
#include "ExceptionDataType.h"
#include "EnvironmentalEngine.h"
// LINE BELOW TO BE DELETED FROM HERE LATER AS IT IS PART OF AUFBAU
// ALLOWS CMDSAVE TO AVOID COMPILER ERRORS
#include "CmdSave.h" 
// ----------------
// LINE BELOW TO BE DELETED FROM HERE LATER AS IT IS PART OF AUFBAU
// ALLOWS CMDLOAD TO AVOID COMPILER ERRORS
#include "CmdLoad.h"
// ----------------

#ifdef AUFBAU

#include "CmdForecast.h"
#include "CmdProduce.h"
#include "CmdLoad.h"
#include "CmdSave.h"

#endif //AUFBAU

using std::unique_ptr;

const std::string GameHandler::ERR_PROGRAM_START = 
  "[ERR] Wrong usage: ./basic <price_lemonade> <price_lemon> <price_sugar>";

GameHandler::GameHandler() 
{
  game_quit_ = false;
  try
  {
  // TODO:  possibly add out of mem exception handling later
    commands_.push_back(unique_ptr<Command>(new CmdSetWeather()));
    commands_.push_back(unique_ptr<Command>(new CmdEcho()));
    commands_.push_back(unique_ptr<Command>(new CmdPlay()));
    commands_.push_back(unique_ptr<Command>(new CmdBalance()));
    commands_.push_back(unique_ptr<Command>(new CmdQuote()));
    commands_.push_back(unique_ptr<Command>(new CmdRecipe()));
    commands_.push_back(unique_ptr<Command>(new CmdBuy()));
    commands_.push_back(unique_ptr<Command>(new CmdQuit()));
    // LINE BELOW TO BE DELETED FROM HERE LATER AS IT IS PART OF AUFBAU
    // ALLOWS CMDSAVE TO AVOID COMPILER ERRORS
    commands_.push_back(unique_ptr<Command>(new CmdSave())); 
    // -----------
    // LINE BELOW TO BE DELETED FROM HERE LATER AS IT IS PART OF AUFBAU
    // ALLOWS CMDLOAD TO AVOID COMPILER ERRORS
    commands_.push_back(unique_ptr<Command>(new CmdLoad()));
    // -----------
#ifdef AUFBAU
    commands_.push_back(unique_ptr<Command>(new CmdForecast()));
    commands_.push_back(unique_ptr<Command>(new CmdProduce()));
    commands_.push_back(unique_ptr<Command>(new CmdLoad()));
    commands_.push_back(unique_ptr<Command>(new CmdSave()));
#endif //AUFBAU
  }
  catch(std::bad_alloc& exception)
  {
    throw exception;
  }
  // initialize player resources
  resources_.lemons = LEMONS_INITIAL_VALUE;
  resources_.sugar = SUGAR_INITIAL_VALUE;
  resources_.money = MONEY_INITIAL_VALUE;
  resources_.balance = ZERO_INITIAL_VALUE;
  resources_.income = ZERO_INITIAL_VALUE;
  resources_.lemonade = ZERO_INITIAL_VALUE;
  resources_.money_spent = ZERO_INITIAL_VALUE;
}

GameHandler::~GameHandler()
{
}

int GameHandler::initialize(int argc, char *parameters[])
{
  if (argc != 4)
  {
    std::cout << ERR_PROGRAM_START << std::endl;
    return 2;
  }
  Parse parser;
  std::string argument_1(parameters[1]);
  std::string argument_2(parameters[2]);
  std::string argument_3(parameters[3]);
  try
  {
    price_lemonade_ = parser.parseInteger(argument_1);
    price_lemon_ = parser.parseInteger(argument_2);
    price_sugar_ = parser.parseInteger(argument_3);
  }
  catch(const ExceptionDataType& exception)
  {
    std::cout << ERR_PROGRAM_START << std::endl;
    return 2;
  }

  EnvironmentalEngine engine;
  environment_condition_ = std::move(engine.createCondition());

  resetStandardRecipe();
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

int GameHandler::resolveCommand()
{
  int return_value = 0;
  bool invalid_command = true;
  unsigned int command_index;
  for (command_index = 0; command_index < commands_.size(); ++command_index)
  {
    if (!(commands_[command_index] -> getName().compare(*command_name_)))
    {
      invalid_command = false;
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
  
  if (invalid_command == true)
  {
    std::cout << "[ERR] Unknown command." << std::endl;
  }
  return return_value;
}

void GameHandler::resetStandardRecipe()
{
  recipe_.lemon = STANDARD_RECIPE_LEMON;
  recipe_.sugar = STANDARD_RECIPE_SUGAR;
  recipe_.water = STANDARD_RECIPE_WATER;
}

void GameHandler::endOfLife()
{
  game_quit_ = true;
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
  resources_.lemons = lemon_value;
}

void GameHandler::setResourceSugar(unsigned int sugar_value)
{
  resources_.sugar = sugar_value;
}

void GameHandler::setResourceMoney(unsigned int money_value)
{
  resources_.money = money_value;
}

void GameHandler::setResourceIncome(unsigned int value)
{
  resources_.income = value;
}

void GameHandler::setResourceLemonade(unsigned int amount)
{
  resources_.lemonade = amount;
}

void GameHandler::addExpenses(unsigned int expenditures)
{
  resources_.expenses += expenditures;
}

void GameHandler::setCustomerSatisfaction(int satisfaction)
{
  customer_satisfaction_ = satisfaction;
}

unsigned int GameHandler::getResourceLemon()
{
  return resources_.lemons;
}

unsigned int GameHandler::getResourceSugar()
{
  return resources_.sugar;
}

unsigned int GameHandler::getResourceMoney()
{
  return resources_.money;
}

int GameHandler::getResourceBalance()
{
  return resources_.balance;
}

unsigned int GameHandler::getResourceIncome()
{
  return resources_.income;
}

unsigned int GameHandler::getResourceLemonade()
{
  return resources_.lemonade;
}

unsigned int GameHandler::getExpenses() 
{
  return resources_.expenses;
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

unsigned int GameHandler::getRecipeLemon()
{
  return recipe_.lemon;
}

unsigned int GameHandler::getRecipeSugar()
{
  return recipe_.sugar;
}

unsigned int GameHandler::getRecipeWater()
{
  return recipe_.water;
}

int GameHandler::getCustomerSatisfaction()
{
  return customer_satisfaction_;
}

float GameHandler::getSatisfactionFactor()
{
  float divisor = 100;
  return customer_satisfaction_ / divisor;
}

const std::unique_ptr<EnvironmentalCondition>& GameHandler::getCondition() const
{
  return environment_condition_;
}

void GameHandler::setRecipe(unsigned int lemon, unsigned int sugar, 
  unsigned int water)
{
  if (lemon + sugar + water == 100)
  {
    recipe_.lemon = lemon;
    recipe_.sugar = sugar;
    recipe_.water = water;
  }
}

void GameHandler::calculateBalance()
{
  resources_.balance = resources_.income - resources_.expenses;
  resources_.income = 0;
  resources_.expenses = 0;
}