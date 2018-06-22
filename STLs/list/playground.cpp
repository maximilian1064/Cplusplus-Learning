#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<class T>
void printlist(list<T>& ls)
{
    for(typename list<T>::iterator it = ls.begin(); it != ls.end(); it++)
        cout << *it << " ";
    cout << "\n";
}

int main()
{
    // constructor/initialization
    int arr[5] = {1, 2, 3, 4, 5};
    list<int> ls1;
    list<int> ls2(5, 1);
    ls1.assign(arr, arr + 4);
    list<int> ls3(arr, arr + 5); 
    list<int> ls4(ls3);
    printlist(ls1);
    printlist(ls2);
    printlist(ls3);
    printlist(ls4);

    // add/remove elements
    ls1.pop_front();
    ls1.push_front(0);
    // no ls1.end() - 1
    ls1.erase(--ls1.end(), ls1.end());
    ls1.insert(++ls1.begin(), arr, arr + 5);
    printlist(ls1);

    // special
    ls2.unique();
    printlist(ls2);
    ls1.sort();
    printlist(ls1);
    ls1.remove(5);
    printlist(ls1);
    ls2.merge(ls1);
    printlist(ls1);
    printlist(ls2);
    ls2.splice(ls2.end(), ls3, ls3.begin(), --ls3.end());
    printlist(ls2);
    printlist(ls3);
    ls4.reverse();
    printlist(ls4);

    return 0;
}
