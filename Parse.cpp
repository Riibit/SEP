//------------------------------------------------------------------------------
// Parse.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
#include "Parse.h"
#include "ExceptionDataType.h"
#include <locale>

Parse::Parse()
{
}

uint Parse::parseInteger(std::string string)
{
  uint parsed_integer;
  std::locale loc;
  for (unsigned int position = 0; position < string.size(); ++position)
  {
    if (!std::isdigit(string[position], loc))
    {
      throw ExceptionDataType();
      return 0;
    }
  }
  parsed_integer = std::stoi(string);
  return parsed_integer;
}

float Parse::parseFloat(std::string input)
{
  float to_return = 0;
  try
  {
    to_return = stof(input);
  }
  catch(const std::invalid_argument& exception)
  {
    throw ExceptionDataType();
    return to_return;
  }
  return to_return;
}