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

class GameHandler; 

class Interface 
{
  public:
    Interface(GameHandler& game);
    const int runInterface();

  private:
    GameHandler game_;


}