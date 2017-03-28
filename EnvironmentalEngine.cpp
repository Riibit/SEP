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
#include <iostream>
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
EnvironmentalCondition EnvironmentalEngine::createCondition()
{
	int rand_value;

	srand (time(NULL));
  rand_value = rand() % 4;
  switch(rand_value)
  {
    case 0 : sky_cover_rng = EnvironmentalCondition::SUNNY;
    break;
    case 1 : sky_cover_rng = EnvironmentalCondition::CLOUDY;
    break;
    case 2 : sky_cover_rng = EnvironmentalCondition::OVERCAST;
    break;
    case 3 : sky_cover_rng = EnvironmentalCondition::VERY_OVERCAST;
    break;
  }
  rand_value = rand() % 4;
  switch(rand_value)
  {
    case 0 : precipitation_rng = EnvironmentalCondition::NONE;
    break;
    case 1 : precipitation_rng = EnvironmentalCondition::LOW;
    break;
    case 2 : precipitation_rng = EnvironmentalCondition::MEDIUM;
    break;
    case 3 : precipitation_rng = EnvironmentalCondition::HIGH;
    break;
  }
  temperature_rng = (rand() % 25 + 10);
  if (temperature_rng <= MAX_TEMP)
    temperature_rng += ((rand() % 10) / 10.0f);
  rand_value = rand() % 4;
  switch(rand_value)
  {
    case 0 : wind_rng = EnvironmentalCondition::NONE;
    break;
    case 1 : wind_rng = EnvironmentalCondition::LOW;
    break;
    case 2 : wind_rng = EnvironmentalCondition::MEDIUM;
    break;
    case 3 : wind_rng = EnvironmentalCondition::HIGH;
    break;
  }
  std::cout << "sky_cover_rng = " << sky_cover_rng << std::endl;
  std::cout << "precipitation_rng = " << precipitation_rng << std::endl;
  std::cout << "temperature_rng = " << temperature_rng << std::endl;
  std::cout << "wind_rng = " << wind_rng << std::endl;

  EnvironmentalCondition *newCondition;
  newCondition = new EnvironmentalCondition(sky_cover_rng,	precipitation_rng, temperature_rng, wind_rng);


	return *newCondition;
}