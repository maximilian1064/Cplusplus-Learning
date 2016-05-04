/*
 * C++ @ coursera, week3, assignment2
 */
#include <iostream>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
    Sample(Sample& s) { v=10; }
};
int main() {
    Sample a(5);
    Sample b = a;
    cout << b.v;
    return 0;
}
