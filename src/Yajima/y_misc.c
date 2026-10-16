/* Source unit: src/Yajima/y_misc_0027be60.c */
#include "type.h"
#include "message_procedure_api.h"



#pragma push


// Intent: returns the sub-table pointer (+0x18) of a message window's sub-table entry.
// FUN_0027BE60
void *itfMesWindowSubTablePtr(s32 handle)

{

  int iVar1;

  

  iVar1 = itfMesWindowGetSubTable(handle);

  return *(void **)(iVar1 + 0x18);

}

#pragma pop
