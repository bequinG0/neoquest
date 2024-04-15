#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <unistd.h>
using namespace std;

class Big_Data
{
private:
    vector <int> man;
    bool _is_negative=false;
public:
    Big_Data(){}

    Big_Data(long long val) {
        *this = Big_Data(to_string(val));
    }

    Big_Data(string data)
    {
        int c=0;
        if(data[0]=='-') { c++; _is_negative=true; }
        for(int i=c; i<data.size(); i++)
        {
            man.push_back(data[i]-'0');
        }
    }

    Big_Data(vector <int> data)
    {
        for(int i=0; i<data.size(); i++)
        {
            man.push_back(data[i]);
        }
    }

    Big_Data& operator= (const Big_Data &val2)
    {
        while(man.size()!=0)
        {
            man.pop_back();
        }
        for(int i=0; i<val2.man.size(); i++)
        {
            man.push_back(val2.man[i]);
        }
        _is_negative=val2._is_negative;
        return *this;
    }//*/

    friend vector <int> input(Big_Data &val1){return val1.man;}

    friend Big_Data operator+(const Big_Data &val1, const Big_Data &val2);
    friend Big_Data operator*(const Big_Data &val1, const Big_Data &val2);
    friend Big_Data operator-(const Big_Data &val1, const Big_Data &val2);
    friend Big_Data operator/(const Big_Data &val1, const Big_Data &val2);

    friend Big_Data operator+=(Big_Data &val1, const Big_Data &val2);
    friend Big_Data operator-=(Big_Data &val1, const Big_Data &val2);
    friend Big_Data operator*=(Big_Data &val1, const Big_Data &val2);
    friend Big_Data operator/=(Big_Data &val1, const Big_Data &val2);

    Big_Data operator++(); Big_Data operator++(int);
    Big_Data operator--(); Big_Data operator--(int);

    friend bool operator>(const Big_Data &val1, const Big_Data &val2);
    friend bool operator<(const Big_Data &val1, const Big_Data &val2);
    friend bool operator==(const Big_Data &val1, const Big_Data &val2);
    friend bool operator>=(const Big_Data &val1, const Big_Data &val2);
    friend bool operator<=(const Big_Data &val1, const Big_Data &val2);
    friend bool operator!=(const Big_Data &val1, const  Big_Data &val2);

    friend ostream& operator<<(ostream &out, Big_Data val1);
    friend istream& operator>>(istream &in, Big_Data& val1);
};

Big_Data Big_Data::operator++()
{
    *this += Big_Data(1);
    return *this;
}

Big_Data Big_Data::operator--()
{
    *this -= Big_Data(1);
    return *this;
}

Big_Data Big_Data::operator++(int)
{
    Big_Data temp(man);
    ++(*this);
    return temp;
}

Big_Data Big_Data::operator--(int)
{
    Big_Data temp(man);
    --(*this);
    return temp;
}

Big_Data operator+(const Big_Data &val1, const Big_Data &val2)
{
    Big_Data summ; int len;
    vector <int> value_1, value_2;
    if(val1._is_negative and !val2._is_negative) 
    {
        Big_Data tmp=val1;
        tmp._is_negative=false;
        return val2-tmp;
    }
    else if(!val1._is_negative and val2._is_negative) 
    {
        Big_Data tmp=val2;
        tmp._is_negative=false;
        return val1-tmp;
    }
    else if(val1._is_negative and val2._is_negative) summ._is_negative=true; 
    for(int i=0; i<val1.man.size(); i++) value_1.push_back(val1.man[i]);
    for(int i=0; i<val2.man.size(); i++) value_2.push_back(val2.man[i]);
    if(value_1.size()>value_2.size())
    {
        len=value_1.size(); int small=value_2.size();
        reverse(value_2.begin(), value_2.end());
        for(int i=0; i<len-small; i++){value_2.push_back(0);}
        reverse(value_2.begin(), value_2.end());
    }
    else
    {
        len=value_2.size(); int small=value_1.size();
        reverse(value_1.begin(), value_1.end());
        for(int i=0; i<len-small; i++){value_1.push_back(0);}
        reverse(value_1.begin(), value_1.end());
    }
    for(int i=len-1; i>=0; i--)
    {
        summ.man.push_back(value_1[i]+value_2[i]);
    }
    reverse(summ.man.begin(), summ.man.end());
    for(int i=summ.man.size()-1; i>=0; i--)
    {
        if(summ.man[i]>=10)
        {
            if(i==0)
            {
                summ.man[i]-=10;
                reverse(summ.man.begin(), summ.man.end());
                summ.man.push_back(1);
                reverse(summ.man.begin(), summ.man.end());
            }
            else {summ.man[i-1]+=1; summ.man[i]-=10;}
        }
    }
    return summ;
}

