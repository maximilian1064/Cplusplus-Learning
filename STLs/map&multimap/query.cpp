#include <iostream>
#include <utility>
#include <string>
#include <map>
using namespace std;

class student
{
    public:
        struct info
        {
            int id;
            string name;
        };
        struct info m_info;
        int score;
};

typedef multimap<int, student::info> score_to_info_map;
typedef score_to_info_map::iterator IT;

// no input check!
// TODO: use iteration to find candiates, rather than equal_range()
int main()
{
    string cmd;
    student st;
    int score;
    score_to_info_map mymap;
    while (cin >> cmd) {
        // add infos
        if (cmd == "add") {
            cin >> st.m_info.name >> st.m_info.id >> st.score;
            IT curr_it = mymap.insert(score_to_info_map::value_type(st.score, st.m_info));
            (*curr_it).second.id++;
        // query
        } else if (cmd == "query") {
            cin >> score;
            IT p_lower = mymap.lower_bound(score);
            // print nobody if database empty
            // or all students have score not less than the one queried
            if (mymap.empty() || p_lower == mymap.begin()) { 
                cout << "nobody!" << "\n";
            // otherwise return the student with largest id
            } else {
                // find candidates 
                score = (*(--p_lower)).first;
                pair<IT, IT> p_range = mymap.equal_range(score);
                // find candidate with the highest id
                // !! multimap::value_type::first is of const type
                pair<int, student::info> query_result = *(p_range.first);
                for (IT it = p_range.first; it != p_range.second; it++) {
                    if ((*it).second.id > query_result.second.id)
                        query_result = *it;
                }

                cout << query_result.second.name << " "
                     << query_result.second.id << " "
                     << query_result.first << "\n";
            }
        }
    }

    return 0;
}
