#include<stdio.h>
int main()
{
    int n;
    int sum=0;
    printf("enter the size of array:");
    scanf("%d",&n);
    int arr[n][n];
    printf("enter the elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
         sum=sum+arr[i][i];
    }
    printf("sum of left diagonal elements in an array is %d",sum);
}


