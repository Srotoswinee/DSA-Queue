/*Implement Queue using stacks*/
#include<iostream>
#include<stack>
using namespace std;
class MyQueue {
    stack<int> s1;
    stack<int> s2;
    public:
        void push(int data) {
            s1.push(data);
        }
        int pop() {
            if (s2.empty()) {
                while (!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if (s2.empty()) {
                throw out_of_range("Queue is empty");
            }
            int ans = s2.top();
            s2.pop();
            return ans;
        }
        bool empty() {
            return s1.empty() && s2.empty();
        }
};
int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    return 0;
}
