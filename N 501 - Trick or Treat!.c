#include<stdio.h>
int iterativeBinarySearch(int array[], int start_index, int end_index, int element){
   while (start_index <= end_index){
      int middle = start_index + (end_index- start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] < element)
         start_index = middle + 1;
      else
         end_index = middle - 1;
   }
   return -1;
}
void merge(int arr[], int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], R[n2];
for (i = 0; i < n1; i++)
L[i] = arr[l + i];
for (j = 0; j < n2; j++)
R[j] = arr[m + 1+ j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
arr[k] = L[i];
i++;
}




else
{
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1)
{
arr[k] = L[i];
i++;
k++;
}
while (j < n2)
{
arr[k] = R[j];
j++;
k++;
}
}
void mergeSort(int arr[], int l, int r)
{
if (l < r)
{
int m = l+(r-l)/2;
mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);
}
}
int main(){
    int a;
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,a);
    int b;
    scanf("%d",&b);
    int brr[b];
    
    for(int i=0;i<b;i++){
        scanf("%d",&brr[i]);
    }
    for(int i=0;i<b;i++){
        int flag=0;
       if(iterativeBinarySearch(arr,0,a,brr[i])!=-1){
           flag=1;
       }
        
        if(flag==1){
            printf("Happy Halloween!\n");
        }
        else{
            printf("Tricky!\n");
        }
    }
}
