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
#include <iostream>

using std::cout;


int CmdEcho::execute (GameHandler& game, std::vector<std::string>& params)
{
  unsigned int counter;

  if (!params.empty())
  {
    for (counter = 0; counter < params.size() - 1; ++counter)
    {
      cout << params[counter] << ' ';
    }
    cout << params[counter] << std::endl;
  }
  return 0;
}