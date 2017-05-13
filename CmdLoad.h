//------------------------------------------------------------------------------
// CmdLoad.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMD_LOAD
#define CMD_LOAD

#include <vector>
#include "Command.h"

//----------------------------------------------------------------------------
// CmdLoad Class
// Class for the load command.
//
class CmdLoad : public Command
{
  public:
    //--------------------------------------------------------------------------
    // Constructor
    CmdLoad();

    bool isBracket(char current_char);

    bool checkTagExists(std::string tag);

    bool checkTagClosed(std::string tag, std::string closing_tag);

    bool tagValidAndClosed(std::vector<std::string> save_line_arguments);

    bool unpairedTagAllowed(std::string unpaired_tag);

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
    // Tag strings
    static const std::string TAG_SAVEFILE;
    static const std::string TAG_STATS;
    static const std::string TAG_WEATHER;
    static const std::string TAG_WIND;
    static const std::string TAG_TEMPERATURE;
    static const std::string TAG_PRECIPITATION;
    static const std::string TAG_COVER;
    static const std::string TAG_CASH;
    static const std::string TAG_BALANCE;
    static const std::string TAG_INCOME;
    static const std::string TAG_EXPENSE;
    static const std::string TAG_LEMONS;
    static const std::string TAG_SUGAR;
    static const std::string TAG_LEMONADE;
    static const std::string TAG_PRICESUGAR;
    static const std::string TAG_PRICELEMONS;
    static const std::string TAG_PRICELEMONADE;


    //--------------------------------------------------------------------------
    // Contains all possible tags
    std::vector<std::string> tag_collection_;
};

#endif //CMD_LOAD