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

EnvironmentalEngine::EnvironmentalEngine()
{
  srand (time(NULL));
}

//------------------------------------------------------------------------------
// The function createCondition creates a new condition, which values are
// random, and returns the condition.
//
// @return EnvironmentalCondition Returns the pointer to the object on the stack
//         
//
EnvironmentalCondition* EnvironmentalEngine::createCondition()
{
  int random_value;
  float temperature;

  EnvironmentalCondition::Cover sky_cover;
  EnvironmentalCondition::Rank precipitation;
  EnvironmentalCondition::Rank wind;

  sky_cover = toCover(rand() % 4);

  precipitation = toRank(rand() % 4);

  temperature = (rand() % 25 + EnvironmentalCondition::MIN_TEMP);

  if (temperature <= EnvironmentalCondition::MAX_TEMP)
    temperature += ((rand() % 10) / 10.0f);

  wind = toRank(rand() % 4);

  EnvironmentalCondition *new_condition;
  new_condition = new EnvironmentalCondition(sky_cover, precipitation, 
    temperature, wind);
  
  return new_condition;
}

//------------------------------------------------------------------------------
// The function toCover sets the correspondent enum value
//
// @return Returns the Enum value
//         
//
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

//------------------------------------------------------------------------------
// The function toRank sets the correspondent enum value
//
// @return Returns the Enum value
//         
//
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
