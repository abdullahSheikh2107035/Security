#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod(ll a,ll b){
    ll m=a-(a/b)*b;
    if(m<0)
    {
        m+=b;
    }
    return m;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    if(b>a){
        ll temp=a;
        a=b;
        b=temp;
    }
    return gcd(b,mod(a,b));
}
ll egcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    ll x1,y1;
    ll gcd=egcd(b,mod(a,b),x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return gcd;
}
ll modpow(ll a,ll e,ll m){
    a=mod(a,m);ll r=1;
    while (e>0)
    {
        if(mod(e,2)==1){
            r=mod(r*a,m);
        }
        a=mod(a*a,m);
        e/=2;
    }
    return r;
    
}
ll modinv(ll a,ll m){
    ll x,y;
    ll gcd=egcd(a,m,x,y);
    if(gcd!=1){
        return -1;
    }
    if(x<0) x+=m;
    return x;
}

int main(){
    ll p,alpha,beta,r1,r2,k,x,m,m1,m2;
    cout<<"Enter prime p :"<<endl;
    cin>>p;
    cout<<"Enter alpha :"<<endl;
    cin>>alpha;
    cout<<"Enter private key x(1<x<p-1):"<<endl;
    cin>>x;
    beta=modpow(alpha,x,p);
    cout<<"Enter random r1 :"<<endl;
    cin>>r1;
    cout<<"Enter random r2 :"<<endl;
    cin>>r2;
    cout<<"Enter message m :"<<endl;
    cin>>m;

    ll c11=modpow(alpha,r1,p);
    ll c12=mod(m*modpow(beta,r1,p),p);
    ll c21=mod(c11*modpow(alpha,r2,p),p);
    ll c22=mod(c12*modpow(beta,r2,p),p);
    ll s=modpow(c21,x,p);
    ll dec=mod(c22*modinv(s,p),p);
    
    cout<<"message m :"<<m<<endl;
    cout<<"Ciphertext 1 : ("<<c11<<","<<c12<<")"<<endl;
    cout<<"Ciphertext 2 : ("<<c21<<","<<c22<<")"<<endl;
    cout<<"Decrypted message : "<<dec<<endl;
}