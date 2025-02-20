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

void display(Node* ptr){
    while (ptr!=NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    
}

void insertPosition(int pos, int n){
    Node* newNode = new Node;
    newNode->data = n;

    if(pos == 1){
        newNode->next = head;
        head = newNode;
    }

    Node* temp = head;

    for(int i=1;i<pos-1 && temp != NULL; i++){
        temp = temp->next;
    }

    if(temp==NULL){
        cout<<"Please enter a valid position";
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertLast(int n){

    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode; 
}

int main(){


    insert(10);
    insert(20);
    insert(30);
    insert(40);

    insertPosition(2,50);
    insertPosition(4,27);

    insertLast(21);
    insertLast(29);


    display(head);

}


