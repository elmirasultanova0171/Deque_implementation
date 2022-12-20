#pragma once

#include <iostream>
#include <stddef.h>  

using namespace std;

struct Node
{
    int data;
    Node* prev, * next;
    
    static Node* getnode(int data)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->prev = newNode->next = NULL;
        return newNode;
    }
};

class Deque
{
    Node* start;
    Node* rear;
    int Size;

public:
    Deque()
    {
        start = rear = NULL;
        Size = 0;
    }


    Node* start_r();
    void pushFront(int data);
    void pushBack(int data);
    void popFront();
    void popBack();
    int front(Node* s);       //Node*
    int back();
    void display();
    void clear();
    bool isEmpty();
};

Node* createnode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* Deque::start_r() {
    return start;
}


bool Deque::isEmpty()
{
    if (Size == 0) {
        return true;
    }
    return false;
}

void Deque::pushFront(int data)
{
    Node* newNode = createnode(data);

    if (start == NULL) {
        rear = start = newNode;
    }

    else
    {
        newNode->next = start;
        start->prev = newNode;
        start = newNode;
    }


    Size++;
}

void Deque::pushBack(int data)
{
    Node* newNode = createnode(data);

    if (rear == NULL)
        start = rear = newNode;

    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }


    Size++;
}

void Deque::popFront()
{

    if (isEmpty())
        cout << "UnderFlow\n";


    else
    {
        Node* temp = start;
        start = start->next;

        if (start == NULL)
            rear = NULL;
        else
            start->prev = NULL;
        free(temp);


        Size--;
    }
}

void Deque::popBack()
{

    if (isEmpty())
        cout << "UnderFlow\n";

    else
    {
        Node* temp = rear;
        rear = rear->prev;

        if (rear == NULL)
            start = NULL;
        else
            rear->next = NULL;
        free(temp);


        Size--;
    }
}

int Deque::front(Node* s)           //Node*
{
    if (isEmpty())
        return -1;

    return s->data;
}

int Deque::back()
{

    if (isEmpty())
        return -1;
    return rear->data;
}

void Deque::display()  //making sure the deque is not destroyed while being displayed
{
    if (start != NULL) {
        for (Node* i = start; i != NULL; i = i->next) {
            cout << front(i) << " ";                 //this is why the front() function is used with a changing Node pointer
        }
    }
    else {
        cout << "Deque is empty" << endl;
    }

}

void Deque::clear() {



    while (start != NULL) {

        popFront();
    }


}
