//------------------------------------------------------------------------------
// main.cpp
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

int main()
{
  EnvironmentalEngine engine;
  EnvironmentalCondition *newCondition;
  newCondition = engine.createCondition();
  return 0;
}