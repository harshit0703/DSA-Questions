#include <bits/stdc++.h>
using namespace std;

Class String
{

Public:

    // default constructor

    String() : res(nullptr), len(0)
    {
        // will take care of String str1;
    }

    String(const char *ch)
    {

        len = strlen(ch);
        res = new char[len + 1];
        strcpy(res, ch);
    }

    String(const String &str)
    {
        len = str.len;
        res = new char[len + 1];
        strcpy(res, str.res);
    }

    String(const String &&str)
    {
        len = str.len;
        res = str.res; // just pointing and not copying
        str = nullptr;
        str.len = 0;
    }

    String &operator=(String str)
    {
        swap(this, str);

        return *this; // CAS idiom
    }

    swap(String & str1, String & str2)
    {
        std::swap(str1.res, str2.res);
        std::swap(str1.len, str2.len);
    }

    unsigned int length()
    {
        return len;
    }

    friend ostream &operator<<(ostream &out, const String &str);
    friend istream &operator>>(istream &in, const String &str);

Private:

    char *res;        // character buffer
    unsigned int len; // for storing the length of the char buffer
};

ostream &operator<<(ostream &out, const String &str)
{
    out << str.res;
    return out;
}

istream &operator>>(istream &in, const String &str)
{
    in >> str.res;
    return in;
}

∼String()
{
    if (res)
    {
        delete[] res;
        res = nullptr;
        len = 0;
    }
}

int main()
{

    String str1;             // default constructor
    String str2 = "hello";   // parameterised constructor
    String str3 = str1;      // copy constructor
    str3 = str2;             // copy assignment operator
    int len = str3.length(); // return the length of the string

    cout << str2; // overloading << operator
    cin >> str1;  // overloading >> operator

    return 0;
}