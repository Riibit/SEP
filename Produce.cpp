//------------------------------------------------------------------------------
// Produce.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "Produce.h"
#include "GameHandler.h"

Produce::Produce()
{
}

Produce::~Produce()
{
}

int Produce::produceLemonade(GameHandler& game, unsigned int quantity)
{
  if(quantity % 4)
  {
    return NOT_DIVISIBLE_BY_FOUR;
  }

  int return_value = 0;

  // Get ingredient stock
  unsigned int lemon_stock = game.getResourceLemon();
  unsigned int sugar_stock = game.getResourceSugar();

  // Calculate needed resources
  unsigned int needed_lemon_per_lemonade = (game.getRecipeLemon() / 3);
  unsigned int needed_sugar_per_lemonade = (game.getRecipeSugar() / 2);

  unsigned int needed_lemon = needed_lemon_per_lemonade * quantity;
  unsigned int needed_sugar = needed_sugar_per_lemonade * quantity;

  // Check if we have enough resources and change quantity if needed
  if(needed_lemon > lemon_stock || needed_sugar > sugar_stock)
  {
    return_value = NOT_ENOUGH_RESOURCES;
    while(needed_lemon > lemon_stock || needed_sugar > sugar_stock)
    {
      quantity -= 4;
      needed_lemon = needed_lemon_per_lemonade * quantity;
      needed_sugar = needed_sugar_per_lemonade * quantity;
    }
  }

  // Add lemonade to stock
  game.setResourceLemonade(game.getResourceLemonade() + quantity);

  // Update Stock
  game.setResourceLemon(lemon_stock - needed_lemon);
  game.setResourceSugar(sugar_stock - needed_sugar);
  
  return return_value;
}