.section .text
.set noat
.set noreorder
glabel func_003df590
    /* 2DF590 003DF590 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2DF594 003DF594 01000224 */  addiu      $2, $0, 0x1
    /* 2DF598 003DF598 1800A5FF */  sd         $5, 0x18($29)
    /* 2DF59C 003DF59C 08004128 */  slti       $1, $2, 0x8
    /* 2DF5A0 003DF5A0 2000A6FF */  sd         $6, 0x20($29)
    /* 2DF5A4 003DF5A4 2800A7FF */  sd         $7, 0x28($29)
    /* 2DF5A8 003DF5A8 3000A8FF */  sd         $8, 0x30($29)
    /* 2DF5AC 003DF5AC 3800A9FF */  sd         $9, 0x38($29)
    /* 2DF5B0 003DF5B0 4000AAFF */  sd         $10, 0x40($29)
    /* 2DF5B4 003DF5B4 4800ABFF */  sd         $11, 0x48($29)
    /* 2DF5B8 003DF5B8 3C100400 */  dsll32     $2, $4, 0
    /* 2DF5BC 003DF5BC 3F100200 */  dsra32     $2, $2, 0
    /* 2DF5C0 003DF5C0 0800E003 */  jr         $31
    /* 2DF5C4 003DF5C4 5000BD27 */   addiu     $29, $29, 0x50
    /* 2DF5C8 003DF5C8 00000000 */  nop
    /* 2DF5CC 003DF5CC 00000000 */  nop
.size func_003df590, 0x40
