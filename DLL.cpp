#include "DLL.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor is already implemented
// do not modify the default constructor
DLL::DLL(){
    headPtr = nullptr;
    itemCount=0;
}

// return the head pointer of the list
// it is already implemented, do not modify it
Node* DLL::getHeadPtr(){
    return headPtr;
}

// copy construct, which copies an existing list n
// the new list is a different object from n
// the new list and object n have the same contents
// Please implement it
DLL::DLL(DLL& n){
    headPtr = NULL; 
    Node* temp = n.getHeadPtr();
    headPtr = NULL;
    Node *temp2 = NULL;
    while (temp != NULL){
        Node *temp3 = new Node;
        temp3 -> name = temp -> name; 
        temp3 -> ssn = temp -> ssn;
        temp3 -> pred = temp2;
        if (headPtr == NULL)
            headPtr = temp2;
        temp3-> succ = NULL;
        if (temp2 != NULL)
            temp2 -> succ = temp3;
        temp2 = temp3; 
        temp = temp -> succ;
    } 
}

// destructor
// release every node of the list
// Please implement it
DLL::~DLL(){
 /*  Node* temp = headPtr;
    if (temp != NULL)
        temp = temp -> succ;
    while (temp != NULL){
        if (temp -> succ == NULL){
            free(temp -> pred);
            free(temp);
            break;
        }
        free(temp -> pred);
        temp = temp -> succ;
    } 
    
    while(headPtr){
        Node* temp = headPtr;
        headPtr = headPtr -> succ;
        free(temp);
    } */
    Node* temp = headPtr;
    Node* temp2 = NULL;
    while (temp != NULL){
        temp2 = temp;
        temp = temp -> succ;
        delete temp2;
    } 
} 

// if some node has SSN matcthes string ss
// return the index value of the node
// the index value of the first node is 0, the second node is 1, etc.
// if there is node matching ss, return -1
int DLL::search(string ss)const{
    if (headPtr == NULL)   
        return -1;
    else if (headPtr ->ssn == ss) {
        return 0;
    }
    else{
        Node *temp = headPtr;
        int index = 0;
        while (temp->ssn != ss && temp->succ != NULL) {
            temp = temp->succ;
            index = index +1;
            if (temp -> ssn == ss) 
                return index; //should i return index??
        }
    }
    return -1;
}


// insert (ss, name) to the existing list
// the SSN values are each node are organized in INCREASING order
// if there is a node matching ss value, return false; otherwise true
// else create a node with (ss, name), insert the node to the proper position
// parameter count is the counter of number of valid insertion
// when you implement this method, consider the following situations:
// 1. list is empty
// 2. node should be inserted to the beginning of the list
// 3. node should be inserted to the middle of the list
// 4. node should be inserted to the end of the list
bool DLL::insert(string ss, string name, int & count){
    if (headPtr == NULL){ 
        headPtr = new Node;
        headPtr -> succ = NULL;
        headPtr -> ssn = ss;
        headPtr -> name = name;
        count = count + 1;
   //     cout << 2;
        return true;
    } 
    else if (headPtr->ssn > ss) {
        Node* temp = new Node;
        headPtr -> pred = temp;
        temp -> succ = headPtr;
        temp -> name = name;
        temp -> ssn = ss;
        headPtr = temp; 
    //    cout<< 4;
        count = count + 1;
        return true;
    }  
    else{
        Node *temp = headPtr;
        while (temp->succ != NULL){
            if (temp->ssn == ss){
                return false;
            }
            temp = temp -> succ;
        }
        temp = headPtr; 
        while(temp -> ssn < ss && temp -> succ != NULL){
        //    if (temp->succ == NULL) //is end nullptr or null?
          //      break;
            temp = temp -> succ;
        //    if (temp->ssn == ss){
          //      return false;
          //  }     
        }
        Node* present = new Node;
        if (temp -> succ == NULL){ //is end nullptr or null?
            temp -> succ = present;
            present -> pred = temp;
            present -> succ = NULL;
            present -> ssn = ss;
            present -> name = name;
            count = count +1;
       //     cout <<9;
         //   cout << 13;
            return true;  
        }
        else{
            Node* before = temp -> pred;
            temp -> pred = present;
            present-> succ = temp;
            present -> pred = before;
            before -> succ = present;
            present->name = name;
            present->ssn = ss;
            count = count + 1;
        //    cout << 5;
            return true;
        } 
    } 
    return false;
}


// remove node containing ss value
// if there is no node containing ss, return false; otherwise true
// consider the following situations:
// 1. list is empty
// 2. node containing ss value is the first node
// 3. node containing ss value is in the middle of the list
// 4. node containing ss value is the last node of the list
bool DLL::remove(string ss, int & count){
    if (headPtr == NULL){
        return false;
    }
    else if (headPtr -> ssn == ss){
        if (headPtr -> succ == NULL){
            free(headPtr);
            headPtr = NULL;
            count = count + 1;
            return true;
        }
        else{
            Node* temp = headPtr -> succ;
            free(headPtr);
            headPtr = temp;
            count = count + 1;
            return true;
        } 
    }
    else {
        Node *temp = headPtr;
        while (temp->ssn != ss){
            if (temp->succ == NULL) //is end nullptr or null?
              return false;
              //  break;
            temp = temp->succ;
        }
        if (temp -> succ == NULL){
            temp -> pred -> succ = NULL;
            free(temp);
            count = count + 1;
            return true;
        }
        else{
            temp -> succ -> pred = temp -> pred;
            temp -> pred -> succ = temp -> succ;
            free(temp);
            count = count + 1;
            return true;
        }
    }
    return false;
} 

// return the number of the nodes
// it is already implemented, do not modify it
int DLL::size(){
    return itemCount;
}

// iterate through each node
// print out SSN and memory address of each node
// do not modify this method
void DLL::display(){
    Node* temp;
    temp = headPtr;
    while (temp!= nullptr) {
        cout << temp->ssn << "\t" << temp << endl;
        temp = temp->succ;
    }
}
