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

class HTMLWriterBalance : public HTMLWriter
{
public:
  HTMLWriterBalance();
  HTMLWriterBalance(string filename_);

  void writeFile(int lemon, int sugar, int cash, int delta);
};

#endif // HTML_WRITER_BALANCE_H
