#include<iostream>
using namespace std;
int main()
{
    cout<<"\n  The program will calculate the average of three numbers entered by the user."<<endl;
    float n1;
    cout<<"\n  First Number : ";
    cin>>n1;
    float n2;
    cout<<"  Second Number : ";
    cin>>n2;
    float n3;
    cout<<"  Third Number : ";
    cin>>n3;
    cout<<"\n  Average = "<<(n1+n2+n3)/3<<endl<<endl;
    return(0);
}
