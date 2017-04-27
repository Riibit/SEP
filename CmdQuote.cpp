//------------------------------------------------------------------------------
// CmdQuote.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdQuote.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdQuote::CMD_NAME = "quote";
const std::string CmdQuote::ERR_QUOTE = "[ERR] Usage: quote";

CmdQuote::CmdQuote() : Command::Command(CMD_NAME, PARA_COUNT, ERR_QUOTE)
{
}

int CmdQuote::execute(GameHandler& game, std::vector<std::string>& params)
{
  int lemon_quote = 100;
  int sugar_quote = 100;

  cout << "L: " << lemon_quote << " $" << endl
  << "S: " << sugar_quote << " $" << endl;
  return 0;
}
