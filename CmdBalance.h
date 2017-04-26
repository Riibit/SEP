//------------------------------------------------------------------------------
// CmdBalance.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDBALANCE_H_INCLUDED
#define CMDBALANCE_H_INCLUDED

#include "Command.h"

class CmdBalance : public Command
{
  public:
    CmdBalance ();
    int execute (GameHandler& game, std::vector<std::string>& params);

    static const std::string CMD_NAME;
};

#endif //CMDBALANCE_H_INCLUDED