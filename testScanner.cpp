#include "scanner.h"

#include <iostream>
#include <istream>
#include <fstream>

using namespace std;

// void testScanner(istream *input);

// int argc, char *argv[]
void testScanner(istream *input) {
  Scanner scanner;

  string delimiterComma = ",";
  string delimiterSpace = " ";
  string delimiterTab = "\t";

  // Instructions:
  // ask the scanner for one token at a time,
  // and display the token to the screen, one per line,
  // including information (descriptive) on what token class, token instance, and token line it is

  // Pseudo-code:
  // while token (token-scanner() != eofTk())
    // print descriptive token followed by token instance or nothing if null followed by line number followed by '\n'

  // -------------------------------------------------------------------------------------------------------------------

  Token *token;

  while(token = scanner.getToken(input)) {
    // cout << "\ntoken:" << endl;
    if(token)
      cout << "\nline " << token->lineNumber << ": " << token->tokenInstance << "\tid: " << token->tokenID << "\n" << endl;
    // cout << "instance: " << token->tokenInstance << endl;
    // cout << "id: " << token->tokenID << endl;
  }

    // needs to separate by character


    // while (new character in the line)

    
    // token = scanner.readString(input, lineNumber);
    // cout << "token ID: " << token->tokenID;

    // lineNumber++;

    // if(line == "EOF" || line == "") {
    //   cout << "end of file" << endl;
    //   // break;
    // }
}
