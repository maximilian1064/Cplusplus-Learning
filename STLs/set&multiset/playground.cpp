#include <iostream>
#include <utility>
#include <string>
#include <set>
using namespace std;

template<class T>
void printset(set<T>& ls)
{
    for(typename set<T>::iterator it = ls.begin(); it != ls.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

template<class T>
void print_multiset(multiset<T>& ls)
{
    for(typename multiset<T>::iterator it = ls.begin(); it != ls.end(); it++)
        cout << *it << " ";
    cout << "\n";
}


int main()
{
    // constructor/initialization
    set<string> s1;
    s1.insert("a");
    s1.insert("bc");
    printset(s1);

    set<string> s2(s1.begin(), --s1.end());
    printset(s2);
    s2.insert("def");
    s1.insert(s2.begin(), s2.end());
    printset(s1);
    printset(s2);

    // funky stuff of set 
    if (s1.find("b") != s1.end())
        cout << "b" << " is in s1\n";
    s1.erase("b");
    s2.erase(s2.begin());
    printset(s1);
    printset(s2);
    // return value of erase changes in C++11
    cout << *s1.erase(s1.lower_bound("b"), s1.upper_bound("bcd")) << "\n";
    printset(s1);
    cout << *s1.end() << "\n";

    /* multiset */
    multiset<string> s3(s1.begin(), s1.end());
    s3.insert(s2.begin(), s2.end());
    print_multiset(s3);
    pair<multiset<string>::iterator, multiset<string>::iterator> p_s3 = s3.equal_range("def"); 
    s3.erase(p_s3.first, p_s3.second);
    print_multiset(s3);

    return 0;
}
