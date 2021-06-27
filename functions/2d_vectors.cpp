#include<iostream>
#include<vector>
using namespace std;

void disp(vector<vector<int>> v,int n,int m){
    for(int i=0;i<n;i++){
        cout<<endl;
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<"\t";
        }
    }
    cout<<endl;
}

void disp(vector<int> v,int n){
    cout<<endl;
    for(auto i = v.begin(); i != v.end() ;i++)
        cout<<*i<<" ";
}

void insert(vector<vector<int>> &v,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int n;
            cin>>n;
            v[i][j] = n;
        }
    }
}

void set_at(vector<vector<int>> &v,int i,int j,int val){
    v[i][j] = val;
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int>(n,0));  //3x3 matrix initialized to zero
    disp(v,m,n);
    insert(v,m,n);
    disp(v,m,n);
    set_at(v,1,1,0);
    disp(v,m,n);



    return 0;
}
