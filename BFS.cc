#include <iostream>
#include <vector>
#include <list>
using namespace std;
bool BFS(vector<vector<int>>& A,int start,int end,int N){
    list<int> List;
    vector<bool>visit(N,false);
    visit[start] = true;
    List.push_back(start);
    while(!List.empty()){
        int temp = List.front();
        List.pop_front();
        vector<int>templist = A[temp];
        for(int i=0;i<templist.size();i++){
            if(i == end && templist[i] == 1)
                return true;
            if(visit[i] == false && templist[i] == 1){
                visit[i] = true;
                List.push_back(i);
            }
        }
    }
    return false;
}
int main(){
    int N;
    cout<<"Please input the N:";
    cin >> N;
    cout<<"Please input the start:";
    int start = 0;
    cin>>start;
    cout<<"Please input the end:";
    int end = 0;
    cin>>end;
    vector<vector<int>>A;
    vector<int>A1(N);
    for(int i=0;i<N;i++){
        A.push_back(A1);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
        cout<<endl;
    }
    cout<<BFS(A,start,end,N);
    return 0;
}