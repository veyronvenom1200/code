/*
 * Author: Nathan Dohm
 * Date: October 15, 2017
 *
 * proj05.cpp is a C++ script that is capable of creating a Beaufort cipher, as
 * well as a Vigenere cipher, which are both Caesar ciphers based on letters of
 * a keyword.
 */

#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;
#include <cmath>
using std::abs;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

string rotate_left(int i, string& normal) {

  /*
   * Creates a left-rotated alphabet, which both ciphers use to get the correct
   * for the encrypted letters.
   */

  if (i < 0) {
    return normal;
  }
  //int index = normal.length() % i;
  string append_val = normal.substr(0, i);
  normal.append(append_val);
  normal.erase(0, i);
  return normal;
}

char beaufort_letter(char plain, char key) {

  /*
   * Uses the left-rotated alphabet to encrypt the plain text char using a key
   * char. The Beaufort letter creates an encrytped letter by rotating the
   * alphabet by a certain index, finds the index of that letter in the rotated
   * alphabet, and then uses that index to encrypt the plain text in the original
   * alphabet.
   */

  if (isalpha(plain) == false or isalpha(key) == false) {
    return plain;
  }
  string alph = alphabet;
  int index = plain - 'a';
  alph = rotate_left(index, alph);
  auto new_char = alph.find(key);
  return alphabet[new_char];
}

char vigenere_letter(char plain, char key) {

  /*
   * Uses the left-rotated alphabet to encrypt the plain text char using a key
   * char. The Vigenere letter creates an encrytped letter by rotating the
   * alphabet by a certain index, finds the index of that letter in the normal
   * alphabet, and then uses that index to encrypt the plain text in the rotated
   * alphabet.
   */

  if (isalpha(plain) == false or isalpha(key) == false) {
    return plain;
  }
  string alph = alphabet;
  int index = plain - 'a';
  alph = rotate_left(index, alph);
  auto new_char = alphabet.find(key);
  return alph[new_char];
}

string encode_beaufort(string normal, string key) {
  string new_str = "";
  while (key.length() < normal.length() + 1) {
    key += key;
  }

  // The following code block was based on code found at http://www.cplusplus.com/forum/beginner/148876/
  for (string::iterator a = normal.begin(); a != normal.end(); a++) { //iterates over the original string in order to find non-alphabetic chars and remove them from the string
    if(!isalpha(normal.at(a - normal.begin())))
    {
        normal.erase(a);
        a--;
      }
    }

  for (int i = 0; i != normal.length(); ++i) {
    new_str += beaufort_letter(normal[i], key[i]);
  }
  return new_str;
}

string encode_vigenere(string normal, string key) {
  string new_str = "";
  while (key.length() < normal.length() + 1) {
    key += key;
  }

  // The following code block was based on code at: http://www.cplusplus.com/forum/beginner/148876/
  for (string::iterator a = normal.begin(); a != normal.end(); a++) { //iterates over the original string in order to find non-alphabetic chars and remove them from the string
    if(!isalpha(normal.at(a - normal.begin())))
    {
        normal.erase(a);
        a--;
      }
    }

  for (int i = 0; i != normal.length(); ++i) {
    new_str += vigenere_letter(normal[i], key[i]);
  }
  return new_str;
}

int main (){

  int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }

  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }

  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
} // of main
