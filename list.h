#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include "itemtype.h"

using namespace std;

class list
{
 public:
  list();
  ~list();
  void append(string file);
  int print_count();
  string print_file();
  void next();
  bool is_empty();
private:
  struct dnode{
    itemtype info;
    dnode *next;
    dnode *prev;
  };
  dnode *first;
};
#endif

