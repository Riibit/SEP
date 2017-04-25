//------------------------------------------------------------------------------
// GameHandler.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

class GameHandler 
{
  public:
    GameHandler();

  private:
    void resolveCommand(std::string command_name);
    static const std::string ECHO;
    static const std::string BALANCE;
    static const std::string RECIPE;
};

#endif //GAMEHANDLER_H