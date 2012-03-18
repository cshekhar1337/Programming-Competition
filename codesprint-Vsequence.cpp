#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<iomanip>
#include<cstring>

using namespace std;
#define MAX 200002

int nums[MAX],longestIncreasing[MAX], longestDecreasing[MAX];

int main()
{
    int N = 0;
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    long maxAns = 0;
    memset(longestDecreasing, 0, sizeof(longestDecreasing));
    memset(longestIncreasing, 0, sizeof(longestDecreasing));
    longestDecreasing[0] = 1;
    longestIncreasing[N-1] = 1;
    for(int j=0;j<N;j++)
    {
        int k = N-1-j;
        int maxDec=0,maxInc=0;
        for(int r=j-1;r>=0;r--)
        {
            if(nums[r]>nums[j] &&
                    longestDecreasing[r] > maxDec)
            {
                maxDec = longestDecreasing[r];
            }
        }

        longestDecreasing[j] = maxDec+1;
        
        for(int r=k+1;r<N;r++)
        {
            if(nums[r] > nums[k] && 
                    longestIncreasing[r] > maxInc)
                maxInc = longestIncreasing[r];
        }

        longestIncreasing[k] = maxInc + 1;
        
    }

    for(int i=0;i<N;i++)
    {
        //cout<<i<<" "<<nums[i]<<" "<<longestIncreasing[i]<<" "<<longestDecreasing[i]<<endl;
        if(longestIncreasing[i] >1 &&
                longestDecreasing[i] > 1 && maxAns < longestDecreasing[i] + longestIncreasing[i] -1)
            maxAns = longestIncreasing[i] + longestDecreasing[i] - 1;
    }

    cout<<maxAns<<endl;


}
