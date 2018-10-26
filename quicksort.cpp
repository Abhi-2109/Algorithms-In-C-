#include<bits/stdc++.h>
using namespace std;
void quicksort(vector <int > &arr,int start,int last)
{
    if(last - start < 2)
        return;
    int pivot = arr[start];
    int i = start + 1;
    int j = last -1;
    while(i!=j)
    {
        if(arr[i] <= pivot)
            i++;
        else if(arr[j] >= pivot)
            j--;
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if(arr[i] < pivot)
    {
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
    quicksort(arr,start,i);
    quicksort(arr,i,last);
}
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
    quicksort(arr,0,n);
    cout<< "After Sorting :"<<endl;
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0 ;
}
