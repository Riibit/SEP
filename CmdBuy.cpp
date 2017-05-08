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

  // enough money for purchase? 
  if (( lemon_buy_amount * lemon_price  + 
  sugar_buy_amount * sugar_price) <= money_value )
  {
    lemon_value += lemon_buy_amount;
    sugar_value += sugar_buy_amount;
    money_value -= lemon_buy_amount * lemon_price;
    money_value -= sugar_buy_amount * sugar_price;
  }
  // no. get 1 by 1 as much as possible of both
  else
  {
    cout << "[WARN] Not enough money. I buy what I can." << endl; 
    while(1)
    {
      if (lemon_value < lemon_value + lemon_buy_amount)
      {
        if ((money_value - lemon_price) >= lemon_price)
          {
            lemon_value ++;
            money_value -= lemon_price;
          }
          else
          {
            break;
          }
        }
      if (sugar_value < sugar_value + sugar_buy_amount)
      {
        if ((money_value - sugar_price) >=  sugar_price)
        {
          sugar_value ++;
          money_value -= sugar_price;
        }
        else
        {
          break;
        }
      }
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
