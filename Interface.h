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

//----------------------------------------------------------------------------
// Interface Class
// class representing the user interface/view
//
class Interface 
{
  public:

    //------------------------------------------------------------------------
    // Constructor
    // @param game Pointer to the calling object
    //
    Interface(GameHandler* game);

    //------------------------------------------------------------------------
    // Initializes the interface
    //  
    const int runPrompt();

    //------------------------------------------------------------------------
    // Acquires command name
    // @param cin_value Input item 
    // @param to_lower Lowercase flag
    //
    const std::string getArgument(char* cin_value, bool to_lower);
    
    //------------------------------------------------------------------------
    // Pushes command parameters to a vector
    // @param cin_value Input item
    //
    void makeVector(char* cin_value);

    static const std::string PROMPT_STRING;
    
  private:
    GameHandler* game_;
};

#endif //INTERFACE_H_INCLUDED