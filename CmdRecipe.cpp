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

#include <locale>
#include <iostream>
#include "CmdRecipe.h"
#include "GameHandler.h"


using std::cout;
using std::endl;

const std::string CmdRecipe::CMD_NAME = "recipe";

const std::string CmdRecipe::ERROR_MSG = 
  "[ERR] Usage: recipe [lemon] [sugar] [water]";
const std::string CmdRecipe::ERROR_MSG_PERCENT =
  "[ERR] The sum of parts must be 100.";

CmdRecipe::CmdRecipe () : Command::Command (CMD_NAME)
{
}

int CmdRecipe::execute (GameHandler& game, std::vector<std::string>& params)
{
  unsigned int lemon_percent;
  unsigned int sugar_percent;
  unsigned int water_percent;

  if (!(params.size() == 3))
  {
    cout << ERROR_MSG << endl;
    return 0;
  }

  for (unsigned int index = 0; index < 3; ++index)
  {
    if (!isItInteger(params[index]))
    {
      cout << ERROR_MSG << endl;
      return 0;
    }
  }

  lemon_percent = std::stoi(params[0]);
  sugar_percent = std::stoi(params[1]);
  water_percent = std::stoi(params[2]);

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

bool CmdRecipe::isItInteger (std::string string)
{
  std::locale loc;
  for (unsigned int position = 0; position < string.size(); ++position)
  {
    if (!std::isdigit(string[position], loc))
    {
      return false;
    }
  }
  return true;
}
