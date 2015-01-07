//
//  MW_File_Iterator.h
//  MW_File_Iterator
//
//  Created by Lucas Menezes on 05/01/15.
//  Copyright (c) 2015 MENEZESWORKS. All rights reserved.
//

#ifndef __MW_File_Iterator__MW_File_Iterator__
#define __MW_File_Iterator__MW_File_Iterator__

#include <stdio.h>
#include <stdlib.h>

typedef struct MW_FI_tagFI * MW_FI_tppFI ;
typedef long long int MW_Int;
typedef enum {
    
    MW_FI_CondRetOK ,
    /* Done correctly */
    MW_FI_CondRetMemoryLack ,
    /* There`s no memory left */
    MW_FI_CondRetFileNotFound ,
    /* File couldn`t be opened correctly */
    MW_FI_CondRetEOF
    /* End Of File */
    
    
} MW_FI_tpCondRet ;

MW_FI_tpCondRet MW_FI_CreateIterator( MW_FI_tppFI* refFI, char* inputPath, char* outputPath, MW_Int sizeOfData);
MW_FI_tpCondRet MW_FI_GetData(MW_FI_tppFI iterator, void** refVector , MW_Int * refSizeOfVector );
MW_FI_tpCondRet MW_FI_AdvanceWriting(MW_FI_tppFI iterator);
MW_FI_tpCondRet MW_FI_AdvanceReading(MW_FI_tppFI iterator);
MW_FI_tpCondRet MW_FI_DestroyIterator(MW_FI_tppFI iterator);

#endif /* defined(__MW_File_Iterator__MW_File_Iterator__) */
