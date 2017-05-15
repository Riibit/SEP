//------------------------------------------------------------------------------
// Parse.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "Parse.h"
#include "ExceptionDataType.h"
#include <locale>

Parse::Parse()
{
}

Parse::~Parse()
{
}

uint Parse::parseInteger(std::string string)
{
  uint to_return = 0;
  std::locale loc;
  for (unsigned int position = 0; position < string.size(); ++position)
  {
    if (!std::isdigit(string[position], loc))
    {
      throw ExceptionDataType();
      return 0;
    }
  }
  try
  {
    to_return = std::stoi(string);
  }
  catch(const std::exception& exception)
  {
    throw ExceptionDataType();
    return to_return;
  }
  return to_return;
}

float Parse::parseFloat(std::string input)
{
  float to_return = 0;
  try
  {
    to_return = stof(input);
  }
  catch(const std::exception& exception)
  {
    throw ExceptionDataType();
    return to_return;
  }
  return to_return;
}

std::string Parse::parseRank(EnvironmentalCondition::Rank rank)
{
  switch(rank)
  {
    case EnvironmentalCondition::NONE :
      return RANK_NONE;
    case EnvironmentalCondition::LOW :
      return RANK_LOW;
    case EnvironmentalCondition::MEDIUM :
      return RANK_MEDIUM;
    default :
      return RANK_HIGH;
  }
}

std::string Parse::parseCover(EnvironmentalCondition::Cover cover)
{
  switch(cover)
  {
    case EnvironmentalCondition::SUNNY :
      return COVER_SUNNY;
    case EnvironmentalCondition::CLOUDY :
      return COVER_CLOUDY;
    case EnvironmentalCondition::OVERCAST :
      return COVER_OVERCAST;
    default :
      return COVER_VERY_OVERCAST;
  }  
}

EnvironmentalCondition::Rank Parse::parseStringToRank(std::string rank)
{
  if(rank.compare(RANK_NONE))
  {
    return EnvironmentalCondition::NONE;
  }
  else if(rank.compare(RANK_LOW))
  {
    return EnvironmentalCondition::LOW;
  }
  else if(rank.compare(RANK_MEDIUM))
  {
    return EnvironmentalCondition::MEDIUM;
  }
  else if(rank.compare(RANK_HIGH))
  {
    return EnvironmentalCondition::HIGH;
  }
}

EnvironmentalCondition::Cover Parse::parseStringToCover(std::string cover)
{
  if(cover.compare(COVER_SUNNY))
  {
    return EnvironmentalCondition::SUNNY;
  }
  else if(cover.compare(COVER_CLOUDY))
  {
    return EnvironmentalCondition::CLOUDY;
  }
  else if(cover.compare(COVER_OVERCAST))
  {
    return EnvironmentalCondition::OVERCAST;
  }
  else if(cover.compare(COVER_VERY_OVERCAST))
  {
    return EnvironmentalCondition::VERY_OVERCAST;
  }
}

