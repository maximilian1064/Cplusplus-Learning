#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* constructor */
    string s1 = "s1";
    cout << s1.length() << "\n";
    string s2("s1", 2);
    cout << s2.length() << "\n";
    string s3(1, 's');
    cout << s1 << "\n"
         << s2 << "\n"
         << s3 << "\n";

    /* string IO */
    getline(cin, s1, 'e');
    cin >> s2 >> s3;
    cout << s1 << "\n"
         << s2 << "\n"
         << s3 << "\n";

    /* operators */ 
    // assignment
    s1 = "s1";
    s2 = s1;
    s3.assign(s1, 1, 2);
    cout << s1 << "\n"
         << s2 << "\n"
         << s3 << "\n";

    // arithmetic
    s1 += s1;
    s2 = s1 + s1;
    s3 = "s1" + s2;
    s3.append(s1, 3, 1);
    cout << s1 << "\n"
         << s2 << "\n"
         << s3 << "\n";

    // comparison
    if ("s1" <= s1 && s1 <= s2 && s2 <= s3)
        cout << s1 << "\n"
             << s2 << "\n"
             << s3 << "\n";
    if (!s1.compare(0, 2, s2, 0, 2))
        cout << s1.substr(0, 2) << "\n";

    /* others */
    swap(s1, s2);
    cout << s1 << " " << s1.length() << "\n"
         << s2 << " " << s2.length() << "\n";

    /* informations */
    
    /* character level manipulation */
    // sampling 
    s1.resize(s2.length() / 2);
    for (string::iterator it1 = s1.begin(), it2 = s2.begin(); 
        it1 < s1.end(); it1++, it2 += 2)
        *it1 = *it2;
    cout << s1 << " " << s1.length() << "\n"
         << s2 << " " << s2.length() << "\n";

    // switch case
    for (size_t i = 0; i < s3.length(); i++)
        if (s3[i] >= 'a' && s3[i] <= 'z')
            s3[i] += 'A' - 'a';
    cout << s3 << " " << s3.length() << "\n";

    // reverse
    string::iterator it;
    string::reverse_iterator rit;
    for (it = s3.begin(), rit = s3.rbegin();
        it < s3.begin() + (s3.end() - s3.begin()) / 2; it++, rit++) {
        char tmp = *it;
        *it = *rit;
        *rit = tmp;
    }
    cout << s3 << " " << s3.length() << "\n";

    /* substring */
    // find
    cout << s2.rfind("s1", 0, 2) << "\n";
    cout << s2.find_last_not_of("s") << "\n";

    // erase
    cout << s2.erase(s2.rfind("s1")) << "\n";

    // search, replace and insert
    size_t i = 0;
    while ((i = s3.find("1S1", i)) != string::npos) {
        s3.replace(i, 3, "1");
        // move index to the rest of the string behind the pattern
        i++;
        s3.insert(i, "2");
        i++;
    }
    cout << s3 << "\n";

    /* C_str */
    const char* c_s3 = s3.c_str();
    cout << c_s3 << "\n";
    s3.erase(s3.find("1S"));
    cout << c_s3 << "\n";

    return 0;
}

