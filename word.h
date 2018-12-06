#ifndef WORD_H
#define WORD_H
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "list.h"
using namespace std;

class Word
{
 public:
  Word();
  ~Word();
  void insert(string word, string file);
  string get_word();
  void head_next();
  int get_list_count();
  string get_list_file();
  bool is_null();
  bool is_list_empty();
  void list_head_next();
 private:
  struct dnode{
    string info;
    dnode *next;
    dnode *prev;
    list wordlist;
  };
  dnode *first;
};

#endif

