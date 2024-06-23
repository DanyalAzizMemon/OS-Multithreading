#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>



int globalsize =0;

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
/*----------------------------------------------------------
-----------------------------------------------------------*/

void *func(void *arg)
{

	int *a = (int*)arg;
	int size = globalsize;
	
	printf("Size ; %d\n\n\n\n\n",size);
	mergeSort(a,0,size-1);
	
			printf("\n----------Sorted Arrray-------------\n");
		for (int i =0; i < size; i++)
		{
			printf("%d\t,",a[i]);
		}


}

int main()
{
	int size;
	int split_arrays;
	int subArr_size;
	int remaining =0;
	
	long int cores = sysconf(_SC_NPROCESSORS_ONLN);
	printf("Number of Cores in this PC : %ld\n",cores); // number of cores

	printf("Enter the number of elements in array : ");
	scanf("%d",&size);

	int array[size];	
	
	printf("\n-------Initializing Array-------\n");
	for (int i =0; i < size; i++)
	{
		printf("Enter element [%d] : ",i+1);
		scanf("%d",&array[i]);
	}
		
		
		if(size == 0)	
			return 0;
			
		else if(size <= cores)
		{

			globalsize = size;
			pthread_t th;
			pthread_create(&th,NULL,func,(void*)array);
			pthread_join(th,NULL);				
		}
		
		else		//6 threads are made
		{
			remaining = (size % 6);
			subArr_size = size / cores;
			//printf("size of arrays made : %d", subArr_size);
		
			
			int a1[subArr_size],a2[subArr_size],a3[subArr_size],a4[subArr_size],a5[subArr_size],a6[subArr_size + remaining];	//array 6 might contain more elements then the remaining		
			
			int g=0;
			for (int i =0; i < subArr_size; i++,g++)	//Array 1
				a1[i] = array[g];
			
			for (int i = 0; i < subArr_size; i++,g++)	//Array 2
				a2[i] = array[g];

			for (int i =0; i < subArr_size; i++,g++)	//Array 3
				a3[i] = array[g];

			for (int i =0; i < subArr_size; i++,g++)	//Array 4
				a4[i] = array[g];

			for (int i =0; i < subArr_size; i++,g++)	//Array 5
				a5[i] = array[g];

			for (int i =0; i < subArr_size + remaining; i++,g++)	//Array 6 with remaining
				a6[i] = array[g];
					
					
					
			
			globalsize = subArr_size;
			pthread_t t[6];
			pthread_create(&t[0],NULL,func,(void*)a1);
			pthread_join(t[0],NULL);				

			pthread_create(&t[1],NULL,func,(void*)a2);
			pthread_join(t[1],NULL);				

			pthread_create(&t[2],NULL,func,(void*)a3);
			pthread_join(t[2],NULL);				

			pthread_create(&t[3],NULL,func,(void*)a4);
			pthread_join(t[3],NULL);				

			pthread_create(&t[4],NULL,func,(void*)a5);
			pthread_join(t[4],NULL);				
			
			globalsize = subArr_size + remaining;		
			pthread_create(&t[5],NULL,func,(void*)a6);
			pthread_join(t[5],NULL);	
			
			
			//combining all the sub sorted arrays and doing a mergesort on them
			g=0;
			for (int i =0; i < subArr_size; i++,g++)	//Array 1
				array[g] = a1[i];
			
			for (int i = 0; i < subArr_size; i++,g++)	//Array 2
				array[g] = a2[i];

			for (int i =0; i < subArr_size; i++,g++)	//Array 3
				array[g] = a3[i];

			for (int i =0; i < subArr_size; i++,g++)	//Array 4
				array[g] = a4[i];

			for (int i =0; i < subArr_size; i++,g++)	//Array 5
				array[g] = a5[i];

			for (int i =0; i < subArr_size + remaining; i++,g++)	//Array 6 with remaining
				array[g] = a6[i];	
			mergeSort(array,0,size-1);
			printf("\n----------------Combining all the sub arrays into 1----------------\n");
			for (int i =0; i < size;i++)
			{
				printf("\nA[%d]: %d\n",i,array[i]);//i,array[i]);
			}	
						
					
		}	
		
}	



