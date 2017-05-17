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

#ifndef PRODUCE_H
#define PRODUCE_H

class GameHandler;

//------------------------------------------------------------------------------
// GameHandler class
// Class for producing digital lemonade
//
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
    // @return int Returns predefined values
    //
    int produceLemonade(GameHandler& game, unsigned int quantity);

    //--------------------------------------------------------------------------
    // Return Value if input is not divisible by four
    static const int NOT_DIVISIBLE_BY_FOUR = 1;

    //--------------------------------------------------------------------------
    // Return Value if resources are not enough to produce the asked quantity
    static const int NOT_ENOUGH_RESOURCES = 2;

    //--------------------------------------------------------------------------
    // The value for producing Lemonade
    static const int PRODUCTION_MODULO = 4;
};

#endif //PRODUCE_H