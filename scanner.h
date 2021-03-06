#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

#include <istream>

using namespace std;

class Scanner {
  public:
    Scanner();

    Token* readString(istream *input, int lineNumber);

  private:
    string keywords[14] = {"begin", "end", "loop", "while", "void", "exit", "getter", "outter", "main", "if", "then", "assign", "data", "proc"};
    // char operatorsDelimiters[20] = {'=', '=>', '=<', '==', ':', ':=', '+', '-', '*', '/', '%', '.', '(', ')', ',', '{', '}', ';', '[', ']'};
    string operatorsDelimiters[20] = {"=", "=>", "=<", "==", ":", ":=", "+", "-", "*", "/", "%", ".", "(", ")", ",", "{", "}", ";", "[", "]"};
    string comment = "$$";

    Token token;
    void lookupToken();
    string isOperatorDelimiter(char inputChar);
    string isReservedWord(string input);

    bool isEmptyString(string input);
};

#endif