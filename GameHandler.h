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

class Command;

class GameHandler 
{
  public:
    GameHandler();
    void runInterface();
    void setInterfaceParameters(std::vector<std::string>* interface_parameters);
    void setInterfaceCommand(std::string* command_name);
    void initCommands();
  private:
    std::string* command_name_;
    std::vector<std::string>* interface_parameters_;
    std::vector<Command*>* commands_;
    void resolveCommand();
};

#endif //GAMEHANDLER_H