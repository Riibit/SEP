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

    //--------------------------------------------------------------------------
    // parseStringToRank Parses string to cover enum
    // @param rank The string to parse
    // @return The corresponend enum values
    //
    EnvironmentalCondition::Rank parseStringToRank(std::string rank);

    //--------------------------------------------------------------------------
    // parseStringToRank Parses string to rank enum
    // @param rank The string to parse
    // @return The corresponend enum values
    //
    EnvironmentalCondition::Cover parseStringToCover(std::string cover);

    //--------------------------------------------------------------------------
    // The values of the rank enum in string form
    static const std::string RANK_NONE;
    static const std::string RANK_LOW;
    static const std::string RANK_MEDIUM;
    static const std::string RANK_HIGH;

    //--------------------------------------------------------------------------
    // The values of the cover enum in string form
    static const std::string COVER_SUNNY;
    static const std::string COVER_CLOUDY;
    static const std::string COVER_OVERCAST;
    static const std::string COVER_VERY_OVERCAST;

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Parse(const Parse& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Parse& operator=(const Parse& original);
};


#endif //PARSE_H_INCLUDED