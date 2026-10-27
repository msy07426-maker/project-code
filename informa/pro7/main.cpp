#include <iostream>
using namespace std;

int main ()
{
    int rows ;
    cout<<"please enter your number of rows .....";
    cin>>rows ;
    cout<<"orginale triangle...."<<endl;;
    for(int i=1;i<=rows;i++)
    {
        for(int j=1 ;j<=i;j++)
        {
            cout<<"*";
        }
        cout <<endl;
    }
    cout<<"\n==========YORE RESULTE==========\n";
    cout<<" revrese triangle.... "<<endl;
    for(int i=rows;i>=1;i--)
    {
        for(int j=1 ;j<=i;j++)
        {
            cout<<"*";
        }
        cout <<endl;
    }
    return 0 ;


}
