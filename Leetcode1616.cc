#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> subSort(vector<int>& array) {
    vector<int>result = array;
    sort(result.begin(),result.end());
    int left = -1;
    int right = -1;
    vector<int>resultSet;
    int count = 0;
    bool flag = true;
    for(int i=0;i<array.size();i++){
        if(array[i] != result[i]){
            if(left == -1){
                left = i;
                continue;
            }
            right = i;
        }
    }
    resultSet.push_back(left);
    resultSet.push_back(right);
    return resultSet;
}