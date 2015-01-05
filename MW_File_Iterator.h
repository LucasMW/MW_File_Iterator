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
typedef int MW_Int;
typedef enum {
    
    MW_FI_CondRetOK ,
    /* Concluiu corretamente */
    MW_FI_CondRetMemoryLack ,
    /* Não há memória pra alocar */
    MW_FI_CondRetFileNotFound ,
    /* o grafo não contém elementos */
    MW_FI_CondRetArestaJaExiste,
    /* A aresta já existe */
    MW_FI_CondRetNoNaoExiste,
    /* O nó não existe */
    MW_FI_CondRetArestaNaoExiste,
    /* A aresta já existe */
    MW_FI_CondRetJaEsta
    /* Já está no nó */
    
} MW_FI_tpCondRet ;

MW_FI_tpCondRet MW_FI_CreateIterator( MW_FI_tppFI* refFI, char* inputPath, char* outputPath, MW_Int sizeOfData);
MW_FI_tpCondRet MW_FI_GetData(MW_FI_tppFI iterator, void** refVector  );



#endif /* defined(__MW_File_Iterator__MW_File_Iterator__) */
