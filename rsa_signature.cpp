#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod(ll a, ll b){
    ll m = a-(a/b)*b;
    if(m<0)
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
    if (gcd!=1)
    {
        return -1;
    }
    if (x < 0)
        x += m;
    return x;
}

bool isValidE(ll e, ll phi)
{
    if (e > 1 && e < phi && gcd(e, phi) == 1)
    {
        return true;
    }
    else
        return false;
}

bool isValidD(ll e, ll d, ll phi)
{
    if (modinv(e, phi) == d)
        return true;
    else
        return false;
}

int main()
{
    // SENDERS KEY GENERATION
    ll ps, qs, ns, phi_s, es, ds;
    cout << "Enter senders prime numbers p and q: ";
    cin >> ps >> qs;
    ns = ps * qs;
    phi_s = (ps - 1) * (qs - 1);
    cout << "Enter e: ";
    cin >> es;
    if (!isValidE(es, phi_s))
    {
        cout << "Invalid e" << endl;
        return 0;
    }
    ds = modinv(es, phi_s);
    if (!isValidD(es, ds, phi_s))
    {
        cout << "Invalid d" << endl;
        return 0;
    }

    // RECEIVERS KEY GENERATION
    ll pr, qr, nr, phi_r, er, dr;
    cout << "Enter receivers prime numbers p and q: ";
    cin >> pr >> qr;
    nr = pr * qr;
    phi_r = (pr - 1) * (qr - 1);
    cout << "Enter e: ";
    cin >> er;
    if (!isValidE(er, phi_r))
    {
        cout << "Invalid e" << endl;
        return 0;
    }
    dr = modinv(er, phi_r);
    if (!isValidD(er, dr, phi_r))
    {
        cout << "Invalid d" << endl;
        return 0;
    }
    ll m;
    cout << "Enter message: ";
    cin >> m;

    ll en = modpow(m, er, nr);
    ll sig = modpow(m, ds, ns);
    ll ver = modpow(sig, es, ns);
    if (sig == m)
        cout << "Signer Verified" << endl;
    else
        cout << "Illegitamate signer" << endl;
    ll dec = modpow(en, dr, nr);
    cout << "sender's public key: (" << es << "," << ns << ")" << endl;
    cout << "sender's private key: (" << ds << "," << ps << "," << qs << ")" << endl;
    cout << "receiver's public key: (" << er << "," << nr << ")" << endl;
    cout << "receiver's private key: (" << dr << "," << pr << "," << qr << ")" << endl;
    cout << "Message: " << m << endl;
    cout << "Encrypted Message: " << en << endl;
    cout << "Signature: " << sig << endl;
    cout << "Verified Signature: " << ver << endl;
    cout << "Decrypted Message: " << dec << endl;
}