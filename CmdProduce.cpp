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
const std::string CmdProduce::ERR_MODULO_LEMONADE = 
  "[ERR] The value of Lemonade must be a multiple of 4.";
const std::string CmdProduce::NOT_ENOUGH_RESOURCES = 
  "[WARN] Not enough resources. I produce what I can.";

CmdProduce::CmdProduce() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdProduce::execute(GameHandler& game, std::vector<std::string>& params)
{
  int producer_return = 0;
  unsigned int lemonade_quantity;
  Parse parser;
  try
  {
    lemonade_quantity = parser.parseInteger(params[0]);
  }
  catch(const ExceptionDataType& exception)
  {
    cout << Command::ERR_WRONG_PARAMETER << endl;
    return 0;
  }

  Produce producer;

  producer_return = producer.produceLemonade(game, lemonade_quantity);

  if(producer_return == Produce::NOT_DIVISIBLE_BY_FOUR)
  {
    cout << ERR_MODULO_LEMONADE << endl;
  }

  if(producer_return == Produce::NOT_ENOUGH_RESOURCES)
  {
    cout << NOT_ENOUGH_RESOURCES << endl;
  }

  return 0;
}
