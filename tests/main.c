#include<stdio.h>
#include "MW_File_Iterator.h"
#define FISIZE 100
void MW_TestFunction(void* function,char* functionName)
{
	int r;
	
	
	
}
int main (void)
{
	MW_FI_tppFI iterador;
	int r;
	MW_Int limit,i;
	char* vector;
	if((r=MW_FI_CreateIterator(&iterador,"test1.txt","test2.txt",FISIZE))!=MW_FI_CondRetOK)
	{
		printf("Create: %d\n",r);
	}
	if((r=MW_FI_AdvanceReading(iterador))!=MW_FI_CondRetOK)
	{
		printf("Adv Reading: %d\n",r);
	}
	if((r=MW_FI_GetData(iterador,&vector,&limit))!=MW_FI_CondRetOK)
	{
		printf("Get Data: %d\n",r);
	}
	for(i=0;i<limit;i++)
	{
		printf("%c",vector[i]);
	}
	printf("limit: %d\n",limit);
	MW_FI_DestroyIterator(iterador);

	return 0;
}