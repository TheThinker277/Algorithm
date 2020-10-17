#include <iostream> 
using namespace std; 
int main(){
int arr[]={3,4,2,7,0};
int temp1=arr[0], temp2=arr[1],n=5;
int i;
for(i=0;i<n-2;i++)
arr[i]=arr[i+2];

arr[n-2]= temp1;
arr[n-1]= temp2;

for(i=0;i<n;i++)
cout<<arr[i]<<endl;
return 0;
}