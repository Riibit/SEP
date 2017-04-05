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
class EnvironmentalCondition

//------------------------------------------------------------------------------
// The class that writes Environment HTML files
//
class HTMLWriterEnvironment : public HTMLWriter
{
  public:
    HTMLWriterEnvironment();
    void writeFile(EnvironmentalCondition::Cover sky_cover, 
      EnvironmentalCondition::Rank precipitation, float temperature, 
      EnvironmentalCondition::Rank wind);
};

#endif // HTML_WRITER_ENV_H