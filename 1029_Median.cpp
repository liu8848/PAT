#include<iostream>
#include <cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m, n;
    cin >> m;
    vector<int> arr1;
    for (int i = 0;i < m;i++)
    {
        int temp;
        scanf("%d",&temp);
        arr1.push_back(temp);
    }
    cin >> n;
    vector<int> arr2;
    for (int i = 0;i < n;i++)
    {
        int temp;
        scanf("%d",&temp);
        arr2.push_back(temp);
    }   
    int output = 0;
    int len = (m + n - 1) / 2, i = 0, j = 0;
    if (m > n)
        swap(arr1, arr2);
    while (len >= 0 && i < arr1.size())
    {
        if (arr1[i] < arr2[j])
        {
            output = arr1[i];
            i++;
        }
        else
        {
            output = arr2[j];
            j++;
        }
        len--;
    }
    while (len >= 0)
    {
        output = arr2[j];
        j++;
        len--;
    }
    cout << output;
}
