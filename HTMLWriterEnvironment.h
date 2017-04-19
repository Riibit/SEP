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

#include <string>
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

    static const std::string icon_sunny_;
    static const std::string icon_cloudy_;
    static const std::string icon_overcast_;
    static const std::string icon_very_overcast_;
};

#endif // HTML_WRITER_ENV_H