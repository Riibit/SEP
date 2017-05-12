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
  catch(const std::out_of_range& exception)
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
  catch(const std::invalid_argument& exception)
  {
    throw ExceptionDataType();
    return to_return;
  }
  catch(const std::out_of_range& exception)
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
      return "none";
    case EnvironmentalCondition::LOW :
      return "low";
    case EnvironmentalCondition::MEDIUM :
      return "medium";
    default :
      return "high";
  }
}

std::string Parse::parseCover(EnvironmentalCondition::Cover cover)
{
  switch(cover)
  {
    case EnvironmentalCondition::SUNNY :
      return "sunny";
    case EnvironmentalCondition::CLOUDY :
      return "cloudy";
    case EnvironmentalCondition::OVERCAST :
      return "overcast";
    default :
      return "very overcast";
  }  
}

