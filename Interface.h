//------------------------------------------------------------------------------
// Command.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
#include <string>
#include <vector>

class GameHandler; 

class Interface 
{
  public:
    Interface();
    const int runInterface();
    const std::vector<std::string> makeVector();

  private:
    //GameHandler game_;


};