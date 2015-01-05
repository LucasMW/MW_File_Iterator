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
    
    
} MW_FI_tpFI ;

MW_FI_tpCondRet MW_FI_CreateIterator( MW_FI_tppFI* refFI, char* inputPath, char* outputPath, MW_Int sizeOfData)
{
    (*refFI)=(MW_FI_tppFI)malloc(sizeof(MW_FI_tpFI)); //allocs FI
    
    (*refFI)->input=fopen(inputPath,"wb");
    if(!((*refFI)->input))
        return MW_FI_CondRetFileNotFound;
    (*refFI)->output=fopen(outputPath,"wb");
    if(!((*refFI)->output))
        return MW_FI_CondRetFileNotFound;
    (*refFI)->data=(char*)malloc(sizeOfData);
    if(!((*refFI)->data))
        return MW_FI_CondRetMemoryLack;
    (*refFI)->sizeOfData=sizeOfData;
    (*refFI)->fSize=ftell((*refFI)->input); //Informs the size
    rewind((*refFI)->input); // resets to the begining;
    
    
    return MW_FI_CondRetOK;
}
MW_FI_tpCondRet MW_FI_GetData(MW_FI_tppFI iterator, void** refVector )
{
    *refVector=(void*)iterator->data;
    return MW_FI_CondRetOK;
}