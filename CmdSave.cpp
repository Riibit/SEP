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

#include "CmdSave.h"
#include "GameHandler.h"
#include <fstream>

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

  savefile << "<weather>" << std::endl;

  savefile << "<wind>" << " "/*game.getEnvCond.wind*/ << "</wind>" << std::endl;
  savefile << "<temperature>" <<" " /*game.getEnvCond.temp*/  << "</temperature>" << std::endl;
  savefile << "<precipitation>" << " "/*game.getEnvCond.prec*/ << "</precipitation>" << std::endl;
  savefile << "<cover>" << " "/*game.getEnvCond.cover*/ << "</cover>" << std::endl;

  savefile << "</weather>" << std::endl;
  
  savefile << "<stats>" << std::endl;

  savefile << "<cash>" << game.getResourceMoney() << "</cash>" << std::endl;
  savefile << "<balance>" << game.getResourceBalance() << "</balance>" << std::endl;
  savefile << "<income>" << " "/*game.getIncome()*/ << "</income>" << std::endl;
  savefile << "<expense>" << game.getExpenses() << "</expense>" << std::endl;
  savefile << "<lemons>" << game.getResourceLemon() << "</lemons>" << std::endl;
  savefile << "<sugar>" << game.getResourceSugar() << "</sugar>" << std::endl;
  savefile << "<pricelemons>" << game.getResourceLemonade() << "</pricelemons>" << std::endl;
  savefile << "<pricesugar>" << game.getPriceSugar() << "</pricesugar>" << std::endl;
  savefile << "<pricelemons>" << game.getPriceLemon() << "</pricelemons>" << std::endl;
  savefile << "<pricelemonade>" << game.getPriceLemonade() << "</pricelemonade>" << std::endl;
  savefile << "</stats>" << std::endl;

  savefile << "</savefile>" << std::endl;
  /*if(!savefile)
  {
    savefile.open(FILENAME.c_str(), ios::in | ios::out | ios::trunc);
  }*/

  savefile.close();
  return 0;
}