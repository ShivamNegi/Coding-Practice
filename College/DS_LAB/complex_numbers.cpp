#include <iostream>

using namespace std;

struct complex
{
    int real, img;
};

complex addition(complex cmp1, complex cmp2)
{
    complex cmp;
    cmp.real = cmp1.real + cmp2.real;
    cmp.img = cmp1.img + cmp2.img;
    return cmp;
}

complex multiplication(complex cmp1, complex cmp2)
{
    complex cmp;
    cmp.real = cmp1.real * cmp2.real - cmp1.img * cmp2.img;
    cmp.img = cmp1.real * cmp2.img + cmp1.img * cmp2.real;
    return cmp;
}

void display(complex cmp)
{
    cout<<cmp.real<<" + "<<cmp.img<<"i\n";
}

int main()
{
    complex cmp1, cmp2;

    cout<<"Enter the two complex numbers: ";
    cin>>cmp1.real>>cmp1.img;
    cin>>cmp2.real>>cmp2.img;

    display(addition(cmp1, cmp2));
    display(multiplication(cmp1, cmp2));

    return 0;
}