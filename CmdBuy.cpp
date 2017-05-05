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

const std::string CmdBuy::CMD_NAME = "buy";

CmdBuy::CmdBuy() : Command::Command(CMD_NAME)
{
}

int CmdBuy::execute(GameHandler& game, std::vector<std::string>& params)
{//TODO fix this cabbage
/*
  uint lemon_value = game.getResourceLemon();
  uint sugar_value = game.getResourceSugar();
  uint money_value = game.getResourceMoney(); // not a pyramid scheme

  try
  {
    uint lemon_buy_amount = parser.parse(params[0]);
    uint sugar_buy_amount = parser.parse(params[1]);
  }
  catch(const ExceptionNotInteger& exception)
  {
    cout << ERR_BUY << endl;
    return 0;
  }

  if (( lemon_buy_amount * PRICE OF LEMON  + 
  sugar_buy_amount * PRICE OF SUGAR) <= money_value )
  {
    lemon_value += lemon_buy_amount;
    sugar_value += sugar_buy_amount;
    money_value -= lemon_buy_amount *  PRICE OF LEMON;
    money_value -= sugar_buy_amount *  PRICE OF SUGAR;
  }
  else
  {
    cout << "[WARN] Not enough money. I buy what I can." << endl; 
    // TODO get price for lemon and sugar from argv[] and use them here
    while(1)
    {
      if (lemon_value < lemon_value + lemon_buy_amount)
      {
        if ((money_value - PRICE OF LEMON) >= PRICE OF LEMON)
          {
            lemon_value ++;
            money_value -= |PRICE OF LEMON|;
          }
          else
          {
            break;
          }
        }
      if (sugar_value < sugar_value + sugar_buy_amount)
      {
        if ((money_value - PRICE OF SUGAR) >=  PRICE OF SUGAR )
        {
          sugar_value ++;
          money_value -= |PRICE OF SUGAR|;
        }
        else
        {
          break;
        }
      }
    }
  }

    game.setResourceSugar(sugar_value);
    game.setResourceLemons(lemon_value);
    game.setResourceMoney(money_value);
    
    return 0;
    */
}
