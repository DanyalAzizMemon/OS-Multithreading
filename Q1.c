#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>

void* count_Func(void *arg)
{
	int count = 0;
	FILE *f;
	char alpha = (char)arg;
    
	f = fopen("temp.txt","r");
	while(!feof(f))
	{
		char ch = fgetc(f);
		int upper = ch -32;
		char d = upper;
		if(ch == alpha||d == alpha)
		count++;
        
	}
	printf("\nFunction called by thread: '%c'\n",alpha);
	printf("Occurent in file :%d\n",count);
	fclose(f);
	pthread_exit(count);
}

int main()
{
	pthread_t t[26];
	int total = 0, *count = 0;   
	char alpha[26];


	for (int i =0, ascii =97; i < 26; i++,ascii++)	//ascii for each alphabet is stored
   		alpha[i] = ascii;
 
	for (int i=0;i<26;i++)
	{
   	     pthread_create( &t[i], NULL, count_Func, (void*)alpha[i] );
        	pthread_join(t[i],&count);
        	total+=(int)count;        
	}

	printf("\nTotal Characters in file : %d\n",total);
    
    
}
