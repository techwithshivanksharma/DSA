#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{

    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void display()
{

    Node *temp;

    if (front == NULL && rear == NULL)
    {
        cout << "Empty queue!" << endl;
        return;
    }
    else
    {
        temp = front;
        cout << "Queue Elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void dequeue()
{

    Node *temp;
    temp = front;

    if (front == NULL && rear == NULL)
    {
        cout << "Empty Queue !Nothing To Delete." << endl;
        return;
    }
    else
    {
        if (front == NULL)
        {
            cout << "All Elements Deleted ,Nothing left to delete" << endl;
            return;
        }
        cout << "Dequeued Element: " << front->data << endl;
        front = front->next;
        free(temp);
    }
}

int main()
{

    // enqueue(4);
    // enqueue(5);
    // enqueue(6);

    display();

    dequeue();

    display();

    return 0;
}