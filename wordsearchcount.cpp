#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "word.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
  DIR *dp;
  struct dirent *dirp;
  if((dp  = opendir(dir.c_str())) == NULL) {
    cout << "Error(" << errno << ") opening " << dir << endl;
    return errno;
  }

  while ((dirp = readdir(dp)) != NULL) {
    files.push_back(string(dirp->d_name));
  }
  closedir(dp);
  return 0;
}

int main(int argc, char* argv[]){
  string dir; //                                                               \              

  vector<string> files = vector<string>();

  if (argc < 2)
    {
      cout << "No Directory specified; Exiting ..." << endl;
      return(-1);
    }
  dir = string(argv[1]);
  if (getdir(dir,files)!=0)
    {
      cout << "Error opening " << dir << "; Exiting ..." << endl;
      return(-2);
    }
  string word;
  Word text;
  string slash("/");
  for (unsigned int i = 0;i < files.size();i++) {
    if(files[i][0]=='.')continue; //skip hidden files                          \              

    ifstream fin((string(argv[1])+slash+files[i]).c_str()); //open using absolu\              
te path
  while(true){
    fin>>word;
    if (fin.eof()) { break; }
    else {
      text.insert(word,files[i]);
    }
  }
  fin.close();
  }
  string input;
  int threshold;
  cout<<"Enter word:"<<endl;
  cin>>input;
  cout<<"Enter threshold:"<<endl;
  cin>>threshold;
  while((text.get_word())!=input){
    if(text.is_null()){
      cout<<"Word not found"<<endl;
      break;
    }
    text.head_next();
  }
  while((text.get_list_count())>=threshold){
    cout<<"File: "<<text.get_list_file()<<"; Count: "<<text.get_list_count()<<endl;
    if(text.is_list_empty()==true){
      break;
    }
    text.list_head_next();
  }
}
