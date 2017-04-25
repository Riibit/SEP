//------------------------------------------------------------------------------
// Command.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <string>
#include <vector>

class GameHandler; 

class Interface 
{
  public:
    Interface();
    const int runInterface();
    const std::string getArgument(char* cin_value, bool to_lower);
    void makeVector(char* cin_value);

    static const std::string PROMPT_STRING;
  private:
    
};

#endif //INTERFACE_H_INCLUDED