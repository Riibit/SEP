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

  savefile << "<savefile>" << std::endl;

  savefile << "  <weather>" << std::endl;

  savefile << "    <wind>" << game.getCondition() -> getWind();
  savefile << "</wind>" << std::endl;
  savefile << "    <temperature>" << game.getCondition() -> getTemperature();
  savefile << "</temperature>" << std::endl; 
  savefile << "    <precipitation>" << game.getCondition() -> getPrecipitation();
  savefile << "</precipitation>" << std::endl;
  savefile << "    <cover>" << game.getCondition() -> getSkyCover();
  savefile << "</cover>" << std::endl;

  savefile << "  </weather>" << std::endl;
  
  savefile << "  <stats>" << std::endl;

  savefile << "    <cash>" << game.getResourceMoney();
  savefile << "</cash>" << std::endl;

  savefile << "    <balance>" << game.getResourceBalance();
  savefile << "</balance>" << std::endl;

  savefile << "    <income>" << game.getResourceIncome();
  savefile << "</income>" << std::endl;

  savefile << "    <expense>" << game.getExpenses() ;
  savefile << "</expense>" << std::endl;

  savefile << "    <lemons>" << game.getResourceLemon();
  savefile << "</lemons>" << std::endl;

  savefile << "    <sugar>" << game.getResourceSugar();
  savefile << "</sugar>" << std::endl;

  savefile << "    <lemonade>" << game.getResourceLemonade();
  savefile << "</lemonade>" << std::endl;

  savefile << "    <pricesugar>" << game.getPriceSugar();
  savefile << "</pricesugar>" << std::endl;

  savefile << "    <pricelemons>" << game.getPriceLemon();
  savefile << "</pricelemons>" << std::endl;

  savefile << "    <pricelemonade>" << game.getPriceLemonade();
  savefile << "</pricelemonade>" << std::endl;
  savefile << "  </stats>" << std::endl;

  savefile << "</savefile>" << std::endl;

  savefile.close();
  return 0;
}