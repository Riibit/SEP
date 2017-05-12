//------------------------------------------------------------------------------
// CmdSave.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
#include <fstream>

#include "CmdSave.h"
#include "GameHandler.h"
#include "EnvironmentalCondition.h"

const std::string CmdSave::CMD_NAME = "save";
const std::string CmdSave::ERR_CMD = "[ERR] Usage: save <filename>";

using std::ios;
CmdSave::CmdSave() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}
  
int CmdSave::execute(GameHandler& game, std::vector<std::string>& params)
{
  std::string save_filename;
  save_filename = params[0];

  std::fstream savefile;
  savefile.open(save_filename.c_str(), ios::in | ios::out | ios::trunc);

   savefile << "<savefile>" << std::endl

   << "  <weather>" << std::endl

   << "    <wind>" << game.getCondition() -> getWind()
   << "</wind>" << std::endl
   << "    <temperature>" << game.getCondition() -> getTemperature()
   << "</temperature>" << std::endl
   << "    <precipitation>" << game.getCondition() -> getPrecipitation()
   << "</precipitation>" << std::endl
   << "    <cover>" << game.getCondition() -> getSkyCover()
   << "</cover>" << std::endl

   << "  </weather>" << std::endl
  
   << "  <stats>" << std::endl

   << "    <cash>" << game.getResourceMoney()
   << "</cash>" << std::endl

   << "    <balance>" << game.getResourceBalance()
   << "</balance>" << std::endl

   << "    <income>" << game.getResourceIncome()
   << "</income>" << std::endl

   << "    <expense>" << game.getExpenses()
   << "</expense>" << std::endl

   << "    <lemons>" << game.getResourceLemon()
   << "</lemons>" << std::endl

   << "    <sugar>" << game.getResourceSugar()
   << "</sugar>" << std::endl

   << "    <lemonade>" << game.getResourceLemonade()
   << "</lemonade>" << std::endl

   << "    <pricesugar>" << game.getPriceSugar()
   << "</pricesugar>" << std::endl

   << "    <pricelemons>" << game.getPriceLemon()
   << "</pricelemons>" << std::endl

   << "    <pricelemonade>" << game.getPriceLemonade()
   << "</pricelemonade>" << std::endl
   << "  </stats>" << std::endl

   << "</savefile>" << std::endl;

  savefile.close();
  return 0;
}