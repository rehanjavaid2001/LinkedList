//Rehan Javaid, rj3dxu, 9/14/2020, List.cpp

#include "List.h"
#include <iostream>
using namespace std;

List::List(){
  head = new ListNode();
  tail = new ListNode();
  count = 0;
}

List::List(const List& source){
 head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;

  // Make a deep copy of the list
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
  }
}

List::~List(){
  makeEmpty();
  delete(head);
  delete(tail);
}

List& List::operator=(const List& source){
if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

    
bool List::isEmpty() const{
  if (count == 0) {
    return true;
  }
  else{
    return false;
  } 
}

void List:: makeEmpty(){
  ListItr l1  = first();
  while ((count != 0) && (l1.isPastEnd() == false)){
    l1.moveForward();
    ListItr l2 = l1.current->previous;
    remove(l2.retrieve());
  }   
}

ListItr List::first(){
  ListItr li(head->next);
  return li;
}

ListItr List::last(){
  ListItr li(tail->previous);
  return li;
}

void List::insertAfter(int x, ListItr position){
  if (position.isPastEnd() != true){
    ListItr l1 = position;
    l1.moveForward();
    position.current -> next = new ListNode();
    l1.current -> previous = position.current -> next;
    position.current->next->previous = position.current;
    position.current->next -> next = l1.current;
    position.current->next->value = x;
  }
  
  else{
    ListItr l1;
    l1 = last();
    l1.current->next = new ListNode();
    l1.current->next->value = x;
    l1.current->next->next = tail;
    tail->previous = l1.current->next;
    tail->previous->previous = l1.current;
  }
  count++;
}

void List::insertBefore(int x, ListItr position){
  if(position.isPastBeginning() != true){
    ListItr l1 = position;
    l1.moveBackward();
    position.current -> previous = new ListNode();
    l1.current -> next = position.current -> previous;
    position.current->previous->next = position.current;
    position.current->previous->previous = l1.current;
    position.current ->previous->value = x;
  }
  else{
    ListItr l1;
    l1 = last();
    l1.current->next = new ListNode();
    l1.current->next->value = x;
    l1.current->next->next = tail;
    tail->previous = l1.current->next;
    tail->previous->previous = l1.current;
  }
  count++;
}

void List::insertAtTail(int x){
  if (count == 0){
    tail->previous = new ListNode();
    tail->previous->value = x;
    tail->previous->next = tail;
    tail->previous->previous = head;
    head->next = tail->previous;
  }
  if (count > 0){
    ListItr l1;
    l1 = last();
    l1.current->next = new ListNode();
    l1.current->next->value = x;
    l1.current->next->next = tail;
    tail->previous = l1.current->next;
    tail->previous->previous = l1.current;
  }
  count++;
}

ListItr List::find(int x){
  if (count == 0){
    ListItr l2(tail);
    return l2;
  }
  ListItr l1 = first();
  while (l1.retrieve() != x){
    l1.moveForward();
    if (l1.isPastEnd() == true){
      ListItr l2(tail);
      return l2;
      break; 
    }
  }
  if (l1.retrieve() == x){
    ListItr l2 = l1;
    return l2;
   }
}

void List::remove(int x){
  if (count == 0){
    isEmpty();
  }
  if (find(x).isPastEnd() != true){
    ListItr l1 = first();
    while (l1.retrieve() != x){
      l1.moveForward();
      if (l1.isPastEnd() == true){
	break;
      }
    }
    if (l1.retrieve() == x){
      l1.moveBackward(); 
      ListItr l2(l1.current->next->next);
      delete(l1.current->next); 
      l1.current -> next = l2.current;
      l2.current-> previous = l1.current;
      count --;
    }
  }
}

int List::size() const{
  return count;
}

void printList(List& source, bool forward){
  if (source.size() == 0 && forward == true){
      cout << "  ";
  }
   if (source.size() == 0 && forward == false){
      cout << "  ";
   }
   if (forward == true && source.size() != 0){
    ListItr l1 = source.first();
    cout << l1.retrieve() << " ";
    l1.moveForward(); 
    while (l1.isPastEnd() == false){
      cout << l1.retrieve() << " ";
      l1.moveForward();
    }
    cout << endl;
  }
   if (forward == false && source.size() != 0){
    ListItr l1 = source.last();
    cout << l1.retrieve() << " ";
    l1.moveBackward(); 
    while (l1.isPastBeginning() == false){
      cout << l1.retrieve() << " ";
       l1.moveBackward();
    }
    cout << endl;
  }
}
