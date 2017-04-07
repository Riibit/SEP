//------------------------------------------------------------------------------
// HTMLWriter.h
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//
#ifndef HTML_WRITER_H
#define HTML_WRITER_H

#include <string>
#include <fstream>

class HTMLWriter
{
public:
  HTMLWriter();
  HTMLWriter(std::string body);

  void writeFile(std::string body);
  std::string isItString(bool input);
private:
  std::string filename_;
};

#endif //HTML_WRITER_H
