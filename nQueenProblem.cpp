#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
int board[20][20];
int ctr;
bool check(int n,int row,int col)
{
  for(int i = row-1;i>=0;i--)
    if(board[i][col] == 1)
      return false;
  for(int i = row - 1, j = col -1; i>=0 && j >= 0; j--,i--)
    if(board[i][j] == 1)
      return false;
  for(int i = row -1, j = col + 1; i >= 0 && j < n; j++,i--)
    if(board[i][j] == 1)
      return false;
  return true;
}
void printnqueens(int n,int row)
{
  if(row==n)
  {
    cout << "Solution No " << ++ctr << endl << endl;
    for(int i = 0; i<n;i++){
    	for(int j=0;j<n;j++)
          cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    return;
  }
  for(int i = 0 ; i < n; i++)
  {
    if(check(n,row,i))
    {
      board[row][i] = 1;
      printnqueens(n,row+1);
      board[row][i] = 0;
    }
  }
  return ;
}
void placeNQueens(int n){
    ctr = 0;
  	memset(board,0,20*20*sizeof(int));
	printnqueens(n,0);

}

int main()
{
    int n;
    cout << "Enter the size of the chess :";
    cin >> n;
    placeNQueens(n);
}
