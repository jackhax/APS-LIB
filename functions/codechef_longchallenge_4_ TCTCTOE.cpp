#include<iostream>
#include<vector>
using namespace std;

int check1(vector<int> board,char c){
    if ((board[0][0] == ch)&&(board[0][0] == board[0][1])&&(board[0][0] == board[0][2]))
        return 1;
    if ((board[0][0] == ch)&&(board[1][0] == board[0][0])&&(board[0][0] == board[0][2]))
        return 1;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        vector<string> matrix(3,"___");
        for(int i=0;i<3;i++){
            cin>>matrix[i];
        }
    }
}

/*
int X = 0;
int O = 0;

int x = 0;
int o = 0;

void disp(vector<string> v){
    for(int i=0;i<3;i++){
        cout<<endl;
        for(int j=0;j<3;j++){
            cout<<v[i][j]<<" ";
        }
    }
}

void input(vector<string> &v){
    for(int i=0;i<3;i++){
        cin>>v[i];
    }
}

int checkH(vector<string> v){
    int c = 0;
    if((v[0][0] == v[0][1] && v[0][1] == v[0][2]) && v[0][0] != '_')
    {
        if(v[0][0] == 'X')
            X++;
        else
            O++;
    }
    if(v[1][0] == v[1][1] && v[1][1] == v[1][2] && v[1][0] != '_')
    {
        if(v[1][0] == 'X')
            X++;
        else
            O++;
    }
    if(v[2][0] == v[2][1] && v[2][1] == v[2][2] && v[2][0] != '_')
    {
        if(v[2][0] == 'X')
            X++;
        else
            O++;
    }
    return X+O;
}

int checkV(vector<string> v){
    int c = 0;
    if((v[0][0] == v[1][0] && v[1][0] == v[2][0] && v[0][0] != '_'))
    {
        if(v[0][0] == 'X')
            X++;
        else
            O++;
    }
    if(v[0][1] == v[1][1] && v[1][1] == v[2][1] && v[0][1] != '_')
    {
        if(v[0][1] == 'X')
            X++;
        else
            O++;
    }
    if(v[0][2] == v[1][2] && v[1][2] == v[2][2] && v[0][2] != '_')
    {
        if(v[0][2] == 'X')
            X++;
        else
            O++;
    }
    return X+O;
}

int checkD(vector<string> v){
    int c = 0;
    if(v[0][0] == v[1][1] && v[1][1] == v[2][2] && v[0][0] != '_')
    {
        if(v[0][0] == 'X')
            X++;
        else
            O++;
    }
    if(v[0][2] == v[1][1] && v[1][1] == v[2][0] && v[1][1] != '_')
    {
        if(v[0][2] == 'X')
            X++;
        else
            O++;
    }
    return X+O;
}

int solve(vector<string> v){
    int unchecked=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(v[i][j] == '_')
                unchecked++;
            else if(v[i][j] == 'X')
                x++;
            else
                o++;
    if(o>x)
        return 3;
    if(x-o>1)
        return 3;
    bool xwin = false,owin=false;

    int h = checkH(v),V = checkV(v),d = checkD(v);
    int c = h+V+d;
    if(c==0 && x-o==1 )
        return 2;
    if(c==3)
        return 3;
    if(c==1 && X==1)
        xwin = true;
    if(c==1 && O==1)
        owin == true;

    if(X==1 && O==1)
        return 3;
    if(c==2 && ((V==1 && h==1) || (V==1 && d==1) || (h==1 && d==1) || (d==2)) && (X==2) && (unchecked%2==0))
        return 1;
    if(unchecked >=1 && c==0)
        return 2;
    if((xwin && x==o) || (owin && x>o))
        return 3;
    if(xwin || owin)
        return 1;

    return 3;

}

int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc;i++){
        X = 0;
        O = 0;
        x = 0;
        o = 0;
        vector<string> v(3,"___");
        input(v);
        cout<<solve(v)<<endl;
    }

    return 0;
}
*/
