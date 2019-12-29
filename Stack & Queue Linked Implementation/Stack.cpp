//
// Created by Jarel Ross .
//Stack.cpp
//

#include "Stack.h"


Stack::Stack() { //Creates an empty stack
    mytop = new node();
    mytop->data = NULL;
    mytop->next = NULL;

}

bool Stack::empty() {//if stack is empty, return true, if not FALSEEEEE
    if(mytop->data == NULL)
        return true;
    return false;
}

void Stack::push(StackElement x) {// adds new value to top of stack
    if(empty()){
        mytop->data = x;// adds data to top node if empty
    }

    else{ //places value on top and moves top pointer up

        node* oldTop = mytop;//creates top pointer
        node*newTop = new node();//new value
        newTop->data = x;
        newTop->next = oldTop;//up the top
        mytop = newTop;
    }
}

int Stack::Top(StackElement & x) {// receives data at the top of the stack
    return mytop->data;
}

void Stack::pop() {//removes data at the top of stack

    if(mytop->next == NULL){
        mytop->data = NULL;

    }

    else{//deletes nodes that are not needed

        node*popped= new node();
        popped = mytop;
        mytop = mytop->next;
        delete popped;// deletes referenced node
    }
}


void Stack::display() {// displays data stored
    std::cout<<std::endl;

    if(empty()){// checks if empty
        std::cout<<"the stack is empty."<<std::endl;
    }

    else{
        node*current = new node();
        current = mytop;
        std::cout<<current->data<<std::endl;
        while(current->next != NULL){
            current = current->next;
            std::cout<<current->data<<std::endl;
        }
    }
    std::cout<<std::endl;

}