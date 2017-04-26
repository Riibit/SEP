//------------------------------------------------------------------------------
// CmdRecipe.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDRECIPE_H_INCLUDED
#define CMDRECIPE_H_INCLUDED


#include "Command.h"

class CmdRecipe : public Command
{
  public:
    CmdRecipe ();
    virtual int execute (GameHandler& game, std::vector<std::string>& params);
    bool isItInteger(std::string string);

    static const std::string CMD_NAME;

    static const std::string ERROR_MSG;
    static const std::string ERROR_MSG_PERCENT;
};

#endif //CMDRECIPE_H_INCLUDED