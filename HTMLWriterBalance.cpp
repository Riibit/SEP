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

const string HTMLWriterBalance::ICON_LEMON = 
  "https://palme.iicm.tugraz.at/wiki/images/3/35/Lemon.png";
const string HTMLWriterBalance::ICON_SUGAR = 
  "https://palme.iicm.tugraz.at/wiki/images/a/a9/Sugar.png";
const string HTMLWriterBalance::ICON_COINS = 
  "https://palme.iicm.tugraz.at/wiki/images/f/f0/Coins.png";

const std::string HTMLWriterBalance::STANDARD_NAME = "Balance.html";


HTMLWriterBalance::HTMLWriterBalance() : HTMLWriter::HTMLWriter(STANDARD_NAME)
{
}

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
    << "<td><img src=\"" << ICON_LEMON 
    << "\" alt=\"\" width=\"64\" height=\"64\" /></td>" << endl
    << "<td><strong>Lemons: </strong>" << lemon << "</td>" << endl
    << "</tr>" << endl
    << "<tr>" << endl
    << "<td><img src=\"" << ICON_SUGAR
    << "\" alt=\"\" width=\"64\" height=\"64\" /></td>" << endl
    << "<td><strong>Sugar: </strong>" << sugar << "</td>" << endl
    << "</tr>" << endl
    << "<tr>" << endl
    << "<td><img src=\"" << ICON_COINS
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