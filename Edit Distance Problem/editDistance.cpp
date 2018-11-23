#include<iostream>
#include<cstring>
using namespace std;
int editDistanceHelper(string s1, string s2, int **dp)
{
  if(s1.size()==0 || s2.size() == 0)
    {
      return s1.size() + s2.size();
    }
  int l1 = s1.size();
  int l2 = s2.size();
  if(dp[l1][l2] != -1)
    return dp[l1][l2];

  if(s1[0] == s2[0])
  {
    dp[l1][l2] =  editDistanceHelper(s1.substr(1), s2.substr(1),dp);
    return dp[l1][l2];
  }


  // Delete a Character
  int e1 = 1 + editDistanceHelper(s1.substr(1),s2,dp);
  int e2 = 1 + editDistanceHelper(s1,s2.substr(1),dp);

  // Replace a Character

  int e3 = 1 + editDistanceHelper(s1.substr(1), s2.substr(1),dp);

  dp[l1][l2] =  min(e1, min(e2,e3));

  return dp[l1][l2];

}
int editDistance(string s1, string s2){


  // Now lets make a helper Function to solve this
  int l1 = s1.size() + 1;
  int l2 = s2.size() + 1;
 	int **dp = new int*[l1];
  	for(int i = 0; i < l1; i++)
      dp[i] = new int[l2];
  for(int i = 0; i < l1; i++)
    for(int j = 0; j < l2; j++)
      dp[i][j] = -1;
  return editDistanceHelper(s1,s2,dp);
}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
