//------------------------------------------------------------------------------
// CmdEcho.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef CMDECHO_H_INCLUDED
#define CMDECHO_H_INCLUDED

#include "Command.h"

class CmdEcho : public Command
{
  public:
    CmdEcho ();
    virtual int execute (GameHandler& game, std::vector<std::string>& params);
    const bool correctParameterCount(const unsigned int to_compare);

    static const unsigned int PARA_COUNT = 0;
};

#endif //CMDECHO_H_INCLUDED