#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll mod(ll a,ll b){
    ll m=a-(a/b)*b;
    if(m<0) m+=b;
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
    a=mod(a,m);
    ll r=1;
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

bool isValidE(ll e,ll phi){
    if(e>1 && e<phi && gcd(e,phi)==1) return true;
    else return false;
}
bool isValidD(ll d,ll e,ll phi)
{
    if(modinv(e,phi)==d) return true;
    else return false;
}

int main(){
    ll p, q, n, phi, e, d;
    cout << "Enter prime numbers p and q: ";
    cin >> p >> q;

    n = p * q;
    phi = (p - 1) * (q - 1);

    cout << "Enter e: ";
    cin >> e;
    if (!isValidE(e, phi)) {
        cout << "Invalid value of e" << endl;
        return 1;
    }

    // cout << "Enter d: ";
    // cin >> d;
    // if (!isValidD(d, e, phi)) {
    //     cout << "Invalid value of d" << endl;
    //     return 1;
    // }

    ll m;
    cout << "Enter message m: ";
    cin >> m;

    ll c = modpow(m, e, n);
    ll i;
    for (i = 1; i < phi; i++) {
        if (modpow(c, i, n) == m) {
            cout << "Found d: " << i << endl;
            break; 
        }
    }

    ll dec = modpow(c, i, n);

    cout<<"public key (e, n): (" << e << ", " << n << ")" << endl;
    cout<<"private key (d, p, q): (" << i << ", " << p << ", " << q << ")" << endl;
    cout<<"message: " << m << endl;
    cout<<"ciphertext: " << c << endl;
    cout<<"decrypted message: " << dec << endl;
    if (dec == m) {
        cout << "Valid private key d :"<<i<<"found"<< endl;
    }

    return 0;
}

    