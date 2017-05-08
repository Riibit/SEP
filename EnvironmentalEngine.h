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
    //--------------------------------------------------------------------------
    // Constructor
    EnvironmentalEngine();

    //--------------------------------------------------------------------------
    // Destructor
    ~EnvironmentalEngine();

    //--------------------------------------------------------------------------
    // The function createCondition creates a new condition, which values are
    // random, and returns the condition.
    //
    // @return EnvironmentalCondition Returns the pointer to the object on the 
    //         stack
    //         
    //
    std::shared_ptr<EnvironmentalCondition> createCondition();

    //--------------------------------------------------------------------------
    // The function toCover sets the correspondent enum value
    //
    // @return Returns the Enum value
    //         
    //
    EnvironmentalCondition::Cover toCover(unsigned int input);

    //--------------------------------------------------------------------------
    // The function toRank sets the correspondent enum value
    //
    // @return Returns the Enum value
    //         
    //
    EnvironmentalCondition::Rank toRank(unsigned int input);


};

#endif // ENV_ENG_H
