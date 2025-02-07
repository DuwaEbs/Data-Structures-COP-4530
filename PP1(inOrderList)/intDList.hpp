#ifndef INTDLLIST_H
#define INTDLLIST_H

#include "IntDList_node.hpp"
class IntDLList{

public:
    //constructor and destructor
    IntDLList();
    ~IntDLList();
    
    bool empty() const;
    void addToHead(int);
    void insertInOrder(int);
    void addToTail(int);

    int deleteFromHead(); //deletes the head and returns its value
    int deleteFromTail(); // deletes the tail and returns its value

    void deleteNode(int);

    bool isInList(int) const;
    
    void printAll() const;

    std::string addToString() const; // returns the string of the ordered integers

private:
    IntDLLNode *head;
    IntDLLNode *tail;

protected:
    void add(IntDLLNode* oldNode, int n);
    void deleteNode(IntDLLNode* oldNode);

};

#endif
