#include<stdio.h>
int main()
{
    int n,pos;
    printf("enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter position:");
    scanf("%d",&pos);
    for(int i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    printf("array elements in the array\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}


