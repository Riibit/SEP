//------------------------------------------------------------------------------
// CmdEcho.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDECHO_H_INCLUDED
#define CMDECHO_H_INCLUDED

#include "Command.h"

//------------------------------------------------------------------------------
// CmdEcho Class
// Class for the echo command.
//
class CmdEcho : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdEcho();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // Overwrites the function to always return true
    // @param to_compare The amount of parameters
    // @return bool Returns always true
    virtual const bool correctParameterCount(const unsigned int to_compare);

    //--------------------------------------------------------------------------
    // The name of the command
    static const std::string CMD_NAME;
};

#endif //CMDECHO_H_INCLUDED