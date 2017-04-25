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

#include "CmdRecipe.h"
#include <string>
#include <locale>
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdRecipe::ERROR_MSG = 
  "[ERR] Usage: recipe [lemon] [sugar] [water]";
const std::string CmdRecipe::ERROR_MSG_PERCENT =
  "[ERR] The sum of parts must be 100.";

int CmdRecipe::execute (GameHandler& game, std::vector<std::string>& params)
{
  unsigned int lemon_percent;
  unsigned int sugar_percent;
  unsigned int water_percent;

  std::locale loc;

  if (!params.size() == 3)
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

  cout << 'L: ' lemon_percent << '%' << endl
  << 'S: ' << sugar_percent << '%' << endl
  << 'W: ' << water_percent << '%' << endl;

}

bool CmdRecipe::isItInteger (std::string string)
{
  for (int char_counter = 0; char_counter < string.size(); ++char_counter)
  {
    if (!std::isdigit(string[char_counter], loc))
    {
      return false;
    }
  }
  return true;
}
