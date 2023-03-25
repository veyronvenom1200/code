#include <iostream>
#include <string>
#include <map>


// let's assume I got the includes correct!
template <typename T>
class MyClass{
public:
  std::map<long,T> m_;
  long l_;

  MyClass(long l=100):l_(l), m_({}) {} ;
  long m1(T);
  T m2(long);
  long m3();
};

template<typename T>
long MyClass<T>::m1(T d){
  long result = l_;
  m_[l_] = d;
  l_++;
  return result;
}

template<typename T>
T MyClass<T>::m2(long l){
  if (m_.count(l) == 0)
    return T();
  else
    return m_[l];
}

template<typename T>
long MyClass<T>::m3(){
  std::pair<long,T> v(0,T());
  for (auto e : m_){
    if (e.second > v.second)
      v = e;
  }
  return v.first;
}

int main (){
  MyClass<long> mc_l;
  mc_l.m1(10);
  mc_l.m1(20);
  auto i1 = mc_l.m1(30);
  std::cout << i1 << std::endl;          // Line 1
  std::cout << mc_l.m2(i1) << std::endl; // Line 2
  std::cout << mc_l.m2(50) << std::endl; // Line 3

  MyClass<std::string> mc_s(1000);
  mc_s.m1("joe");
  mc_s.m1("bill");
  auto i2 = mc_s.m1("fred");
  std::cout << i2 << std::endl;           // Line 4
  std::cout << mc_s.m3() << std::endl;    // Line 5
}
