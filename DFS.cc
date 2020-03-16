#include <iostream>
#include <vector>
using namespace std;
bool DFS(vector<vector<int>>A,vector<bool>&visit,int start,int end,int N){
    vector<int> templist = A[start];
    for(int i=0;i<N;i++){
        if(templist[i] == 1 && i== end)
            return true;
        if(templist[i] == 1 && i != end && visit[i]==false){
            visit[i] = true;
            if(DFS(A,visit,i,end,N))
                return true;
            visit[i] = false;
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
    vector<bool>visit(N,false);
    cout<<DFS(A,visit,start,end,N)<<endl;
    return 0;
}