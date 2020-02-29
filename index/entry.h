// file: entry.h

#pragma once

#include <set>
#include <ostream>
#include <iomanip>
#include <iterator>

template<typename K, typename V>
class entry;

template<typename K, typename V>
std::ostream& operator << (std::ostream &os, const entry<K,V> &e);

template<typename K, typename V>
class entry {

private:
  K key;
  std::set<V> values;

public:
  entry(K key) : key(key) {}
  virtual ~entry() {}
  void add_value(V value) { values.insert(value); }
  bool operator < (const entry &e) const { return key < e.key; }
  friend std::ostream& operator << <K, V>(std::ostream &os, const entry<K,V> &e);
};

template<typename K, typename V>
std::ostream& operator << (std::ostream &os, const entry<K,V> &e) {
  os << std::setw(15) << e.key << " (" << e.values.size() << "): ";
  copy(e.values.begin(), e.values.end(), std::ostream_iterator<V>(os, ","));
  return os;
}