// #include<iostream>
// #include<vector>
// #include<string>
// #include<algorithm>
// using namespace std;

// class stack_
// {
// public:
//     stack_()=default;
//     ~stack_()=default;

//     void Pop(){
//         if(top==-1){
//             cout<<"Invalid"<<endl;
//         }
//         else{
//             cout<<sta[top]<<endl;
//             sta.pop_back();
//             top--;
//         }
//     }

//     void Push(int val){
//         sta.push_back(val);
//         top++;
//         // cout<<val<<endl;
//     }

//     void PeekMedian(){
//         if(top==-1){
//             cout<<"Invalid"<<endl;
//             return;
//         }
//         vector<int>temp=sta;
//         sort(temp.begin(),temp.end());
//         int n=temp.size();
//         if(n%2==0){
//             cout<<temp[n/2-1]<<endl;
//         }else{
//             cout<<temp[(n+1)/2-1]<<endl;
//         }
//     }

// private:
//     vector<int> sta;
//     int top=-1;
// };


// int main(){
//     int N;
//     cin>>N;
//     stack_ st;
//     string ope;
//     for(int i=0;i<N;i++){
//         cin>>ope;
//         if(ope=="Pop"){
//             st.Pop();
//         }else if(ope=="PeekMedian"){
//             st.PeekMedian();
//         }else{
//             int val;
//             cin>>val;
//             st.Push(val);
//         }
//     }
//     return 0;
// }


#include<cstdio>
#include<stack>
using namespace std;

const int _size=100000;
const int capi=500;
int bucket[_size/capi][capi];
int _count[_size/capi];

int getmid(int size){
    int ind=(size+1)/2,cnt=0,i,j;
    for(i=0;i<_size;i++){
        if(cnt + _count[i]>=ind) break;
        cnt+=_count[i];
    }
    for(j=0;j<capi;j++){
        cnt+=bucket[i][j];
        if(cnt>=ind)
            return j+i*capi;
    }
    return 0;
}

char str[10];
int main(){
    int n,tmp;
    scanf("%d",&n);
    stack<int> s;
    while(n--){
        scanf("%s",str);
        switch (str[1]) 
        {
        case 'e':{
            if(s.empty())
                printf("Invalid\n");
            else
                printf("%d\n",getmid(s.size())+1);
            break;
        }
        case 'o':{
            if(s.empty()){
                printf("Invalid\n");
            }
            else{
                tmp=s.top();
                s.pop();
                printf("%d\n",tmp);
                tmp--;
                bucket[tmp/capi][tmp%capi]--;
                _count[tmp/capi]--;
            }
            break;
        }
        case 'u':{
            scanf("%d",&tmp);s.push(tmp);
            tmp--;
            bucket[tmp/capi][tmp%capi]++;
			_count[tmp/capi]++;
        }
        break;
        }
    }
    return 0;
}