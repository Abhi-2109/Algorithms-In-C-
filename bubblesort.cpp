#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector <int > arr;
    cout<< " Enter the number of elemnents : ";
    cin>>n;
    int temp;
    cout << "Enter the elements  :"<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    for(int i = 0;i<n-1;i++)
    {
        for(int j = 0 ;j < n-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "After sorting :"<<endl;
    for(int i = 0 ;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
