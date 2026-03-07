#include<stdio.h>
int main()
{
    int n,first,second;
    printf("enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements:\n");
    for(int i;i<n;i++){
        scanf("%d",&arr[i]);
    }
    if(arr[0]>arr[1]){
      first=arr[0];
      second=arr[1];
    }
    else{
        first=arr[1];
        second=arr[0];
    }
    for(int j=2;j<n;j++){
        if(arr[j] > first){
            second=first;
            first=arr[j];
        }
    }
    printf("second largest element in an array is %d",second);
}
