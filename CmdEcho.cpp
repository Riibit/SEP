//------------------------------------------------------------------------------
// CmdEcho.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdEcho.h"
#include "ReturnValues.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdEcho::CMD_NAME = "echo";

CmdEcho::CmdEcho() : Command::Command(CMD_NAME)
{
}

int CmdEcho::execute(GameHandler& game, std::vector<std::string>& params)
{
  unsigned int counter;
  if((params.empty()))
  {
    cout << endl;
  }
  else
  {
    for(counter = 0; counter < (params.size() - 1); ++counter)
    {
      cout << params[counter] << ' ';
    }
    cout << params[counter] << endl;
  }
  return RETURN_SUCCESS;
}

const bool CmdEcho::correctParameterCount(const unsigned int to_compare)
{
  return true;
}