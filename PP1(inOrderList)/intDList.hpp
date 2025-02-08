#ifndef INTDLLIST_H
#define INTDLLIST_H

#include "IntDList_node.hpp"
class IntDLList{

public:
    //constructor and destructor
    IntDLList(); //done
    ~IntDLList(); //done
    
    bool empty() const;//done
    void addToHead(int); //ryan done
    void insertInOrder(int); //done
    void addToTail(int); //ryan done

    int deleteFromHead(); //deletes the head and returns its value //ryan done
    int deleteFromTail(); // deletes the tail and returns its value//ryan done

    void deleteNode(int); //done
                            
    bool isInList(int) const; //done
    
    void printAll() const; //done
                    
    std::string addToString() const; // returns the string of the ordered integers //COLLAB AL FINAL

private:
    IntDLLNode *head;
    IntDLLNode *tail;
protected:
    void add(IntDLLNode* oldNode, int n); //done kinda
    void removeNode(IntDLLNode* oldNode);

};

#endif
//what functions you wanna make, i could lock in on add and delete if you wanna work on some other ones. i like that