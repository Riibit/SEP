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
#include <limits>

using std::string;
using std::cin;
using std::cout;

const string Interface::PROMPT_STRING = "sep> ";

Interface::Interface()
{
  //game_ = game;
}

const int Interface::runInterface()
{
  string input;
  std::vector<string> arguments;
  char character;

  while (1)
  {
    cout << PROMPT_STRING;
    while (1)
    {
      character = cin.get();
      if (character != ' ')
      {
        break;
      }
    }
    if (character == '\n')
    {
      continue;
    }
    while (character != ' ' && character != '\n')
    {
      input.push_back(std::tolower(character));
      character = cin.get();
    }

    if (!input.compare("quit"))
    {
      arguments = makeVector(&character);
      cout << "Going out of business" << std::endl;
      return 0;
    }
    else if (!input.compare("echo"))
    {
      arguments = makeVector(&character);
      cout << "<<" << arguments.size() << ">>" << std::endl;
      for (unsigned int index = 0; index < arguments.size(); index++)
      {
        cout << arguments[index] << std::endl;
      }
    }
    
    if (character != '\n')
    {
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    input.clear();
  }
}


const std::vector<string> Interface::makeVector(char* cin_value)
{
  //new std::vector<string> return_vector;
  string temporarily_used_string_value;
  std::vector<string> return_vector;
  while(!(*cin_value == '\n'))
  {
    cout << "test" << std::endl;
    cin >> temporarily_used_string_value;
    return_vector.push_back(temporarily_used_string_value);
    *cin_value = cin.get();
  }
  return return_vector;
}


/*
const std::vector<string> Interface::makeVector(char cin_value)
{
  string temporarily_used_string_value;
  std::vector<string> return_vector;
  if (cin_value == '\n')
  {
    return return_vector;
  }
  while (!(cin_value == '\n'))
  {
    cin_value = cin.get();
    cin >> temporarily_used_string_value;
    return_vector.push_back(temporarily_used_string_value);
    
  }
  return return_vector;
}
*/