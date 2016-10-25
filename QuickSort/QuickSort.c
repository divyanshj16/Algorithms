//quicksort Algorithm to sort any number of distinct elements from a file

#include <stdio.h>
#include <stdlib.h>

int arr[10000];

void swap(int c, int d){
	if(c == d)
		return;
	int temp;
	temp = arr[d];
	arr[d] = arr[c];
	arr[c] = temp;
}

int partition(int pivot_index,int end){
	int pivot = arr[pivot_index];
	int i = pivot_index + 1;
	for(int j = i;j < end; j++){
		if(arr[j] < pivot){
			swap(i,j);
			i++;
		}
	}
	swap(pivot_index,(i-1));
	return i;
}


void qs(int st ,int size){
	if(size == st){
		printf("going back\n");
		return;
	}
	int p_index = st;                                //rand() % size;  -- FOR RANDOMISED QUICKSORT
	int x = partition(p_index,size);
	qs(st,x-1);
	qs(x,size);

}


int main()
{
	FILE *fp;                                       //input is in a file QuickSort.txt with a different number at each line
	int num, i = 0;
	fp = fopen("QuickSort.txt","r");
	rewind(fp);
	while(1){
		if(fscanf(fp, "%d", &num) <= 0)	
			break;
		else{
			arr[i++] = num;		
		}
	}
	qs(0,i);

	for(int l = 0;l < i ; l++)
		printf("%d\n",arr[l] );


	return 0;
}
