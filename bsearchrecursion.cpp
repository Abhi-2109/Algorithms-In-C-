#include<bits/stdc++.h>
using namespace std;
int bsearch(vector <int> arr, int low, int high, int key)
{
    if(low==high)
        return -1;
    int mid = (low + high)/2;
    if(arr[mid] == key)
        return mid;
    if(arr[mid] > key)
        return bsearch(arr,low,mid,key);
    return bsearch(arr,mid+1,high,key);
}
int main()
{
    int n;
    vector <int > arr;
    cout<< " Enter the number of elemnents : ";
    cin>>n;
    int temp;
    cout << "Enter the elements in sorted order :"<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    cout << " Enter the key you want to search : ";
    int key;
    cin>>key ;
    int x = bsearch(arr,0,n,key);
    if(x == -1)
    {
        cout << "Element is not present "<<endl;
    }
    else
    {
        cout << "Element found at position "<< x + 1 << endl;
    }
    return 0;
}
