#include<iostream>
using namespace std;

class complex
{
    double imag;
    double real;
    public:
    complex():imag(0),real(0){};
    complex(double re, double im):imag(im),real(re){};

    complex operator + (complex obj)
    {
        return complex(obj.real + real, obj.imag + imag);
    }

    complex operator * (complex obj)
    {
        return complex(obj.real * real - obj.imag * imag, obj.real * imag + real * obj.imag);
    }

    friend istream& operator >>(istream& in, complex& obj)
    {
        cout<<"Enter the real and imaginary part: ";
        in>>obj.real>>obj.imag;
        return in;
    }

    friend ostream& operator <<(ostream& out, complex& obj)
    {
        out<<obj.real<<" + "<<obj.imag<<"i"<<endl;
        return out;
    }
};

int main()
{
    complex obj1;
    complex obj2;
    cin>>obj1;
    cin>>obj2;
    // complex ans = obj1 + obj2;
    complex ans2 = obj1 * obj2;
    // cout<<ans;
    cout<<ans2;
    return 0;
}