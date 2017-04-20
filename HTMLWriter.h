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

class HTMLWriter
{
  public:
    HTMLWriter(std::string filename);
    void writeFile(std::string body);
    
  private:
    std::string filename_;
};

#endif //HTML_WRITER_H