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

int CmdBalance::execute (GameHandler& game, std::vector<std::string>& params){
{
  if (!params.empty())
  {
    for (unsigned int counter = 0; counter < params.size() - 1; ++counter)
    {
      cout << params[counter] << ' ';
    }
    cout << params[counter] << std::endl;
  }
}