#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

long long charValue(char c){
    if(c>='0'&&c<='9') return c-'0';
    else return c-'a'+10;
}

//将字符串从rad进制转为十进制
long long translate(string str,int rad){
    long long res=0;
    for(long long i=str.size()-1,wei=1;i>=0;i--,wei*=rad){
        long long j=charValue(str[i]);
        res+=j*wei;
    }
    return res;
}

long long transCompare(string str,long long rad,long long value){
    long long res=0;
    for(long long i=str.size()-1,wei=1;i>=0;i--,wei*=rad){
        long long j=charValue(str[i]);
        res+=j*wei;
        if(res>value) return 1;
    }
    if(res>value) return 1;
    if (res==value)
    {
        return 0;
    }
    if(res<value) return -1;
    
}

int main(){
    string N1,N2;
    long long tag,radix;

    cin>>N1>>N2>>tag>>radix;

    if(tag==2){
        swap(N1,N2);
    }

    long long value=translate(N1,radix);

    long long maxN2=0;
    for(long long pos=0;pos<N2.size();pos++){
        long long v=charValue(N2[pos]);
        if(v>maxN2){
            maxN2=v;
        }
    }
    if (translate(N2,maxN2+1)==value)
    {
        cout<<maxN2+1;
        return 0;        
    }

    long long left,right;
    for(left=maxN2+1,right=INT_MAX;left<=right;){
        long long mid=(left+right)/2;
        int com=transCompare(N2,mid,value);
        if(com==0){
            cout<<mid;
            return 0;
        }
        if(com==-1){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    cout<<"Impossible";
    return 0;
    
}