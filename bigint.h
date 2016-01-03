#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdint.h>
const int maxn = 1000;
using namespace std;
class  bign
{
public:
    int len, s[maxn];
    bign operator = (const char* num);
    bign operator = (int num);
    bign operator +(const bign &other);
    bign operator +(const int & num);
    bign operator *(const bign &other);
    bign operator *(int num) const;
    bool operator <(bign &other);
    bool operator == (bign &other);
    bool operator >(bign &other);
    bool operator <=(bign &other);
    bool operator >=(bign &other);
    string str() const;
    bign(int num);
    bign(const char* num);
    bign();
};
istream& operator >> (istream &in, bign &x);
ostream& operator << (ostream &out, const bign &x);
