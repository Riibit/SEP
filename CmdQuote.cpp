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
#include "GameHandler.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdQuote::CMD_NAME = "quote";
const std::string CmdQuote::ERR_CMD = "[ERR] Usage: quote";

CmdQuote::CmdQuote() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdQuote::execute(GameHandler& game, std::vector<std::string>& params)
{
  cout << "L: " << game.getPriceLemon() << " $" << endl
  << "S: " << game.getPriceSugar() << " $" << endl;
  return 0;
}
