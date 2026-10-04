#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod(ll a, ll b)
{
    ll m = a - (a / b) * b;
    if (m < 0)
        m += b;
    return m;
}
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        ll temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
        return a;
    return gcd(b, mod(a, b));
}
ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = egcd(b, mod(a, b), x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
ll modpow(ll a, ll e, ll m)
{
    a = mod(a, m);
    ll r = 1;
    while (e > 0)
    {
        if (mod(e, 2) == 1)
        {
            r = mod(r * a, m);
        }
        a = mod(a * a, m);
        e = e / 2;
    }
    return r;
}
ll modinv(ll a, ll m)
{
    ll x, y;
    ll gcd = egcd(a, m, x, y);
    if (gcd != 1)
        return -1;
    if (x < 0)
        x += m;
    return x;
}

int main(){
    ll p,alpha,beta,k,x;
    cout<<"Enter prime number p : ";
    cin>>p;
    cout<<"Enter primitive root alpha(1<alpha<p-1) : ";
    cin>>alpha;
cout<<"Enter random number k(1<k<p-1 and gcd(k,p-1)=1) : ";
    cin>>k;
    cout<<"Enter private key x (1<x<p-1): ";
    cin>>x;
    beta=modpow(alpha,x,p);
    ll m;
    cout<<"Enter message (1<m<p-1):"<<endl;
    cin>>m;
    //encrypt-decrypt
    ll c1=modpow(alpha,k,p);
    ll c2=m*modpow(beta,k,p);

    ll s=modpow(c1,x,p);
    ll s_inv=modinv(s,p);
    ll dec=mod(c2*s_inv,p);

    //signature
    ll y1=modpow(alpha,k,p);
    ll k_inv=modinv(k,p-1);
    ll y2=mod((m-x*y1)*k_inv,p-1);
    ll lhs=mod(modpow(y1,y2,p)*modpow(beta,y1,p),p);
    ll rhs=modpow(alpha,m,p);
  
    cout<<"prime number p : "<<p<<endl;
    cout<<"primitive root alpha : "<<alpha<<endl;
    cout<<"private key x : "<<x<<endl;
    cout<<"public key beta : "<<beta<<endl;
    cout<<"random number k : "<<k<<endl;
    cout<<"message : "<<m<<endl;
    cout<<"ciphertext c1 : "<<c1<<endl;
    cout<<"ciphertext c2 : "<<c2<<endl;
    cout<<"decrypted message : "<<dec<<endl;
    cout<<"signature y1 : "<<y1<<endl;
    cout<<"signature y2 : "<<y2<<endl;
    cout<<"lhs : "<<lhs<<endl;
    cout<<"rhs : "<<rhs<<endl;
      if(lhs==rhs){
        cout<<"Signature is valid"<<endl;
    }
    else{
        cout<<"Signature is invalid"<<endl;
    }



}