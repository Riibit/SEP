//------------------------------------------------------------------------------
// Command.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "Command.h"



//------------------------------------------------------------------------------
Command::Command(std::string name, unsigned int parameter_count) 
  : command_name_(name) : parameter_count_(parameter_count)
{
}

//------------------------------------------------------------------------------
Command::~Command()
{
}

const bool Command::correctParameterCount(const unsigned int to_compare)
{
  if (parameter_count_ == to_compare)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//------------------------------------------------------------------------------
const std::string &Command::getName() const
{
  return command_name_;
}
