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
#include "ExceptionDataType.h"

const float  EnvironmentalEngine::REALISTIC_TEMPERATURE_MARGIN_FLOAT = 
  static_cast<float>(EnvironmentalEngine::REALISTIC_TEMPERATURE_MARGIN);

const float  EnvironmentalEngine::DIGIT_MODULUS_FLOAT = 
  static_cast<float>(EnvironmentalEngine::DIGIT_MODULUS);

EnvironmentalEngine::EnvironmentalEngine()
{
  srand (time(NULL));
}

EnvironmentalEngine::~EnvironmentalEngine()
{
}

std::unique_ptr<EnvironmentalCondition> EnvironmentalEngine::createCondition()
{
  float temperature = randomTemperature();
  return std::unique_ptr<EnvironmentalCondition>
    (new EnvironmentalCondition(randomCover(), randomRank(), 
    temperature, randomRank()));
}

void EnvironmentalEngine::randomizeCondition(
  const std::unique_ptr<EnvironmentalCondition>& condition)
{
  condition -> setSkyCover(randomCover());
  condition -> setPrecipitation(randomRank());
  condition -> setTemperature(randomTemperature());
  condition -> setWind(randomRank());
}

void EnvironmentalEngine::realisticCondition(
  const std::unique_ptr<EnvironmentalCondition>& condition)
{
  int enum_value;
  float temperature = condition -> getTemperature();
  float temperature_summand = REALISTIC_TEMPERATURE_MARGIN_FLOAT - 
    (rand() % 11);
  if(temperature_summand < REALISTIC_TEMPERATURE_MARGIN)
  {
    temperature_summand += ((rand() % DIGIT_MODULUS) / DIGIT_MODULUS_FLOAT);
  }
  temperature += temperature_summand;
  if(temperature < EnvironmentalCondition::MIN_TEMP)
  {
    temperature = EnvironmentalCondition::MIN_TEMP;
  }
  if(temperature > EnvironmentalCondition::MAX_TEMP)
  {
    temperature = EnvironmentalCondition::MAX_TEMP;
  }
  condition -> setTemperature(temperature);

  enum_value = realisticEnumInteger(static_cast<int>(
    condition -> getSkyCover()), EnvironmentalCondition::MAX_COVER_INT);
  condition -> setSkyCover(
    static_cast<EnvironmentalCondition::Cover>(enum_value));

  enum_value = realisticEnumInteger(static_cast<int>(
    condition -> getPrecipitation()), EnvironmentalCondition::MAX_RANK_INT);
  condition -> setPrecipitation(
    static_cast<EnvironmentalCondition::Rank>(enum_value));

  enum_value = realisticEnumInteger(static_cast<int>(
    condition -> getWind()), EnvironmentalCondition::MAX_RANK_INT);
  condition -> setWind(
    static_cast<EnvironmentalCondition::Rank>(enum_value));
}

int EnvironmentalEngine::realisticEnumInteger(int enum_value, int upper_range)
{
  int enum_summand = (rand() % 3) - 1;
  enum_value += enum_summand;
  if(enum_value <= 0)
  {
    enum_value = 0;
  }
  if(enum_value >= upper_range)
  {
    enum_value = upper_range;
  }
  return enum_value;
}

float EnvironmentalEngine::randomTemperature()
{
  float temperature;

  temperature = ((rand() % 25) + EnvironmentalCondition::MIN_TEMP);

  temperature += ((rand() % DIGIT_MODULUS) / DIGIT_MODULUS_FLOAT);

  return temperature;
}

EnvironmentalCondition::Cover EnvironmentalEngine::randomCover()
{
  return toCover(rand() % (EnvironmentalCondition::MAX_COVER_INT + 1));
}

EnvironmentalCondition::Rank EnvironmentalEngine::randomRank()
{
  return toRank(rand() % (EnvironmentalCondition::MAX_RANK_INT + 1));
}

EnvironmentalCondition::Cover EnvironmentalEngine::toCover(unsigned int input)
{
  if(input > EnvironmentalCondition::MAX_COVER_INT)
  {
    throw ExceptionDataType();
  }  
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
  if(input > EnvironmentalCondition::MAX_RANK_INT)
  {
    throw ExceptionDataType();
  }

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
