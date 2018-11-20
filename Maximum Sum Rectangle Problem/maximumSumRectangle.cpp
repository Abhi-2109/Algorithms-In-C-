#include<bits/stdc++.h>
using namespace std;
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
    int **output = new int*[n];
    for(int i=0; i < n; i++)
        output[i] = new int[m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int sum = 0;
            for(int k = i; k < n; k++)
            {
                for(int l = j; l < m; l++)
                {
                    sum += input[k][l];
                }
            }
            output[i][j] = sum;
        }
    }
   // cout << "Half Done " << endl;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = i; k < n; k++)
            {
                for(int l = j; l < m ; l++)
                {
                    //cout << i << j << k << l << endl;
                    int rectsum;
                    if(l+1 < m && k+1 < n)
                        rectsum = output[i][j] - output[i][l+1] - output[k+1][j] + output[k+1][l+1];
                    else if(l+1 < m)
                        rectsum = output[i][j] - output[i][l+1];
                    else if(k+1 < n)
                        rectsum = output[i][j] -output[k+1][j];
                    else
                        rectsum = output[i][j];
                    if(rectsum > maxSum)
                        maxSum = rectsum;
                }
            }
        }
    }
    cout << maxSum;
    return 0;
}
