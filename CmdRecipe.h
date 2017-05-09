//------------------------------------------------------------------------------
// CmdRecipe.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDRECIPE_H_INCLUDED
#define CMDRECIPE_H_INCLUDED

#include "Command.h"

class GameHandler;

//----------------------------------------------------------------------------
// CmdRecipe Class
// Class for the recipe command.
//
class CmdRecipe : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdRecipe();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Function Param = 0 or Param = 3
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // Executes the command if there are no parameters.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    int executeParameterOne(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // Executes the command if there are three parameters.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    int executeParameterTwo(GameHandler& game, std::vector<std::string>& params);
    
    //--------------------------------------------------------------------------
    // Checks if the string is an Integer.
    // @param string The string to check.
    // @return bool False if not Integer, otherwise true.
    bool isItInteger(std::string string);

    //--------------------------------------------------------------------------
    // Overwrites the function to return true if the PARA_COUNT == 3 || 0
    // @param to_compare The amount of parameters
    // @return bool Returns true if input is correct
    virtual const bool correctParameterCount(const unsigned int to_compare);

    //--------------------------------------------------------------------------
    // The name of the command
    static const std::string CMD_NAME;

    //--------------------------------------------------------------------------
    // The error message if the parameter count is not right
    static const std::string ERR_RECIPE;

    //--------------------------------------------------------------------------
    // The message if the parameters dont add up to 100
    static const std::string ERROR_MSG_PERCENT;

    //--------------------------------------------------------------------------
    // The message if the lemon value is not a multiple of 3
    static const std::string ERROR_MODULO_LEMON;

    //--------------------------------------------------------------------------
    // The message if the sugar value is not a multiple of 2
    static const std::string ERROR_MODULO_SUGAR;

    //--------------------------------------------------------------------------
    // Number of Parameters for this function
    static const unsigned int PARA_COUNT_ONE = 0;
    static const unsigned int PARA_COUNT_TWO = 3;
};

#endif //CMDRECIPE_H_INCLUDED