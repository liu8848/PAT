#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int n=s.size();
    if(n<2) {
        cout<<n<<endl;
        return 0;
    }

    //最长回文子串
    int maxLen=1;
    vector<vector<int>> dp(n,vector<int>(n));
    //初始化所有长度为1的子串都是回文,以及两边相等的长度为二的字符串也是回文
    for(int i=0;i<n;i++) {
        dp[i][i]=true;
        if(i < n - 1 && s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            maxLen = 2;
        }
    }

    for(int L=3;L<=n;L++){
        for(int i = 0; i + L - 1 < n; i++) {
            int j = i + L -1;
            if(s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                maxLen = L;
            }
        }
    }
    cout<<maxLen<<endl;
    return 0;
}