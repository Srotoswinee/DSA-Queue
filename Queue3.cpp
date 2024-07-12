#include <iostream>
using namespace std;
class CirQueue
{
public:
    int size;
    int *arr;
    int front;
    int rear;
    CirQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is Full" << endl;
        } else if (front == -1) {
            front = rear = 0;
            arr[rear] = data;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = data;
        } else {
            rear++;
            arr[rear] = data;
        }
    }
    void pop() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
        } else if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
    }

   void displayQueue() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << "Elements in Circular Queue are: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << arr[i] << " ";

            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CirQueue q(5);

    q.push(14);
    q.push(22);
    q.push(13);
    q.push(9);

    q.displayQueue();

    q.pop();
    q.pop();

    q.displayQueue();
    q.push(20);
    q.push(5);

    q.displayQueue();

    return 0;
}
