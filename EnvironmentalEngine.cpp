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
#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"

//------------------------------------------------------------------------------
// The function createCondition creates a new condition, which values are
// random, and returns the condition.
//
// @return Returns a new condition 
//         
//
EnvironmentalCondition* EnvironmentalEngine::createCondition()
{
  int random_value;
  float temperature;

  EnvironmentalCondition::Cover sky_cover;
  EnvironmentalCondition::Rank precipitation;
  EnvironmentalCondition::Rank wind;

  srand (time(NULL));
  random_value = rand() % 4;

  switch(random_value)
  {
    case 0 : sky_cover = EnvironmentalCondition::SUNNY;
      break;
    case 1 : sky_cover = EnvironmentalCondition::CLOUDY;
      break;
    case 2 : sky_cover = EnvironmentalCondition::OVERCAST;
      break;
    case 3 : sky_cover = EnvironmentalCondition::VERY_OVERCAST;
      break;
  }
  random_value = rand() % 4;

  switch(random_value)
  {
    case 0 : precipitation = EnvironmentalCondition::NONE;
      break;
    case 1 : precipitation = EnvironmentalCondition::LOW;
      break;
    case 2 : precipitation = EnvironmentalCondition::MEDIUM;
      break;
    case 3 : precipitation = EnvironmentalCondition::HIGH;
      break;
  }
  temperature = (rand() % 25 + EnvironmentalCondition::MIN_TEMP);

  if (temperature <= EnvironmentalCondition::MAX_TEMP)
    temperature += ((rand() % 10) / 10.0f);

  random_value = rand() % 4;

  switch(random_value)
  {
    case 0 : wind = EnvironmentalCondition::NONE;
      break;
    case 1 : wind = EnvironmentalCondition::LOW;
      break;
    case 2 : wind = EnvironmentalCondition::MEDIUM;
      break;
    case 3 : wind = EnvironmentalCondition::HIGH;
      break;
  }

  EnvironmentalCondition *new_condition;
  new_condition = new EnvironmentalCondition(sky_cover, precipitation, 
    temperature, wind);
  
  return new_condition;
}