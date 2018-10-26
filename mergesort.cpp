#include<bits/stdc++.h>
using namespace std;
void mer(vector <int> &arr,int start, int mid, int last)
{
    vector < int > temp;
    int i = start, j = mid;
    while(i < mid && j < last)
    {
        if(arr[i] > arr[j])
        {
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<last)
    {
        temp.push_back(arr[j]);
        j++;
    }
    int k = 0;
    for(int i=start; i< last;i++)
    {
        arr[i] = temp[k];
        k++;
    }
}
void mergesort(vector < int > &arr, int start,int last)
{
    if(last - start > 1 )
    {
        int mid = (last + start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid,last);
        mer(arr,start,mid,last);
    }

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
    mergesort(arr,0,n);
    cout<< "After Sorting :"<<endl;
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0 ;
}
