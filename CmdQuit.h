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

class CmdQuit : public Command
{
  public:
    CmdQuit();
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    static const std::string CMD_NAME;
    static const std::string QUIT_MSG;
};

#endif //CMDQUIT_H_INCLUDED