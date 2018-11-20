// Used Dynamic Programming Iterative Solution

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int r,c;
    cin >> r >> c;
    int **input = new int*[r];
    for(int i = 0; i < r; i++)
      input[i] = new int[c];
    for(int i =0; i < r; i++)
      for(int j=0; j < c; j++)
        cin >> input[i][j];
    int **dp = new int*[r];
    for(int i = 0; i < r; i++)
      dp[i] = new int[c];



    // setting the base conditions

    dp[r-1][c-1] = 1;

    for(int i = r-2; i >=0; i--)
    {
      dp[i][c-1] = max(dp[i+1][c-1] - input[i+1][c-1],1);
    }
    for(int j = c-2; j >=0; j--)
    {
      dp[r-1][j] = max(dp[r-1][j+1] - input[r-1][j+1], 1);
    }
    for(int i = r-2; i >= 0; i--)
    {
      for(int j = c-2; j >= 0; j--)
        dp[i][j] = min(max(dp[i+1][j] - input[i+1][j],1),max(dp[i][j+1]-input[i][j+1],1));
    }
    cout << dp[0][0] << endl;

  }
    return 0;
}
