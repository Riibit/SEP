//------------------------------------------------------------------------------
// CmdBalance.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDBALANCE_H_INCLUDED
#define CMDBALANCE_H_INCLUDED

#include "Command.h"

//----------------------------------------------------------------------------
// CmdBalance Class
// Class for the balance command.
//
class CmdBalance : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdBalance();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    int execute(GameHandler& game, std::vector<std::string>& params);
    
    //--------------------------------------------------------------------------
    /// The name of the command
    static const std::string CMD_NAME;

    //--------------------------------------------------------------------------
    /// The error message if the parameter count is not right
    static const std::string ERR_CMD;

    //--------------------------------------------------------------------------
    /// Number of Parameters for this function
    static const unsigned int PARA_COUNT = 0;
};

#endif //CMDBALANCE_H_INCLUDED