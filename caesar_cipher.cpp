#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll mod(ll x, ll m){
  while(x<0) x+=m;
  while(x>=m) x-=m;
  return x;
}

string encrypt(string s,int k){
  string res="";
  for(ll i=0;i<s.length();i++){
    if(isupper(s[i])){
      res+=char(mod((ll(s[i])+k-65),26)+65);
    }
    else if(islower(s[i])){
      res+=char(mod((ll(s[i])+k-97),26)+97);
    }
    else{
      res+=s[i];
    }
  }
  return res;
}
int main() {
  string s;
  getline(cin,s);
  ll k;
  cin>>k;
  cout<<"Message :" <<s<<endl;
  string en=encrypt(s,k);
  string dec=encrypt(en,-k);
  cout<<"Encrypted Message :" << en <<endl;
  cout<<"Decrypted Message :" <<dec<<endl;
}