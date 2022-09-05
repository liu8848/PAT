#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string bigNumPlus(string&A,string&B){
    int more=0;
    int negA=0,negB=0;
    int m=A.size(),n=B.size();
    if(A[m-1]=='-'){
        negA=1;
        A.pop_back();
        m--;
    }
    if(B[n-1]=='-'){
        negB=1;
        B.pop_back();
        n--;
    }
    int len=min(m,n);
    string ans;
    if(negA&&negB){
        int i=0;
        for(;i<len;++i){
            int sum=(A[i]-'0')+(B[i]-'0')+more;
            more=sum/10;
            ans.push_back('0'+sum%10);
        }
        while(i<m){
            int sum=(A[i]-'0')+more;
            more=sum/10;
            ans.push_back('0'+sum%10);
            ++i;
        }
        while(i<n){
            int sum=(B[i]-'0')+more;
            more=sum/10;
            ans.push_back('0'+sum%10);
            ++i;
        }
        if(more>0){
            ans.push_back('0'+more);
        }
        if(negA){
            ans.push_back('-');
        }
    }
    else{
        if(negA){
            int i=0;
            int ret=0;
            for(;i<len;++i){
                int a=A[i]-'0'-ret,b=B[i]-'0';
                if(a>=b){
                    ret=0;
                    ans.push_back('0'+(a-b));
                    continue;
                }else{
                    ret=1;
                    a+=10;
                    ans.push_back('0'+(a-b));
                    continue;
                }
            }
            if(i<m){
                int a=A[i]-'0'-ret;
                if(a<0){
                    ret=1;
                    a+=10;
                    ans.push_back(a);
                    
                }
            }
        }
    }
    return ans;
}

bool compare(string&A,string&B){
    if(A.size()!=B.size()) return A.size()>B.size();
    // for(int i=0;i<A.size();++i){
    //     if(A[i]<B[i]) return false;
    // }
    // return true;
    return A>B;
}

int main(){
    int N;
    cin>>N;
    string A,B,C;
    for(int i=0;i<N;++i){
        cin>>A>>B>>C;
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        reverse(C.begin(),C.end());
        string ans=bigNumPlus(A,B);
        if(compare(ans,C)){
            printf("Case #%d: True\n",i);
        }else{
            printf("Case #%d: False\n",i);
        }
    }
    return 0;
}