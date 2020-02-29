// file: utils.cpp

#include "utils.h"

#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

// auxiliary functions
// isalpha does not work for Umlauts etc.
// convert interfaces
// STL is strict about interfaces
bool is_punct(char ch) { return static_cast<bool>(ispunct(ch)); }
bool is_digit(char ch) { return static_cast<bool>(isdigit(ch)); }
bool is_alpha(char ch) { return static_cast<bool>(isalpha(ch)); }

char to_lower(char ch) { return static_cast<char>(tolower(ch)); }

string normalize(string word) {
  string::iterator new_end;
  // e.g. 'H3ll?o'
  new_end = remove_if(word.begin(), word.end(), is_punct); // copies non-punct forward
  // -> 'H3llo <new_end> o'
  new_end = remove_if(word.begin(), new_end, is_digit); // moves non-digits forward
  // -> 'Hllo <new_end> oo'
  word.erase(new_end, word.end()); // container must remove elements because iterator cannot delete them
  // -> 'Hllo'
  transform(word.begin(), word.end(), word.begin(), to_lower); //from begin to end and write result at begin of word.begin()
  // -> 'hllo'
  return word;
}

void open_stream(int argc, char *argv[], ifstream &fin) {
  if (argc < 2) {
    cerr << "ERROR: missing input file name" << endl;
    cerr << "usage: " << argv[0] << " <filename>" << endl;
    exit(1);
  }
  // NOTE: ifstream fin(argv[0]) would close file on return (automatic variable)
  fin.open(argv[1]);
  if (fin.fail()) {
    cerr << "ERRO: file " << argv[1] << " not found" << endl;
    exit(2);
  }
  // NOTE: fin returned in reference argument
}