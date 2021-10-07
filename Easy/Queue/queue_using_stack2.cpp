#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;

public:
    void push(int val)
    {
        s1.push(val);
    }

    int pop()
    {
        if (s1.empty())
        {
            cout << "queue is empty.";
            return -1;
        }

        int x = s1.top();
        s1.pop();
        if(s1.empty()){
            return x;       // base condition
        }

        int topval = pop();
        push(x);
        return topval;
        
    }

    bool empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    // queue functionality can be achieved by using 1 stack with recursion
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty();

    return 0;
}