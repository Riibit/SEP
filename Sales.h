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

  private:
    static const int STANDARD_CUSTOMER_COUNT = 500;
}

#endif //SALES_H