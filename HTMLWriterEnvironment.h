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

#include "HTMLWriter.h"
#include "EnvironmentalCondition.h"

//------------------------------------------------------------------------------
// The class for writing Environment HTML files
//
class HTMLWriterEnvironment : public HTMLWriter
{
  public:
    using HTMLWriter::HTMLWriter;
    void writeFile(EnvironmentalCondition conditions);

  private:
    std::string isItString(bool input);
    std::string rankString(EnvironmentalCondition::Rank rank);

    static const std::string ICON_SUNNY;
    static const std::string ICON_CLOUDY;
    static const std::string ICON_OVERCAST;
    static const std::string ICON_VERY_OVERCAST;
};

#endif // HTML_WRITER_ENV_H