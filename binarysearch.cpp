#include<bits/stdc++.h>
using namespace std;
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
    int low = 0;
    int high = n;
    while(low != high)
    {
        //cout << low << ' '<<high<<endl;
        int mid = (low + high)/2;
        if(arr[mid] == key)
        {
            cout << "The key is found at position "<<mid + 1<<endl;
            break;
        }
        else if(arr[mid] > key)
        {
            high = mid;
            continue;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
    }
    if(low == high )
    {
        cout << "The Key is not present in the array "<<endl;
    }

}
