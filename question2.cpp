//Chirag Gupta
//2010990173
//SET-02


#include <bits/stdc++.h>
using namespace std;

void sort_map_values(map<int, int> mymap)
{
    //declared comparator
    auto comp = [](pair<int, int> one, pair<int, int> two) {
        
        //if value for the first element is greater
        // then swap value
        
        if (one.second > two.second)
            return false;
            
        //if value for the first element is lower
        // then don't swap
        
        else if (one.second < two.second)
            return true;
            
        //if values are same for the elements
        
        else { 
            if (one.first < two.first) {
                return false;
            }
            else
                return true;
        }
    };

    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> pqu(comp);

    for (auto& ij : mymap) {
        pqu.push(ij);
    }
    
    
    //Print the sorted map
    cout << "key value\n";
    while (!pqu.empty()) {
        cout << pqu.top().first << "    " << pqu.top().second << endl;
        pqu.pop();
    }
}

void print(map<int, int> mymap)
{
    cout << "key value\n";
    for (auto & [ key, value ] : mymap)
        cout << key << "   " << value << endl;
}

int main()
{
    map<int, int> mymap;
 
    mymap[1] = 6;
    mymap[2] = 8;
    mymap[6] = 3;
    mymap[9] = 8;
 
    cout << "Before sorting given map is:\n";
    print(mymap);
 
    cout << "After sorting based on value new map is: \n";
    sort_map_values(mymap);

    return 0;
}
