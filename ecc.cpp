#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll a,b,c;

struct point{
    ll x;ll y;
    bool inf;
    point(ll x,ll y,bool inf=false)
    {
        this->x=x;
        this->y=y;
        this->inf=inf;
    }
};

ll mod(ll a,ll b){
    ll m=a-(a/b)*b;
    if(m<0)
    {
        m+=b;
    }
    return m;
}
ll modinv(ll n,ll p){
    n=mod(n,p);
    if(n<0) n+=a;
    for (ll i = 1; i < p; i++)
    {
        if(mod(n*i,p)==1)
        {
            return i;
        }
    }
    
}

point add(point p,point q){
    if(p.inf) return q;
    if(q.inf) return p;
    if((p.x==q.x) && mod(p.y+q.y,a)==0) return point(0,0,true);
    ll s;
    if(p.x==q.x && p.y==q.y){
        s=mod((3*p.x*p.x + b)*modinv(2*p.y,a),a);
    } 
    else{
        s=mod((q.y-p.y)*modinv(q.x-p.x,a),a);
    }
    s=mod(s+a,a);
    ll x3,y3;
    x3=mod(s*s-p.x-q.x,a);
    x3=mod(x3+a,a);
    y3=mod(s*(p.x-x3)-p.y,a);
    return point(x3,y3);
}

point mul(ll k,point P){
    point r(0,0,true);
    while (k>0)
    {
        if(mod(k,2)==1){
            r=add(r,P);
        }
        P=add(P,P);
        k/=2;
    }
    return r;    
}

point pneg(point P){
    if(P.inf) return P;
    return point(P.x,mod(a-P.y,a));
}

void print(string name,point p){
    cout<<name<<" :";
    if(p.inf) cout<<"O"<<endl;
    else {
        cout<<"("<<p.x<<","<<p.y<<")"<<endl;
    }
}

int main(){
    cout<<"ENTER PRIME a ,Curve b,c "<<endl;
    cin>>a>>b>>c;
    point G(5,1);
    ll m1,m2,k1,k2,d;
    cout<<"enter m1,m2,k1,k2"<<endl;
    cin>>m1>>m2>>k1>>k2>>d;
    point pm1=mul(m1,G);
    point pm2=mul(m2,G);
    point Q=mul(d,G);

    point c11=mul(k1,G);
    point c12=add(pm1,mul(k1,Q));
    point c21=mul(k2,G);
    point c22=add(pm2,mul(k2,Q));

    point c1=add(c11,c21);
    point c2=add(c12,c22);

    point expected=add(pm1,pm2);
    point decp=add(c2,pneg(mul(d,c1)));
    print("pm1",pm1);
    print("pm2",pm2);
    print("ex",expected);
    print("dec",decp);


 // rerand

    ll s;
    cout<<"ENTER FRESH s"<<endl;
    cin>>s;
    point r1=mul(s,G);
    point r2=mul(s,Q);

    point c1p=add(c11,r1);
    point c2p=add(c12,r2);
    point decrp=add(c2p,pneg(mul(d,c1p)));

    print("decrp",decrp);
    


}