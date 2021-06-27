#include <iostream>
using namespace std;

void initial_padding(string *a,int n){
    //adds n zeroes at the beginning of the string
    string s = "";
    for(int i=0;i<n;i++)
        s += "0";
    *a = s + *a;
}

//14. Initial Unpad
void initial_unpadding(string *a){
    int i = 0;
    string b=*a;
    for(i=0;i<b.length();i++){
        if( b[i] != '0')
            break;
    }
    *a = b.substr(i,b.length());
}

bool verifyNum(string num){
    //ascii of numbers is from 48 to 57
    int len = num.length();
    for(int i=0;i<len;i++)
        if(!(num[i] >=48 && num[i]<=57  || (num[i] == '-' && i==0)))
            return false;
    return true;
}

int numCompare(string a,string b){
    //returns 1 if a>b
    //returns 0 if a==b
    //return -1 if a<b

    if(a[0] == '-' && b[0] != '-')
        return -1;
    if(a[0] != '-' && b[0] == '-')
        return 1;

    int la = a.length();
    int lb = b.length();

    if(la>lb)
        return 1;
    if(lb>la)
        return -1;

    for(int i=0;i<la;i++){
        if(a[i]>b[i])
            return 1;
        if(b[i]>a[i])
            return -1;
    }

    return 0;

}

int char_to_int(char a){
    string ch(1,a);
    if(verifyNum(ch))
        return ch[0]-48;
    return NULL;
}

//11. convert int to char
string int_to_str(int a){
    string s(1,a+48);
    return s;
}

//12. Reverse string
void reverse_string(string &a){
    int len = a.length();
    for(int i=0;i<len/2;i++){
        swap(a[i],a[len-1-i]);
    }
}

string sum(string a,string b){
    string c = "";
    bool neg = false;

    int la = a.length();
    int lb = b.length();

    la>lb?initial_padding(&b,la-lb):initial_padding(&a,lb-la);
    la = a.length();

    int carry = 0;
    int sum = 0;

    for(int i=la-1;i>=0;i--){
        int m = char_to_int(b[i]);
        int n = char_to_int(a[i]);

        sum = m + n + carry;;
        carry = sum>=10?1:0;
        sum = sum>=10?sum%10:sum;

        c = c + int_to_str(sum);
    }
    if(carry != 0)
        c += int_to_str(carry);
    reverse_string(c);
    if(neg)
        c = "-" + c;
    return c;
}


bool is_in(char a){
    string e = "EQUINOX";
    for(int j=0;j<8;j++){
        if(a == e[j])
        return true;
    }
    return false;
}

int main() {
	int tc;
	cin>>tc;
	for(int i=0;i<tc;i++){
	    int N;
	    string A,B;
	    string SARTHAK = "0", ANURADHA = "0";
	    cin>>N>>A>>B;
	    for(int i=0;i<N;i++){
	        string s;
	        cin>>s;
	        if(is_in(s[0]))
	            SARTHAK = sum(SARTHAK,A);
	        else
	            ANURADHA = sum(ANURADHA,B);
	    }
	    if(numCompare(SARTHAK,ANURADHA) == 1)
	        cout<<"SARTHAK";
	    else if(numCompare(SARTHAK,ANURADHA) == -1)
	        cout<<"ANURADHA";
	    else
	        cout<<"DRAW";
	   if(i<tc-1)
	        cout<<endl;
	}

}
