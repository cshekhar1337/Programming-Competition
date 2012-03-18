#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<iomanip>

using namespace std;

double calc(double P, int query)
{
    if(abs(P) < 1e-9)
    {
        if(query%2 == 0)
            return 1.0;
        return 0.0;
    }

    double A = (1.0-2*P);
    return P*  ((1.0 - pow(A,query))/(1.0 - A));

}

int main()
{
    double P=0;
    cin>>P;
    long Q = 0;
    cin>>Q;
    int query=0;
    cout.precision(4);
    cout.setf(ios::fixed,ios::floatfield); 
    for(long i=0;i<Q;i++)
    {
        cin>>query;
        cout<<calc(P,query)<<endl;
    }
}
