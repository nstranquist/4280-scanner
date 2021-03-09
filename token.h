#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum tokenIDs {IDENT_tk, NUM_tk, KW_tk, OpDelim_tk }; // 0, 1, 2, 3

// Types in Alphabet: Identifiers, Keywords, Operators/Delimiters, Integers, (not token) Comments

struct Token {
  // string tokenID; // enum TokenID
  tokenIDs tokenID;
  string tokenInstance; // the actual value of the final token
  int lineNumber;
};

#endif