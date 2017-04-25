//------------------------------------------------------------------------------
// CmdQuit.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdQuit.h"

//------------------------------------------------------------------------------
Command::~Command()
{
}

//------------------------------------------------------------------------------
const std::string &Command::getName() const
{
  return command_name_;
}
