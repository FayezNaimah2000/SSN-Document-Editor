#include <cstdio>
#include <ctime>
#include "DLL.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
  clock_t start, end;
  double duration;
  start = clock();

  DLL myList;
  string r = "r";
  string de = "d";
  string i = "i";
  int retrieveCount = 0;
  int insertCount = 0;
  int deleteCount = 0;
  int itemNumber = 0;
  int size =0;
  string file = argv[1];
  string command; 
  string b; 
  string c; 
  string d;
  
  fstream input(argv[1]); 
  while (!input.eof()){
    input >> command >> b >> c >> d;
    string name = c + d;
    if ((i.compare(command) == 0)){
      myList.insert(b, name, insertCount);
    } 
    if ((de.compare(command) == 0)){
      myList.remove(b, deleteCount);
    } 
    if ((r.compare(command) == 0)){
      if (myList.search(b) == -1){
        retrieveCount = retrieveCount;
      }
      else {
        retrieveCount = retrieveCount +1;
      }
    } 
  }
  input.close();
  //myList.display();
  itemNumber = insertCount - deleteCount;
  size = insertCount - deleteCount;
  cout << "The number of Valid Insertion: " << insertCount << endl;
  cout << "The number of Valid Deletion: " << deleteCount << endl;
  cout << "The number of Valid Retrieval: " << retrieveCount << endl;
  cout << "Item numbers in the array: " << itemNumber << endl;
  cout << "Array size is " << size << endl; 
  end = clock();
  duration = (end - start) / (double)CLOCKS_PER_SEC;
  cout << "elapsed time: " << duration << '\n';  
}
