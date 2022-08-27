#include<iostream>
using namespace std;
int main()
{
    cout<<"\n  The program will calculate the volume of the cuboid whose dimensions are given by the user."<<endl;
    float ln;
    cout<<"\n  Enter Length : ";
    cin>>ln;
    float bd;
    cout<<"  Enter Breadth : ";
    cin>>bd;
    float ht;
    cout<<"  Enter Height : ";
    cin>>ht;
    cout<<"\n  Volume of cuboid = "<<ln*bd*ht<<" cu.unts"<<endl<<endl;
    return(0);
}
