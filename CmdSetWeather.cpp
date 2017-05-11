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

#include <iostream>
#include "CmdSetWeather.h"
#include "GameHandler.h"
#include "Parse.h"
#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"

const std::string CmdSetWeather::CMD_NAME = "setweather";
const std::string CmdSetWeather::ERR_CMD = "[ERR] Usage: setweather <cover> \
<precipitation> <temperature> <wind>";
const std::string CmdSetWeather::ERR_WRONG_PARAMETER = "[ERR] Wrong parameter";

CmdSetWeather::CmdSetWeather() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdSetWeather::execute(GameHandler& game, std::vector<std::string>& params)
{
  uint int_cover;
  uint int_precipitation;
  float temperature;
  uint int_wind;

  EnvironmentalCondition::Cover sky_cover;
  EnvironmentalCondition::Rank precipitation;
  EnvironmentalCondition::Rank wind;

  Parse parser;
  int_cover = parser.parseInteger(params[0]);
  int_precipitation = parser.parseInteger(params[1]);
  temperature = parser.parseFloat(params[2]);
  int_wind = parser.parseInteger(params[3]);

  EnvironmentalEngine get_enums;
  sky_cover = get_enums.toCover(int_cover);
  precipitation = get_enums.toRank(int_precipitation);
  wind = get_enums.toRank(int_wind);

  game.getCondition() -> setSkyCover(sky_cover);
  game.getCondition() -> setPrecipitation(precipitation);
  game.getCondition() -> setWind(wind);

  if(!(game.getCondition() -> setTemperature(temperature)))
  {
    game.getCondition() -> setTemperature(temperature);
  }
  else
  {
    std::cout << ERR_WRONG_PARAMETER << std::endl;
  }

  return 0;
}