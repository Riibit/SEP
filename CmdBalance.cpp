//------------------------------------------------------------------------------
// CmdBalance.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdBalance.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdBalance::CMD_NAME = "balance";
const std::string CmdBalance::ERR_BALANCE = "[ERR] Usage: balance";
static const unsigned int PARA_COUNT = 0;

CmdBalance::CmdBalance() : Command::Command(CMD_NAME, PARA_COUNT, ERR_BALANCE)
{
}

int CmdBalance::execute(GameHandler& game, std::vector<std::string>& params)
{
  int lemon = 100;
  int sugar = 100;
  int cash = 1000;

  cout << "L: " << lemon << endl
  << "S: " << sugar << endl
  << "----------" << endl
  << "C: " << cash << " $" << endl;
  return 0;
}
