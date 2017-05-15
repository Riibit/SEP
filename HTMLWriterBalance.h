//------------------------------------------------------------------------------
// HTMLWriterBalance.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#ifndef HTML_WRITER_BALANCE_H
#define HTML_WRITER_BALANCE_H

#include "HTMLWriter.h"

//------------------------------------------------------------------------------
// The class for writing Balance HTML files
//
class HTMLWriterBalance : public HTMLWriter
{
  public:
    //--------------------------------------------------------------------------
    // Inherit HTMLWriter constructor
    using HTMLWriter::HTMLWriter;

    //--------------------------------------------------------------------------
    // Constructor
    HTMLWriterBalance();

    //------------------------------------------------------------------------------
    // Creates the body part of the Balance html file and passes it to the
    // writeFile function of the parent class
    //
    // @param lemon The lemon value that is to be written in the html file
    // @param sugar The sugar value that is to be written in the html file
    // @param cash The cash value that is to be written in the html file
    // @param delta The delta value that is to be written in the html file
    //
    void writeFile(int lemon, int sugar, int cash, int delta);

    //--------------------------------------------------------------------------
    // String values for the correspondend icons.
    const static std::string ICON_LEMON;
    const static std::string ICON_SUGAR;
    const static std::string ICON_COINS;

    //--------------------------------------------------------------------------
    // String value for the html-files name.
    static const std::string STANDARD_NAME;
};

#endif // HTML_WRITER_BALANCE_H