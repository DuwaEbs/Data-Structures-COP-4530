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
        //deleteFromHead();
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
// void IntDLList::addToHead(int n){

//     if(empty()){ //if the list is empty, place the new node in the center of the head and tail then return
//         IntDLLNode* node = new IntDLLNode(n, nullptr, nullptr);
//         head = node;
//         tail = node;
//         return;
//     }

//     //otherwise, put the new node after the head 
//     IntDLLNode* node = new IntDLLNode(n);
//     head->prev = node;
//     node->next = head;
//     node->prev = nullptr;

// }

void IntDLList::printAll() const{

    IntDLLNode* temp = head;
    while(temp != nullptr){
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout <<endl;

}

int main(){
    IntDLList myList;

    myList.addToHead(7);
    myList.addToHead(5);
    myList.addToHead(4);
    myList.addToHead(2);

    myList.printAll();


    return 0;
}