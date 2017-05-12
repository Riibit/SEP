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
#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"

#include <iostream>
#include <string

using std::cout;
using std::endl;

const std::string CmdForecast::CMD_NAME = "forecast";
const std::string CmdForecast::ERR_CMD = 
  "[ERR] Usage: forecast";

CmdForecast::CmdForecast() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdForecast::execute(GameHandler& game, std::vector<std::string>& params)
{
  EnvironmentalCondition condition;

  int sky_cover = static_cast<int>(condition.getSkyCover());
  return 0;
}
