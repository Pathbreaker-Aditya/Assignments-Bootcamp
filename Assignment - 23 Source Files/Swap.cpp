#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    cout<<"\n  The program will swap the values of two variables without using the third variable."<<endl;
    int var1,var2;
    cout<<"\n  Enter value of First Variable (var1) : ";cin>>var1;
    cout<<"  Enter value of Second Variable (var2) : ";cin>>var2;
    cout<<"\n  Current values of (var1) = "<<var1<<", (var2) = "<<var2<<endl;
    var2=var1+var2;
    var1=var2-var1;
    var2=var2-var1;
    cout<<"\n  Press any key to execute swapping...";
    getch();
    cout<<"\n\n  Swapped values of (var1) = "<<var1<<", (var2) = "<<var2<<endl;
    return(0);
}
