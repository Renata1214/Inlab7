#include "payload.h"
#include "mylist.h"
#include <iostream>

using std::string;
using std::cout;

//Node initializer
Node:: Node (Payload n){
    instance = (n);
    next_link = nullptr;
}

List :: List (){
    Head_List= nullptr;
}

List::~List (){
     while (Head_List != nullptr) {
        Node* temp = Head_List;
        Head_List = Head_List->next_link;
        delete temp;
    }
};  

//Push front
void List::push_front (const Payload& name){
    Node *newNode= new Node (name); //Ask if i need a variable or if i can just declare it inside the function
    newNode->next_link= Head_List;
    Head_List = newNode;
    }

//Pop front
void List::pop_front (){
    if(Head_List == nullptr){
        cout << "No elements inside the list" << '\n';
    }
    else{
    Node * temp = Head_List->next_link;
    Head_List -> ~Node ();
    Head_List = temp;}
}


//Push Back

void List::push_back (const Payload& name){
     if (Head_List == nullptr) {
        Head_List = new Node(name);
    } else {
        Node* tail = Head_List;
        while (tail->next_link != nullptr) {
            tail = tail->next_link;
        }
        tail->next_link = new Node(name);
    }
}

//Pop back
void List::pop_back(){
   if (Head_List == nullptr) {
        cout << "No elements inside the list" << '\n';
        return;
    } else if (Head_List->next_link == nullptr) {
        delete Head_List;
        Head_List = nullptr;
        return;
    } else {
        Node* tail = Head_List;
        while (tail->next_link->next_link != nullptr) {
            tail = tail->next_link;
        }
        delete tail->next_link;
        tail->next_link = nullptr;
    }
}


//size, not as a variable.
int List::size ()const{
    int counter =0;
    Node * temp = Head_List;
    while (temp !=nullptr){
        temp = temp -> next_link;
        counter ++;
    }
    return counter;
}


//ASK ABOUT THIS!!!!!!!!!!!!!!!!!
int List::capacity ()const{
    int counter =0;
    Node * temp = Head_List;
    while (temp !=nullptr){
        temp = temp -> next_link;
        counter ++;
    }
    return counter;
}




//print function
void List::print ()const{
    Node * temp = Head_List;
    while (temp !=nullptr){
        temp->instance.print();
         temp = temp -> next_link;
    }
}

//Operator
Payload& List::operator[](int i) {
 Node* iterator = Head_List;
    for (int j = 0; j < i; j++) {  
        iterator = iterator->next_link;
    }
    return iterator->instance;
}

Payload& List::operator[](int i) const{
    Node* iterator = Head_List;
    for (int j = 0; j < i; j++) {  
        iterator = iterator->next_link;
    }
    return iterator->instance;
}

//Additional Functions 
bool List::empty() const{
    bool nempty= 0;
    if (Head_List==nullptr){
        nempty = 1;
    }
    return nempty;
}

Payload List::front() const{
    if (Head_List==nullptr){
        cout << "No objects inside the list" << '\n';
        throw "Error";
    }
    else {
        return Head_List->instance;
    }
}

Payload List::back() const{
    if (Head_List==nullptr){
        cout << "No objects inside the list" << '\n';
        throw "Error";
    }
    else{
            Node * temp = Head_List;
            while (temp->next_link!=nullptr){
              temp = temp -> next_link; 
            }
            return temp -> instance;
    }
}


Node* List::swap_nodes () {

        Node* ptr1;
        Node* ptr2;
        Node* ptr3;

    
            ptr1= Head_List;
            ptr3=ptr1;
            ptr2= ptr1->next_link;
            Head_List=ptr2;

        while (true){
            ptr1->next_link= ptr2->next_link;
            ptr2->next_link=ptr1;
           
            ptr1=ptr1-> next_link;
            ptr3->next_link=ptr1;
             if(ptr1->next_link==NULL)
             break;

            ptr2=ptr1->next_link;
        } 

        return Head_List;
        
        }