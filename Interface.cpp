//------------------------------------------------------------------------------
// Interface.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "Interface.h"
#include <iostream>
#include <cctype>
using std::string;
using std::cin;
using std::cout;

Interface::Interface()
{
  //game_ = game;
}

const int Interface::runInterface()
{
  string input;
  std::vector<string> arguments;
  /*
  bool control_value;
  unsigned int index;
  */
  while (1)
  {
    /*
    index = 0;
    control_value == FALSE;
    while(1)
    {
      character = cin.get();
      if (character == '\n')
      {
        break;
      }
      control_value = TRUE;
      if (character != ' ')
      {
        input[index] = character;
      }
    }
    */
    cout << "sep> ";
    if ((cin.get() == '\n'))
    {
      continue;
    }
    cin >> input;
    for (unsigned int index; index < input.size(); index++)
    {
      input[index] = std::tolower(input[index]);
    }
    if (!input.compare("quit"))
    {
      cout << "Going out of business" << std::endl;
      return 0;
    }
    else if (!input.compare("echo"))
    {
      arguments = makeVector();
    }
  }
}

const std::vector<string> Interface::makeVector()
{
  //new std::vector<string> return_vector;
  string temporarily_used_string_value;
  std::vector<string> return_vector;
  while(!(cin.get() == '\n'))
  {
    return_vector.push_back(temporarily_used_string_value);
  }
  return return_vector;
}