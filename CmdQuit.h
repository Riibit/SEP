//------------------------------------------------------------------------------
// CmdQuit.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDQUIT_H_INCLUDED
#define CMDQUIT_H_INCLUDED

#include "Command.h"

class GameHandler;

//------------------------------------------------------------------------------
// CmdQuit Class
// Class for the quit command.
//
class CmdQuit : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdQuit();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // The name of the command
    static const std::string CMD_NAME;

    //--------------------------------------------------------------------------
    // The error message if the parameter count is not right
    static const std::string ERR_QUIT;

    //--------------------------------------------------------------------------
    // The leaving message
    static const std::string QUIT_MSG;

    //--------------------------------------------------------------------------
    // Number of Parameters for this function
    static const unsigned int PARA_COUNT = 0;
};

#endif //CMDQUIT_H_INCLUDED