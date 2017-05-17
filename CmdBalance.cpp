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
#include "GameHandler.h"
#include "ReturnValues.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdBalance::CMD_NAME = "balance";
const std::string CmdBalance::ERR_CMD = "[ERR] Usage: balance";


CmdBalance::CmdBalance() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdBalance::execute(GameHandler& game, std::vector<std::string>& params)
{
  cout << "L: " << game.getResourceLemon() << endl
  << "S: " << game.getResourceSugar() << endl
  << "----------" << endl
  << "C: " << game.getResourceMoney() << " $" << endl
  << "B: " << game.getResourceBalance() << " $" << endl;
  return RETURN_SUCCESS;
}
