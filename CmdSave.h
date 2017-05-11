//------------------------------------------------------------------------------
// CmdSave.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMD_SAVE
#define CMD_SAVE

#include "Command.h"

//----------------------------------------------------------------------------
// CmdSave Class
// Class for the save command.
//
class CmdSave : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdSave();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // The name of the command
    static const std::string CMD_NAME;

    //--------------------------------------------------------------------------
    // The error message if the parameter count is not right
    static const std::string ERR_CMD;

    //--------------------------------------------------------------------------
    // Number of Parameters for this function
    static const unsigned int PARA_COUNT = 1;

    //--------------------------------------------------------------------------
    // Filename recieved from promt
    static const std::string FILENAME;    
};

#endif //CMD_SAVE