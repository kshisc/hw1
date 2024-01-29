#include "ulliststr.h"

#include <iostream>
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

void printValues(ULListStr data){
  for(int i=0;i<int(data.size());i++){
    cout << data.get(i) << " ";
  }
  cout << endl;
}

int main(int argc, char* argv[])
{
  ULListStr dat;

  dat.push_back("1"); //empty
  dat.push_back("2"); //more than one item
  dat.pop_front();
  dat.pop_front();
  dat.push_front("2"); //empty
  dat.push_front("1"); //more than one item
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("10");
  dat.push_back("11");
  dat.push_back("12");
  dat.pop_back();

  printValues(dat);
  cout << dat.back() << endl;
  cout<< dat.front() << endl;
  cout << dat.get(0) << " " << dat.get(1) << endl;

  cout << dat.size() << endl;
}
