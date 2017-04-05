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
/*
#include "HTMLWriter.h"
#include "HTMLWriterEnvironment.h"
#include "HTMLWriterBalance.h"
*/

int main()
{
  EnvironmentalEngine engine;
  EnvironmentalCondition *newCondition;
  newCondition = engine.createCondition();
  delete newCondition;
  newCondition = NULL;
  return 0;
}