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
#include "ReturnValues.h"
#include "HTMLWriterBalance.h"
#include <iostream>

using std::cout;
using std::endl;

const std::string CmdBuy::CMD_NAME = "buy";
const std::string CmdBuy::ERR_CMD = 
  "[ERR] Usage: buy <lemon> <sugar>";
const std::string CmdBuy::NOT_ENOUGH_MONEY = 
  "[WARN] Not enough money. I buy what I can.";


CmdBuy::CmdBuy() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdBuy::execute(GameHandler& game, std::vector<std::string>& params)
{
  // loading game data
  unsigned int lemon_value = game.getResourceLemon();
  unsigned int sugar_value = game.getResourceSugar();
  unsigned int money_value = game.getResourceMoney();
  

  unsigned int money_spent;
  unsigned int sugar_buy_amount;
  unsigned int lemon_buy_amount;

  Parse parser;
  try
  {
    lemon_buy_amount = parser.parseInteger(params[0]);
    sugar_buy_amount = parser.parseInteger(params[1]);
  }
  catch(const ExceptionDataType& exception)
  {
    cout << Command::ERR_WRONG_PARAMETER << endl;
    return RETURN_SUCCESS;
  }

  bool error_output = true;
  while(1)
  {
    if(((lemon_buy_amount * game.getPriceLemon()) + 
    (sugar_buy_amount * game.getPriceSugar())) <= money_value)
    {
      lemon_value += lemon_buy_amount;
      sugar_value += sugar_buy_amount;
      money_spent = lemon_buy_amount * game.getPriceLemon(); 
      money_spent += sugar_buy_amount * game.getPriceSugar(); 
      money_value -= money_spent;
      break;
    }
    if(error_output)
    {
      cout << NOT_ENOUGH_MONEY << endl;
      error_output = false;
    }
    if(lemon_buy_amount > 0)
    {
      lemon_buy_amount--;
    }
    if(sugar_buy_amount > 0)
    {
      sugar_buy_amount--;
    }
  }
  // output
  cout << "Bought:" << endl;
  cout << "L: " << lemon_value - game.getResourceLemon() << endl;
  cout << "S: " << sugar_value - game.getResourceSugar() << endl;

  // update game data
  game.addExpenses(money_spent);
  game.setResourceSugar(sugar_value);
  game.setResourceLemon(lemon_value);
  game.setResourceMoney(money_value);

  HTMLWriterBalance balance_writer;
  balance_writer.writeFile(game.getResourceLemon(), game.getResourceSugar(), 
    game.getResourceMoney(), game.getResourceBalance());

  return RETURN_SUCCESS;
}
