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

//----------------------------------------------------------------------------
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
    // Parses string to unsigned integer
    // @param input The string that is to be parsed
    // @return uint The parsed unsigned integer
    uint parseInteger(std::string input);

    //--------------------------------------------------------------------------
    // Parses string to float
    // @param input The string that is to be parsed
    // @return uint The parsed float
    float parseFloat(std::string input);
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Parse(const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Parse& operator=(const Command& original);    
};


#endif //PARSE_H_INCLUDED