#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

using namespace std;

class Scanner {
  public:
    Scanner();

    void readString();

  private:
    Token token;
    void lookupToken();
};

#endif