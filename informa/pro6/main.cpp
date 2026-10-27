#include <iostream>
using namespace std;
int revresenum (int num)
{
    int revrese_num = 0;
    int remeainder;
    while(num!=0)
    {
        remeainder=num%10;
        revrese_num =(revrese_num *10)+remeainder;
        num/=10;
    }

    return revrese_num;

}
int main ()
{
    int user_inpute ;
    cout<<"please enter your number .....";
    cin>>user_inpute ;
    int resulte = revresenum(user_inpute);
    cout<<"\n==========YORE RESULTE==========\n";
    cout<<" orginale number "<<user_inpute <<endl;;
    cout<<" revrese number "<<resulte<< endl;

    return 0 ;


}
