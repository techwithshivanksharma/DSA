#include<iostream>

using namespace std;

#define N 10
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){

    if(rear == N-1){
        cout<<"Over flow!";
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){

    if(front == -1 and rear == -1){
        cout<<"Underflow! Can't Delete Elements"<<endl;
    }
    else if(front == rear){
        cout<<"Dequeued element is :"<<queue[front]<<endl;
        front = rear = -1;
    }
    else{
        cout<<"Dequeued element is :"<<queue[front]<<endl;
        front++;
    }

}

void display(){
    if(front == -1 && rear == -1){
        cout<<"Underflow!";
    }
    else{
        cout<<"Queue Elements: ";
        for(int i=front; i < rear + 1; i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);

    display();

    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();

    display();

    return 0;
}