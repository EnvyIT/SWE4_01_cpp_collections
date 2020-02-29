#include <fstream>
#include <set>
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
  // vector<string> words;
  using cont_t = set<string>; // O(n*log(n)) which has a red-black tree as underlying impl.
  cont_t words;
  transform(istream_iterator<string>(fin), //string s ; fin >> s;
            istream_iterator<string>(), //end of any istream
            //back_insert_iterator<vector<string>>(words), //inserting into container via
            // back_inserter(words),
           inserter(words, begin(words)),
            normalize);
  fin.close();

  /*sort(begin(words),
       end(words));

  cont_t::iterator new_end  = unique(begin(words),
         end(words));
  words.erase(new_end, 
              end(words));*/

  copy(begin(words),
       end(words),
       ostream_iterator<string>(cout, ", "));
  cout << endl << words.size() << endl;
  return 0;
}