Big_Data operator*(const Big_Data &val1, const Big_Data &val2)
{
    vector <int> value_1, value_2;
    for(int i=0; i<val1.man.size(); i++) value_1.push_back(val1.man[i]);
    for(int i=0; i<val2.man.size(); i++) value_2.push_back(val2.man[i]);
    if(value_1[0]==0 or value_2[0]==0)
    {
        Big_Data null("0");
        return null;
    }
    Big_Data sum; int len, siz;
    if(val1._is_negative and val2._is_negative) sum._is_negative=false;
    else if(val1._is_negative or val2._is_negative) sum._is_negative=true;
    if(value_1.size()>value_2.size())
    {
        len=value_1.size(); int small=value_2.size();
        reverse(value_2.begin(), value_2.end());
        for(int i=0; i<len-small; i++){value_2.push_back(0);}
        reverse(value_2.begin(), value_2.end());
        siz=value_1.size();
    }
    else
    {
        len=value_2.size(); int small=value_1.size();
        reverse(value_1.begin(), value_1.end());
        for(int i=0; i<len-small; i++){value_1.push_back(0);}
        reverse(value_1.begin(), value_1.end());
        siz=value_2.size();
    }
    vector <vector<int>> prr;
    for(int i=0; i<siz; i++)
    {
        prr.push_back(vector <int>());
        for(int j=0; j<value_1.size(); j++)
        {
            prr[i].push_back(0);
        }
    }
    for(int i=0; i<prr.size(); i++)
    {
        for(int j=0; j<prr[i].size(); j++)
        {
            prr[i][j]=value_1[j]*value_2[i];
        }
    }
    reverse(prr.begin(), prr.end());
    for(int i=0; i<prr.size(); i++)
    {
        for(int j=prr[i].size()-1; j>=0; j--)
        {
            if(prr[i][j]>=10)
            {
                if(j==0)
                {
                    int t=0; t=prr[i][j];
                    prr[i][j]=prr[i][j]%10;
                    reverse(prr[i].begin(), prr[i].end());
                    prr[i].push_back(t/10);
                    reverse(prr[i].begin(), prr[i].end());
                }
                else
                {
                    prr[i][j-1]+=prr[i][j]/10;
                    prr[i][j]=prr[i][j]%10;
                }
            }
        }
    }
    for(int i=0; i<prr.size(); i++)
    {
        int _i=i; 
        while(_i-->0)
        {
            prr[i].push_back(0);
        }
    }
    for(int i=0; i<prr.size(); i++)
    {
        int _i=i;
        _i=prr[prr.size()-1].size()-prr[i].size();
        while(_i-->0)
        {
            reverse(prr[i].begin(), prr[i].end());
            prr[i].push_back(0);
            reverse(prr[i].begin(), prr[i].end());
        }
    }
    for(int j=0; j<prr[0].size(); j++)
    {
        int s=0;
        for(int i=0; i<prr.size(); i++)
        {
            s+=prr[i][j];
        }
        sum.man.push_back(s);
    }
    for(int i=sum.man.size()-1; i>=0; i--)
    {
        if(sum.man[i]>=10)
        {
            if(i==0)
            {
                sum.man[i]%=10;
                reverse(sum.man.begin(), sum.man.end());
                sum.man.push_back(sum.man[i]/10);
                reverse(sum.man.begin(), sum.man.end());
            }
            else{sum.man[i-1]+=sum.man[i]/10; sum.man[i]%=10;}
        }
    }
    reverse(sum.man.begin(), sum.man.end());
    while(sum.man[sum.man.size()-1]==0)
    {
        sum.man.pop_back();
    }
    reverse(sum.man.begin(), sum.man.end());
    return sum;
}//*/

