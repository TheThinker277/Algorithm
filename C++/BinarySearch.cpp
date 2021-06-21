#include<iostream>
using namespace std;
//using iteration
int binarySearchIter(int a[], int l, int r, int key) 
{ 
   while(r>l) { 
        int mid = l + (r - l) / 2; 
  
        if (a[mid] == key) 
            return mid; 
   
        if (a[mid] > key) 
            r=mid-1;
        else
            l=mid+1;
         
    } 
   
    return -1; 
} 
//using recursion 
int binarySearchRec(int arr[], int l, int r, int key) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == key) 
            return mid; 
   
        if (arr[mid] > key) 
            return binarySearchRec(arr, l, mid - 1, key); 
  
        return binarySearchRec(arr, mid + 1, r, key); 
    } 
   
    return -1; 
} 
int main()
{

    int n,key;
    cout<<"ENTER THE NUMBER OF ELEMENTS"<<"\n";
    cin>>n;
    cout<<"ENTER THE ELEMENTS"<<"\n";
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"ENTER THE ELEMENT YOU WANT TO FIND THE POSITION OF"<<"\n";
    cin>>key;  
    int pos = binarySearchIter(a, 0, n - 1, key);
    int pos2 = binarySearchRec(a, 0, n - 1, key);  
    (pos == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at position " << pos+1<<endl;
    (pos2 == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at position " << pos2+1;                 
    return 0; 
}