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
#include "Parse.h"

#include <iostream>
#include <string>

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
  Parse parser;

  int sky_cover = static_cast<int>(game.getCondition() -> getSkyCover());
  int precipitation = static_cast<int>(game.getCondition() -> getPrecipitation());
  float temperature = game.getCondition() -> getTemperature();
  int wind = static_cast<int>(game.getCondition() -> getWind());
  float under_temperature;
  float over_temperature;

  EnvironmentalCondition::Cover under_sky_cover = 
    static_cast<EnvironmentalCondition::Cover>(weatherLower(sky_cover));

  EnvironmentalCondition::Cover over_sky_cover = 
    static_cast<EnvironmentalCondition::Cover>(weatherHigher(sky_cover));

  EnvironmentalCondition::Rank under_precipitation = 
    static_cast<EnvironmentalCondition::Rank>(weatherLower(precipitation));

  EnvironmentalCondition::Rank over_precipitation = 
    static_cast<EnvironmentalCondition::Rank>(weatherHigher(precipitation));

  EnvironmentalCondition::Rank under_wind = 
    static_cast<EnvironmentalCondition::Rank>(weatherLower(wind));

  EnvironmentalCondition::Rank over_wind = 
    static_cast<EnvironmentalCondition::Rank>(weatherHigher(wind));


  under_temperature = temperature - SWING;
  if(under_temperature < EnvironmentalCondition::MIN_TEMP)
  {
    under_temperature = EnvironmentalCondition::MIN_TEMP;
  }

  over_temperature = temperature + SWING;
  if(over_temperature > EnvironmentalCondition::MAX_TEMP)
  {
    over_temperature = EnvironmentalCondition::MAX_TEMP;
  }

  cout << "The weather forecast for next week is:" << endl
  << "Sky cover: Between " << parser.parseCover(under_sky_cover)
  << " and " << parser.parseCover(over_sky_cover) << endl
  << "Precipitation: Between " << parser.parseRank(under_precipitation)
  << " and " << parser.parseRank(over_precipitation) << endl
  << "Temperature: Between " << under_temperature << "°C"
  << " and " << over_temperature << "°C" << endl
  << "Wind: Between " << parser.parseRank(under_wind)
  << " and " << parser.parseRank(over_wind) << endl;

  return 0;
}

int CmdForecast::weatherLower(int enum_value)
{
  if(enum_value != 0)
  {
    enum_value -= 1;
    return enum_value;
  }
  else
  {
    return enum_value;
  }
}

int CmdForecast::weatherHigher(int enum_value)
{
  if(enum_value != 3)
  {
    enum_value += 1;
    return enum_value;
  }
  else
  {
    return enum_value;
  }
}