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
#include <memory>
#include "GameHandler.h"
#include "Sales.h"

Sales::Sales()
{
}

Sales::~Sales()
{
}

unsigned int Sales::calculateCustomers(GameHandler& game)
{
  unsigned int customer_count;
  std::unique_ptr<EnvironmentalCondition> condition = game.getCondition();


}

