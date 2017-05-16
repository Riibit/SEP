//------------------------------------------------------------------------------
// CmdForecast.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMD_FORECAST_H
#define CMD_FORECAST_H

#include "Command.h"

//------------------------------------------------------------------------------
// CmdForecast class
// Class for the forecast command
//
class CmdForecast : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdForecast();

    //--------------------------------------------------------------------------
    // Executes the command
    //
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    //
    // @return int Returns integer representing the success of the action
    //
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // Calculates the lower enum values
    //
    // @param int The enum value casted into int
    //
    // @return int Returns the lower value
    //
    int weatherLower(int enum_value);

    //--------------------------------------------------------------------------
    // Calculates the higher enum values
    //
    // @param int The enum value casted into int
    //
    // @return int Returns the higher value
    //
    int weatherHigher(int enum_value);

    //--------------------------------------------------------------------------
    /// The name of the command
    static const std::string CMD_NAME;

    //--------------------------------------------------------------------------
    /// The error message if the parameter count is not right
    static const std::string ERR_CMD;

    //--------------------------------------------------------------------------
    /// Number of Parameters for this function
    static const unsigned int PARA_COUNT = 0;

    //--------------------------------------------------------------------------
    /// Temperature swing value
    static const int SWING = 5;
};

#endif //CMD_FORECAST_H