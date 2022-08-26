#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    int k, n;
    double a;
    map<int, double, greater<int>> mp;
    string line;
    getline(cin, line);
    istringstream s1(line);
    s1 >> k;
    for (int j = 0; j < k; j++)
    {
        s1 >> n >> a;
        if (mp.find(n) == mp.end())
        {
            mp[n] = a;
        }
        else
        {
            mp[n] += a;
        }
    }

    getline(cin,line);
    istringstream s2(line);
    s2>>k;
    for(int i=0;i<k;i++){
        s2>>n>>a;
        if (mp.find(n) == mp.end())
        {
            mp[n] = a;
        }else{
            mp[n]+=a;
            if(mp[n]==0){
                mp.erase(n);
            }
        }
    }

    cout << mp.size();
    for (auto &[key, val] : mp)
    {
        cout << " " << key << " " << val;
    }
    return 0;
}