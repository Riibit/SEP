//------------------------------------------------------------------------------
// Command.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class GameHandler;

//------------------------------------------------------------------------------
// Command Class
// Class for the command management.
//
class Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Command(const Command& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    Command& operator=(const Command& original);
    
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;

    //--------------------------------------------------------------------------
    // The variable which saves the corresponding error messages
    std::string parameter_message_;

    //--------------------------------------------------------------------------
    // How many parameters a command accepts
    unsigned int parameter_count_;


  public:
    //--------------------------------------------------------------------------
    // Constructor
    Command(std::string name);

    //--------------------------------------------------------------------------
    // Constructor
    Command(std::string name, unsigned int paramter_count, 
      std::string parameter_message);

    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Command();

    //--------------------------------------------------------------------------
    // Executes the command.
    //
    // @param game The game where action should be performed on
    // @param params Possible parameters needed for the execution
    //
    // @return Integer representing the success of the action
    //
    virtual int execute(GameHandler& game, 
      std::vector<std::string>& params) = 0;

    //--------------------------------------------------------------------------
    // Checks if the Command has the correct amount of parameters
    //
    // @param The amount of parameters
    //
    // @return True if the amount is correct, otherwise false 
    //
    virtual const bool correctParameterCount(const unsigned int to_compare);
    
    //--------------------------------------------------------------------------
    // Getter Methods
    const std::string& getName() const;

    const std::string& getErrorMessage() const;

    //--------------------------------------------------------------------------
    // The error message displays if the parameter is wrong or invalid
    static const std::string ERR_WRONG_PARAMETER;
};

#endif //COMMAND_H_INCLUDED