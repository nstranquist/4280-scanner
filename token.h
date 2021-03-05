#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

struct Token {
  string tokenID;
  Token *tokenInstance;
  int lineNumber;
};

#endif