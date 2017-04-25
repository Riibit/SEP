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
#include "GameHandler.h"
#include <iostream>
#include <cctype>
#include <limits>

using std::string;
using std::cin;
using std::cout;

const string Interface::PROMPT_STRING = "sep> ";

Interface::Interface(GameHandler& game)
{
  game_ = game;
}

const int Interface::runPrompt()
{
  string input;
  std::vector<string> arguments;
  char character;

  while (1)
  {
    cout << PROMPT_STRING;
    
    input = getArgument(&character, true);

    if (input.empty())
    {
      continue;
    }
    string* heap_command;
    heap_command = new string(input);
    game_.setInterfaceCommand(heap_command);
    makeVector(&character);




/*
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
    */
    input.clear();
  }
}

const string Interface::getArgument(char* cin_value, bool to_lower)
{
  string return_string;
  while (1)
  {
    *cin_value = cin.get();
    if (*cin_value != ' ')
    {
      break;
    }
  }
  while (*cin_value != ' ' && *cin_value != '\n')
  {
    if (to_lower)
    {
      return_string.push_back(std::tolower(*cin_value));
    }
    else
    {
      return_string.push_back(*cin_value);
    }
    *cin_value = cin.get();
  }
  return return_string;
}

void Interface::makeVector(char* cin_value)
{
  string temporarily_used_string_value;
  new std::vector<string> *heap_parameters;
  while(!(*cin_value == '\n'))
  {
    temporarily_used_string_value = getArgument(cin_value, false);
    if (temporarily_used_string_value.empty())
    {
      break;
    }
    *heap_parameters.push_back(temporarily_used_string_value);
  }
  game_.setInterfaceParameters(heap_parameters);
}
