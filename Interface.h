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
//#include <vector>

class GameHandler;

//------------------------------------------------------------------------------
// Interface Class
// class representing the user interface/view
//
class Interface 
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    // @param game Pointer to the calling object
    //
    Interface(GameHandler* game);

    //--------------------------------------------------------------------------
    // Destructor
    ~Interface();

    //--------------------------------------------------------------------------
    // Initializes the interface
    //  
    const int runPrompt();

    //--------------------------------------------------------------------------
    // Acquires command name
    // @param cin_value Input item 
    // @param to_lower Lowercase flag
    // @return Lowercase Input item
    //
    const std::string getArgument(char* cin_value, bool to_lower);
    
    //--------------------------------------------------------------------------
    // Pushes command parameters to a vector
    // @param cin_value Input item
    //
    void makeVector(char* cin_value);

    //--------------------------------------------------------------------------
    /// The string before every command entry
    static const std::string PROMPT_STRING;

  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Interface(const Interface& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Interface& operator=(const Interface& original);

    //--------------------------------------------------------------------------
    // Object pointer to game
    GameHandler* game_;
};

#endif //INTERFACE_H_INCLUDED