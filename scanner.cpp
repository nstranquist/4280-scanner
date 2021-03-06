#include "scanner.h"

#include <string>
#include <iostream>
#include <istream>

using namespace std;

Scanner::Scanner() {

}

Token* Scanner::readString(istream *input, int lineNumber) {
  Token *token;
  string line;

  token->lineNumber = lineNumber;
  
  printf("reading character");

  // Read Input from istream
  while (getline(*input, line)) {
    cout << "line: " << line << endl;

    


    if(line == "EOF" || line == "") {
      cout << "end of file" << endl;
      token->tokenInstance = "";
      token->tokenID = "EOF";
      return token;
    }


  }

  token->lineNumber = 1;

  return token;
}

void Scanner::lookupToken() {
  printf("looking up token");
}

// TODO: Could just return the character
string Scanner::isOperatorDelimiter(char inputChar) {
  string input = "" + inputChar;
  // Reference: https://stackoverflow.com/questions/19215027/check-if-element-found-in-array-c#19215059
  
  // check if input character is included in the `operatorsDelimiters` array
  // size_t arraySize = sizeof(this->operatorsDelimiters) / sizeof(char);
  // char *end = this->operatorsDelimiters + arraySize;
  int arrayLength = sizeof(this->operatorsDelimiters) / sizeof(this->operatorsDelimiters[0]);
  for(int i=0; i<arrayLength; i++) {
    cout << "delimiter: " << this->operatorsDelimiters[i] << endl;

    if(this->operatorsDelimiters[i] == input) {
      cout << "matching character!" << endl;
      return this->operatorsDelimiters[i];
    }
  }

  return ""; // NULL
}

string Scanner::isReservedWord(string input) {
  int arrayLength = sizeof(this->keywords) / sizeof(this->keywords[0]);
  for(int i=0; i<arrayLength; i++) {
    cout << "keyword: " << this->keywords[i] << endl;

    if(this->keywords[i] == input) {
      cout << "matching reserved word!" << endl;
      return this->keywords[i];
    }
  }

  return ""; // NULL
}

bool Scanner::isEmptyString(string input) {
  if(input.length() == 0) return true;
  return false;
}