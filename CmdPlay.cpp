//------------------------------------------------------------------------------
// CmdPlay.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include <iostream> // ----------------------------------------------- DEBUG
#include <cmath>
#include "CmdPlay.h"
#include "GameHandler.h"
#include "Sales.h"
#include "Produce.h"
#include "EnvironmentalEngine.h"
#include "HTMLWriterBalance.h"
#include "HTMLWriterEnvironment.h"
#include "ReturnValues.h"

const std::string CmdPlay::CMD_NAME = "play";
const std::string CmdPlay::ERR_CMD = "[ERR] Usage: play";

CmdPlay::CmdPlay() : Command::Command(CMD_NAME, PARA_COUNT, ERR_CMD)
{
}

int CmdPlay::execute(GameHandler& game, std::vector<std::string>& params)
{
  Sales sales;

#ifndef AUFBAU

  Produce produce;
  int to_produce = 0;
  float influence_factor = sales.calculateSaleInfluence(game) / 100.0f;
  to_produce = std::round(sales.calculateCustomers(game) * influence_factor);

  if(to_produce % Produce::PRODUCTION_MODULO)
  {
    to_produce += Produce::PRODUCTION_MODULO - 
      (to_produce % Produce::PRODUCTION_MODULO);
  }
  
  produce.produceLemonade(game, to_produce);

#endif // AUFBAU


  sales.calculateSales(game);

  EnvironmentalEngine engine;


#ifdef AUFBAU

  engine.realisticCondition(game.getCondition());

#else

  engine.randomizeCondition(game.getCondition());

#endif // AUFBAU



  HTMLWriterEnvironment environment_writer;
  environment_writer.writeFile(game.getCondition());

  HTMLWriterBalance balance_writer;
  balance_writer.writeFile(game.getResourceLemon(), game.getResourceSugar(), 
    game.getResourceMoney(), game.getResourceBalance());

  game.resetStandardRecipe();
  return RETURN_SUCCESS;
}