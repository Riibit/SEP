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


using std::cout;
using std::endl;

const std::string CmdRecipe::CMD_NAME = "recipe";

const std::string CmdRecipe::ERR_RECIPE = 
  "[ERR] Usage: recipe [lemon] [sugar] [water]";
const std::string CmdRecipe::ERROR_MSG_PERCENT =
  "[ERR] The sum of parts must be 100.";

CmdRecipe::CmdRecipe() : Command::Command(CMD_NAME, PARA_COUNT, ERR_RECIPE)
{
}


int CmdRecipe::execute(GameHandler& game, std::vector<std::string>& params)
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
  
  catch(const ExceptionNotInteger& exception)
  {
    cout << ERR_RECIPE << endl;
    return 0;
  }

  if (lemon_percent + sugar_percent + water_percent != 100)
  {
    cout << ERROR_MSG_PERCENT << endl;
    return 0;
  }

  cout << "L: " << lemon_percent << '%' << endl
  << "S: " << sugar_percent << '%' << endl
  << "W: " << water_percent << '%' << endl;
  return 0;
}
