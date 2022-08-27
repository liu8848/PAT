#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

struct student
{
    string Name;
    string Gender;
    string ID;
    int Grade;
    student(string name,string gender,string id,int grade):Name(name),Gender(gender),ID(id),Grade(grade){}
};


int main(){
    string line;
    istringstream s;
    int N;
    getline(cin,line);
    s.str(line);
    s>>N;
    vector<student> male;
    vector<student> female;
    string name,gender,id;
    int grade;
    for(int i=0;i<N;i++){
        s.clear();
        getline(cin,line);
        s.str(line);
        s>>name>>gender>>id>>grade;
        student stu(name,gender,id,grade);
        if(gender=="M"){
            male.push_back(stu);
        }else{
            female.push_back(stu);
        }
    }
    auto compare=[](const student&lhs,const student&rhs){return lhs.Grade<rhs.Grade;};
    sort(male.begin(),male.end(),compare);
    sort(female.begin(),female.end(),compare);
    int f_index=-1,m_index=-1;
    if(female.size()<=0) {cout<<"Absent"<<endl;}
    else{
        f_index=female.size()-1;
        cout<<female[f_index].Name<<" "<<female[f_index].ID<<endl;
    }
    if(male.size()<=0) cout<<"Absent"<<endl;
    else{
        m_index=0;
        cout<<male[m_index].Name<<" "<<male[m_index].ID<<endl;
    }
    if(f_index==-1||m_index==-1){
        cout<<"NA"<<endl;
    }
    else{
        cout<<abs(male[m_index].Grade-female[f_index].Grade)<<endl;
    }
    return 0;
}