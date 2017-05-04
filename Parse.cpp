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

int parseInteger(std::string string)
{
  int parsed_integer;
  std::locale loc;
  for (unsigned int position = 0; position < string.size(); ++position)
  {
    if (!std::isdigit(string[position], loc))
    {
      return -1;
    }
  }
  parsed_integer = std::stoi(string);
  return parsed_integer;
}
