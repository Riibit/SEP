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
#include <iostream>

#include "CmdQuit.h"

const std::string CmdQuit::QUIT_MSG = "Going out of business!";
const std::string CmdQuit::CMD_NAME = "quit";

CmdQuit::CmdQuit () : Command::Command(CMD_NAME)
{
}

int CmdQuit::execute (GameHandler& game, std::vector<std::string>& params)
{
  std::cout << QUIT_MSG << std::endl;

  return 0;
}
