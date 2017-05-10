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
    // @return std::unique_ptr<EnvironmentalCondition> Returns the pointer to 
    //   the object on the stack wrapped in a unique_ptr
    //
    std::unique_ptr<EnvironmentalCondition> createCondition();

    //--------------------------------------------------------------------------
    // The function randomizeCondition randomizes the EnvironmentalCondition
    //
    // @param condition The EnvironmentalCondition object that is to be 
    //   randomized
    //
    void randomizeCondition(
      const std::unique_ptr<EnvironmentalCondition>& condition);

    //--------------------------------------------------------------------------
    // Creates a random temperature between the defined limitations
    //
    // @return float Returns the float
    //
    float randomTemperature();

    //--------------------------------------------------------------------------
    // Creates a random Cover enum value
    //
    // @return EnvironmentalCondition::Cover Returns the Enum value
    //
    EnvironmentalCondition::Cover randomCover();

    //--------------------------------------------------------------------------
    // Creates a random Rank enum value
    //
    // @return EnvironmentalCondition::Rank Returns the Enum value
    //
    EnvironmentalCondition::Rank randomRank();

    //--------------------------------------------------------------------------
    // The function toCover sets the correspondent enum value
    //
    // @return EnvironmentalCondition::Cover Returns the Enum value
    //
    EnvironmentalCondition::Cover toCover(unsigned int input);

    //--------------------------------------------------------------------------
    // The function toRank sets the correspondent enum value
    //
    // @return EnvironmentalCondition::Rank Returns the Enum value
    //
    EnvironmentalCondition::Rank toRank(unsigned int input);

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    EnvironmentalEngine(const EnvironmentalEngine& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    EnvironmentalEngine& operator=(const EnvironmentalEngine& original);
};

#endif // ENV_ENG_H
