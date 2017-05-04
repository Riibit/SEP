//------------------------------------------------------------------------------
// GameHandler.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <string>
#include <vector>
#include <memory>

class Command;

//----------------------------------------------------------------------------
// GameHandler Class
// Class that runs the various methods of the game.
//
class GameHandler 
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    GameHandler();

    //--------------------------------------------------------------------------
    // Destructor
    ~GameHandler();

    //--------------------------------------------------------------------------
    // play executes the prompt method and is used to terminate the 
    // programm.
    // @return return_value Returns the corresponding return value.
    int play();

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    void setInterfaceParameters(std::vector<std::string>* 
      interface_parameters);
    void setInterfaceCommand(std::string* command_name);

    //--------------------------------------------------------------------------
    // endOfLife Method
    // Sets the variable game_quit_ to false so that the programm terminates
    // 
    void endOfLife();

  private:
    //--------------------------------------------------------------------------
    /// The name of the command that was given in stdin
    std::string* command_name_;

    //--------------------------------------------------------------------------
    /// The interface parameters given in stdin
    std::vector<std::string>* interface_parameters_;

    //--------------------------------------------------------------------------
    /// Vector with all command object initialized at construction
    std::vector<std::unique_ptr<Command>> commands_;

    //--------------------------------------------------------------------------
    /// The bool that ends the game if true. to be set in the endOfLife method
    bool game_quit_;

    //--------------------------------------------------------------------------
    // resolveCommand Method
    // Compares the first arg with the commands and checks the if the number of
    // parameters are correct.
    // 
    // @return Returns the correspondent return value.
    int resolveCommand();
};

#endif //GAMEHANDLER_H