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

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"


const float EnvironmentalCondition::MIN_TEMP = 10;
const float EnvironmentalCondition::MAX_TEMP = 35;
const float EnvironmentalCondition::HOT_THRESHOLD = 
  ((((MAX_TEMP - MIN_TEMP) / 3) * 2) + MIN_TEMP);
const float EnvironmentalCondition::CHILLY_THRESHOLD = 
  ((MAX_TEMP - MIN_TEMP) / 3) + MIN_TEMP;

EnvironmentalCondition::EnvironmentalCondition()
{
}

EnvironmentalCondition::~EnvironmentalCondition()
{
}


EnvironmentalCondition::EnvironmentalCondition(Cover sky_cover, 
  Rank precipitation, float temperature, Rank wind)
{
  setSkyCover(sky_cover);
  setPrecipitation(precipitation);
  setTemperature(temperature);
  setWind(wind);
}

bool EnvironmentalCondition::isItHot()
{
  if(sky_cover_ == SUNNY && temperature_ > HOT_THRESHOLD)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool EnvironmentalCondition::isItRainy()
{
  if((precipitation_ == MEDIUM || precipitation_ == HIGH)
    && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool EnvironmentalCondition::isItStormy()
{
  if((wind_ == MEDIUM || wind_ == HIGH) 
    && (sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool EnvironmentalCondition::isItCloudy()
{
  if(sky_cover_ == OVERCAST || sky_cover_ == VERY_OVERCAST)
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool EnvironmentalCondition::isItChilly()
{
  if(temperature_ < CHILLY_THRESHOLD)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void EnvironmentalCondition::setSkyCover(Cover cover)
{
  sky_cover_ = cover;
}

EnvironmentalCondition::Cover EnvironmentalCondition::getSkyCover(void)
{
  return sky_cover_;
}

void EnvironmentalCondition::setPrecipitation(Rank rank)
{
  precipitation_ = rank;
}

EnvironmentalCondition::Rank EnvironmentalCondition::getPrecipitation(void)
{
  return precipitation_;
}

bool EnvironmentalCondition::setTemperature(float temperature)
{
  if(temperature >= MAX_TEMP || temperature <= MIN_TEMP)
  {
    temperature_ = temperature;
    return true;
  }
  return false;
}

float EnvironmentalCondition::getTemperature(void)
{
  return temperature_;
}

void EnvironmentalCondition::setWind(Rank rank)
{
  wind_ = rank;
}

EnvironmentalCondition::Rank EnvironmentalCondition::getWind(void)
{
  return wind_;
}