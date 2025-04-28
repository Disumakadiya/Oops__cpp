#include<iostream>
using namespace std;

int main()
{
    int n, m;

    cout<<"Enter the size of 1st array: ";
    cin>>n;
    cout<<"Enter the size of 2nd array: ";
    cin>>m;

    int *arr1 = new int[n];
    int *arr2 = new int[m];

    cout<<"Enter the 1st sorted array elements: ";
    for(int i=0; i<n; i++)
    {
        cin>>arr1[i];
    }

    cout<<"Enter the 2nd sorted array elements: ";
    for(int j=0; j<m; j++)
    {
        cin>>arr2[j];
    }

    int *merged = new int[m+n];

    int i=0, j=0, k=0; // k for merged array

    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    while(i<n)
    {
        merged[k++] = arr1[i++];
    }
    while(j<m)
    {
        merged[k++] = arr2[j++];
    }

    cout<<"Merged sorted array: "<<endl;
    for(int idx=0; idx<m+n; ++idx)
    {
        cout<<merged[idx]<<" ";
    }
    cout<<endl;

    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}

///virtual constructor is not created
//but virtual destructor is created
//to run virtual function we need to make object of that class
//object is deleted by last reverse order
//destructor call pela derived class nu thase pachi base class nu thase call 