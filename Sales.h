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

class Sales
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Sales();

    //--------------------------------------------------------------------------
    // Destructor
    ~Sales();

    unsigned int calculateCustomers(GameHandler& game);

    int calculateSaleInfluence(GameHandler& game);

    void calculateSales(GameHandler& game);

  private:
    static const int STANDARD_CUSTOMER_COUNT = 500;
    static const int TWENTY = 20;
    static const int FIFTY = 50;
    static const int HUNDRED = 100;
    static const int MINIMUM_PERCENT = -100;

    static const float VALUE_STORMY;
    static const float VALUE_RAINY;
    static const float VALUE_CLOUDY;
    static const float VALUE_HOT;
};

#endif //SALES_H