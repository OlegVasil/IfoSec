#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

string characters = "#abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
bool IsTheNumberSimple(int n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    for (long i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
int NOD(int first, int second)
{
    while (first != 0 && second != 0)
    {
        if (first > second) first %= second;
        else second %= first;
    }
    return first + second;
}
double Calculate_d(long m)
{
    long d = m - 1;

    for (long i = 2; i <= m; i++)
        if ((m % i == 0) && (d % i == 0)) //если имеют общие делители
        {
            d--;
            i = 1;
        }

    return d;
}

double Calculate_e(long m, long d)
{
    long e = 2;

    while ((e * d) % m != 1)
        e++;


    return e;
}
vector <long> RSA_Encode(string s, long e, int n)
{
    vector <long> result;
    for (int i = 0; i < s.size(); i++)
    {
        int index = characters.find(s[i]);
        cout << "s[i] = " << s[i] << "   " << index << endl;
        long bi = index;
        long e_ = e;

        bi = long(pow(bi, e_));
        cout << "bi" << bi << endl;
        long n_ = n;
        bi = bi % n_;
        result.push_back(bi);
    }

    return result;
}
string RSA_Dedoce(vector<long> input, long d, long n)
{
    string result = "";

    for (int i = 0; i < input.size(); i++)
    {
        long bi = input[i];
        long d_ = d;
        bi = long(pow(bi, d_));
        long n_ = n;
        bi = bi % n_;
        int index = stoi(long(to_string(bi)));

        result += characters[index];
    }

    return result;
}

void Encrypt(int p, int q, string s)
{
    long n = p * q;
    long m = (p - 1) * (q - 1);
    long d = Calculate_d(m);
    long e = Calculate_e(m, d);

    vector <long> result = RSA_Encode(s, e, n); \
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << endl;

    string res = RSA_Dedoce(result, d, n);
    cout << res;
}

int main()
{

    cout << "Input p and q: ";
    int p, q;
    cin >> p >> q;
    if (IsTheNumberSimple(p) && IsTheNumberSimple(q)) {
        string s;
        cout << "Input s ";
        cin >> s;
        Encrypt(p, q, s);


    }
    else
        cout << "Is not simple numbers";


}