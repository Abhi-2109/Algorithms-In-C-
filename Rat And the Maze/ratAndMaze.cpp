#include<bits/stdc++.h>
int output[20][20];

bool check(int maze[][20],int row,int col,int n)
{
  if(maze[row][col] == 0 || output[row][col] == 1)
    return false;
  if(col == n || row == n || col < 0 || row < 0)
    return false;
  return true;
}
void rattravel(int maze[][20],int n,int row,int col)
{
  if(n-1 == col && n-1 == row)
  {
    output[n-1][n-1] = 1;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cout << output[i][j] << " ";
    cout << endl << endl;
    output[n-1][n-1] = 0;
    return;
  }
  output[row][col] = 1;
  if(check(maze,row - 1,col,n))
  	rattravel(maze,n,row-1,col);
  if(check(maze,row+1,col,n))
    rattravel(maze,n,row + 1,col);
  if(check(maze,row,col-1,n))
  	rattravel(maze,n,row,col-1);
  if(check(maze,row,col+1,n))
  	rattravel(maze,n,row,col + 1);
  output[row][col] = 0;
  return;
}
void ratInAMaze(int maze[][20], int n){
  memset(output,0,20*20*sizeof(int));
  rattravel(maze,n,0,0);


}

