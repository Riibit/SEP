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
  std::ostringstream environment_body;
  string icon;


  switch(condition.getPrecipitation())
  {
    case EnvironmentalCondition::NONE : icon = ICON_SUNNY;
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
    case EnvironmentalCondition::VERY_OVERCAST: 
      environment_body << ICON_VERY_OVERCAST;
      break;
  }


  environment_body << "\" alt=\"\" width=\"128\"";  
  environment_body << " height=\"128\" /></td>" << endl;
  environment_body << "<td>" << endl;
  environment_body << "<p><strong>Precipitation: </strong>medium</p>" << endl;
  environment_body << "<p><strong>Temperature: </strong>14.6°C</p>" << endl;
  environment_body << "<p><strong>Wind: </strong>medium</p>" << endl;
  environment_body << "<p><strong>Hot: </strong>false</p>" << endl;
  environment_body << "<p><strong>Rainy: </strong>true</p>" << endl;
  environment_body << "<p><strong>Stormy: </strong>true</p>" << endl;
  environment_body << "</td>" << endl;
  environment_body << "</tr>" << endl;
  environment_body << "</tbody>" << endl;
  environment_body << "</table>";
  
  HTMLWriter html_writer("LimoStandl.html");
  html_writer.writeFile(environment_body.str());

  std::cout << environment_body.str();
}


