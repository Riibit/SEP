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
 
#ifndef NOTINTEGER_EXCEPTION_H_INCLUDED
#define NOTINTEGER_EXCEPTION_H_INCLUDED

#include "OwnBaseException.h"

//------------------------------------------------------------------------------
// Not Integer Exception
//
class ExceptionNotInteger : public OwnBaseException
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    ExceptionNotInteger();
};
 
#endif // NOTINTEGER_EXCEPTION_H_INCLUDED