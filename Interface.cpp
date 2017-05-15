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

using std::string;
using std::cin;
using std::cout;

const string Interface::PROMPT_STRING = "sep> ";

Interface::Interface(GameHandler* game)
{
  game_ = game;
}

Interface::~Interface()
{
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
    game_ -> setInterfaceCommand(heap_command);
    makeVector(&character);
    break;

  }
  return 0;
}

const string Interface::getArgument(char* cin_value, const bool to_lower)
{
  string return_string;
  while (1)
  {
    *cin_value = cin.get();
    if (!(std::isspace(*cin_value)) || *cin_value == '\n')
    {
      break;
    }
  }
  while (!(std::isspace(*cin_value)))
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
  std::vector<string> *heap_parameters;
  heap_parameters = new std::vector<string>;
  while(!(*cin_value == '\n'))
  {
    temporarily_used_string_value = getArgument(cin_value, false);
    if (temporarily_used_string_value.empty())
    {
      break;
    }
    heap_parameters -> push_back(temporarily_used_string_value);
  }
  game_ -> setInterfaceParameters(heap_parameters);
}
