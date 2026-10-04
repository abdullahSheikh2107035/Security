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
    cout<<"Enter random num k (1<x<p-1 and gcd(k,p-1)=1):"<<endl;
    cin>>k;
    cout<<"Enter private key x(1<x<p-1):"<<endl;
    cin>>x;
    beta=modpow(alpha,x,p);
    cout<<"Enter random r1 :"<<endl;
    cin>>r1;
    cout<<"Enter random r2 :"<<endl;
    cin>>r2;
    cout<<"Enter message m :"<<endl;
    cin>>m;
    cout<<"Enter message m1 :"<<endl;
    cin>>m1;
    cout<<"Enter message m2 :"<<endl;
    cin>>m2;
    //Homomorphic
    ll c11=modpow(alpha,r1,p);
    ll c12=mod(m1*modpow(beta,r1,p),p);
    ll s1=modpow(c11,x,p);
    ll dec1=mod(c12*modinv(s1,p),p);

    ll c21=modpow(alpha,r2,p);
    ll c22=mod(m2*modpow(beta,r2,p),p);
    ll s2=modpow(c21,x,p);
    ll dec2=mod(c22*modinv(s2,p),p);
    ll m1m2=m1*m2;
    if(m1m2>p-1){m1m2=mod(m1m2,p);}
    ll cp1=modpow(alpha,k,p);
    ll cp2=mod(m1m2*modpow(beta,k,p),p);
    ll sp=modpow(cp1,x,p);
    ll decm1m2=mod(cp2*modinv(sp,p),p);


    ll c1=mod(c11*c21,p);
    ll c2=mod(c12*c22,p);
    ll s=modpow(c1,x,p);
    ll dechomo=mod(c2*modinv(s,p),p);

    cout<<"public key p,alpha,beta :("<<p<<" "<<alpha<<" "<<beta<<")"<<endl;
    cout<<"private key x :("<<x<<")"<<endl;
    cout<<"message m1 :("<<m1<<")"<<endl;
    cout<<"message m2 :("<<m2<<")"<<endl;
    cout<<"message m1m2 :("<<m1m2<<")"<<endl;
    cout<<"c11   "<<c11<<endl;
    cout<<"c12   "<<c12<<endl;
    cout<<"dec1  "<<dec1<<endl;
    cout<<"c21   "<<c21<<endl;
    cout<<"c22   "<<c22<<endl;
    cout<<"dec2  "<<dec2<<endl;
    cout<<"cp1   "<<cp1<<endl;
    cout<<"cp2   "<<cp2<<endl;
    cout<<"decm1m2  :"<<decm1m2<<endl;
    cout<<"c1  :"<<c1<<endl;
    cout<<"c2   :"<<c2<<endl;
    cout<<"dechomo   :"<<dechomo<<endl;

}
