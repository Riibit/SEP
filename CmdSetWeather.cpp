//------------------------------------------------------------------------------
// CmdSetWeather.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdSetWeather.h"
#include "GameHandler.h"

const std::string CmdSetWeather::CMD_NAME = "setweather";

CmdSetWeather::CmdSetWeather() : Command::Command(CMD_NAME, PARA_COUNT)
{
}

int CmdSetWeather::execute(GameHandler& game, std::vector<std::string>& params)
{
   
}