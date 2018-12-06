#include "list.h"

list::list() {first=0;}

list::~list() {
  dnode*n=first;
  while(n){
    dnode *garbage=n;
    n=n->next;
    delete garbage;
  }
}

void list::append(string file){
  if (first==0){
    dnode *d=new dnode;
    d->info.set_filename(file);
    d->info.set_count(1);
    d->next=NULL;
    d->prev=NULL;
    first=d;
    return;
  }
    dnode *n=first;
    while(n!=NULL){
      if (n->info.filename()==file){
        int counter=n->info.count();
        n->info.set_count(counter+1);
        counter++;
        if(n->prev==NULL)
          return;
        if(n->next==NULL){
          n->prev->next=NULL;
        }
        else{
          n->prev->next=n->next;
          n->next->prev=n->prev;
        }
        dnode*q=first;

        while(q){
          if((q->info.count())>counter){
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
          n->next=NULL;
          n->prev=q;
          q->next=n;
          return;
        }
        if(q->prev==NULL){
          n->prev=NULL;
          n->next=q;
          q->prev=n;
          first=n;
          return;
        }
else{
          q->prev->next=n;
          n->prev=q->prev;
          n->next=q;
          q->prev=n;
          return;
        }
      }
      n=n->next;
    }
    if(n==NULL){
    dnode *d=new dnode;
    d->info.set_filename(file);
    d->info.set_count(1);
    d->next=NULL;
    n=first;
    while(n->next){
      n=n->next;
    }
    n->next=d;
    d->prev=n;
    return;
}
}

int list::print_count(){
  return first->info.count();
}
string list::print_file(){
  return first->info.filename();
}

void list::next(){
  first=first->next;
}

bool list::is_empty(){
  if(first->next==NULL){
    return true;
  }
  else{
    return false;
  }
}

