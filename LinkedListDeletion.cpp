#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;


void insert(int n){

    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}

void display(Node *ptr){

    ptr = head;

    cout<<"Elements: ";

    while (ptr != NULL)
    {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }
    
}

void deleteFirst(){

    if(head == NULL){
        cout<<"Linked List is Empty!!";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteLast(){

    if(head == NULL){
        cout<<"Linked List is Empty!!";
        return;
    }
    
    Node* temp = head;

    if(temp->next == NULL){
        delete head;
        head = NULL;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

void deletePosition(int pos){

    if(head == NULL){
        cout<<"Linked List is Empty !!!";
        return;
    }

    Node* temp = head;

    if(pos == 1){
        
        head == temp->next;
        delete temp;
        return;
    }

    for(int i=1; temp != NULL && i < pos-1; i++){
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL){
        cout<<"Position "<< pos <<" doesn't exist in Linked List !!" << endl; 
        return;
    }

    Node* nxt = temp->next->next;
    delete temp->next;
    temp->next = nxt; 
}


int main(){

    insert(11);
    insert(12);
    insert(13);
    insert(14);
    insert(15);
    insert(17);
    insert(20);

    display(head);

    deleteFirst();
    deleteLast();
    deletePosition(3);
   
    display(head);
}