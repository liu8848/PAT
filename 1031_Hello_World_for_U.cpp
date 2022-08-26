#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    string line;
    getline(cin,line);
    int N=line.size();
    int n2=3;
    int n1,n3;
    while (n2<=N-2)
    {
        if((N-n2)%2!=0){
            n2++;
            continue;
        }
        else{
            n1=(N-n2)/2;
            if(n1+1<=n2) break;       
        }
        n2++;
    }
    for(int i=0;i<n1;i++){
        cout<<line[i]<<string(n2-2,' ')<<line[N-i-1]<<endl;
    }
    cout<<line.substr(n1,n2);
    return 0;
}