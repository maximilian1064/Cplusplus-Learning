#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    // constructor/initialization
    deque<string> d1(5, "ab"); 
    // stack
    stack<string> s1(d1);
    cout << s1.top() << " " << s1.size() << "\n";
    s1.pop();
    s1.push("abc");
    cout << s1.top() << " " << s1.size() << "\n";
    cout << s1.empty() << "\n";
    // queue
    queue<string> q1(d1);
    q1.push("abc");
    q1.pop();
    cout << q1.front() << " " << q1.back() << " " << q1.size() << "\n";
    // priority queue
    
    return 0;
}
