//------------------------------------------------------------------------------
// EnvironmentalCondition.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include <iostream>
#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"

EnvironmentalCondition::EnvironmentalCondition()
{
  
}

EnvironmentalCondition::EnvironmentalCondition(Cover sky_cover, Rank precipitation, float temperature, Rank wind)
{
    setSkyCover(sky_cover);
    setPrecipitation(precipitation);
    setTemperature(temperature);
    setWind(wind);
}

//------------------------------------------------------------------------------
// Method to find out if it is sunny
//
// @return Returns true if it is sunny and the temperature is in the top one 
//         third
//
bool EnvironmentalCondition::isItHot()
{
  if (sky_cover_ == SUNNY && temperature_ > (HOT_TRESHOLD))
  {
    return true;
  }
  else
  {
    return false;
  }
}

//------------------------------------------------------------------------------
// Method to find out if it is rainy
//
// @return Returns true if the precipation is medium or high and the sky cover
//         is overcast or very overcast
//
bool EnvironmentalCondition::isItRainy()
{
  if ((precipitation_ == MEDIUM || precipitation_ == HIGH)
    && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    return true;
  }
  else
  {
    return false;
  } 
}

//------------------------------------------------------------------------------
// Method to find out if it is stormy
//
// @return Returns true if the wind is medium or high and the sky cover is 
//         overcast or very overcast
//
bool EnvironmentalCondition::isItStormy()
{
  if ((wind_ == MEDIUM || wind_ == HIGH) 
    && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    return true;
  }
  else
  {
    return false;
  }
}

//------------------------------------------------------------------------------
// Method to set sky cover rank
//
// @param cover The sky cover rank that is to be set
//
void EnvironmentalCondition::setSkyCover(Cover cover)
{
  sky_cover_ = cover;
}

//------------------------------------------------------------------------------
// Method to get the sky cover rank
//
// @return Returns the sky cover rank
//
EnvironmentalCondition::Cover EnvironmentalCondition::getSkyCover(void)
{
  return sky_cover_;
}

//------------------------------------------------------------------------------
// Method to set the precipitation rank
//
// @param rank The precipitation rank that is to be set
//
void EnvironmentalCondition::setPrecipitation(Rank rank)
{
  precipitation_ = rank;
}

//------------------------------------------------------------------------------
// Method to get the precipitation rank
//
// @return Returns the precipitation rank
//
EnvironmentalCondition::Rank EnvironmentalCondition::getPrecipitation(void)
{
  return precipitation_;
}

//------------------------------------------------------------------------------
// Method to set the temperature
//
// @param temperature the value of the temperature that is to be set
//
void EnvironmentalCondition::setTemperature(float temperature)
{
  if (temperature_ >= MAX_TEMP || temperature_ <= MIN_TEMP)
  {
    temperature_ = temperature;
  }
}

//------------------------------------------------------------------------------
// Method to get the temperature
//
// @return Returns the temperature
//
float EnvironmentalCondition::getTemperature(void)
{
  return temperature_;
}

//------------------------------------------------------------------------------
// Method to set the wind rank
//
// @param rank The wind rank that is to be set
//
void EnvironmentalCondition::setWind(Rank rank)
{
  wind_ = rank;
}

//------------------------------------------------------------------------------
// Method to get the wind rank
//
// @return Returns the wind rank
//
EnvironmentalCondition::Rank EnvironmentalCondition::getWind(void)
{
  return wind_;
}

//---------------------MAIN-----------------------------------------------------
