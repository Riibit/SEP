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

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"
#include "HTMLWriter.h"
#include "HTMLWriterEnvironment.h"
#include "HTMLWriterBalance.h"

using std::string;
using std::endl;

const std::string HTMLWriterEnvironment::icon_sunny_ = "icons/Sunny.png";
const std::string HTMLWriterEnvironment::icon_cloudy_ = "icons/Cloudy.png";
const std::string HTMLWriterEnvironment::icon_overcast_ = "icons/Overcast.png";
const std::string HTMLWriterEnvironment::icon_very_overcast_ =
 "icons/Very_overcast.png";

HTMLWriterEnvironment::HTMLWriterEnvironment()
{

}

HTMLWriterEnvironment::HTMLWriterEnvironment(string filename)
{
  filename_ = filename;
}  

void HTMLWriterEnvironment::writeFile(EnvironmentalCondition condition)
{
  HTMLWriter html_writer(filename_);
  std::ostringstream environment_body;
  string precipitation;
  string wind;

  switch(condition.getPrecipitation())
  {
    case EnvironmentalCondition::NONE : precipitation = "none";
      break;
    case EnvironmentalCondition::LOW : precipitation = "low";
      break;
    case EnvironmentalCondition::MEDIUM : precipitation = "medium";
      break;
    case EnvironmentalCondition::HIGH : precipitation = "high";
      break;
  }

  switch(condition.getWind())
  {
    case EnvironmentalCondition::NONE : wind = "none";
      break;
    case EnvironmentalCondition::LOW : wind = "low";
      break;
    case EnvironmentalCondition::MEDIUM : wind = "medium";
      break;
    case EnvironmentalCondition::HIGH : wind = "high";
      break;
  }
  
  environment_body << "<table>" << endl
    << "<tbody>" << endl
    << "<tr>" << endl
    << "<td><p style=\"text-align:center\">"
    << "<strong>Sky cover</strong></p><br>" << endl
    << "<img src=\"";

  switch(condition.getSkyCover())
  {
    case EnvironmentalCondition::SUNNY : environment_body << icon_sunny_;
      break;
    case EnvironmentalCondition::CLOUDY : environment_body << icon_cloudy_;
      break;
    case EnvironmentalCondition::OVERCAST : environment_body << icon_overcast_;
      break;
    case EnvironmentalCondition::VERY_OVERCAST : 
      environment_body << icon_very_overcast_;
      break;
  }

  environment_body << "\" alt=\"\" width=\"128\"" 
    << " height=\"128\" /></td>" << endl
    << "<td>" << endl
    << "<p><strong>Precipitation: </strong>" << precipitation
    << "</p>" << endl
    << "<p><strong>Temperature: </strong>" 
    << condition.getTemperature()
    << "°C</p>" << endl
    << "<p><strong>Wind: </strong>" << wind
    << "</p>" << endl
    << "<p><strong>Hot: </strong>"
    << html_writer.isItString(condition.isItHot())
    << "</p>" << endl << "<p><strong>Rainy: </strong>"
    << html_writer.isItString(condition.isItRainy())
    << "</p>" << endl << "<p><strong>Stormy: </strong>"
    << html_writer.isItString(condition.isItStormy())
    << "</p>" << endl
    << "</td>" << endl
    << "</tr>" << endl
    << "</tbody>" << endl
    << "</table>" << endl;
   
  html_writer.writeFile(environment_body.str());
}


