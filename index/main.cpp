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
  using cont_t = vector<string>;
  // vector<string> words;
  cont_t words;
  transform(istream_iterator<string>(fin), //string s ; fin >> s;
            istream_iterator<string>(), //end of any istream
            //back_insert_iterator<vector<string>>(words), //inserting into container via
            back_inserter<vector<string>>(words),
            normalize);
  fin.close();

  sort(begin(words),
       end(words));

  cont_t::iterator new_end  = unique(begin(words),
         end(words));
  words.erase(new_end, 
              end(words));

  copy(begin(words),
       end(words),
       ostream_iterator<string>(cout, ", "));
  cout << endl << words.size() << endl;
  return 0;
}