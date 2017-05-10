//------------------------------------------------------------------------------
// Sales.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
#include <iostream>
#include <memory>
#include "GameHandler.h"
#include "Sales.h"
#include "EnvironmentalCondition.h"

const float Sales::VALUE_STORMY = 0.1;
const float Sales::VALUE_RAINY = 0.5;
const float Sales::VALUE_CLOUDY = 0.8;
const float Sales::VALUE_HOT = 1.5;

Sales::Sales()
{
}

Sales::~Sales()
{
}

unsigned int Sales::calculateCustomers(GameHandler& game)
{
  float customer_count = STANDARD_CUSTOMER_COUNT;
  //std::unique_ptr<EnvironmentalCondition> condition;
  //*condition = game.getCondition();
  
  if(game.getCondition() -> isItStormy())
  {
    customer_count = customer_count * VALUE_STORMY;
    return customer_count;
  }

  if(game.getCondition() -> isItRainy())
  {
    customer_count = customer_count * VALUE_RAINY;
    return customer_count;
  }

  if(game.getCondition() -> isItCloudy())
  {
    customer_count = customer_count * VALUE_CLOUDY;
    return customer_count;
  }

  if(game.getCondition() -> isItHot())
  {
    customer_count = customer_count * VALUE_HOT;
    return customer_count;
  }
  return customer_count;
}

