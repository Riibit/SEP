//------------------------------------------------------------------------------
// CmdBuy.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "CmdBuy.h"
#include "GameHandler.h"
#include "Parse.h"
#include "ExceptionDataType.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdBuy::CMD_NAME = "buy";
const std::string CmdBuy::ERR_CMD = 
  "[ERR] Usage: buy <lemon> <sugar>";

CmdBuy::CmdBuy() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdBuy::execute(GameHandler& game, std::vector<std::string>& params)
{
  // game data loaded
  unsigned int lemon_value = game.getResourceLemon();
  unsigned int sugar_value = game.getResourceSugar();
  unsigned int money_value = game.getResourceMoney(); // not a pyramid scheme
  unsigned int lemon_price = game.getPriceLemon();
  unsigned int sugar_price = game.getPriceSugar();
  
  // local variables
  unsigned int money_spent = 0;
  unsigned int sugar_buy_amount = 0;
  unsigned int lemon_buy_amount = 0;

  Parse parser;
  try
  {
    lemon_buy_amount = parser.parseInteger(params[0]);
    sugar_buy_amount = parser.parseInteger(params[1]);
  }
  catch(const ExceptionDataType& exception)
  {
    cout << ERR_CMD << endl;
    return 0;
  }

  bool error_output = true;
  while(1)
  {
    if (( lemon_buy_amount * lemon_price  + 
    sugar_buy_amount * sugar_price) <= money_value )
    {
      lemon_value += lemon_buy_amount;
      sugar_value += sugar_buy_amount;
      money_spent += lemon_buy_amount * lemon_price; 
      money_spent += sugar_buy_amount * sugar_price; 
      money_value -= money_spent;
      break;
    }
    if(error_output)
    {
      cout << "[WARN] Not enough money. I buy what I can." << endl;
      error_output = false;
    }
    if (lemon_buy_amount > 0)
    {
      lemon_buy_amount--;
    }
    if (sugar_buy_amount > 0)
    {
      sugar_buy_amount--;
    }
  }
  // output
  cout << "Bought:" << endl;
  cout << "L: " << lemon_value - game.getResourceLemon() << endl;
  cout << "S: " << sugar_value - game.getResourceSugar() << endl;

  // update game data
  game.setResourceSugar(sugar_value);
  game.setResourceLemon(lemon_value);
  game.setResourceMoney(money_value);

  return 0;
}
