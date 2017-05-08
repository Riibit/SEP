//------------------------------------------------------------------------------
// EnvironmentalEngine.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinić 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef ENV_ENG_H
#define ENV_ENG_H

#include <memory>
#include "EnvironmentalCondition.h"

//------------------------------------------------------------------------------
// The class that contains the environmental engine
//
class EnvironmentalEngine 
{
  public:
    EnvironmentalEngine();

    std::shared_ptr<EnvironmentalCondition> createCondition();

    EnvironmentalCondition::Cover toCover(unsigned int input);
    EnvironmentalCondition::Rank toRank(unsigned int input);


};

#endif // ENV_ENG_H
