#include <fstream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <iomanip>

#include "utils.h"

using namespace std;

using entries_t = map<string, set<int>>;

int main(int argc, char* argv[]) {
  ifstream fin;
  open_stream(argc, argv, fin);
  string line;
  int cur_line_no = 0;
  entries_t words;

  while (fin.good()) {
    cur_line_no++;
    getline(fin, line);
    istringstream line_stream(line);
    for_each(istream_iterator<string>(line_stream),
             istream_iterator<string>(),
             [cur_line_no, &words](string word)
             {
               words[normalize(word)].insert(cur_line_no);
             });
  }
  fin.close();


  for(const auto &entry : words) {
    cout << setw(15) << entry.first
      << '(' << entry.second.size() << ") :";
    copy(begin(entry.second), 
         end(entry.second), 
         ostream_iterator<int>(cout, ", "));
    cout << endl;
  }
  cout << endl << words.size() << endl;
  return 0;
}