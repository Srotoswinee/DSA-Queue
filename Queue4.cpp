#include <iostream>
using namespace std;

class Deque {
    int* arr;
    int size;
    int front;
    int rear;

public:
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushrear(int data) {
        if (rear == size - 1) {
            cout << "Queue is Full" << endl;
            return;
        } else if (front == -1) { // If the queue is initially empty
            front = rear = 0;
            arr[rear] = data;
        } else {
            rear++;
            arr[rear] = data;
        }
    }

    void pushfront(int data) {
        if (front == 0) {
            cout << "Queue is Full" << endl;
            return;
        } else if (front == -1) { // If the queue is initially empty
            front = rear = 0;
            arr[front] = data;
        } else {
            front--;
            arr[front] = data;
        }
    }

    void popfront() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void poprear() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            rear--;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Elements in the deque are: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq(5);

    dq.pushrear(1);
    dq.pushrear(2);
    dq.pushfront(3);
    dq.pushfront(4);
    dq.pushrear(5);

    dq.display();

    dq.popfront();
    dq.poprear();

    dq.display();

    return 0;
}
