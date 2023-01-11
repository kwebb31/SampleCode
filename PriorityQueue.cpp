//by Kat Webb
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    length = 0;
    head = nullptr;
}

PriorityQueue::~PriorityQueue(){
//make a temp node that begins the unwinding of it all 
    Node *temp;
//inchworm through and delete all the nodes
    while(head != nullptr) {
       temp = head;
       head = head->next;
       delete temp;
   }
//set length equal to zero
    length = 0;
}

int PriorityQueue::Dequeue() {
    //if there's nothing in there back up! return zero, no pass go
    if(head == nullptr)
        return 0;
    else{
       //temp pointer created that points to head
        Node * temp = head;

        //set head equal to the next node
        head = head->next;

        //the value is the data inside the temp pointer's variable (pointing to the now ex-head)
        int value = temp->data;

        //delete temp now that we've gotten the value from it
        delete temp;

        //subtract one from the length cause we dequeued a number
        length--;

        //return the value, the information in the pointer packaging
        return value;
    }
}
void PriorityQueue::Enqueue(int value) {
    //make a new pointer and stuff
    Node * nodeToInsert = new Node;

    //point that header at some data
    nodeToInsert->data = value;

    //sets a pointer of Node named current (and another named prev) equal to head's pointer
    Node * curr = head;
    Node * prev = head;


    //if there's nothing in the list, set the head equal to nodeToInsert, and then the next node to nullptr
    if(length == 0){
        head = nodeToInsert;
        head->next = nullptr;
    }
    //added in an equals sign here for the event that a number is equal to another number...
    //but yeah, if our value is less than or equal to the head value we're on, insert the nodeToInsert there.
    else if(value <= head->data) {
            Node * temp = head;
            head = nodeToInsert;
            nodeToInsert->next = temp;
    }
    //if it's not equal to or less than the current number,  keep moving the current and next pointers over
    else{
        while(curr != nullptr){
            if (curr->data >= nodeToInsert->data)
                break;
            prev = curr;
        curr = curr->next;
         }
    //insert the node after the current marker, so that we put it in the spot we want.
    nodeToInsert->next = curr;
    prev->next = nodeToInsert;
    }
    //finally, add one to length cause we went through and added something new 
    length++;
}

int PriorityQueue::Size(){
    //literally just returns the current length of the linked list. 
    return length;
}
