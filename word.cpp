#include "word.h"
Word::Word(){
  first=0;
}

Word::~Word(){
  dnode*n=first;
  while(n){
    dnode *garbage=n;
    n=n->next;
    delete garbage;
  }
}

void Word::insert(string word, string file){
  if (first==0){
    dnode *d=new dnode;
    d->info=word;
    d->wordlist.append(file);
    d->next=NULL;
    d->prev=NULL;
    first=d;
    return;
  }
  dnode *n=first;
  while(n!=NULL){
    if((n->info)==word){
      n->wordlist.append(file);
      return;
    }
    n=n->next;
  }
  if(n==NULL){
    dnode *q=first;
    dnode *d=new dnode;
    d->info=word;
    d->wordlist.append(file);
    while(q){
      if((q->info).compare(word)<0){
      q=q->next;
    }
    else{
      break;
    }
    }
    if(q==NULL){
      q=first;
      while(q->next){
        q=q->next;
        }
      d->next=NULL;
      d->prev=q;
      q->next=d;
      return;
      }
    if(q->prev==NULL){
      d->prev=NULL;
      d->next=q;
      q->prev=d;
      first=d;
      return;
      }
    else{
      q->prev->next=d;
      d->prev=q->prev;
      d->next=q;
      q->prev=d;
      return;
      }
  }
}
string Word::get_word(){
  return first->info;
}

void Word::head_next(){
  first=first->next;
}

int Word::get_list_count(){
  return first->wordlist.print_count();
}

string Word::get_list_file(){
  return first->wordlist.print_file();
}

bool Word::is_null(){
  if (first==NULL)
    return true;
  else{
    return false;
  }
}

void Word::list_head_next(){
  first->wordlist.next();
}

bool Word::is_list_empty(){
  return first->wordlist.is_empty();
}



