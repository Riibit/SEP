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
#include <cmath>
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
  unsigned int customer_count = STANDARD_CUSTOMER_COUNT;

  if(game.getCondition() -> isItStormy())
  {
    customer_count = std::round(customer_count * VALUE_STORMY);
  }
  else if(game.getCondition() -> isItRainy())
  {
    customer_count = std::round(customer_count * VALUE_RAINY);
  }
  else if(game.getCondition() -> isItCloudy())
  {
    customer_count = std::round(customer_count * VALUE_CLOUDY);
  }
  else if(game.getCondition() -> isItHot())
  {
    customer_count = std::round(customer_count * VALUE_HOT);
  }

#ifdef AUFBAU
  customer_count = std::round(customer_count * game.getSatisfactionFactor());
#endif //AUFBAU customer_satisfaction
  return customer_count;
}

int Sales::calculateSaleInfluence(GameHandler& game)
{
  int sale_percent = HUNDRED;

  if(game.getCondition() -> isItHot())
  {
    if(game.getRecipeSugar() < GameHandler::STANDARD_RECIPE_SUGAR)
    {
      sale_percent += TWENTY;
    }
    else if(game.getRecipeSugar() > GameHandler::STANDARD_RECIPE_SUGAR)
    {
      sale_percent -= TWENTY;
    }

    if(game.getRecipeLemon() > GameHandler::STANDARD_RECIPE_LEMON)
    {
      sale_percent += TWENTY;
    }
  }
  else if(game.getCondition() -> isItChilly())
  {
    if(game.getRecipeSugar() > GameHandler::STANDARD_RECIPE_SUGAR)
    {
      sale_percent += TWENTY;
    }
    else if(game.getRecipeSugar() < GameHandler::STANDARD_RECIPE_SUGAR)
    {
      sale_percent -= TWENTY;
    }

    if(game.getRecipeLemon() > GameHandler::STANDARD_RECIPE_LEMON)
    {
      sale_percent -= TWENTY;
    }
  }

  if(game.getRecipeSugar() > 15)
  {
    sale_percent -= FIFTY;
  }

  if(game.getRecipeSugar() > 20)
  {
    sale_percent -= HUNDRED;
  }

  if(game.getRecipeLemon() > 12)
  {
    sale_percent -= FIFTY;
  }   
  
  if(game.getRecipeLemon() > 18)
  {
    sale_percent -= HUNDRED;
  } 

  if(game.getRecipeWater() > 95)
  {
    sale_percent -= FIFTY;
  }   
  
  if(game.getRecipeWater() > 98)
  {
    sale_percent -= HUNDRED;
  }  

  if(sale_percent < MINIMUM_PERCENT)
  {
    sale_percent = MINIMUM_PERCENT;
  } 
  
  return sale_percent;    
}

void Sales::calculateSales(GameHandler& game)
{
  unsigned int customers = calculateCustomers(game);
  int sale_percent = calculateSaleInfluence(game);
  int lemonade_price = game.getPriceLemonade();
  int revenue;
  int money;
  int satisfaction_changed;
  float influence_factor = sale_percent / 100.0f;

  customers = std::round(customers * influence_factor);

  if(customers > game.getResourceLemonade())
  {
    if(game.getCustomerSatisfaction() < TEN)
    {
    }
    else
    {
      satisfaction_changed = game.getCustomerSatisfaction();
      satisfaction_changed -= TEN;
      game.setCustomerSatisfaction(satisfaction_changed);
    }
    customers = game.getResourceLemonade();
  }
  else
  {
    if(game.getCustomerSatisfaction() > 110)
    {

    }
    else
    {
      satisfaction_changed = game.getCustomerSatisfaction();
      satisfaction_changed += TEN;
      game.setCustomerSatisfaction(satisfaction_changed);
    }  
  }

  revenue = customers * lemonade_price;

  money = game.getResourceMoney();
  money += revenue;
  game.setResourceMoney(money);

  game.setResourceIncome(revenue);
  game.calculateBalance();
}


