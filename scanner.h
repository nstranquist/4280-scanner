#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

#include <istream>

using namespace std;

class Scanner {
  public:
    Scanner();

    Token* getToken(istream *input);

    void testTable();

    string tokenNames[4] = { "Identifier", "Numeric", "Keyword", "Operator_Delimiter" }; // to match up with the enum values

  private:
    int lineNumber = 1;
    bool isCommentActive = false;
    bool isEndOfFile = false;
    string keywords[14] = {"begin", "end", "loop", "while", "void", "exit", "getter", "outter", "main", "if", "then", "assign", "data", "proc"};
    string singleOperatorsDelimiters[17] = {"=", ":", ":=", "+", "-", "*", "/", "%", ".", "(", ")", ",", "{", "}", ";", "[", "]"};
    string doubleOperatorsDelimiters[4] = {"=>", "=<", "==", ":="};
    string comment = "$$";

    Token token;
    void lookupToken();
    bool isOperatorDelimiter(char inputChar);
    bool isDoubleOperatorDelimiter(string input);
    bool isNumeric(char inputChar);
    bool isComment(char inputChar);
    bool isAlpha(char inputChar);
    bool isReservedWord(string input);
    bool isTokenEmpty(Token *token);
    bool isEmptyString(string input);
};

#endif