#include<stdio.h>
#include<conio.h>
int minimum(int arr[],int k,int n);
int main(){
	int n,i;
	printf("Enter the number of elemensts in an array\n");
	scanf("%d",&n);
	int arr[n];
	printf("enter elemnts of array\n");
	for(i=0;i<n;i++){
	   scanf("%d",&arr[i]);
	}
	int temp=0,ref=0;
	for(i=0;i<n-1;i++){
		ref = minimum(arr,i,n);
		temp = arr[i];
		arr[i] = arr[ref];
		arr[ref] = arr[i];
	}
	printf("The array in sorted order\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	return 0;
}
	int minimum(int arr[],int k,int n){
	int init,index,i;
	init = arr[k];
	index = k;
	printf("Strating Index is %d\n",index);
	for(i=k+1;i<n;i++){
		if(arr[i]<init){
		 	init = arr[i];
		 	index = i;
		}
	}
	printf("Index is %d\n",index);
	return(index);
}
