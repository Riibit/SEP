//------------------------------------------------------------------------------
// CmdProduce.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdProduce.h"
#include "GameHandler.h"
#include "Parse.h"
#include "ExceptionDataType.h"
#include "Produce.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdProduce::CMD_NAME = "produce";
const std::string CmdProduce::ERR_CMD = 
  "[ERR] Usage: produce <lemonade>";

CmdProduce::CmdProduce() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdProduce::execute(GameHandler& game, std::vector<std::string>& params)
{
  unsigned int lemonade_quantity;
  Parse parser;
  try
  {
    lemonade_quantity = parser.parseInteger(params[0]);
  }
  catch(const ExceptionDataType& exception)
  {
    cout << ERR_CMD << endl;
    return 0;
  }

  Produce producer;
  if(producer.produceLemonade(game, lemonade_quantity) 
    == Produce::NOT_DIVISIBLE_BY_FOUR)
  {
    cout << Command::ERR_WRONG_PARAMETER << endl;
  }

  return 0;
}
