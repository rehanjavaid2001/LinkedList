//Rehan Javaid, rj3dxu, 9/14/2020, ListItr.cpp

#include "ListItr.h"
#include <iostream>
using namespace std; 

ListItr::ListItr(){
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode; 
}

bool ListItr::isPastEnd() const{
  if ((current->next) == NULL) {
    return true;
  }
  else{
    return false;
  }
}

bool ListItr::isPastBeginning() const{
  if ((current->previous) == NULL) {
    return true;
  }
  else{
    return false;
  }
}

void ListItr::moveForward(){
  if (isPastEnd() != true){
    current = current -> next;
  }
}

void ListItr::moveBackward(){
  if (isPastBeginning() != true){
    current = current -> previous;
  }
}

int ListItr::retrieve() const{
  int x;
  if (isPastEnd() == false && isPastBeginning() == false){
    x = current -> value;
    return x;
  }
}


