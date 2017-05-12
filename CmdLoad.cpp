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

#include "CmdLoad.h"
#include "Parse.h"

const std::string CmdLoad::CMD_NAME = "load";
const std::string CmdLoad::ERR_CMD = "[ERR] Usage: load <filename>";

const std::string CmdLoad::TAG_SAVEFILE = "<savefile>";
const std::string CmdLoad::TAG_STATS = "  <stats>";
const std::string CmdLoad::TAG_WEATHER = "  <weather>";
const std::string CmdLoad::TAG_WIND = "    <wind>";
const std::string CmdLoad::TAG_TEMPERATURE = "    <temperature>";
const std::string CmdLoad::TAG_PRECIPITATION = "    <precipitation>";
const std::string CmdLoad::TAG_COVER = "    <cover>";
const std::string CmdLoad::TAG_CASH = "    <cash>";
const std::string CmdLoad::TAG_BALANCE = "    <balance>";
const std::string CmdLoad::TAG_INCOME = "    <income>";
const std::string CmdLoad::TAG_EXPENSE = "    <expense>";
const std::string CmdLoad::TAG_LEMONS = "    <lemons>";
const std::string CmdLoad::TAG_SUGAR = "    <sugar>";
const std::string CmdLoad::TAG_PRICESUGAR = "    <pricesugar>";
const std::string CmdLoad::TAG_PRICELEMONS = "    <pricelemons>";

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
}
  
int CmdLoad::execute(GameHandler& game, std::vector<std::string>& params)
{
  std::string load_filename = params[0];

  std::string savefile_line;
  std::ifstream savefile;
  savefile.open(load_filename);

  if (!savefile)
  {
    std::cout << "[ERR] Could not open file." << std::endl; // replace this hardcoded error string with a const string
  }
  else
  {
    /*std::getline(savefile, savefile_line);
    if (savefile_line.compare("<savefile>"))
    {
      std::cout << "[ERR] Invalid file." << std::endl; // replace this hardcoded error string with a const string
    }
    std::getline(savefile, savefile_line);
    if (savefile_line.compare("  <weather>") || savefile_line.compare("  <stats>"))
    {
      std::cout << "[ERR] Invalid file." << std::endl; // replace this hardcoded error string with a const string
    }

    std::cout << savefile_line << std::endl; // debugging line REMOVE
    */
    savefile.close();
  }
  return 0;
}