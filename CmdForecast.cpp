//------------------------------------------------------------------------------
// CmdForecast.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdForecast.h"
#include "GameHandler.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdProduce::CMD_NAME = "forecast";
const std::string CmdProduce::ERR_CMD = 
  "[ERR] Usage: forecast";

CmdForecast::CmdForecast() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdForecast::execute(GameHandler& game, std::vector<std::string>& params)
{
  return 0;
}
