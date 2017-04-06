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
#include <iostream>

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"
#include "HTMLWriter.h"
#include "HTMLWriterEnvironment.h"
#include "HTMLWriterBalance.h"

using std::string;
using std::endl;

HTMLWriterEnvironment::HTMLWriterEnvironment()
{

}  

void HTMLWriterEnvironment::writeFile(EnvironmentalCondition condition)
{
  HTMLWriter html_writer("LimoStandl.html");
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
  
  environment_body << "<table>" << endl;
  environment_body << "<tbody>" << endl;
  environment_body << "<tr>" << endl;
  environment_body << "<td><strong>Sky cover</strong></td>" << endl;
  environment_body << "<td></td>" << endl;
  environment_body << "</tr>" << endl;
  environment_body << "<tr>";
  environment_body << "<td><img src=\"";

  switch(condition.getSkyCover())
  {
    case EnvironmentalCondition::SUNNY : environment_body << ICON_SUNNY;
      break;
    case EnvironmentalCondition::CLOUDY : environment_body << ICON_CLOUDY;
      break;
    case EnvironmentalCondition::OVERCAST : environment_body << ICON_OVERCAST;
      break;
    case EnvironmentalCondition::VERY_OVERCAST : 
      environment_body << ICON_VERY_OVERCAST;
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
    << "</table>";
   
  html_writer.writeFile(environment_body.str());

  std::cout << environment_body.str();
}


