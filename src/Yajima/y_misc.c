#include "type.h"
#include "message_procedure_api.h"

/* itfMesWindowGetSubTable returns an entry whose payload pointer is at +0x18.
   The preceding entry fields are not consumed by this accessor. */
typedef struct ItfMesWindowSubTableEntry {
    u8 pad00[0x18];
    void *data;
} ItfMesWindowSubTableEntry;


#pragma push


// Returns the data pointer of a message window's sub-table entry.
// FUN_0027BE60
void *itfMesWindowSubTablePtr(s32 handle)

{

  s32 entryAddress;


  entryAddress = itfMesWindowGetSubTable(handle);

  return ((ItfMesWindowSubTableEntry *)entryAddress)->data;

}

#pragma pop
