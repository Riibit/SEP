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

#include <string>
#include <vector>
#include <memory>

class Command;

class GameHandler 
{
  public:
    GameHandler();
    ~GameHandler();
    int runInterface();
    void setInterfaceParameters(std::vector<std::string>* 
      interface_parameters);
    void setInterfaceCommand(std::string* command_name);
    void endOfLife();
  private:
    std::string* command_name_;
    std::vector<std::string>* interface_parameters_;
    std::vector<std::unique_ptr<Command>> commands_;
    bool game_quit_;
    int resolveCommand();
};

#endif //GAMEHANDLER_H