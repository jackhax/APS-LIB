#include<iostream>
using namespace std;

template <typename T>
void swap(T *a,T *b){
    T c = *a;
    *a = *b;
    *b = c;
}

int min(int a,int b){
    return a>=b?b:a;
}

int max(int a,int b){
    return a>=b?a:b;
}

//9. verify if the string is number
bool verifyNum(string num){
    //ascii of numbers is from 48 to 57
    int len = num.length();
    for(int i=0;i<len;i++)
        if(!(num[i] >=48 && num[i]<=57  || (num[i] == '-' && i==0)))
            return false;
    return true;
}

//10. convert char to int
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

//13. Initial pad
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

//15. Number compare
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

string substract(string a,string b);
//16. ADD
string sum(string a,string b){
    string c = "";
    bool neg = false;

    if(a[0] == '-' && b[0] != '-'){
        return substract(b,a.substr(1,a.length()-1));
    }

    if(b[0] == '-' && a[0] != '-'){
        return substract(a,b.substr(1,b.length()-1));
    }

    if(b[0] == '-' && a[0] == '-'){
        neg = true;
        a = a.substr(1,a.length()-1);
        b = b.substr(1,b.length()-1);
    }

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

//17. Substract
string substract(string a,string b){
    string c = "";
    bool neg = false;

    if(b[0] == '-' && a[0] != '-'){
        return sum(a,b.substr(1,b.length()-1));
    }

    if(a[0] == '-' && b[0] != '-'){
        return sum(a,"-"+b);
    }

    if(a[0] == '-' && b[0] == '-'){
        a = a.substr(1,a.length()-1);
        b = b.substr(1,b.length()-1);
        swap(a,b);
    }

    if(numCompare(a,b) == -1){
        swap(a,b);
        neg = true;
    }

    int la = a.length();
    int lb = b.length();

    la>lb?initial_padding(&b,la-lb):initial_padding(&a,lb-la);
    la = a.length();

    int carry = 0;
    int sum = 0;

    for(int i=la-1;i>=0;i--){
        int m = char_to_int(a[i]);
        int n = char_to_int(b[i]);

        sum = m - carry - n;
        sum = sum<0?((m-carry+10)-n):sum;
        carry = (m-n-carry)<0?1:0;
        c = c + int_to_str(sum);
    }
    reverse_string(c);
    initial_unpadding(&c);
    if(c=="")
        c = "0";
    if((carry == 1 || neg))
        c = "-" + c;
    return c;
}

//18. Mul
string mul(string a,string b){
    string c="";
    bool neg = false;

    if(a[0] == '-' && b[0] != '-'){
        neg = true;
        a = a.substr(1,a.length()-1);
    }
    if(a[0] != '-' && b[0] == '-'){
        neg = true;
        b = b.substr(1,b.length()-1);
    }
    if(a[0] == '-' && b[0] == '-'){
        a = a.substr(1,a.length()-1);
        b = b.substr(1,b.length()-1);
    }

    if(a.length()<b.length())
        swap(&a,&b);



    int la = a.length();
    int lb = b.length();

    int summ=0;
    int carry = 0;

    string prod = "0";

    for(int i=lb-1;i>=0;i--){
        string s = "";
        carry = 0;
        int m = char_to_int(b[i]);
        for(int j=la-1;j>=0;j--){
            int n = char_to_int(a[j]);
            summ = m*n + carry;
            carry = summ>=10?summ/10:0;
            summ = summ>=10?summ%10:summ;
            s += int_to_str(summ);
        }
        if(carry!=0)
            s += int_to_str(carry);
        initial_padding(&s,(lb-1)-i);
        reverse_string(s);
        prod = sum(prod,s);
    }
    initial_unpadding(&prod);
    if(prod == "")
        prod = "0";
    if(neg)
        prod = "-"+prod;
    return prod;
}

//19. Factorial
string factorial(string a){
    string f="1",c="0";
    while(numCompare(c,a) == -1){
        c = sum(c,"1");
        f = mul(f,c);
    }
    return f;
}
