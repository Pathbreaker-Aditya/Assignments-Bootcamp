#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    cout<<"\n  The program will calculate the sum of all elements of an array of size 10"<<endl;
    int arr[10],i,sum;
    cout<<"\n  Enter the 10 elements : "<<endl;
    for(sum=0,i=0;i<10;i++)
    {
        cout<<"  ";
        cin>>arr[i];
        sum=sum+arr[i];
    }
    cout<<"\n  Press any key to generate Sum.";
    getch();
    cout<<"\n  Sum is "<<sum<<endl<<endl;
    return(0);
}
