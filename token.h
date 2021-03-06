#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

// enum tokenID {_tk, _tk, etc.};
// string tokenNames[] = {"Identifier", "Number", "Keyword", etc};

struct Token {
  string tokenID; // enum TokenID
  string tokenInstance; // the actual value of the final token
  int lineNumber;
};

#endif