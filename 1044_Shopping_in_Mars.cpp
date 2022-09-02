#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    vector<int> diamonds(N+1);
    for(int i=1;i<=N;i++){
        cin>>diamonds[i];
    }

    int left=1,right=1;
    bool tag=false;
    int minVal=INT_MIN;
    vector<string> res;
    while(right<=N){
        // while(M>0&&left<=right){
        //     M-=diamonds[right];
        //     right++;
        // }
        M-=diamonds[right];
        right++;
        if(M==0){
            cout<<left<<"-"<<right-1<<endl;
            tag=true;
        }
        while(left<right&&M<0){
            M+=diamonds[left++];
            if(M==0){
                cout<<left<<"-"<<right-1<<endl;
            }
            if(M<0){
                if(M>minVal){
                    res.clear();
                    minVal=M;
                }
                if(M==minVal)
                    res.push_back(to_string(left)+"-"+to_string(right-1));
            }
        }
    }
    if(!tag){
        for(auto s:res)
            cout<<s<<endl;
    }
    return 0;
}