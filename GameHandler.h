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
    void setInterfaceParameters(std::vector<std::string>* interface_parameters);
    void setInterfaceCommand(string);
  private:
    static const std::string command_name;
    std::vector<std::string>* interface_parameters_;
    void resolveCommand(std::string command_name);
};

#endif //GAMEHANDLER_H