#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void insert(int n)
{

    Node *newNode = new Node;

    newNode->data = n;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertEnd(int n)
{

    Node *newNode = new Node;

    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPos(int n, int pos)
{

    Node *newNode = new Node;
    newNode->data = n;

    if (pos == 1)
    {
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
        return;
    }
    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Invalid Position :" << pos << endl;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFirst()
{

    if (head == NULL)
    {
        cout << "Linked List is Empty: ";
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete temp;
}

void deleteLast()
{

    if (head == NULL)
    {
        cout << "Linked List is Empty: ";
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    delete temp;
}

void deletePos(int pos)
{

    if (head == NULL)
    {
        cout << "Linked List is Empty: ";
        return;
    }

    Node *temp = head;

    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "Please enter a valid position: ";
        return;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void display()
{
    Node *temp = head;

    cout << "Elements: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    insert(12);
    insert(13);
    insert(14);
    insert(15);
    insert(16);

    display();

    /* insertEnd(24);
    insertEnd(25); */

    insertAtPos(24, 6);
    insertAtPos(27, 3);
    insertAtPos(29, 1);

    // deleteFirst();
    // deleteLast();

    display();

    return 0;
}