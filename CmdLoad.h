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

    //--------------------------------------------------------------------------
    // isBracket checks if a character is an angle bracket, used in 
    // savefile parsing
    //
    // @param current_char character from savefile line that is being checked
    //
    // @return true if char is an angle bracket
    //
    bool isBracket(char current_char);

    //--------------------------------------------------------------------------
    // checkTagExists checks if a tag found in savefile is allowed, used in 
    // savefile parsing
    //
    // @param tag that is being checked
    //
    // @return true if tag exists in list of allowed tags
    //
    bool checkTagExists(std::string tag);

    //--------------------------------------------------------------------------
    // checkTagClosed checks if a paired tag is closed or not, used in 
    // savefile parsing
    //
    // @param tag tag from savefile that is being checked
    // @param closing_tag corresponding closing tag from the same line
    //
    // @return true if char is an angle bracket
    //    
    bool checkTagClosed(std::string tag, std::string closing_tag);
    
    //--------------------------------------------------------------------------
    // tagValidAndClosed calls two methods above to determine the validity 
    // of the tags in the line
    // @param vector containing all savefile tags and values from one line
    // @return true if the tag exists and is closed properly
    //
    bool tagValidAndClosed(std::vector<std::string> save_line_arguments);
    
    //--------------------------------------------------------------------------
    // unpairedTagAllowed checks if an unclosed tag is allowed to be closed
    // in another line
    // @param tag which is being tested
    // @return true if the tag is allowed to be alone in a line
    //
    bool unpairedTagAllowed(std::string unpaired_tag);

    //--------------------------------------------------------------------------
    // fileIsValid checks if file is valid by checking unpaired tags and closed
    // paired tags and if they exist
    // @param vector containing all savefile tags and values from one line
    // 
    // @return true if the file is valid 
    //
    bool fileIsValid(std::vector<std::string> save_line_arguments);

    //--------------------------------------------------------------------------
    // loadResourceValue carries the values read from savefile to the
    // game (calls appropriate setters)
    // @param game The object of GameHandler where the game is being run
    // @param tag_name name of variable to be loaded into game
    // @return tag_value value of variable to be loaded into game
    //
    void loadResourceValue(GameHandler& game, std::string tag_name,
        std::string tag_value);

    bool hierarchyCheckPassed(std::vector<std::string> all_savefile_tags);

    bool isWeatherTag(std::string tag);

    bool isStatsTag(std::string tag);

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Integer representing the success of the action
    virtual int execute(GameHandler& game, std::vector<std::string>& params);

    //--------------------------------------------------------------------------
    // The start and end index of weather tag strings
    static const int WEATHER_START = 3;
    static const int WEATHER_END = 6;

    //--------------------------------------------------------------------------
    // The start index of stats tag strings
    static const unsigned int STATS_START = 7;

    //--------------------------------------------------------------------------
    // The name of the command
    static const std::string CMD_NAME;

    //--------------------------------------------------------------------------
    // The error message if the parameter count is not right
    static const std::string ERR_CMD;

    //--------------------------------------------------------------------------
    // The error message if there is a problem while opening savefile
    static const std::string FILE_OPEN_ERROR;

    //--------------------------------------------------------------------------
    // The error message if savefile is invalid
    static const std::string ERR_FILE_INVALID;

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