#include<stdio.h>
#include "MW_File_Iterator.h"
#define VERSION 0.712
#define FISIZE 100
void MW_TestFunction(void* function,char* functionName)
{
	int r;
}
int main (void)
{
	FILE* out;
	MW_FI_tppFI iterador,iterador2;
	int r;
	MW_Int limit,i;
	char* vector;
	printf("Show Version: %f\n",VERSION);
	if((r=MW_FI_CreateIterator(&iterador,"test1.txt","test3.txt",FISIZE))!=MW_FI_CondRetOK)
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
	if((r=MW_FI_AdvanceWriting(iterador))!=MW_FI_CondRetOK)
	{
		printf("Writing %d\n",r);
	}
	for(i=0;i<limit;i++)
	{
		printf("%c",vector[i]);
	}
	printf("limit: %d\n",limit);
	MW_FI_DestroyIterator(iterador);
	/* Current Use test */
	printf("Current use test\n");
	out=fopen("test4.txt","wb");
	if((r=MW_FI_CreateIterator(&iterador,"test1.txt","test2.txt",FISIZE))!=MW_FI_CondRetOK)
		printf("Create: %d\n",r);
	while(MW_FI_AdvanceReading(iterador)!=MW_FI_CondRetEOF)
	{
		MW_FI_GetData(iterador,&vector,&limit);
		for(i=0;i<limit;i++)
		{
			printf("%c",vector[i]);
			fprintf(out,"%c",vector[i]);
		}
		MW_FI_AdvanceWriting(iterador);

	}
	//printf(" <Ended loop> ");
	MW_FI_GetData(iterador,&vector,&limit);
	for(i=0;i<limit;i++)
		{
			printf("%c",vector[i]);
			fprintf(out,"%c",vector[i]);
		}
	MW_FI_AdvanceWriting(iterador);
	MW_FI_DebugStruct(iterador);
	MW_FI_DestroyIterator(iterador);
	system("PAUSE");
	return 0;
}
