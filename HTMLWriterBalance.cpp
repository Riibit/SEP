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
#include <iostream>

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"
#include "HTMLWriter.h"
#include "HTMLWriterEnvironment.h"
#include "HTMLWriterBalance.h"

using std::string;
using std::endl;

HTMLWriterBalance::HTMLWriterBalance()
{

}

HTMLWriterBalance::HTMLWriterBalance(string filename)
{
	filename_ = filename;
}

void HTMLWriterBalance::writeFile(int lemon, int sugar, int cash, int delta)
{
	HTMLWriter html_writer(filename_);
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

  html_writer.writeFile(balance_body.str());
  }