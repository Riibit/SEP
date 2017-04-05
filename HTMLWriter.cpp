//------------------------------------------------------------------------------
// HTMLWriter.cpp
//
// Group: Group 15666, study assistant Hasan Durmaz
//
// Authors: Milan Drinic 1431883
// Christopher Hinterer 1432027
// Julian Rudolf 1331657
//------------------------------------------------------------------------------
//

#include "EnvironmentalCondition.h"
#include "EnvironmentalEngine.h"
#include "HTMLWriter.h"
#include "HTMLWriterEnvironment.h"
#include "HTMLWriterBalance.h"

HTMLWriter::HTMLWriter()
{

}

HTMLWriter::HTMLWriter(string filename)
{
  filename_ = filename;
}

void HTMLWriter::writeFile(string body)
{
  std::ofstream writer;
  writer.open (filename_);
  if(writer.is_open())
  {
    writer << "<!DOCTYPE html>" << std::endl;
    writer << "<html lang=\"en\">" << std::endl;
    writer << "<head>" << std::endl;
    writer << "<meta charset=\"utf-8\">" << std::endl;
    writer << "<meta http-equiv=\"refresh\" content=\"3\">" << std::endl;
    writer << "<title>SEP 2017</title>" << std::endl;
    writer << "<style>body{margin: 0px; padding: 0px;}</style>" << std::endl;
    writer << "</head>" << std::endl;
    writer << "<body>" << body;
    writer << "</body>" << std::endl;
    writer << "</html>";
    writer.close();
  }
}