//------------------------------------------------------------------------------
// CmdBuy.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMD_BUY
#define CMD_BUY

#include "Command.h"

//------------------------------------------------------------------------------
// CmdBuy Class
// Class for the buy command.
//
class CmdBuy : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdBuy();

    //--------------------------------------------------------------------------
    // Executes the command.
    //
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    //
    // @return Integer representing the success of the action
    //
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // The name of the command
    static const std::string CMD_NAME;

    //--------------------------------------------------------------------------
    // The error message if the parameter count is not right
    static const std::string ERR_CMD;

    //--------------------------------------------------------------------------
    // Number of Parameters for this function
    static const unsigned int PARA_COUNT = 2;

    //--------------------------------------------------------------------------
    // The error message if there is not enough money
    static const std::string NOT_ENOUGH_MONEY;
};

#endif //CMD_BUY