#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>

#include "utils.h"
#include "entry.h"

using namespace std;

int main(int argc , char * argv[]) {
  ifstream fin;
  open_stream(argc, argv, fin);
  vector<string> words;
  transform(istream_iterator<string>(fin), //string s ; fin >> s;
            istream_iterator<string>(), //end of any istream
            back_insert_iterator<vector<string>>(words), //inserting into container via iterator
            normalize);
  fin.close();

  copy(begin(words),
       end(words),
       ostream_iterator<string>(cout, ", "));
  cout << endl << words.size() << endl;
  return 0;
}