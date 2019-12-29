//
// Created by Jarel Ross
// Queue.cpp
//

#include "Queue.h"

 Queue::Queue(){//creates an empty Queue
     myfront = new qnode();
     myfront->data = NULL;
     myfront->next = NULL;
     myback = myfront;
 }

bool Queue::empty() {// return true if queue is empty
    if(myfront->data == NULL)
        return true;
    return false;

}

void Queue::AddQ(QueueElement x) {//adds value to back of queue
    if(empty()){
        myfront->data = x;
        myfront->next = myback;
    } else if (myback->data == NULL){
        myback->data = x;
    }else{// if full, adds to back
        qnode* newQ= new qnode();//creates new node
        newQ->data = x;
        myback->next=newQ;
        myback=newQ;
    }
}

int Queue::Front(QueueElement &x) {//receives data at the front of queue
    return myfront->data;
}
void Queue::RemoveQ() {//removes value from front od queue
    if(myfront->next == NULL){
        myfront->data = NULL;
        myback = myfront;
    }
    else{//removes node completely
        qnode* removed = myfront;//moves to back
        myfront = myfront->next;
        delete removed;
    }
}

void Queue::display() {
    std::cout<<std::endl;
    //checks if empty
    if(empty()){
        std::cout<<"Queue is empty"<<std::endl;
    }//if theres something/ display it
    else{
        qnode* current = new qnode();
        current = myfront;
        std::cout<<current->data<<std::endl;
        while(current != myback) {
            current = current->next;
            std::cout << current->data << std::endl;
        }
    }

    std::cout<<std::endl;
}