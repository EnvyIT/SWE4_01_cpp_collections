#include <fstream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <sstream>

#include "utils.h"
#include "entry.h"

using namespace std;

using entry_t = entry<string, int>;
using entries_t = set<entry_t>;

static entries_t words;
static int cur_line_no = 0;

static void add_word(string word) {
  entry_t e{ normalize(word) };
  pair<entries_t::const_iterator, bool> result_pair = words.insert(e);
  const_cast<entry_t&>(*result_pair.first).add_value(cur_line_no);
}

int main(int argc, char* argv[]) {
  ifstream fin;
  open_stream(argc, argv, fin);
  string line;
  while (fin.good()) {
    cur_line_no++;
    getline(fin, line);
    istringstream line_stream(line);
    for_each(istream_iterator<string>(line_stream),
             istream_iterator<string>(),
             add_word);
  }
  fin.close();

  copy(begin(words),
       end(words),
       ostream_iterator<entry_t>(cout, "\n"));
  cout << endl << words.size() << endl;
  return 0;
}