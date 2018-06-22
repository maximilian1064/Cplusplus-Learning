#include <iostream>
#include <utility>
#include <string>
#include <map>
using namespace std;

template<class key, class value>
ostream& operator <<(ostream& o, const pair<key, value>& p)
{
    o << "[" << p.first << " " << p.second << "]";
    return o;
}


int main()
{
    // constructor/initialization
    map<int, string> m1;
    m1.insert(map<int, string>::value_type(1, "a"));
    m1.insert(make_pair(2, "bc"));
    m1.insert(make_pair(3, "34"));
    // natural way of insertion
    m1[4] = "678";
    m1[4] = "911";
    m1.insert(make_pair(4, "910"));
    m1[5];
    for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
        cout << *it << ",";
    cout << "\n";

    // modifier
    for (map<int, string>::iterator it = m1.begin(); it != m1.end(); ) {
        if (it->second < "a") {
            it = m1.erase(it);
        } else {
            it++;
        }
    }
    for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
        cout << *it << ",";
    cout << "\n";

    // should be faster with iterating + lower_bound
    m1.erase(m1.lower_bound(2), m1.upper_bound(2));
    for (map<int, string>::iterator it = m1.begin(); it != m1.end(); it++)
        cout << *it << ",";
    cout << "\n";

    cout << m1.count(2) << "\n";

    return 0;
}
