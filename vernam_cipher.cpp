#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod(ll x, ll m)
{
    while (x < 0)
    {
        x += m;
    }
    while (x >= m)
    {
        x -= m;
    }
    return x;
}

ll XOR(ll a, ll b)
{
    ll res = 0;
    ll p = 1;
    while (a + b > 0)
    {
        ll x = mod(a, 2);
        ll y = mod(b, 2);
        res += (x + y - 2 * x * y) * p;
        a /= 2;
        b /= 2;
        p *= 2;
    }

    return res;
}

string encrypt(string m,string k){
    if(k.empty()){
        cout<<"Key is empty"<<endl;
        return "";
    }
    if(m.length()!=k.length()){
        cout<<"Key and message length mismatch"<<endl;
        return "";
    }
    string en;
    for (ll i = 0; i < m.length(); i++)
    {
        unsigned char a = m[i];
        unsigned char b = k[mod(i,k.length())];
        en+=char(XOR(a,b));
    }
    return en;
    
}

string toHex(string s){
    string hex="0123456789ABCDEF";
    string res="";
    for ( unsigned char c : s)
    {
        res+=hex[c/16];
        res+=hex[mod(c,16)];
    }
    return res;
    
}

int main(){
    
    string m,k;
    cout<<"Enter message and key"<<endl;
    getline(cin,m);
    getline(cin,k);
    cout<<"Message :" <<m<<endl;
    cout<<"Hex MESSAGE :"<<toHex(m)<<endl;
    string en=encrypt(m,k);
    string dec=encrypt(en,k);
    cout<<"Encrypted Message :" <<toHex(en)<<endl;
    cout<<"Decrypted Message :" <<toHex(dec) <<endl;
}