#include <iostream>

#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const string& val){
  if(tail_==NULL){ //empty list
    Item* i=new Item();
    head_=i;
    tail_=i;
  }
  else if(tail_->last==ARRSIZE){ //last item of array reached
    Item* i=new Item();
    tail_->next=i;
    i->prev=tail_;
    tail_=i;
  }
  
  //add to back
  tail_->val[tail_->last]=val;
  tail_->last=tail_->last + 1;
  size_++;
}

void ULListStr::pop_back(){
  if(tail_==NULL){ //empty list before
    return;
  }

  tail_->last=tail_->last - 1;
  size_--;

  if((tail_->first) == (tail_->last)){ //empty array
    Item* temp=tail_;

    if(size_==0){ //empty list after
      head_=NULL;
      tail_=NULL;
    }
    else{
      tail_=tail_->prev;
    }
    delete temp;
  }
}

void ULListStr::push_front(const string& val){
  if(head_==NULL){ //empty list
    Item* i=new Item();
    head_=i;
    tail_=i;
  }
  else if(head_->first==0){ //first item of array filled
    Item* i=new Item();
    head_->prev=i;
    i->next=head_;
    head_=i;
  }
  
  //add to front
  if((head_->last) == (head_->first)){ //empty array
    head_->first=ARRSIZE;
    head_->last=ARRSIZE;
  }
  head_->first=head_->first - 1;
  head_->val[head_->first]=val;
  size_++;
}

void ULListStr::pop_front(){
  if(head_==NULL){ //empty list before
    return;
  }

  head_->first=head_->first + 1;
  size_--;

  if((head_->first) == (head_->last)){ //empty array
    Item* temp=head_;

    if(size_==0){ //empty list after
      head_=NULL;
      tail_=NULL;
    }
    else{
      head_=head_->next;
    }
    delete temp;
  }
}

string const & ULListStr::back() const{
  int i=(tail_->last)-1;
  return (tail_->val[i]);
}

string const & ULListStr::front() const{
  int i=head_->first;
  return (head_->val[i]);
}

string* ULListStr::getValAtLoc(size_t loc) const{
  Item* curr=head_;
  size_t sum=0;
  while(curr!=NULL){
    size_t i=curr->first;
    while(i < curr->last){
      if(sum==loc){
        return &(curr->val[i]);
      }
      i++;
      sum++;
    }
    curr=curr->next;
  }
  return NULL;
}
//


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
