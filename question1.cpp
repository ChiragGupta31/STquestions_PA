//Chirag Gupta
//2010990173
//SET-02

#include <bits/stdc++.h>
using namespace std;


//declared long vector for mean

long mean(vector<long> grades){
    return accumulate(begin(grades), end(grades), (long)0)/grades.size();
}


//declared long vector for median
long median(vector<long> grades, int size){
    sort(begin(grades), end(grades));
    
    if(size % 2 != 0){
        return grades[size/2];
    }
    
    int a = size/2;
    int b = a + 1;
    
    return (grades[a] + grades[b])/2; 
}


//calculating mode 

pair<vector<string>, int> mode(vector<string> names, vector<long> grades){
    unordered_map<int, int> mymap;
    
    for(int i=0; i<grades.size(); i++)
        mymap[grades[i]]++;
    
    int key, val = 0;
    for(auto& p: mymap){
        if(p.second > val)
            key = p.first;
    }
    
    pair<vector<string>, int> ans;
    vector<string> studentsWithMode;
    for(int i=0; i<grades.size(); i++){
        if(grades[i] == mymap[key])
            studentsWithMode.push_back(names[i]);
    }
    
    return ans;
}

int main()
{
    vector<string> names;
    vector<long> grades;


    //taken user input for the number of name/grade pairs that will be entered.
    cout<<"Enter no. of pairs: "<<endl;
    int num;
    cin>>num;
    
    int grade;
    string name;
   
    
    //taking use input for names and grades of students
    for(int i=0; i<num; i++){
        cin>>name>>grade;
        names.push_back(name);
        grades.push_back(grade);
    }


    //displaying mean and median

    cout<<"mean of the grades: "<<mean(grades)<<endl;
    cout<<"median of the grades: "<<median(grades, num)<<endl;

    //displaying mode

    pair<vector<string>, int> p = mode(names, grades);
    cout<<"mode of the grades: "<<p.second<<endl<<"students with the mode ";
    for(int i=0; p.first.size(); i++){
        cout<<p.first[i]<<" ";
    }
        
    return 0;
}