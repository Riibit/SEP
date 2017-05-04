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

class parse
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    parse();

    int parseInteger(std::string input);

};


#endif //PARSE_H_INCLUDED