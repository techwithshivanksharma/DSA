#include<iostream>

using namespace std;

struct  Node
{
    int data;
    Node* next;
    Node* prev;
};

Node* head = NULL;

void insert(int n){
    
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = head;
    newNode->prev = NULL;

    if(head != NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void insertLast(int n){

    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node* temp = head;

    if(head == NULL){
        head = newNode;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(int n, int pos){

    Node* newNode = new Node;
    newNode->data = n;

    if(pos == 1){
        newNode->next = head;
        newNode->prev = NULL;

        if(head != NULL){
            head->prev = newNode;
        }

        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i=1; i< pos-1 && temp != NULL; i++){

        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"Invalid Position";
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL){
        temp->next->prev = newNode;
    }

    temp->next = newNode;

}

void display(){
    Node* temp = head;

    if(head == NULL){
        cout<<"Empty List";
        return;
    }

    cout<<"Elements: ";
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp=temp->next;
    }
}

int main(){

    insert(20);
    insert(30);
    insert(50);
    insert(40);
    insert(10);

    display();

    //insertLast(12);
    //insertAtPos(12,4);
    insertAtPos(13,2);

    display();

    return 0;
}