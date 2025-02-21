#include<iostream>

using namespace std;

struct  Node
{
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

void display(){
    
    Node* temp = head;

    cout<<"Elements: "<<endl;

    while (temp != NULL)
    {
        cout<< temp->data <<" ";
        temp = temp->next;
    }

    cout<<endl;   
}

int search(int element){

    Node* temp = head;
    int pos = 1;

    while(temp != NULL){
        
        if(temp->data == element){
            return pos;
        }

        temp = temp->next;
        pos++;
    }
    return -1;
}

int main(){

    insert(12);
    insert(13);
    insert(14);
    insert(15);
    insert(16);

    display();

    int position = search(12);

    if(position == -1){
        cout<<"Element is not present in the Linked List !!"<< endl;
    }
    else{
        cout<<"Element found at Position : "<< position << endl;
    }
    return 0;
}