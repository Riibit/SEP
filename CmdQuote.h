//------------------------------------------------------------------------------
// CmdQuote.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDQUOTE_H_INCLUDED
#define CMDQUOTE_H_INCLUDED

#include "Command.h"

class CmdQuote : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdQuote();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    static const std::string ERR_QUOTE;
    static const std::string CMD_NAME;
};

#endif //CMDQUOTE_H_INCLUDED