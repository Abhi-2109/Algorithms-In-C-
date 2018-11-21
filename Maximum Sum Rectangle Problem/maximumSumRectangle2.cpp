#include<bits/stdc++.h>
using namespace std;
int kadane(int *arr, int n)
{
  int currentSum = 0,maxSum = INT_MIN;
  for(int i = 0; i < n; i++)
  {
    currentSum += arr[i];
    maxSum = max(currentSum,maxSum);
    currentSum = max(currentSum,0);
  }
  return maxSum;
}
int main()
{
    int n,m;
    cin >> n >> m;
    int **input = new int*[n];
    for(int i = 0; i < n; i++)
        input[i] = new int[m];
    for(int i = 0; i < n;  i++)
        for(int j = 0; j < m; j++)
            cin >> input[i][j];
	int maxSum = INT_MIN;
  	for(int i = 0; i < m; i++)
    {
      int *output = new int[n];
      for(int k = 0; k < n; k++)
        output[k] = 0;
      
      for(int j = i; j < m; j++)
      {
        for(int k = 0; k < n; k++)
          output[k] += input[k][j];
        
        // Apply kadane Algorithm
        int sum = kadane(output,n);
        maxSum = max(maxSum, sum);
        
      }    
    }
 	cout << maxSum;
    return 0;
}

