//------------------------------------------------------------------------------
// CmdLoad.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "CmdLoad.h"
#include "Parse.h"

const std::string CmdLoad::CMD_NAME = "load";
const std::string CmdLoad::ERR_CMD = "[ERR] Usage: load <filename>";

const std::string CmdLoad::TAG_SAVEFILE = "savefile";
const std::string CmdLoad::TAG_STATS = "stats";
const std::string CmdLoad::TAG_WEATHER = "weather";
const std::string CmdLoad::TAG_WIND = "wind";
const std::string CmdLoad::TAG_TEMPERATURE = "temperature";
const std::string CmdLoad::TAG_PRECIPITATION = "precipitation";
const std::string CmdLoad::TAG_COVER = "cover";
const std::string CmdLoad::TAG_CASH = "cash";
const std::string CmdLoad::TAG_BALANCE = "balance";
const std::string CmdLoad::TAG_INCOME = "income";
const std::string CmdLoad::TAG_EXPENSE = "expense";
const std::string CmdLoad::TAG_LEMONS = "lemons";
const std::string CmdLoad::TAG_SUGAR = "sugar";
const std::string CmdLoad::TAG_PRICESUGAR = "pricesugar";
const std::string CmdLoad::TAG_PRICELEMONS = "pricelemons";
const std::string CmdLoad::TAG_PRICELEMONADE = "pricelemonade";
const std::string CmdLoad::TAG_LEMONADE = "lemonade";

CmdLoad::CmdLoad() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
  tag_collection_.push_back(TAG_SAVEFILE);
  tag_collection_.push_back(TAG_STATS);
  tag_collection_.push_back(TAG_WEATHER);
  tag_collection_.push_back(TAG_WIND);
  tag_collection_.push_back(TAG_TEMPERATURE);
  tag_collection_.push_back(TAG_PRECIPITATION);
  tag_collection_.push_back(TAG_COVER);
  tag_collection_.push_back(TAG_CASH);
  tag_collection_.push_back(TAG_BALANCE);
  tag_collection_.push_back(TAG_INCOME);
  tag_collection_.push_back(TAG_EXPENSE);
  tag_collection_.push_back(TAG_LEMONS);
  tag_collection_.push_back(TAG_SUGAR);
  tag_collection_.push_back(TAG_PRICESUGAR);
  tag_collection_.push_back(TAG_PRICELEMONS);
  tag_collection_.push_back(TAG_PRICELEMONADE);
  tag_collection_.push_back(TAG_LEMONADE);
}
  
int CmdLoad::execute(GameHandler& game, std::vector<std::string>& params)
{
  std::string load_filename = params[0];

  std::vector<std::string> unpaired_tags; // tags closed in another line

  std::string savefile_line;
  std::ifstream savefile;
  savefile.open(load_filename);

  if (!savefile)
  {
    std::cout << "[ERR] Could not open file." << std::endl; // replace this hardcoded error string with a const string
  }
  else
  {
    while(getline(savefile, savefile_line)) // get lines of savefile 
    {
      bool file_valid = false;
      std::vector<std::string> save_line_arguments;

      std::stringstream stream(savefile_line);
      std::string argument;
      char line_char;

      // get tag content
      while(!stream.eof())
      {
        argument.clear();
          
        while(!isBracket((line_char = stream.get())))
        {
          argument.push_back(line_char);
        }
        if(!argument.empty())
        {
          save_line_arguments.push_back(argument);
        }
      }

      if (save_line_arguments.size() == 1) // tags 
      {
        unpaired_tags.push_back(save_line_arguments[0]);
      }

      // check tag validity
      if (tagValidAndClosed(save_line_arguments))
      {
        file_valid = true;
      }

      if (!file_valid)
      {
        std::cout << "[ERR] Invalid file." << std::endl; // replace this hardcoded error string with a const string
        break;
      }

      // get value current tag

      // set variable to value 
    }
    savefile.close();
  }
  return 0;
}

bool CmdLoad::checkTagExists(std::string tag)
{
  bool exists = false;
  for(unsigned int tag_id = 0; tag_id < tag_collection_.size() ; tag_id++)
  {
    if (!tag.compare(tag_collection_[tag_id]))
    {
      exists = true;
      break; // found, exiting loop
    }
  }
  return exists;
}

bool CmdLoad::checkTagClosed(std::string tag, std::string closing_tag)
{
  bool closed = false;
  std::string tag_corrected = "/";
  tag_corrected += tag;
  if (!tag_corrected.compare(closing_tag))
  {
    closed = true;
  }

  return closed;
}

bool CmdLoad::isBracket(char current_char)
{
  if (current_char == '<' || current_char == '>' || current_char == EOF || current_char == ' ')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool CmdLoad::tagValidAndClosed(std::vector<std::string> save_line_arguments)
{
  bool valid = true;
        if (!checkTagExists(save_line_arguments[0])) // if tag exists
        {
          valid = false;
        }
        else if(save_line_arguments.size() == 3)
        {
          if (!checkTagClosed(save_line_arguments[0], save_line_arguments[2]))
          {
            valid = false;
          }
        }
  return valid;
}

/*bool CmdLoad::unpairedTagAllowed(std::string unpaired_tag)
{
  if (unpaired_tag == )
  {
    
  }
}*/