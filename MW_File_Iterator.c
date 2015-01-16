//
//  MW_File_Iterator.c
//  MW_File_Iterator
//
//  Created by Lucas Menezes on 05/01/15.
//  Copyright (c) 2015 MENEZESWORKS. All rights reserved.
//

#include "MW_File_Iterator.h"

typedef struct MW_FI_tagFI
{
    FILE* input;
    /* FILE pointer for the input File */
    FILE* output;
    /* FILE pointer for the output File */
    MW_Int fSize;
    /* size of the input File */
    MW_Int bytesWritten;
    /* bytes of the already written in output */
    char* data;
    /* Vector that is exposed */
    MW_Int sizeOfData;
    /* size of data vector */
	MW_Int sizeOfActualData;
	/* size of data vector actually filled with information */
    
    
} MW_FI_tpFI ;

MW_FI_tpCondRet MW_FI_CreateIterator( MW_FI_tppFI* refFI, char* inputPath, char* outputPath, MW_Int sizeOfData)
{
    (*refFI)=(MW_FI_tppFI)malloc(sizeof(MW_FI_tpFI)); //allocs FI
    
    (*refFI)->input=fopen(inputPath,"rb");
    if(!((*refFI)->input))
        return MW_FI_CondRetFileNotFound;
    (*refFI)->output=fopen(outputPath,"wb");
    if(!((*refFI)->output))
        return MW_FI_CondRetFileNotFound;
    (*refFI)->data=(char*)malloc(sizeOfData);
    if(!((*refFI)->data))
        return MW_FI_CondRetMemoryLack;
    (*refFI)->sizeOfData=sizeOfData;
	(*refFI)->sizeOfActualData=0; //there's no data yet
    (*refFI)->fSize=ftell((*refFI)->input); //Informs the size
    rewind((*refFI)->input); // resets to the begining;
    
    
    return MW_FI_CondRetOK;
}
MW_FI_tpCondRet MW_FI_GetData(MW_FI_tppFI iterator, void** refVector, MW_Int * refSizeOfVector)
{
    *refVector=(void*)iterator->data;
    *refSizeOfVector=(MW_Int)iterator->sizeOfActualData;
    return MW_FI_CondRetOK;
}
MW_FI_tpCondRet MW_FI_AdvanceReading(MW_FI_tppFI iterator)
{
    char c,r;
    MW_Int i=0;
    do
    {
        r=fscanf(iterator->input,"%c",&c);
        iterator->data[i]=c;
        i++;
    }while(i<iterator->sizeOfData && r!=EOF);
    if(r==EOF)
    {
        i--; //cancells iteration
		iterator->sizeOfActualData=i;
        return MW_FI_CondRetEOF;
    }
//Warning not sure yet if another data field is required to save i value ( shorter vector limit by the EOF
	iterator->sizeOfActualData=iterator->sizeOfData;
    return MW_FI_CondRetOK;
}
MW_FI_tpCondRet MW_FI_AdvanceWriting(MW_FI_tppFI iterator)
{
    
    MW_Int i;
	if(iterator->bytesWritten==iterator->fSize)
		return MW_FI_CondRetFinishedWriting;
    for(i=0; i<(iterator->sizeOfActualData) && (iterator->bytesWritten)<(iterator->fSize); i++)
    {
        fprintf(iterator->output,"%c",iterator->data[i]);
		//printf("%c",iterator->data[i]);
			iterator->bytesWritten++;
    }
	if(iterator->bytesWritten>=iterator->fSize)
		return MW_FI_CondRetFinishedWriting;
    return MW_FI_CondRetOK;
}
MW_FI_tpCondRet MW_FI_DestroyIterator(MW_FI_tppFI iterator)
{
    fclose(iterator->input);
    fclose(iterator->output);
    free(iterator->data);
    iterator->fSize=0;
    iterator->sizeOfData=0;
    iterator->data=NULL;
    iterator->bytesWritten=0;
    iterator->input=NULL;
    iterator->output=NULL;
	free(iterator); // frees struct memory
    return MW_FI_CondRetOK;
}
void MW_FI_DebugStruct(MW_FI_tppFI iterator)
{	
	printf("output: %d\n ",iterator->output);
}
char* MW_FI_Vesion(void)
{
    char* version="MW_FI_v1.0a";
    return version;
    
}