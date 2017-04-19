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

using std::string;
using std::endl;

const string HTMLWriterEnvironment::icon_sunny_ = "icons/Sunny.png";
const string HTMLWriterEnvironment::icon_cloudy_ = "icons/Cloudy.png";
const string HTMLWriterEnvironment::icon_overcast_ = "icons/Overcast.png";
const string HTMLWriterEnvironment::icon_very_overcast_ = 
  "icons/Very_overcast.png";

//------------------------------------------------------------------------------
// Creates the body part of the Environmental html file and passes it to the
// writeFile function of the parent class
//
// @param condition The EnvironmentalCondition object that supplies the values
//        that are to be written
//
void HTMLWriterEnvironment::writeFile(EnvironmentalCondition condition)
{
  std::ostringstream environment_body;

  environment_body << "<table>" << endl
    << "<tbody>" << endl
    << "<tr>" << endl
    << "<td><p style=\"text-align:center\">"
    << "<strong>Sky cover</strong></p><br>" << endl
    << "<img src=\"";

  switch(condition.getSkyCover())
  {
    case EnvironmentalCondition::SUNNY :
      environment_body << icon_sunny_;
      break;
    case EnvironmentalCondition::CLOUDY :
      environment_body << icon_cloudy_;
      break;
    case EnvironmentalCondition::OVERCAST :
      environment_body << icon_overcast_;
      break;
    case EnvironmentalCondition::VERY_OVERCAST : 
      environment_body << icon_very_overcast_;
      break;
  }

  environment_body << "\" alt=\"\" width=\"128\"" 
    << " height=\"128\" /></td>" << endl
    << "<td>" << endl
    << "<p><strong>Precipitation: </strong>"
    << HTMLWriterEnvironment::rankString(condition.getPrecipitation())
    << "</p>" << endl
    << "<p><strong>Temperature: </strong>"
    << condition.getTemperature()
    << "°C</p>" << endl
    << "<p><strong>Wind: </strong>"
    << HTMLWriterEnvironment::rankString(condition.getWind())
    << "</p>" << endl
    << "<p><strong>Hot: </strong>"
    << HTMLWriterEnvironment::isItString(condition.isItHot())
    << "</p>" << endl << "<p><strong>Rainy: </strong>"
    << HTMLWriterEnvironment::isItString(condition.isItRainy())
    << "</p>" << endl << "<p><strong>Stormy: </strong>"
    << HTMLWriterEnvironment::isItString(condition.isItStormy())
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

//------------------------------------------------------------------------------
// Takes a Rank enum defined in the EnvironmentalCondition and returns the
// corresponding strings
//
// @param rank The rank enum
//
// @return string The corresponding string
//
string HTMLWriterEnvironment::rankString(EnvironmentalCondition::Rank rank)
{
  switch(rank)
  {
    case EnvironmentalCondition::NONE :
      return "none";
    case EnvironmentalCondition::LOW :
      return "low";
    case EnvironmentalCondition::MEDIUM :
      return "medium";
    default :
      return "high";
  }
}