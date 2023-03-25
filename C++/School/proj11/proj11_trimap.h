/*
 * Author: Nathan Dohm
 * Date: 12/05/17
 * proj11_trimap.h is a C++ header that creates a new STL-like data structure
 * in which you are able to search the structure (similar to a map) for either
 * the key, index, or value (unlike a map, which is limited to just the key).
 */

#ifndef SINGLELINK_H
#define SINGLELINK_H

#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
#include <vector>
using std::string;

// forward declaration so we can make Element a friend of TriMap
template<typename K, typename V>
class TriMap;

// private Element, friend of TriMap class
template <typename K, typename V>
class Element{

private:
  K key_;
  size_t index_ = 0;
  Element *next_ = nullptr;

public:
  V value_;

  Element() = default;
  Element(K key, V val, size_t i) : key_(key),index_(i), next_(nullptr), value_(val) {};

  // *defined* in the class, makes templating easier.
  friend ostream& operator<<(ostream& out, Element& e){
    out << e.key_ << ":" << e.value_ << ":" << e.index_;
    return out;
  }
  friend class TriMap<K,V>;
};


template<typename K, typename V>
class TriMap{

private:
  Element<K,V> *head_ = nullptr;
  Element<K,V> *tail_ = nullptr;
  size_t size_ = 0;

  // a private function, used by operator<<
  void print_list(ostream& out);

public:
  TriMap() = default;
  TriMap(K, V);
  TriMap(const TriMap&);
  TriMap& operator=(TriMap);
  ~TriMap();
  long size();
  bool insert(K,V);
  bool remove(K);
  Element<K,V>* find_key(K);
  Element<K,V>* find_value(V);
  Element<K,V>* find_index(size_t);

  // *defined* in the class, makes templating easier.
  // uses private method print_list
  // you can remove print_list and just do it here if you
  // prefer. I won't test print_list
  friend ostream& operator<<(ostream& out, TriMap<K,V>& sl){
    sl.print_list(out);
    return out;
  };
};

template<typename K, typename V>
TriMap<K,V>::TriMap(K key, V value) {
  Element<K,V> *ptr = new Element<K,V>(key, value, size_);
  head_ = ptr;
  tail_ = ptr;
};

/*
bit of work. we need to remember a pointer that walks
down the list to copy, as tail_ walks down the new list.
Make a new node (copy the current node of the list we are copying),
update the tail_->next_ to point to the new node, update tail_ to new node
 */
template<typename K, typename V>
TriMap<K,V>::TriMap(const TriMap& tm){
  if (tm.head_ == nullptr){
    head_ = nullptr;
    tail_ = nullptr;
    }
    else{
        head_ = new Element<K,V>(tm.head_->key_, tm.head_->value_, size_);
        tail_ = head_;
        Element<K,V>* tm_ptr = tm.head_->next_;
        Element<K,V>* new_node;
        while (tm_ptr != nullptr){
            new_node = new Element<K,V>(tm_ptr->key_, tm_ptr->value_, size_);
            tail_->next_ = new_node;
            tm_ptr = tm_ptr->next_;
            tail_ = new_node;
        }
    }
}

template<typename K, typename V>
TriMap<K,V>& TriMap<K,V>::operator=(TriMap tm){
    swap(head_, tm.head_);
    swap(tail_, tm.tail_);
    return *this;
}


// walk down the list using head_ , keeping a trailer pointer called to_del
// delete what to_del points to
// move head_ and to_del to the next node.
template<typename K, typename V>
TriMap<K,V>::~TriMap(){
    Element<K,V>* to_del = head_;
    while (to_del != nullptr){
        head_ = head_->next_;
        delete to_del;
        to_del = head_;
  }
  head_ = nullptr;
  tail_ = nullptr;
}

template<typename K, typename V>
long TriMap<K,V>::size(){

}

template<typename K, typename V>
bool TriMap<K,V>::insert(K key, V value){

    Element<K,V>* e = new Element<K,V>(key, value, size_);

    auto curr = head_;
    if(head_ == nullptr) {
        tail_ = e;
        head_ = e;
        ++size_;
    } else if (tail_->key_ < key) {
        tail_->next_ = e;
        tail_ = e;
        ++size_;
    } else if (head_->key_ > key) {
        e->next_ = head_; // adds new node to the head
        head_ = e;
        ++size_;
    } else {
        Element<K,V>* d = new Element<K,V>;
        for (d = head_; d->key_ <= key; d = d->next_) { // in a perfect world, this would properly insert the element pointer into the linked list, but it places one past
            if (d->key_== key) {
                return false;
            }
        }
        e->next_ = d->next_;
        d->next_ = e;
    }
    return true;
}

template<typename K, typename V>
bool TriMap<K,V>::remove(K key){
  // again, what are all the cases!!!
  // also, if you delete a node, the indicies of all
  // nodes with a higher index have that index reduced by one

    return true;
}

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_key(K key){
  // no binary search, just linear search
    Element<K,V>* e = new Element<K,V>;
    for (e = head_; e != nullptr; e = e->next_) {
        if (e->key_ == key) {
            return e;
        }
    }
    return nullptr;
}

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_value(V val){
    Element<K,V>* e = new Element<K,V>;
    for (e = head_; e != nullptr; e = e->next_) {
        if (e->value_ == val) {
            return e;
        }
    }
    return nullptr;

}

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_index(size_t i){
    Element<K,V>* e = new Element<K,V>;
    for (e = head_; e != nullptr; e = e->next_) {
        if (e->index_ == i) {
            return e;
        }
    }
    return nullptr;
}

template<typename K, typename V>
void TriMap<K,V>::print_list(ostream &out){
    ostringstream oss;
    Element<K,V> *ptr;
    for(ptr = head_; ptr != nullptr; ptr = ptr->next_)
    oss << *ptr << ", ";
    string s = oss.str();
    out << s.substr(0,s.size()-2);

};


#endif
