/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>
using namespace std;

void printList(Node* n){
  while(n!=nullptr){
    cout << n->value << " ";
    n=n->next;
  }
}

int main(int argc, char* argv[])
{
  Node* n3=new Node(3,nullptr);
  Node* n2=new Node(2,n3);
  Node* n1=new Node(1,n2);
  Node* evens=nullptr;
  Node* odds=nullptr;

  split(n1,evens,odds);
  printList(n1);
  printList(evens);
  printList(odds);

  delete n1;
  delete n2;
  delete n3;
}

