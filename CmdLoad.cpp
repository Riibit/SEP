//------------------------------------------------------------------------------
// CmdLoad.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdLoad.h"
#include "Parse.h"
#include <fstream>

const std::string CmdLoad::CMD_NAME = "load";
const std::string CmdLoad::ERR_CMD = "[ERR] Usage: load <filename>";

CmdLoad::CmdLoad() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}
  
int CmdLoad::execute(GameHandler& game, std::vector<std::string>& params)
{
  std::string load_filename = params[0];

  std::ifstream savefile;
  savefile.open(load_filename.c_str());

  savefile.close();
  return 0;
}