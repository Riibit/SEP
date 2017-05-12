//------------------------------------------------------------------------------
// CmdPlay.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdPlay.h"

const std::string CmdPlay::CMD_NAME = "play";
const std::string CmdPlay::ERR_CMD = "[ERR] Usage: play";

CmdPlay::CmdPlay() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdPlay::execute(GameHandler& game, std::vector<std::string>& params)
{

  return 0;
}