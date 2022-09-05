#include<iostream>
#include<vector>
#include<string>

using namespace std;

int n;

string changeNum(string str, int& e) {
    int k = 0;  //str的下标
    while(str.length() > 0 && str[0] == '0')
        str.erase(str.begin()); //先去掉前导0
    //如果是小数
    if (str[0] == '.') {
        str.erase(str.begin());
        //去掉非0位前面的所有0
        while(str.length() > 0 && str[0] == '0') {
            str.erase(str.begin());
            e--;    //小数，指数依次递减
        }
    } 
    //如果是整数
    else {
        while(k < str.length() && str[k] != '.') {
            k++;
            e++;
        }
        if (k < str.length()) str.erase(str.begin() + k);
    }
   
    //说明这个数为0
    if (str.length() == 0)  e = 0;  //指数为0
    int num = 0; k = 0;
    string ans = "";
    while(num < n) {
        if (k < str.length()) ans += str[k++];
        else ans += '0';    //如果超过表示范围后面要补0
        num++;
    }
    return ans;
}

int main() {
    string str1, str2;
    cin >> n >> str1 >> str2;
    int e1 = 0, e2 = 0;
    string ans1 = changeNum(str1, e1), ans2 = changeNum(str2, e2);
    if (ans1 == ans2 && e1 == e2) cout << "YES 0." << ans1 << "*10^" << e1 << endl;
    else cout << "NO 0." << ans1 << "*10^" << e1 << " " << "0." << ans2 << "*10^" << e2 << endl; 
    return 0;
}
