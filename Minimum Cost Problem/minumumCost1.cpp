// This is a recursive Dynamic Programming Solution

#include<bits/stdc++.h>
using namespace std;
int min_cost(int **input, int si, int sj, int ei, int ej, int **output)
{
    if(si==ei && sj==ej)
    {
        return input[ei][ej];
    }
    if(si > ei || sj > ej)
        return INT_MAX;
    if(output[si][si] != -1)
        return output[si][sj];
    int option1 = min_cost(input, si+1, sj, ei,ej,output);
    int option2 = min_cost(input,si,sj+1,ei,ej,output);
    int option3 = min_cost(input,si+1,sj+1,ei,ej,output);
    output[si][sj] = input[si][sj] + min(option1, min(option2,option3));
    return output[si][sj];
}
int main()
{
    int **input = new int*[3];
    input[0] = new int[3];
    input[1] = new int[3];
    input[2] = new int[3];
	input[0][0] = 4;
	input[0][1] = 3;
	input[0][2] = 2;
	input[1][0] = 1;
	input[1][1] = 8;
	input[1][2] = 3;
	input[2][0] = 1;
	input[2][1] = 1;
	input[2][2] = 8;
    // Making a 2D output array to store the results

    int **output = new int*[3];
    output[0] = new int[3];
    output[1] = new int[3];
    output[2] = new int[3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j <3;j++)
            output[i][j] = -1;
	cout << min_cost(input, 0,0,2,2,output) << endl;
    return 0;
}
