#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    // constructor
    int array[5] = {1, 2, 3, 4, 5};
    vector<int> v1(5, 1);
    vector<int> v2 = v1;
    vector<int> v3(array, array + 5);
    vector<int> v4(5);

    for (size_t i = 0; i < v2.size(); i++) {
        cout << v1[i] << " "
             << v2[i] << " "
             << v3[i] << " "
             << v4[i] << "\n";
    }

    // modifier
    v1.insert(v1.end() - 1, v3.begin(), v3.end());
    v1.push_back(7);
    v1.erase(v1.end() - 2, v1.end());
    v1.pop_back();
    v1.front() = 0;
    v1.back() = 0;
    for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
        cout << *it;
    cout << "\n";

    // capacity
    // try to access garbage failed, overwritten malloc/free infos
    v2.resize(11);
    memcpy(&v2[5], &v3[0], 6 * sizeof(int));
    for (size_t i = 0; i < v2.size() + 2; i++)
        cout << v2[i];
    cout << "\n";
    cout << v2.size() << " " << v2.capacity() << "\n";

    // algorithms
    sort(v2.begin(), v2.end());  
    cout << *find(v2.begin(), v2.end(), 4) 
         << *find(v2.begin(), v2.end() - 2, 5) << "\n";

    return 0;
}
