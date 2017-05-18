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
#include <iostream>
#include "Command.h"

const std::string Command::ERR_WRONG_PARAMETER = "[ERR] Wrong parameter.";

Command::Command(std::string name)
{
  command_name_ = name;
}

Command::Command(std::string name, unsigned int parameter_count, 
  std::string parameter_message)
{
  command_name_ = name;
  parameter_count_ = parameter_count;
  parameter_message_ = parameter_message;
}

Command::~Command()
{
}

const bool Command::correctParameterCount(unsigned int to_compare)
{
  if(parameter_count_ == to_compare)
  {
    return true;
  }
  return false;
}

const std::string &Command::getErrorMessage() const
{
  return parameter_message_;
}

const std::string &Command::getName() const
{
  return command_name_;
}