Big_Data operator-(const Big_Data &val1, const Big_Data&val2)
{
    if(val1==val2) return 0;
    Big_Data res;
    int len, siz=0; vector <int> value_1, value_2;
    if(val1._is_negative and val2._is_negative)
    {
        Big_Data tmp=val2;
        tmp._is_negative=false;
        return tmp+val1;
    }
    else if(!val1._is_negative and val2._is_negative) 
    {
        Big_Data tmp=val2;
        tmp._is_negative=false;
        return val1+tmp;
    }
    else if(val1._is_negative and !val2._is_negative) 
    {
        Big_Data tmp=val2;
        tmp._is_negative=true;
        return val1+tmp;
    }
    if(val1>val2)
    {
//https://github.com/bequinG0
        for(int i=0; i<val1.man.size(); i++) value_1.push_back(val1.man[i]);
        for(int i=0; i<val2.man.size(); i++) value_2.push_back(val2.man[i]);
    }
    if(val2.man.size()>val1.man.size())
    {
        for(int i=0; i<val2.man.size(); i++) value_1.push_back(val2.man[i]);
        for(int i=0; i<val1.man.size(); i++) value_2.push_back(val1.man[i]);
        res._is_negative=true;
    }
    else if(val2.man.size()==val1.man.size())
    {
        if(val2.man>val1.man)
        {
            for(int i=0; i<val2.man.size(); i++) value_1.push_back(val2.man[i]);
            for(int i=0; i<val1.man.size(); i++) value_2.push_back(val1.man[i]);
            res._is_negative=true;
        }
    }
    if(value_1.size()>value_2.size())
    {
        len=value_1.size(); int small=value_2.size();
        reverse(value_2.begin(), value_2.end());
        for(int i=0; i<len-small; i++){value_2.push_back(0);}
        reverse(value_2.begin(), value_2.end());
        siz=value_1.size();
    }
    else
    {
        len=value_2.size(); int small=value_1.size();
        reverse(value_1.begin(), value_1.end());
        for(int i=0; i<len-small; i++){value_1.push_back(0);}
        reverse(value_1.begin(), value_1.end());
        siz=value_2.size();
    }
    for(int i=value_1.size()-1; i>=0; i--)
    {
        if(value_1[i]<value_2[i])
        {
            value_1[i-1]-=1;
            value_1[i]+=10;
            value_1[i]-=value_2[i];
        }
        else
        {
            value_1[i]-=value_2[i];
        }
    }
    for(int i=0; i<value_1.size(); i++)
    {
        res.man.push_back(value_1[i]);
    }
    while(res.man[0]==0 and res.man.size()!=1)
    {
        reverse(res.man.begin(), res.man.end());
        res.man.pop_back();
        reverse(res.man.begin(), res.man.end());
    }
    return res;
}//*/

Big_Data big_pow(int n, int step)
{
    Big_Data res=1;
    while(step-->0) res=res*n;
    return res;
}

Big_Data operator/(const Big_Data &val1, const Big_Data &val2)
{
    Big_Data tmp, tmp1;
    int step=0; Big_Data res=0;
    if(val1._is_negative and val2._is_negative) res._is_negative=false;
    else if(val1._is_negative or val2._is_negative) res._is_negative=true;
    for(int i=0; i<val1.man.size(); i++) tmp.man.push_back(val1.man[i]);
    for(int i=0; i<val2.man.size(); i++) tmp1.man.push_back(val2.man[i]);
    while(tmp>=tmp1)
    {
        while(tmp1*big_pow(2, step)<=tmp) step++;
        step--;
        if(tmp1*big_pow(2, step)<=tmp)
        {
            res=res+big_pow(2, step);
            tmp=tmp-tmp1*big_pow(2, step);
        }
    }
    return res;
}

Big_Data operator+=(Big_Data &val1, const Big_Data &val2)
{
    val1=val1+val2;
    return val1;
}

Big_Data operator-=(Big_Data &val1, const Big_Data &val2)
{
    val1=val1-val2;
    return val1;
}

Big_Data operator*=(Big_Data &val1, const Big_Data &val2)
{
    val1=val1*val2;
    return val1;
}

Big_Data operator/=(Big_Data &val1, const Big_Data &val2)
{
    val1=val1/val2;
    return val1;
}

