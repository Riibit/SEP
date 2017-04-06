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

#define ICON_LEMON "icons/Lemon.png"
#define ICON_SUGAR "icons/Sugar.png"
#define ICON_COINS "icons/Coins.png"

class HTMLWriterBalance : public HTMLWriter
{
public:
  HTMLWriterBalance();
  HTMLWriterBalance(std::string filename);

  void writeFile(int lemon, int sugar, int cash, int delta);
private:
  std::string filename_;
};

#endif // HTML_WRITER_BALANCE_H
