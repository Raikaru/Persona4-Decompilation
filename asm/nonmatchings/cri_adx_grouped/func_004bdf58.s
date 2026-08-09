.section .text
.set noat
.set noreorder
glabel func_004bdf58
    /* 3BDF58 004BDF58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDF5C 004BDF5C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDF60 004BDF60 0400848C */  lw         $4, 0x4($4)
    /* 3BDF64 004BDF64 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDF68 004BDF68 C2501308 */  j          func_004d4308
    /* 3BDF6C 004BDF6C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdf58, 0x18
