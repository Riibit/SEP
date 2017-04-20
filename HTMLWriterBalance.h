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
    using HTMLWriter::HTMLWriter;
    void writeFile(int lemon, int sugar, int cash, int delta);

    const static std::string ICON_LEMON;
    const static std::string ICON_SUGAR;
    const static std::string ICON_COINS;
};

#endif // HTML_WRITER_BALANCE_H