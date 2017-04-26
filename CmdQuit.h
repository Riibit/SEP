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

class CmdQuit : public Command
{
  public:
    using Command::Command;

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action

    int execute(GameHandler& game, std::vector<std::string>& params) = 0;
};

#endif //CMDQUIT_H_INCLUDED