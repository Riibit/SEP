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
#include "GameHandler.h"
#include "EnvironmentalCondition.h"
#include "HTMLWriterEnvironment.h"
#include "HTMLWriterBalance.h"

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
  std::vector<std::string> savefile_values; // holds values in string form until end of file check
  std::vector<std::string> savefile_value_names; // holds names of values untile end of file check

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
      bool file_is_valid = true;
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

      file_is_valid = fileIsValid(save_line_arguments, unpaired_tags);
      
      if (!file_is_valid)
      {
        std::cout << "[ERR] Invalid file." << std::endl; // replace this hardcoded error string with a const string
        break;
      }

      // get value current tag
      if (save_line_arguments.size() == 3)
      {
        savefile_value_names.push_back(save_line_arguments[0]);
        savefile_values.push_back(save_line_arguments[1]);
      }
    }
    // set variable to value
    for (unsigned int value_id = 0; value_id < savefile_values.size(); ++value_id)
    {
      loadResourceValue(game, savefile_value_names[value_id], savefile_values[value_id]);
    }
    savefile.close();
  }
  // reload html files on load
  HTMLWriterEnvironment environment_writer("Environment.html");
  environment_writer.writeFile(game.getCondition());

  HTMLWriterBalance balance_writer("Balance.html");
  balance_writer.writeFile(game.getResourceLemon(), game.getResourceSugar(), 
  game.getResourceMoney(), game.getResourceBalance());

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

bool CmdLoad::fileIsValid(std::vector<std::string> save_line_arguments,
 std::vector<std::string> unpaired_tags)
{
  bool file_valid = true;
  if (save_line_arguments.size() == 1 &&
      unpairedTagAllowed(save_line_arguments[0])) // legal unpaired tags
      {
        unpaired_tags.push_back(save_line_arguments[0]);
      }
      else if (save_line_arguments.size() == 1 && 
        !unpairedTagAllowed(save_line_arguments[0])) 
      {
        file_valid = false;
      }
      else if(save_line_arguments.size() != 3 || 
        !tagValidAndClosed(save_line_arguments)) // invalid or unclosed tags
      {
        file_valid = false;
      }
    return file_valid;
}

bool CmdLoad::unpairedTagAllowed(std::string unpaired_tag)
{
  bool allowed = false;
  if (unpaired_tag != TAG_SAVEFILE || unpaired_tag != "/" + TAG_SAVEFILE)
  {
    allowed = true;
  }
  else if (unpaired_tag != TAG_WEATHER || unpaired_tag != "/" + TAG_WEATHER)
  {
    allowed = true;
  }
  else if (unpaired_tag != TAG_STATS || unpaired_tag != "/" + TAG_STATS)
  {
    allowed = true;
  }
  return allowed;
}

// sudo send help
void CmdLoad::loadResourceValue(GameHandler& game, std::string tag_name, std::string tag_value)
{
  Parse parser;

  if (!tag_name.compare(TAG_SAVEFILE) || !tag_name.compare(TAG_WEATHER)
    || !tag_name.compare(TAG_STATS))
  {
  }
  else if (!tag_name.compare(TAG_WIND))
  {
    game.getCondition() -> setWind(parser.parseStringToRank(tag_value));
  }
  else if (!tag_name.compare(TAG_TEMPERATURE))
  {
    game.getCondition() -> setTemperature(parser.parseFloat(tag_value));
  }
  else if (!tag_name.compare(TAG_PRECIPITATION))
  {
    game.getCondition() -> setPrecipitation(parser.parseStringToRank(tag_value));
  }
  else if (!tag_name.compare(TAG_COVER))
  {
    game.getCondition() -> setSkyCover(parser.parseStringToCover(tag_value));
  }
  else if (!tag_name.compare(TAG_CASH))
  {
    game.setResourceMoney(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_BALANCE))
  {
    game.setResourceBalance(std::stoi(tag_value));
  }
  else if (!tag_name.compare(TAG_INCOME))
  {
    game.setResourceIncome(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_EXPENSE))
  {
    game.setResourceExpense(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_LEMONS))
  {
    game.setResourceLemon(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_SUGAR))
  {
    game.setResourceSugar(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_LEMONADE))
  {
    game.setResourceLemonade(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_PRICESUGAR))
  {
    game.setPriceSugar(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_PRICELEMONS))
  {
    game.setPriceLemon(parser.parseInteger(tag_value));
  }
  else if (!tag_name.compare(TAG_PRICELEMONADE))
  {
    game.setPriceLemonade(parser.parseInteger(tag_value));
  }
}