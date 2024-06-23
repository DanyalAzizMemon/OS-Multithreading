#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


//this function recieves the relevent row and column in a single array
//index stores alternating values
//temp[0] = m1 value AND temp[1] = m2 value
void *multiply(void *arg)
{
	int *args = (int*)arg;
	int sum=0;
	int i=0;
	do
	{
		sum = args[i] * args[i+1] + sum;
		i+=2;
	}
	while(i<6);
	args[0] = sum;
}


int main()
{
	int m1[3][3],m2[3][3],m3[3][3],temp[6];
	pthread_t th[9];
	
	//Input of m1
	printf("----------Enter values for matrix 1----------\n");
	for (int i = 0; i < 3;i++)
	{
		for(int j=0; j<3;j++)
		{
			printf("Enter Value [%d][%d] : ",i+1,j+1);
			scanf("%d",&m1[i][j]);
		}
		printf("\n");
	}
	
	
	//Input of m2
	printf("\n\n----------Enter values for matrix 2----------\n");
	for (int i = 0; i < 3;i++)
	{
		for(int j=0; j<3;j++)
		{
			printf("Enter Value [%d][%d] : ",i+1,j+1);
			scanf("%d",&m2[i][j]);
		}
		printf("\n");
	}
	
	//displaying matrix 1
	printf("\n\n-----Matrix 1-----\n");
	for (int i = 0; i < 3;i++)
	{
		printf("|");
		for(int j=0; j<3;j++)
		{
			printf(" %d ",m1[i][j]);
		}
		printf("\t|\n");
	}

	
	//displaying matrix 1
	printf("\n\n-----Matrix 2-----\n");
	for (int i = 0; i < 3;i++)
	{
		printf("|");
		for(int j=0; j<3;j++)
		{
			printf(" %d ",m2[i][j]);
		}
		printf("\t|\n");
	}
	
		
	int t_iterator=0;
	int x=0;
	for (int i = 0; i < 3;i++)
	{
		for(int j=0; j<3;j++)
		{
			//int value=0;
			int t=0;
			for(int k =0; k <3;k++)
			{
				temp[t] = m1[i][k];
				temp[t+1] = m2[k][j];
				t+=2;
			}
			
			pthread_create(&th[t_iterator],NULL,multiply,(void*)temp);
			pthread_join(th[t_iterator],NULL);
			++t_iterator;

			//x is used for resultant columns
			if(x>2)		//value reset once it completes one cycle (value of rows)
				x=0;
			m3[i][x] = temp[0]; //the value of final answer is stored in the first index of temp array
			++x;			
		
		}
	}
	
	
	//printing final array
	//displaying matrix 3
	printf("\n\n--Matrix 1 * Matrix 2--\n");
	for (int i = 0; i < 3;i++)
	{
		printf("|");
		for(int j=0; j<3;j++)
		{
			printf(" %d ",m3[i][j]);
		}
		printf("\t|\n");
	}
	
	
	
	
}
