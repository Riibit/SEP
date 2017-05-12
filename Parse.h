//------------------------------------------------------------------------------
// Parse.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

#include <string>
#include "EnvironmentalCondition.h"

//------------------------------------------------------------------------------
// Parse Class
// Class that parses various values.
//

class Parse
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Parse();

    //--------------------------------------------------------------------------
    // Destructor
    ~Parse();

    //--------------------------------------------------------------------------
    // parseInteger Parses string to unsigned integer
    // @param input The string that is to be parsed
    // @return uint The parsed unsigned integer
    //
    uint parseInteger(std::string input);

    //--------------------------------------------------------------------------
    // parseFloat Parses string to float
    // @param input The string that is to be parsed
    // @return uint The parsed float
    //
    float parseFloat(std::string input);

    //--------------------------------------------------------------------------
    // parseRank Parses Rank enum to string
    // @param rank the Enum value to parse
    // @return string The parsed string
    //
    std::string parseRank(EnvironmentalCondition::Rank rank);

    //--------------------------------------------------------------------------
    // parseCover Parses cover enum to string
    // @param cover the Enum value to parse
    // @return string The parsed string
    //
    std::string parseCover(EnvironmentalCondition::Cover cover);

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Parse(const Parse& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Parse& operator=(const Parse& original);    
};


#endif //PARSE_H_INCLUDED