bool operator>(const Big_Data &val1, const Big_Data &val2)
{
    if(val1.man.size()!=val2.man.size())
    {
        if(val1._is_negative == val2._is_negative)
        {
            if(!val1._is_negative and val1.man.size()>val2.man.size()) return true;
            else if(val1._is_negative and val1.man.size()<val2.man.size()) return true; 
        }
        else
        {
            if(val1._is_negative) return false;
            else return true;
        }
    }
    else if(val1.man.size()==val2.man.size())
    {
        if(val1._is_negative==val2._is_negative)
        {
            if(val1._is_negative and val1.man>val2.man) return false;
            else if(val1._is_negative and val1.man<val2.man) return true;
            if(!val1._is_negative and val1.man>val2.man) return true; 
        }
        else
        {
            if(val1._is_negative) return false;
            else return true;
        }
    }
    return false;
}

bool operator<(const Big_Data &val1, const Big_Data &val2)
{
    if(val1.man.size()!=val2.man.size())
    {
        if(val1._is_negative == val2._is_negative)
        {
            if(!val1._is_negative and val1.man.size()<val2.man.size()) return true;
            else if(val1._is_negative and val1.man.size()>val2.man.size()) return true; 
        }
        else
        {
            if(val1._is_negative and !val2._is_negative) return true;
            else if(!val1._is_negative and val2._is_negative) return false;
        }
    }
    else if(val1.man.size()==val2.man.size())
    {
        if(val1._is_negative==val2._is_negative)
        {
            if(val1._is_negative and val1.man>val2.man) return true;
            else if(!val1._is_negative and val1.man<val2.man) return true;
        }
        else
        {
            if(val1._is_negative) return true;
            else return false;
        }
    }
    return false;
}

bool operator==(const Big_Data &val1, const Big_Data &val2)
{
    if(val1.man.size()!=val2.man.size())
    {
        return false;
    }
    else
    {
        if (val1._is_negative!=val2._is_negative) return false;
        for(int i=0; i<val1.man.size(); i++)
        {
            if(val1.man[i]!=val2.man[i])
            {
                return false;
            }
        }
        return true;
    }
}

bool operator!=(const Big_Data &val1, const Big_Data &val2)
{
    if(val1.man.size()!=val1.man.size())
    {
        return true;
    }
    else
    {
        for(int i=0; i<val1.man.size(); i++)
        {
            if(val1.man[i]!=val2.man[i])
            {
                return true;
            }
        }
        if(val1._is_negative!=val2._is_negative) return true;
        return false;   
    }
}

bool operator>=(const Big_Data &val1, const Big_Data &val2)
{
    if(val1.man.size()!=val2.man.size())
    {
        if(val1._is_negative == val2._is_negative)
        {
            if(!val1._is_negative and val1.man.size()>val2.man.size()) return true;
            else if(val1._is_negative and val1.man.size()<val2.man.size()) return true;
        }
        else
        {
            if(val2._is_negative) return true;
            else return false;
        }
    }
    else if(val1.man.size()==val2.man.size())
    {
        if(val1._is_negative == val2._is_negative)
        {
            if(!val1._is_negative and val1.man>=val2.man) return true;
            else if(val1._is_negative and val1.man<=val2.man) return true;
        }
        else
        {
            if(!val1._is_negative) return true;
            else return false;
        }
    }
    return false;
}

bool operator<=(const Big_Data &val1, const Big_Data &val2)
{
    if(val1.man.size()!=val2.man.size())
    {
        if(val1._is_negative == val2._is_negative)
        {
            if(!val1._is_negative and val1.man.size()<val2.man.size()) return true;
            else if(val1._is_negative and val1.man.size()>val2.man.size()) return true;
        }
        else
        {
            if(val1._is_negative) return true;
            else return false;
        }
    }
    else if(val1.man.size()==val2.man.size())
    {
        if(val1._is_negative == val2._is_negative)
        {
            if(!val1._is_negative and val1.man<=val2.man) return true;
            else if(val1._is_negative and val1.man>=val2.man) return true;
        }
        else
        {
            if(val1._is_negative) return true;
            else return false;
        }
    }
    return false;
}

ostream& operator<<(ostream &out, Big_Data val1)
{
    if(val1._is_negative) cout << "-";
    for(int i=0; i<val1.man.size(); i++) out << val1.man[i];
    return out;
}

istream& operator>>(istream &in, Big_Data& val1)
{
    string s; in >> s;
    val1 = Big_Data(s);
    return in;
} 

int main()
{
    //write something...
}
