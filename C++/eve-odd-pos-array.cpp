#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

int main(){

int arr[]={3,4,2,1,9};
int n=5;
int evenPos = n / 2; 
  
    // total odd positions 
    int oddPos = n - evenPos; 
  
    int tempArr[5]; 
  
    // copy original array in an 
    // auxiliary array 
     for(int i = 0; i < n; i++) 
        tempArr[i] = arr[i]; 
  
    // sort the auxiliary array 
    sort(tempArr, tempArr + n); 
  
    int j = oddPos - 1; 

    for (int i = 0; i < n; i += 2) { 
        arr[i] = tempArr[j]; 
        j--; 
    } 

     j = oddPos; 
  
    // fill up even positions in original 
    // array 
    for (int i = 1; i < n; i += 2) { 
        arr[i] = tempArr[j]; 
        j++; 
    } 
  
    // display array 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
//for(i=0;i<n;i+=2)
//{arr[i]= temp[j];
//j--
//}
//for(i=1;i<n;i+=2)
//arr[i]=arr[j];
//j++
    


  