//------------------------------------------------------------------------------
// OwnBaseException.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
 
#ifndef DATA_TYPE_EXCEPTION_H_INCLUDED
#define DATA_TYPE_EXCEPTION_H_INCLUDED

#include "OwnBaseException.h"

//------------------------------------------------------------------------------
// ExceptionDataType class
// Not Integer Exception
//
class ExceptionDataType : public OwnBaseException
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    ExceptionDataType();

    //--------------------------------------------------------------------------
    // Destructor
    ~ExceptionDataType();
};
 
#endif // DATA_TYPE_EXCEPTION_H_INCLUDED