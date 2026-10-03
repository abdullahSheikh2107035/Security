#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod(ll a,ll b){
    ll m=a-(a/b)*b;
    if(m<0){
        m+=b;
    }
    return m;
}
ll gcd(ll a,ll b){
    if(b>a){
        ll temp=a;
        a=b;
        b=temp;
    }
    if(b==0) return a;
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
    a=mod(a,m);
    ll r=1;
    while (e>0)
    {
        if (mod(e,2)==1)
        {
            r=mod(r*a,m);
        }
        a=mod(a*a,m);
        e/=2;
    }
    return r;
}
//Modular Inverse using extended euclidean algorithm

ll modinv(ll a,ll m){
    ll x,y;
    ll gcd=egcd(a,m,x,y);
    if(gcd!=1) return -1;
    if(x<0) x+=m;
    return x;

}

bool isValidE(ll e,ll phi){
    if(e>1 && e<phi && gcd(e,phi)==1){
        return true;
    }
    else return false;
}

bool isValidD(ll d,ll e,ll phi){
    if(modinv(e,phi)==d) return true;
    else return false;
}

int main(){
    ll p,q,n,phi,e,d;
    cout<<"Enter prime numbers p and q: ";
    cin>>p>>q;
    n=p*q;
    phi=(p-1)*(q-1);
    cout<<"Enter e: ";
    cin>>e;
    if(!isValidE(e,phi)){
        cout<<"Invalid e"<<endl;
        return 0;
    }
    d=modinv(e,phi);
    cout<<"Private key d: "<<d<<endl;
    if(!isValidD(d,e,phi)){
        cout<<"Invalid d"<<endl;
        return 0;
    }
    ll m1,m2;
    cout<<"Enter message m1: ";
    cin>>m1;
    cout<<"Enter message m2: ";
    cin>>m2;

    ll c1=modpow(m1,e,n);
    ll c2=modpow(m2,e,n);

    ll d1=modpow(c1,d,n);
    ll d2=modpow(c2,d,n);
    ll dec=mod(d1*d2,n);

    ll cp=mod(c1*c2,n);
    ll dec_m1m2=modpow(cp,d,n);
    ll m1m2=m1*m2;
    // Check if m1*m2 is greater than or equal to n, and reduce it modulo n if necessary
    if(m1m2>=n){
        m1m2=mod(m1m2,n);
    }
    cout<<"Public key (e,n): ("<<e<<","<<n<<")"<<endl;
    cout<<"Private key (d,p,q): ("<<d<<","<<p<<","<<q<<")"<<endl;
    cout<<"m1: "<<m1<<endl;
    cout<<"m2: "<<m2<<endl;
    cout<<"Encrypted m1: "<<c1<<endl;
    cout<<"Encrypted m2: "<<c2<<endl;
    cout<<"Decrypted m1: "<<d1<<endl;
    cout<<"Decrypted m2: "<<d2<<endl;
    cout<<"Encrypted m1m2: "<<cp<<endl;
    cout<<"Decrypted m1m2: "<<dec<<endl;
    cout<<"Encrypted m1*m2: "<<cp<<endl;
    cout<<"Decrypted Encrypted m1*m2: "<<dec_m1m2<<endl;

    if (m1m2 == dec && dec == dec_m1m2) {
        cout << "Homomorphic property holds." << endl;
    } else {
        cout << "Homomorphic property does not hold." << endl;
    }

    return 0;
}