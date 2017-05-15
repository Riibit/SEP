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

#include <memory>
#include "HTMLWriter.h"
#include "EnvironmentalCondition.h"


//------------------------------------------------------------------------------
// The class for writing Environment HTML files
//
class HTMLWriterEnvironment : public HTMLWriter
{
  public:
    //--------------------------------------------------------------------------
    // Inherit HTMLWriter constructor
    using HTMLWriter::HTMLWriter;

    //--------------------------------------------------------------------------
    // Constructor
    HTMLWriterEnvironment();

    //------------------------------------------------------------------------------
    // Creates the body part of the Environmental html file and passes it to the
    // writeFile function of the parent class
    //
    // @param condition The EnvironmentalCondition object that supplies the values
    //        that are to be written
    //
    void writeFile(const std::unique_ptr<EnvironmentalCondition>& condition);

    //--------------------------------------------------------------------------
    // String values for the correspondend icons.
    static const std::string ICON_SUNNY;
    static const std::string ICON_CLOUDY;
    static const std::string ICON_OVERCAST;
    static const std::string ICON_VERY_OVERCAST;

    //--------------------------------------------------------------------------
    // String value for the html-files name.
    static const std::string STANDARD_NAME;

  private:
    //------------------------------------------------------------------------------
    // Takes a boolean value and returns a true or falase string depending on the
    // value
    //
    // @param input The boolean value
    //
    // @return string The corresponding string
    //
    std::string isItString(bool input);
};

#endif // HTML_WRITER_ENV_H