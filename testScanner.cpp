#include "scanner.h"

#include <istream>
#include <iostream>

using namespace std;

// int argc, char *argv[]
void testScanner(istream *input) {
  Scanner scanner;

  string delimiterComma = ",";
  string delimiterSpace = " ";
  string delimiterTab = "\t";
  string line;

  // Instructions:
  // ask the scanner for one token at a time,
  // and display the token to the screen, one per line,
  // including information (descriptive) on what token class, token instance, and token line it is

  // Pseudo-code:
  // while token (token-scanner() != eofTk())
    // print descriptive token followed by token instance or nothing if null followed by line number followed by '\n'

  // -------------------------------------------------------------------------------------------------------------------

  // Read Input from istream
  while (getline(*input, line)) {
    cout << "line: " << line << endl;
    if(line == "EOF" || line == "") {
      cout << "end of file" << endl;
      break;
    }

    // Split line into characters, check for delimiters, build tree this way
    // if((line.find(delimiterSpace)) != string::npos) {
    //   splitByDelimiter(delimiterSpace, line);
    // }
    // else if((line.find(delimiterComma)) != string::npos) {
    //   splitByDelimiter(delimiterComma, line);
    // }
    // else if((line.find(delimiterTab)) != string::npos) {
    //   splitByDelimiter(delimiterTab, line);
    // }
    // else {
    //   // line is 1 word, do something with it

    //   // string key = this->getCharKey(line);
    //   // this->handleNewNode(key, line);
    // }
  }
}
