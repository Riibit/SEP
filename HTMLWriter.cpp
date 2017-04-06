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
    writer << "<!DOCTYPE html>" << endl;
    writer << "<html lang=\"en\">" << endl;
    writer << "<head>" << endl;
    writer << "<meta charset=\"utf-8\">" << endl;
    writer << "<meta http-equiv=\"refresh\" content=\"3\">" << endl;
    writer << "<title>SEP 2017</title>" << endl;
    writer << "<style>body{margin: 0px; padding: 0px;}</style>" << endl;
    writer << "</head>" << endl;
    writer << "<body>" << "<h1><center>LIMOSTANDL</center></h1>" << body;
    writer << "</body>" << endl;
    writer << "</html>";
    writer.close();
  }
}

string isItString(bool input)
{
  switch(input)
  {
    case TRUE : return "true";
      break;
    case FALSE : return "false";
      break;
  }
}