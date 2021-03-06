//------------------------------------------------------------------------------
// CmdRecipe.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include <iostream>
#include "CmdRecipe.h"
#include "GameHandler.h"
#include "Parse.h"
#include "ExceptionDataType.h"
#include "ReturnValues.h"


using std::cout;
using std::endl;

const std::string CmdRecipe::CMD_NAME = "recipe";

const std::string CmdRecipe::ERR_CMD = 
  "[ERR] Usage: recipe [lemon] [sugar] [water]";
const std::string CmdRecipe::ERROR_MSG_PERCENT =
  "[ERR] The sum of parts must be 100.";
const std::string CmdRecipe::ERROR_MODULO_LEMON =
  "[ERR] The value of Lemon must be a multiple of 3.";
const std::string CmdRecipe::ERROR_MODULO_SUGAR =
  "[ERR] The value of Sugar must be a multiple of 2.";

CmdRecipe::CmdRecipe() : Command::Command(CMD_NAME, PARA_COUNT_ONE, ERR_CMD)
{
}


int CmdRecipe::execute(GameHandler& game, std::vector<std::string>& params)
{

  if(params.size() == PARA_COUNT_ONE)
  {
    return executeParameterOne(game, params);
  }
  else
  {
    return executeParameterTwo(game, params);
  }
}

int CmdRecipe::executeParameterOne(GameHandler& game, 
  std::vector<std::string>& params)
{
  printRecipe(game);
  return RETURN_SUCCESS;
}

int CmdRecipe::executeParameterTwo(GameHandler& game, 
  std::vector<std::string>& params) 
{
  unsigned int lemon_percent;
  unsigned int sugar_percent;
  unsigned int water_percent;

  Parse parser;
  try
  {
    lemon_percent = parser.parseInteger(params[0]);
    sugar_percent = parser.parseInteger(params[1]);
    water_percent = parser.parseInteger(params[2]);
  }
  catch(const ExceptionDataType& exception)
  {
    cout << Command::ERR_WRONG_PARAMETER << endl;
    return RETURN_SUCCESS;
  }

  if(lemon_percent + sugar_percent + water_percent != 100)
  {
    cout << ERROR_MSG_PERCENT << endl;
    return RETURN_SUCCESS;
  }

  if((lemon_percent % 3) != 0)
  {
    cout << ERROR_MODULO_LEMON << endl;
    return RETURN_SUCCESS;
  }

  if((sugar_percent % 2) != 0)
  {
    cout << ERROR_MODULO_SUGAR << endl;
    return RETURN_SUCCESS;
  }
  game.setRecipe(lemon_percent, sugar_percent, water_percent);
  printRecipe(game);
  return RETURN_SUCCESS;
}

void CmdRecipe::printRecipe(GameHandler& game)
{
  cout << "L: " << game.getRecipeLemon() << '%' << endl
    << "S: " << game.getRecipeSugar() << '%' << endl
    << "W: " << game.getRecipeWater() << '%' << endl;
}

const bool CmdRecipe::correctParameterCount(const unsigned int to_compare)
{
  if(to_compare == PARA_COUNT_ONE || to_compare == PARA_COUNT_TWO)
  {
    return true;
  }
  return false;
}
