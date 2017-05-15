//------------------------------------------------------------------------------
// HTMLWriterEnvironment.cpp 
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include <sstream>
#include "HTMLWriterEnvironment.h"
#include "Parse.h"

using std::string;
using std::endl;

const string HTMLWriterEnvironment::ICON_SUNNY = 
  "https://palme.iicm.tugraz.at/wiki/images/9/9a/Sunny.png";
const string HTMLWriterEnvironment::ICON_CLOUDY = 
  "https://palme.iicm.tugraz.at/wiki/images/3/33/Cloudy.png";
const string HTMLWriterEnvironment::ICON_OVERCAST = 
  "https://palme.iicm.tugraz.at/wiki/images/6/6f/Overcast.png";
const string HTMLWriterEnvironment::ICON_VERY_OVERCAST = 
  "https://palme.iicm.tugraz.at/wiki/images/3/30/Very_overcast.png";

const std::string HTMLWriterEnvironment::STANDARD_NAME = "Environment.html";

HTMLWriterEnvironment::HTMLWriterEnvironment() : HTMLWriter::HTMLWriter(
  STANDARD_NAME)
{
}

//------------------------------------------------------------------------------
// Creates the body part of the Environmental html file and passes it to the
// writeFile function of the parent class
//
// @param condition The EnvironmentalCondition object that supplies the values
//        that are to be written
//
void HTMLWriterEnvironment::writeFile(
  const std::unique_ptr<EnvironmentalCondition>& condition)
{
  std::ostringstream environment_body;
  Parse parser;

  environment_body << "<table>" << endl
    << "<tbody>" << endl
    << "<tr>" << endl
    << "<td><p style=\"text-align:center\">"
    << "<strong>Sky cover</strong></p><br>" << endl
    << "<img src=\"";

  switch(condition -> getSkyCover())
  {
    case EnvironmentalCondition::SUNNY :
      environment_body << ICON_SUNNY;
      break;
    case EnvironmentalCondition::CLOUDY :
      environment_body << ICON_CLOUDY;
      break;
    case EnvironmentalCondition::OVERCAST :
      environment_body << ICON_OVERCAST;
      break;
    case EnvironmentalCondition::VERY_OVERCAST : 
      environment_body << ICON_VERY_OVERCAST;
      break;
  }

  environment_body << "\" alt=\"\" width=\"128\"" 
    << " height=\"128\" /></td>" << endl
    << "<td>" << endl
    << "<p><strong>Precipitation: </strong>"
    << parser.parseRank(condition -> getPrecipitation())
    << "</p>" << endl
    << "<p><strong>Temperature: </strong>"
    << condition -> getTemperature() << "°C</p>" << endl
    << "<p><strong>Wind: </strong>"
    << parser.parseRank(condition -> getWind()) << "</p>" << endl
    << "<p><strong>Hot: </strong>"
    << HTMLWriterEnvironment::isItString(condition -> isItHot()) << "</p>" << endl
    << "<p><strong>Rainy: </strong>"
    << HTMLWriterEnvironment::isItString(condition -> isItRainy())
    << "</p>" << endl << "<p><strong>Stormy: </strong>"
    << HTMLWriterEnvironment::isItString(condition -> isItStormy())
    << "</p>" << endl
    << "</td>" << endl
    << "</tr>" << endl
    << "</tbody>" << endl
    << "</table>" << endl;

  HTMLWriter::writeFile(environment_body.str());
}

//------------------------------------------------------------------------------
// Takes a boolean value and returns a true or falase string depending on the
// value
//
// @param input The boolean value
//
// @return string The corresponding string
//
string HTMLWriterEnvironment::isItString(bool input)
{
  if(input)
  {
    return "true";
  }
  else
  {
    return "false";
  }
}
