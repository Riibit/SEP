//------------------------------------------------------------------------------
// CmdSave.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdSave.h"
#include "Parse.h"

const std::string FILENAME = "";
const std::string CmdSave::CMD_NAME = "save";
const std::string CmdSave::ERR_CMD = "[ERR] Usage: save <filename>";

CmdSave::CmdSave() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}
  
int CmdSave::execute(GameHandler& game, std::vector<std::string>& params)
{
  return 0;
}