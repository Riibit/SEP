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
	//----------------------------------------------------------
	//Engine:
	
	srand (time(NULL));
  sky_cover_rng = rand() % 5;
  precipitation_rng = rand() % 5;
  temperature_rng = (rand() % 10 + 25) + ((rand() % 10) / 10);
  wind_rng = rand() % 5;
  std::cout << "sky_cover_rng =" << sky_cover_rng << std::endl;
  std::cout << "temperature_rng =" << precipitation_rng << std::endl;
  std::cout << "temperature_rng =" << temperature_rng << std::endl;
  std::cout << "wind_rng =" << wind_rng << std::endl;

  EnvironmentalCondition::EnvironmentalCondition *newCondition = new EnvironmentalCondition::EnvironmentalCondition(
    sky_cover_rng, precipitation_rng, temperature_rng, wind_rng);


	//----------------------------------------------------------
	return newCondition;
}


