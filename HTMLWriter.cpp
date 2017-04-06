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

using std::string;
using std::endl;

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
  writer.open (filename_.c_str());
  if(writer.is_open())
  {
    writer << "<!DOCTYPE html>" << endl << "<html lang=\"en\">" << endl
      << "<head>" << endl << "<meta charset=\"utf-8\">" << endl
      << "<meta http-equiv=\"refresh\" content=\"3\">" << endl
      << "<title>SEP 2017</title>" << endl 
      << "<style>body{margin: 0px; padding: 0px;}</style>" << endl << "</head>" 
      << endl << "<body>" << "<h1><center>LIMOSTANDL</center></h1>" << body
      << "</body>" << endl << "</html>";
    writer.close();
  }
}

std::string isItString(bool input)
{
  if(input)
  {
    return "true";
  }
  else
  {
    return "false";
  }
}