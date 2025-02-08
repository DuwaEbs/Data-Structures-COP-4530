#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "IntDList.hpp"

using namespace std;

IntDLList::IntDLList(){
    head = new IntDLLNode;
    tail = new IntDLLNode;

    head->next = tail;
    tail->prev = head;

    head->prev = nullptr;
    tail->next = nullptr;
}

IntDLList::~IntDLList(){
    while(!empty()){
        deleteFromHead();
    }
    delete head;
    delete tail;
}

bool IntDLList::empty() const{
    return(head->next == tail); //if the head points to the tail, there are no nodes in the list other than the sentinels
}


void IntDLList::add(IntDLLNode* oldNode, int n){
    
    IntDLLNode* newNode = new IntDLLNode; //allocate space for a new node in the list
    newNode->info = n;
    newNode->next = oldNode;
    newNode->prev = oldNode->prev;
    
    oldNode->prev->next = newNode;
    oldNode->prev = newNode;
    
}
void IntDLList::addToHead(int n){
    add(head->next, n);   
}
void IntDLList::addToTail(int n){
    add(tail, n);
}

bool IntDLList::isInList(int n) const{

    IntDLLNode* current = head->next;
    while(current != tail && current -> info != n) //traverse the list to find target node
        {
            current = current -> next;
        }
    if(current!=tail){
        return true;
    }
    else
        return false;

}

/* removeNode is a helper function which removes a node of choice, it
  */
void IntDLList::removeNode(IntDLLNode* node){ 
    IntDLLNode* before = node->prev;
    IntDLLNode* after = node->next;

    before->next = after;
    after->prev = before;                                   
    delete node;
}

int IntDLList::deleteFromHead(){
    int ret = head->next->info;
    removeNode(head->next);
    return ret;   
}

int IntDLList::deleteFromTail(){
    int ret = tail->prev->info;
    removeNode(tail->prev);
    return ret;
}

void IntDLList::insertInOrder(int n){
    

    if(empty()) //checks if list is empty
    {
        addToHead(n);
        return;
    }
    
    if(n <= head -> next-> info) //inserts val n at the beginning
    {
        addToHead(n);
        return;
    }
    
    IntDLLNode* current = head->next;


    while(current != tail && current-> info < n) //traverse the list to find correct position
    {
        current = current -> next;
    }
  

    add(current, n);

}

void IntDLList::deleteNode(int n){
    
    // if (empty()) //list empty, nothing to delete
    //     return;

    IntDLLNode* current = head->next;

    while(current != tail && current -> info != n) //traverse the list to find target node
        {
            current = current -> next;
        }

    if (current == tail) //if none of the nums in list are target node
        return;

    // if (current == head) //head node is target node
    // {
    //     head = head -> next; //move head forward
    //     if (head != nullptr) //if list was not just one node
    //         head -> prev = nullptr;
    //     else
    //         tail = nullptr;
    // }
    removeNode(current);
}




void IntDLList::printAll() const{

    IntDLLNode* temp = head->next;
    cout << "HEAD <-> ";
    while(temp != tail){
        //cout << temp->info << " ";
        cout << temp->info << " (" << temp << ") <-> ";
        temp = temp->next;
    }
    cout << "TAIL" <<endl;

}

















//goofy main, not even real so pushing to the bottom
int main(){
    IntDLList myList;

    myList.addToHead(2);
    myList.addToHead(5);
    myList.addToHead(4);
    myList.addToHead(2);
    myList.addToTail(13);
    myList.addToTail(43);
    myList.addToTail(123);
    myList.insertInOrder(346);
    myList.insertInOrder(2);
    myList.insertInOrder(567);
    myList.insertInOrder(2345);
    myList.insertInOrder(256);
    myList.insertInOrder(23);
    myList.insertInOrder(3);

    cout << myList.isInList(346) << endl << myList.isInList(345) <<endl;
    myList.printAll();
    
    myList.deleteNode(23);
    myList.printAll();
    
    myList.deleteNode(346);
    myList.printAll();
    myList.deleteNode(1000);
    
    myList.printAll();

    
    return 0;
}