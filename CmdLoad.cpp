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

CmdLoad::CmdLoad() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}
  
int CmdLoad::execute(GameHandler& game, std::vector<std::string>& params)
{
}