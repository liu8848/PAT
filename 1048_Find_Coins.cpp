#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int N, value;
    cin >> N >> value;
    // vector<int> coins(N);
    set<int> coins;
    map<int, int> mp;
    int max_coin = 0;
    for (int i = 0; i < N; i++)
    {
        // cin>>coins[i];
        int coin;
        cin >> coin;
        coins.insert(coin);
        mp[coin]++;
    }
    for (auto &coin : coins)
    {
        mp[coin]--;
        int remain = value - coin;
        if (mp[remain] > 0)
        {
            cout << coin << " " << remain << endl;
            return 0;
        }
    }

    cout << "No Solution" << endl;
    return 0;
}