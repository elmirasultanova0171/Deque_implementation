
#include "Deque.h"
#include <iostream>
#include <stddef.h>  

using namespace std;


int main() {

    Deque deq;
    cout << "1.pushFront()" << endl;
    cout << "2.pushBack()" << endl;
    cout << "3.popFront()" << endl;
    cout << "4.popBack()" << endl;
    cout << "5.front()" << endl;
    cout << "6.back()" << endl;
    cout << "7.isEmpty()" << endl;
    cout << "8.display()" << endl;
    cout << "9.clear()" << endl;

    while (true) {
        int operation;
        cin >> operation;
        if (operation <= 2) {
            int val;
            cout << "enter the value ";
            cin >> val;
            if (operation == 1) {
                deq.pushFront(val);
            }
            else deq.pushBack(val);
        }
        else {
            if (operation == 3) {
                deq.popFront();
            }
            else if (operation == 4) {
                deq.popBack();
            }
            else if (operation == 5) {
                if (deq.front(deq.start_r()) != -1)
                    cout << "Front element: " << deq.front(deq.start_r()) << endl;
                else cout << "The deque is empty" << endl;
            }
            else if (operation == 6) {
                if (deq.back() != -1)
                    cout << "Rear element: " << deq.back() << endl;
                else cout << "The deque is empty" << endl;
            }
            else if (operation == 7) {
                if (deq.isEmpty()) cout << "The deque is empty" << endl;
                else cout << "The deque is not empty" << endl;
            }
            else if (operation == 8) {
                deq.display();
            }
            else if (operation == 9) {
                if (deq.isEmpty()) cout << "The deque is empty" << endl;
                else deq.clear();
            }
            else break;
        }
    }
    return 0;
}