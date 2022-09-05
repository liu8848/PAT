#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    set<int> a[50];
    int N,M,K;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>M;
        int num;
        for(int j=0;j<M;j++){
            cin>>num;
            a[i].insert(num);
        }
    }
    cin>>K;
    int t1,t2;
    for(int i=0;i<K;i++){
        cin>>t1>>t2;
        int len=a[t1-1].size();
        int cnt=0;
        for(auto it=a[t1-1].begin();it!=a[t1-1].end();it++){
            if (a[t2-1].count(*it))
            {
                cnt++;
            }
        }
        printf("%.1lf%\n",1.0*cnt/(a[t1-1].size()+a[t2-1].size()-cnt)*100.0);
    }
    return 0;
}