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

//------------------------------------------------------------------------------
// HTMLWriter class
// The class for writing html files
//
class HTMLWriter
{
  public:
    //--------------------------------------------------------------------------
    // Constructor for the class
    //
    // @param filename The filename of the html file that is to be written
    //
    HTMLWriter(std::string filename);

    //--------------------------------------------------------------------------
    // Destructor
    ~HTMLWriter();


    //--------------------------------------------------------------------------
    // The function that writes the html file with the given body
    //
    // @param body The string that is to be inserted in the body of the html 
    //        file
    //
    void writeFile(std::string body);
    
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    HTMLWriter(const HTMLWriter& original);

    //--------------------------------------------------------------------------
    // Private assignment operator
    HTMLWriter& operator=(const HTMLWriter& original);
      std::string filename_;
};

#endif //HTML_WRITER_H