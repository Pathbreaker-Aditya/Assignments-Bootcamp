#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    cout<<"\n  The program will find greater in two numbers entered by the user.";

    int num1;
    cout<<"\n\n  First Number : ";
    cin>>num1;

    int num2;
    cout<<"  Second Number : ";
    cin>>num2;

    if(num1>num2)
        cout<<"  "<<num1<<" > "<<num2;
    else if(num1<num2)
        cout<<"  "<<num2<<" > "<<num1;
    else
        cout<<"  Numbers are equal";

    cout<<endl;

    return(0);
}
