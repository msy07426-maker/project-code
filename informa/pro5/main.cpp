#include <iostream>
using namespace std;
long long factorial(int n)
{
    cout<<n<<endl;
    if(n<=1)
    {
         return 1 ;
    }
    return n*factorial(n-1) ;
}
int main ()
{
    int n;
    cout<<"pleas inter your number.... ";
    cin>>n;
    cout<<n<<factorial(n)<<endl;
    return 0 ;


}
