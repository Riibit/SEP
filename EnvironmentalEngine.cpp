//------------------------------------------------------------------------------
// EnvironmentalEngine.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinić 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include <ctime>
#include <cstdlib>
#include "EnvironmentalEngine.h"
#include <iostream>

EnvironmentalEngine::EnvironmentalEngine()
{
  srand (time(NULL));
}

EnvironmentalEngine::~EnvironmentalEngine()
{
}

std::unique_ptr<EnvironmentalCondition> EnvironmentalEngine::createCondition()
{
  return std::unique_ptr<EnvironmentalCondition>
    (new EnvironmentalCondition(randomCover(), randomRank(), 
    randomTemperature(), randomRank()));
}

void EnvironmentalEngine::randomizeCondition(
  const std::unique_ptr<EnvironmentalCondition>& condition)
{
  condition -> setSkyCover(randomCover());
  condition -> setPrecipitation(randomRank());
  condition -> setTemperature(randomTemperature());
  condition -> setWind(randomRank());
}

float EnvironmentalEngine::randomTemperature()
{
  float temperature;

  temperature = (rand() % 25 + EnvironmentalCondition::MIN_TEMP);

  if (temperature <= EnvironmentalCondition::MAX_TEMP)
  {
    temperature += ((rand() % 10) / 10.0f);
  }
  return temperature;
}

EnvironmentalCondition::Cover EnvironmentalEngine::randomCover()
{
  return toCover(rand() % 4);
}

EnvironmentalCondition::Rank EnvironmentalEngine::randomRank()
{
  return toRank(rand() % 4);
}

EnvironmentalCondition::Cover EnvironmentalEngine::toCover(unsigned int input)
{
  switch(input)
  {
    case 0 :
      return EnvironmentalCondition::SUNNY;
      break;
    case 1 :
      return EnvironmentalCondition::CLOUDY;
      break;
    case 2 :
      return EnvironmentalCondition::OVERCAST;
      break;
    default :
      return EnvironmentalCondition::VERY_OVERCAST;
      break;
  }
}

EnvironmentalCondition::Rank EnvironmentalEngine::toRank(unsigned int input)
{
  switch(input)
  {
    case 0 :
      return EnvironmentalCondition::NONE;
      break;
    case 1 :
      return EnvironmentalCondition::LOW;
      break;
    case 2 :
      return EnvironmentalCondition::MEDIUM;
      break;
    default :
      return EnvironmentalCondition::HIGH;
      break;
  }  
}
