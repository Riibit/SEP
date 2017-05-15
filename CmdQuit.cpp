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
#include "GameHandler.h"
#include "ReturnValues.h"

const std::string CmdQuit::CMD_NAME = "quit";
const std::string CmdQuit::ERR_QUIT = "[ERR] Usage: quit";
const std::string CmdQuit::QUIT_MSG = "Going out of business!";

CmdQuit::CmdQuit() : Command::Command(CMD_NAME, PARA_COUNT, ERR_QUIT)
{
}

int CmdQuit::execute(GameHandler& game, std::vector<std::string>& params)
{
  std::cout << QUIT_MSG << std::endl;
  game.endOfLife();
  return RETURN_SUCCESS;
}
