#include "testScanner.h"
// #include "scanner.h"

#include <iostream>
#include <istream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  // Processing the arguments (as in P0) and then calling testScanner() function with interface and preparation as needed
    // Input types: `scanner [file]` to read from stdin or file.fs (extension is implicit)

  istream *in;
  ifstream out;
  
  if (argc == 1) {
    in = &cin;
    cout << "Please enter the input for the program. Finish by entering a new line." << endl;
  }
  // Argument given, open the file and use it
  else if (argc == 2)
  {
    string fileName = argv[1];
    cout << "file given: " << fileName << endl;
    out.open(fileName); 
    in = &out;

    cout << "Reading your file..." << endl;
    if(!out.is_open()) {
      // Before error, check if .fs is being added or not
      if(fileName.find(".fs") == std::string::npos) {
        // try one more time to open the file
        out.open(fileName + ".fs");
        in = &out;

        if(!out.is_open()) {
          cout << "Error: Your file could not be read. It probably does not exist." << endl;
          return 1;
        }
        else {
          cout << "proceeding with file" << endl;
        }
      }
      else {
        cout << "Error: Your file could not be read. It probably does not exist." << endl;
        return 1;
      }
    }
    else if (out.peek() == ifstream::traits_type::eof()) {
      cout << "Error: Your file is empty, so it could not be used." << endl;
      return 1;
    }
    else {
      cout << "File has been opened successfully." << endl;
    }
  }
  else {
    cout << "Error: Too many arguments given. Please retry with 1 or 2 arguments (including the command)." << endl;
    return 1;
  }

  testScanner(in);

  out.close();

  cout << "program has ran" << endl;

  return 0;
}