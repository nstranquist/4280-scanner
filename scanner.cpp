#include "scanner.h"
#include "token.h"
#include "table.h"

#include <string>
#include <iostream>
#include <istream>

using namespace std;

const int numRows = 5;
const int numCols = 2;

Scanner::Scanner() {

}

void Scanner::testTable() {
  cout << "row / col / value" << endl;
  // Read from table, printing each row / cols
  for(int row=0; row<numRows; row++) {
    for(int col=0; col<numCols; col++) {
      cout << row << " " << col << " " << table[row][col] << endl;
    }
  }
}

Token* Scanner::getToken(istream *input) {
  Token *token = new Token();

  
  // cout << "line number: " << this->lineNumber << endl;

  token->lineNumber = this->lineNumber;

  char c;
  char nextChar;

  bool tokenComplete = false;

  

  // Read Input from istream
  while (!tokenComplete) {
    input->get(c);

    // cout << c << endl;

    if(this->isEndOfFile) {
      // cout << "end of file. returning null" << endl;
      return NULL;
    }
    else if(input->peek() == EOF) {
      // cout << "next char is eof" << endl;
      tokenComplete = true;
      this->isEndOfFile = true;
      nextChar = NULL;
    }
    else {
      nextChar = input->peek();
    }

    if(this->isCommentActive) {
      if(c == '$') {
        if(nextChar != NULL && nextChar == '$') {
          input->get(c);
          // cout << "--> ending comment block" << endl;
          this->isCommentActive = false;
        }
        else if(nextChar != NULL && nextChar != '$') {
          cout << "SCANNER ERROR: line " << this->lineNumber << ": '$' is not a valid character. Did you mean '$$'?" << endl;
        }
      }
    }
    else if(c == '$') {
      if(nextChar != NULL && nextChar == '$') {
        input->get(c);
        // cout << "--> starting comment block" << endl;
        this->isCommentActive = true;
      }
      else if(nextChar != NULL && nextChar != '$') {
        cout << "SCANNER ERROR: line " << this->lineNumber << ": '$' is not a valid character. Did you mean '$$'?" << endl;
      }
    }
    else if(c == ' ') {
      // cout << "--> is space" << endl;
      if(!this->isTokenEmpty(token))
        tokenComplete = true;
      else {
        // cout << "--> token not empty" << endl;
        cout << token->tokenInstance << endl;
      }
    }
    else if(c == '\n') {
      this->lineNumber = this->lineNumber + 1;
      if(this->isTokenEmpty(token))
        token->lineNumber = this->lineNumber;
      else
        tokenComplete = true;
    }

    // Need to do additional checks
    //  || this->isDoubleOperatorDelimiter(token->tokenInstance + c)
    else if(this->isOperatorDelimiter(c)) {
      // cout << "is operator / delimiter" << endl;
      token->tokenID = OpDelim_tk; // "operator_delimiter"; index 3

      token->tokenInstance = token->tokenInstance + c;

      if(nextChar != NULL) {
        string testWord = token->tokenInstance + nextChar;
        if(this->isDoubleOperatorDelimiter(testWord)) {
          // cout << "--> is double op/delim" << endl;
          input->get(c);
          token->tokenInstance = token->tokenInstance + c;
        }
      }

      tokenComplete = true;
    }

    else if(this->isNumeric(c)){
      // cout << "is numeric" << endl;

      token->tokenInstance = token->tokenInstance + c;

      int tokenLength = token->tokenInstance.length();
      // cout << "numeric token length: " << tokenLength << endl;

      if(tokenLength <= 1)
        token->tokenID = NUM_tk; // "numeric"; index 1

      if(!this->isNumeric(nextChar)) {
        tokenComplete = true;
      }
    }
    else if(this->isAlpha(c)) {
      // cout << "is alphanumeric" << endl;

      token->tokenInstance = token->tokenInstance + c;
      
      int tokenLength = token->tokenInstance.length();
      // cout << "alpha token length: " << tokenLength << endl;

      if(tokenLength <= 1)
        token->tokenID = IDENT_tk; // "alpha"; index 0

      if(!this->isAlpha(nextChar)) {
        tokenComplete = true;
      }
    }

    // TODO: Identifiers

    else {
      // cout << "reached end of file. character is other. would throw error" << endl;
      // cout << "--> SCANNER ERROR: would throw error, unrecognized token: ";
      cout << c << endl;
      if(!this->isTokenEmpty(token))
        tokenComplete = true;
    }
  }

  if(token->tokenID == IDENT_tk) { // "alpha"
    // check for reserved words
    if(this->isReservedWord(token->tokenInstance)) {
      // cout << "is reserved word. returning" << endl;
      token->tokenID = KW_tk; // "reserved"; index 2 (keyword)
      return token;
    }
  }

  return token;
}

void Scanner::lookupToken() {
  printf("looking up token");
}

// TODO: Could just return the character
bool Scanner::isOperatorDelimiter(char inputChar) {
  string input = "";
  input += inputChar;
  // Reference: https://stackoverflow.com/questions/19215027/check-if-element-found-in-array-c#19215059
  
  // check if input character is included in the `operatorsDelimiters` array
  // size_t arraySize = sizeof(this->operatorsDelimiters) / sizeof(char);
  // char *end = this->operatorsDelimiters + arraySize;
  int arrayLength = sizeof(this->singleOperatorsDelimiters) / sizeof(this->singleOperatorsDelimiters[0]);
  for(int i=0; i<arrayLength; i++) {
    // cout << "delimiter: " << this->singleOperatorsDelimiters[i] << endl;

    if(this->singleOperatorsDelimiters[i] == input) {
      // cout << "--> matching op/delim!" << endl;
      return true;
    }
  }

  return false;
}

bool Scanner::isDoubleOperatorDelimiter(string input) {
  int arrayLength = sizeof(this->doubleOperatorsDelimiters) / sizeof(this->doubleOperatorsDelimiters[0]);

  for(int i=0; i<arrayLength; i++) {
    if(this->doubleOperatorsDelimiters[i] == input) {
      // cout << "--> matching double op/delim" << endl;
      return true;
    }
  }

  return false;
}

bool Scanner::isReservedWord(string input) {
  int arrayLength = sizeof(this->keywords) / sizeof(this->keywords[0]);
  for(int i=0; i<arrayLength; i++) {
    // cout << "keyword: " << this->keywords[i] << endl;

    if(this->keywords[i] == input) {
      // cout << "--> matching reserved word!" << endl;
      return true;
    }
  }

  return false;
}

bool Scanner::isNumeric(char inputChar) {
  if(isdigit(inputChar))
    return true;
  return false;
}

bool Scanner::isAlpha(char inputChar) {
  if((inputChar >= 'A' && inputChar <= 'Z') || (inputChar >= 'a' && inputChar <= 'z')) {
    return true;
  }
  else if (inputChar == '_') {
    // cout << "is underscore, counting as alphanumeric" << endl;
    return true;
  }
  return false;
}

bool Scanner::isComment(char inputChar) {
  if(inputChar == '$$') {
    cout << "is a comment character" << endl;
    return true;
  }
  return false;
}

bool Scanner::isEmptyString(string input) {
  if(input.length() == 0) return true;
  return false;
}

bool Scanner::isTokenEmpty(Token *token) {
  if(token->tokenInstance.length() == 0)
    return true;
  return false;
}