//------------------------------------------------------------------------------
// HTMLWriterBalance.cpp 
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
#include <sstream>
#include "HTMLWriterBalance.h"

using std::string;
using std::endl;

const string HTMLWriterBalance::icon_lemon_ = "icons/Lemon.png";
const string HTMLWriterBalance::icon_sugar_ = "icons/Sugar.png";
const string HTMLWriterBalance::icon_coins_ = "icons/Coins.png";

//------------------------------------------------------------------------------
// Creates the body part of the Balance html file and passes it to the
// writeFile function of the parent class
//
// @param lemon The lemon value that is to be written in the html file
// @param sugar The sugar value that is to be written in the html file
// @param cash The cash value that is to be written in the html file
// @param delta The delta value that is to be written in the html file
//
void HTMLWriterBalance::writeFile(int lemon, int sugar, int cash, int delta)
{
  std::ostringstream balance_body;

  balance_body << "<table>" << endl
    << "<tbody>" << endl
    << "<tr>" << endl
    << "<td><img src=\"" << icon_lemon_ 
    << "\" alt=\"\" width=\"64\" height=\"64\" /></td>" << endl
    << "<td><strong>Lemons: </strong>" << lemon << "</td>" << endl
    << "</tr>" << endl
    << "<tr>" << endl
    << "<td><img src=\"" << icon_sugar_
    << "\" alt=\"\" width=\"64\" height=\"64\" /></td>" << endl
    << "<td><strong>Sugar: </strong>" << sugar << "</td>" << endl
    << "</tr>" << endl
    << "<tr>" << endl
    << "<td><img src=\"" << icon_coins_
    << "\" alt=\"\" width=\"64\" height=\"64\" /></td>" << endl
    << "<td>" << endl
    << "<p><strong>Cash: </strong>" << cash << "$</p>" << endl
    << "<p><strong>Delta: </strong>" << delta << "$</p>" << endl
    << "</td>" << endl
    << "</tr>" << endl
    << "</tbody>" << endl
    << "</table>" << endl;

  HTMLWriter::writeFile(balance_body.str());
}