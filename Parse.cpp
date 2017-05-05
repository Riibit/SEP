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
#include "ExceptionNotInteger.h"
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
      throw ExceptionNotInteger();
      return 0;
    }
  }
  parsed_integer = std::stoi(string);
  return parsed_integer;
}
