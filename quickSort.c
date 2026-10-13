#include<stdio.h>
int partition(int arr[], int b, int e) {
    int p= b; // pivot
    while(1) 
    {
        
    while(arr[p] <= arr[e] && p!= e)
    {
        e--;                
    }
    if(arr[p] > arr[e]) 
    {
        int temp= arr[p];
        arr[p]= arr[e];
        arr[e]= temp;
        p= e;
    }

    else if(p== e)
    {
        return p;
    }
    while(arr[p] >= arr[b] && p!= b)
    {
        b++;                
    }
    if(arr[p] < arr[b])
    {
        int temp= arr[p];
        arr[p]= arr[b];
        arr[b]= temp;
        p= b;   
    }
    else if(p== b)
    {
        return p;
    }
        
   }
}
void quickSort(int arr[], int b, int e) 
{
    int loc;
    if(b < e) {
        loc= partition(arr, b, e);
        quickSort(arr, b, loc-1);
        quickSort(arr, loc+1, e);
    }
}
int main() {
    int arr[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n-1);
    printf("Sorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}