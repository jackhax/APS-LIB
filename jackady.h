#include<iostream>
#include <cstring>
#include<string.h>
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

//1
int set_bits(int a){
    int c = 0;
    while(a){
        a = a & (a-1);
        c++;
    }
    return c;
}

//2
int unset_bits(int a){
    int c=0;
    while(a){
        if((a&1)==0)
            c++;
        a=a>>1;
    }
    return c;
}

//3
int mask_bits(int val,int mask){
    /*

    Bit-Masking means imposing mask over bits. Here is a bit-masking with AND-

     1 1 1 0 1 1 0 1   [input]
(&)  0 0 1 1 1 1 0 0    [mask]
------------------------------
     0 0 1 0 1 1 0 0  [output]

    */
    return val&mask;
}




//4. return nCk
int binomial_coeff(int n,int k){
    int arr[k+1];
    memset(arr,0,sizeof(arr));
    arr[0] = 1;

    for(int i=1;i<=n;i++)
        for(int j=min(i,k);j>0;j--)
            arr[j] += arr[j-1];

    return arr[k];
}

//5. length of longest common subsequence:
int lcs_len(string a,string b){
    int al = a.length();
    int bl = b.length();

    int mat[al+1][bl+1];

    for(int i=0;i<=al;i++)
        for(int j=0 ;j<=bl ;j++)
            if(i==0 || j==0)
                mat[i][j] = 0;

    for(int i=1 ; i<=al ; i++){
        for(int j=1 ; j<=bl ; j++){
            if(a[i-1]==b[j-1])
                mat[i][j] = mat[i-1][j-1] + 1;
            else
                mat[i][j] = max(mat[i][j-1],mat[i-1][j]);
        }
    }
    return mat[al][bl];
}

//6.
string toggle_case(string a){
    int l = a.length();
    for(int i=0;i<l;i++){
        if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122))
            if(a[i]>=97)
                a[i] = a[i] & (~32);
            else
                a[i] = a[i] | 32;
    }
    return a;
}

template <typename T>
int partition (T arr[], int low, int high)
{
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//7 Quick Sort.
template <typename T>
void quick_sort(T arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

//8. Number of ways to get a number using sum of 3,5,10
//Ex to get 15: 3+3+3+3+3,5+5+5,10+5 there are 3 ways
int combination(int n){
    int *arr = new int(n+1);

    if(arr == NULL)
        return -1;

    for(int i=0;i<=n;i++)
        arr[i] = 0;
    arr[0] = 1;

    for(int i=3;i<=n;i++)
        arr[i] = arr[i] + arr[i-3];

    for(int i=5;i<=n;i++)
        arr[i] = arr[i] + arr[i-5];

    for(int i=10;i<=n;i++)
        arr[i] = arr[i] + arr[i-10];

    return arr[n];
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
    int la = a.length();
    int lb = b.length();

}
