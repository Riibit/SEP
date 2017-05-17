//------------------------------------------------------------------------------
// Sales.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef SALES_H
#define SALES_H

//------------------------------------------------------------------------------
// Sales Class
// Class that calculates the total revenue
//
class Sales
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Sales();

    //--------------------------------------------------------------------------
    // Destructor
    ~Sales();

    //--------------------------------------------------------------------------
    // Calculates the amount of customers based on the weather
    //
    // @param game The game where action should be performed on
    //
    // @return uint Returns the amount of customers
    //
    unsigned int calculateCustomers(GameHandler& game);

    //--------------------------------------------------------------------------
    // Calculates the percentage which changes the total amount of sales
    //
    // @param game The game where action should be performed on
    //
    // @return int Returns the percentage
    //
    int calculateSaleInfluence(GameHandler& game);

    //--------------------------------------------------------------------------
    // Calculates the total amount of revenue and balance made
    //
    // @param game The game where action should be performed on
    //
    void calculateSales(GameHandler& game);
    

  private:
    //--------------------------------------------------------------------------
    // The standart amount of customers
    static const int STANDARD_CUSTOMER_COUNT = 500;

    //--------------------------------------------------------------------------
    // The values which are used to calculate the Sale influence
    static const int TWENTY = 20;
    static const int FIFTY = 50;
    static const int HUNDRED = 100;
    static const int TEN = 10;

    //--------------------------------------------------------------------------
    // The biggest loss in sales possible
    static const int MINIMUM_PERCENT = -100;

    //--------------------------------------------------------------------------
    // The percentages of the correspondent weather influences
    static const float VALUE_STORMY;
    static const float VALUE_RAINY;
    static const float VALUE_CLOUDY;
    static const float VALUE_HOT;
};

#endif //SALES_H