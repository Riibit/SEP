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
  using Command::Command;
  int execute (GameHandler& game, std::vector<std::string>& params);
};

#endif //CMDBALANCE_H_INCLUDED