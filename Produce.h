//------------------------------------------------------------------------------
// Produce.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

class GameHandler;

class Produce
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Produce(const Produce& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Produce& operator=(const Produce& original);

  public:
    //--------------------------------------------------------------------------
    // Constructor
    Produce();

    //--------------------------------------------------------------------------
    // Destructor
    ~Produce();

    //--------------------------------------------------------------------------
    // Produces lemonade
    //
    // @param game The game where action should be performed on
    // @param quantity The quantity of lemonade that is to be produced
    //
    int produceLemonade(GameHandler& game, unsigned int quantity);

    int NOT_DIVISIBLE_BY_FOUR = 1;
    int NOT_ENOUGH_RESOURCES = 2;
};