//------------------------------------------------------------------------------
// HTMLWriterEnvironment.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef HTML_WRITER_ENV_H
#define HTML_WRITER_ENV_H

#define ICON_SUNNY "icons/Sunny.png"
#define ICON_CLOUDY "icons/Cloudy.png"
#define ICON_OVERCAST "icons/Overcast.png"
#define ICON_VERY_OVERCAST "icons/Very_overcast.png"

class EnvironmentalCondition;

//------------------------------------------------------------------------------
// The class that writes Environment HTML files
//
class HTMLWriterEnvironment : public HTMLWriter
{
  public:
    HTMLWriterEnvironment();
    void writeFile(EnvironmentalCondition conditions);
};

#endif // HTML_WRITER_ENV_H