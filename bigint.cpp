#include "bigint.h"
bign::bign() 
{
   memset(s,0,sizeof(s));
   len = 1;
}
bign bign::operator = (const char* num)
{
    len =strlen(num);
    for(int i = 0 ;i<len ;i++) {
        s[i] = num[len -i -1] -'0';
    }
    return *this;
}
bign bign::operator = (int num)
{
    char s[maxn];
    sprintf(s,"%d",num);
    *this = s;
    return *this;
}
bign bign::operator +(const bign &other)
{
    bign c;
    int a = 0;
    int min_len = this->len < other.len ? this->len  : other.len ;
    int i;
    for (i = 0; i < min_len ; ++i)
    {
      int s = this->s[i] + other.s[i] + a;
      c.s[i] = s%10;
      a = s/10;
    }
    for (; i < this->len; ++i)
    {
      int s = this->s[i] + a;
      c.s[i] = s%10;
      a = s/10;
    }
    for (; i < other.len; ++i)
    {
      int s = other.s[i] + a;
      c.s[i] = s%10;
      a = s/10;
    }
    c.len = i;
    if (a != 0)
    {
      c.len = i+1;
      c.s[i] = a;
    }
    return c;
}
bign bign::operator +(const int & num)
{
    bign big_num (num);
    return big_num + *this;
}
bign bign::operator *(const bign &other)
{
      int n = this->len;
      int m = other.len;
      int *a = this->s;
      const int *b = other.s;
      bign sum(0);
      for (int i = n-1; i >=0; i--)
      {
        int c = 0;
        bign r_sum = other * a[i];
        sum = sum*10 + r_sum;
      } 
      return sum;
}
bign bign::operator *(int num) const
{
    bign sum(0);
    const int* a = this->s;
    int* res = sum.s;
    uint64_t c = 0;
    sum.len = 0;
    for (int i = 0; i < this->len ; ++i)
    {
      uint64_t s = a[i]*num + c; 
      sum.len ++; 
      res[sum.len - 1] = (s%10);
      c = s/10;
    }
    if (c != 0)
    {
      sum.len ++;
      res[sum.len - 1] = c;
    }
    return sum;
}
bool bign::operator <(bign &other){
    if (this->len != other.len){
      return (this->len < other.len);
    } 
    for (int i = this->len - 1; i >= 0; --i)
    {
      if (this->s[i] != other.s[i])
      {
        return this->s[i] < other.s[i];
      }
    }
    return false;
}
bool bign::operator == (bign &other)
{
    if (this->len != other.len){
      return false;
    } 
    for (int i = 0; i < this->len; ++i)
    {
      if (this->s[i] != other.s[i])
      {
        return false;
      }
    }
    return true;
}
bool bign::operator >(bign &other)
{
    return (!(*this < other)) && (!(*this == other));
}
bool bign::operator <=(bign &other)
{
    return !(*this > other);
}
bool bign::operator >=(bign &other)
{
    return !(*this < other);
}
bign::bign(int num)
{
    *this = num;
}
bign::bign(const char* num)
{
   *this = num;
}
string bign::str() const
{
    string res = "";
    for(int i=0;i<len;i++) 
    {  
      res = (char)(s[i] + '0' ) + res ;
    }
    if(res == "") res = "0";
    return res;
}
istream& operator >> (istream &in, bign &x)
  {
    string s;
    in >> s;
    x =s.c_str();
    return in;
  } 
  ostream& operator << (ostream &out, const bign &x)
  {
    out << x.str();
    return out;
  }
