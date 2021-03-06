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

#include <fstream>
#include "HTMLWriter.h"

using std::string;
using std::endl;

HTMLWriter::HTMLWriter(string filename)
{
  filename_ = filename;
}

HTMLWriter::~HTMLWriter()
{
}


void HTMLWriter::writeFile(string body)
{
  std::ofstream writer;
  writer.open(filename_.c_str());
  if(writer.is_open())
  {
    writer << "<!DOCTYPE html>" << endl
      << "<html lang=\"en\">" << endl
      << "<head>" << endl
      << "<meta charset=\"utf-8\">" << endl
      << "<meta http-equiv=\"refresh\" content=\"3\">" << endl
      << "<title>SEP 2017</title>" << endl
      << "<style>body{margin: 0px; padding: 0px;}</style>" << endl
      << "</head>" << endl
      << "<body>" << endl
      << "<h1 style=\"text-align:center\">LIMOSTANDL</h1>" << endl
      << body
      << "</body>" << endl
      << "</html>";
    writer.close();
  }
  else
  {
  }
}