//------------------------------------------------------------------------------
// CmdBuy.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdBuy.h"

const std::string CmdBuy::CMD_NAME = "buy";

CmdBuy::CmdBuy() : Command::Command(CMD_NAME)
{
}

int CmdBuy::execute(GameHandler& game, std::vector<std::string>& params)
{
  int sugar_value = game

  Somewhere.setSugar(sugar_value);
  Somewhere.setLemons(lemon_value);
  
  return 0;
}
