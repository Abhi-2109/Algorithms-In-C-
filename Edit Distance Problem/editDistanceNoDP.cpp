#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2){
	if(s1.size()==0 || s2.size() == 0)
    {
      return s1.size() + s2.size();
    }
  if(s1[0] == s2[0])
    return editDistance(s1.substr(1), s2.substr(1));

  // Delete a Character or Insert a Character

  int e1 = 1 + editDistance(s1.substr(1),s2);
  int e2 = 1 + editDistance(s1,s2.substr(1));

  // Replace a Character

  int e3 = 1 + editDistance(s1.substr(1), s2.substr(1));

  return min(e1, min(e2,e3));
}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
