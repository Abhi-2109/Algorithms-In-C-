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
    for(int i = 0 ; i < n ;i++)
    {
        int m = 0;
        for(int j = 0 ;j < n-i;j++)
        {
            if(arr[m] < arr[j])
                m = j;
        }
        int temp = arr[n-i-1];
        arr[n-i-1] = arr[m];
        arr[m] = temp;
    }

    cout << "After Sorting : "<<endl;
    for(int i = 0 ; i < n;i++)
        cout<<arr[i]<<' ';
    return 0;
}
