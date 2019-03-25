#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n ;i++)
        cin >> arr[i];
    int maxSum=INT_MIN,currentSum = 0;

    // This is also called kadane Algorithm


    for(int i=0; i < n; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum,currentSum);
        currentSum = max(currentSum,0);
    }
    cout << maxSum;
}

