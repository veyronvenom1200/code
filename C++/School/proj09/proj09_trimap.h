#ifndef TRIMAP
#define TRIMAP

#include<string>
using std::string;
#include<iostream>
using std::ostream;
#include<vector>
using std::vector;
#include<initializer_list>
using std::initializer_list;

class Element{
 private:
  string key_;
  size_t index_ = 0;

 public:
  string value_;

  Element()=default; // default constructor
  Element(string k, string v, long i): key_(k),  index_(i), value_(v) {} ; // initializer list

  // void Print_key() {
  //   std::cout << key_ << std::endl;
  // }

  friend class TriMap;
  friend ostream& operator<<(ostream&, const Element&);
};


class TriMap {
private:
  vector<Element> vec_;
  size_t sz_ = 0;

public:
  TriMap() = default;
  TriMap(const Element&); // how would you create constructors for this
  TriMap(initializer_list<Element>); // and this

  size_t size();
  bool insert(string,string);
  bool remove(string);
  Element* find_key(const string&);
  Element* find_value(const string&);
  Element* find_index(size_t);

  friend ostream& operator<<(ostream&, const TriMap&);
};

#endif
