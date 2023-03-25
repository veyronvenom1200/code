/*
 * Author: Nathan Dohm
 * Date: October 30, 2017
 *
 * proj07.cpp is a C++ script that determines the knn classifier
 */

#include<iostream>
using std::cout; using std::endl; using std::ostream;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
#include<utility>
using std::pair;
#include <iomanip>
#include <sstream>
#include <cmath>

#include "proj07_functions.h"

vector<string> split(const string &s, char delim) {

/*
 * splits the function based on the delim
 */

  vector<string> v;
  string word = "";
  for (int i = 0; i != s.length() + 1; ++i) {
    if (s[i] == delim or (i == s.length())) {
      v.push_back(word);
      word = "";
    } else {
      word+=s[i];
    }
  }
  return v;
}

void read_data(map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf) {

/*
 * creates map m
 */

  string line;
  while (getline(inf, line)) {
    auto v = split(line, ',');
    vector<double> d;
    string type = v[v.size() - 1]; // variable for map value
    v.erase(v.begin() + v.size() - 1);
    for (auto &a : v) {
      // cout << a << endl;
      d.push_back(std::stod(a));
    }
    // cout << endl;
    m.insert(std::pair<vector<double>, string>(d, type));
  }
  auto pos = m.begin();
  string s = pair_to_string(*pos);
}

string pair_to_string(const pair<vector<double>, string> &p) {

/*
 * prints out each pair to a precision of three decimal places
 */

  string s;
  std::streamsize ss = std::cout.precision(); // used to reset ostream precision
  cout << std::fixed << std::setprecision(3);
  for (auto &a : std::get<0>(p)) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(3) << a;
    s += stream.str() + ' ';
  }
  cout << std::setprecision(ss);
  s += p.second;
  return s;
}

void print_map(const map<vector<double>, string> &m, std::ostream &out) {

/*
 * prints map m using the function pair_to_string
 */

  for(map<vector<double>, string>::const_iterator i = m.begin(); i != m.end(); ++i) {
    out << pair_to_string(std::pair<vector<double>, string>(i->first,i->second)) << endl;
  }
}

double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count) {

/*
 * determines the distance between v1 and v2 in order to find the knn
 */

  double d = 0;
  for (int i = 0; i != feature_count + 1; ++i) {
    d += std::pow((v2[i] - v1[i]), 2);
  }
  return std::pow(d, .5);
}

map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k) {

/*
 * creates a new map of the k_neighbors using the function distance
 */

  vector<double> distance_vector, minimum;
  vector<vector<double>> new_v;
  vector<string> type;
  map<vector<double>, string> new_m;
  for(map<vector<double>, string>::const_iterator it = m.begin(); it != m.end(); ++it) {
    if (it->first != test) {
      new_v.push_back(it->first); // used for vector keys in new_m
      type.push_back(it->second); // used for vector values in new_m
      double d = distance(test, it->first, k);
      distance_vector.push_back(d);
    }
  }

  for (int i = 0; i != k; ++i) {
    double min = *std::min_element(distance_vector.begin(), distance_vector.end());
    minimum.push_back(min);
    distance_vector.erase(std::remove(distance_vector.begin(), distance_vector.end(), min), distance_vector.end()); // removes the min values
  }

  //minimum.erase(minimum.begin()); // removes the value that is calculated by comparing test to itself in the map
  for (int j = 0; j != k; ++j) {
    auto index = std::find(minimum.begin(), minimum.end(), minimum[j]);
    new_m.insert(std::pair<vector<double>, string>(new_v[index - minimum.begin()], type[index - minimum.begin()]));
  }
  return new_m;
}

double test_one(const map<vector<double>, string> &m, pair<vector<double>, string> test, int k) {

/*
 * determines the k_neighbor of a single pair, and returns the percentage of correct
 * within the new map
 */

  double l = 0;
  map<vector<double>, string> new_m = k_neighbors(m, test.first, k);
  for (map<vector<double>, string>::const_iterator i = new_m.begin(); i != new_m.end(); ++i) {
    if (i->second == test.second) {
      ++l;
    }
  }
  return l/k;
}

double test_all(const map<vector<double>, string> &m, int k) {

/*
 * similar to function test_one, but calculates the percentage for the whole map
 */

  double percent = 0;
  for (map<vector<double>, string>::const_iterator i = m.begin(); i != m.end(); ++i) {
    percent += test_one(m, std::pair<vector<double>, string>(i->first,i->second), k);
  }
  return percent/k;
}


int main (){

  ifstream fin("little.txt");
  map<vector<double>, string> m;
  read_data(m,4,fin);

  //ifstream f("iris.data.txt");
  // read_data(m, 4, f);
  // print_map(m, cout);
  // auto start = m.begin();
  // // auto follow = next(start, 1);
  // //cout << distance(start->first, follow->first, 4) << endl;
  // auto result = k_neighbors(m, start->first, 3);
  // auto pos = result.begin();
  // vector<double> v = pos->first;
  auto start = m.begin();
  double result = test_one(m, *start, 3);
  cout << result << endl;

  // cout << "test: " << pair_to_string(*m.begin() ) << endl;
  // print_map(result, cout);
  // cout << "Accuracy for first: "<<test_one(m, *(m.begin() ), 3) << endl;
  cout << "Accuracy for all: " << test_all(m, 3) << endl;
}
