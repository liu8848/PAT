#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    string no;
    int C;
    int M;
    int E;
    int A;
};

int get(vector<int> &s, int target)
{
    int i;
    for(i=0;i<s.size();i++){
        if(s[i]==target) break;
    }
    return i + 1;
}
int main()
{
    string line;
    istringstream s;
    int n = 0, m = 0;
    getline(cin, line);
    s.str(line);
    s >> n >> m;
    unordered_map<string, student> mp;
    unordered_map<int, string> dic({{0, "A"}, {1, "C"}, {2, "M"}, {3, "E"}});
    vector<int> rank_C, rank_M, rank_E, rank_A;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        s.clear();
        s.str(line);
        student stu;
        s >> stu.no >> stu.C >> stu.M >> stu.E;
        stu.A = (stu.C + stu.E + stu.M) / 3;
        rank_C.push_back(stu.C);
        rank_E.push_back(stu.E);
        rank_M.push_back(stu.M);
        rank_A.push_back(stu.A);
        mp[stu.no] = stu;
    }
    sort(rank_A.begin(),rank_A.end(),greater<int>());
    sort(rank_C.begin(),rank_C.end(),greater<int>());
    sort(rank_M.begin(),rank_M.end(),greater<int>());
    sort(rank_E.begin(),rank_E.end(),greater<int>());

    for (int i = 0; i < m; i++)
    {
        cin >> line;
        if (mp.find(line) == mp.end())
        {
            cout << "N/A" << endl;
            continue;
        }
        vector<int> Rank(4, 0);
        Rank[0] = get(rank_A, mp[line].A);
        Rank[1] = get(rank_C, mp[line].C);
        Rank[2] = get(rank_M, mp[line].M);
        Rank[3] = get(rank_E, mp[line].E);
        auto it = min_element(Rank.begin(), Rank.end());
        int index = it - Rank.begin();
        cout << *it << " " << dic[index] << endl;
    }
    return 0;
}