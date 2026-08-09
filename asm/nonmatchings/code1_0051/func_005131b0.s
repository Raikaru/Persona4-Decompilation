.section .text
.set noat
.set noreorder
glabel func_005131b0
    /* 4131B0 005131B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4131B4 005131B4 2D30A000 */  daddu      $6, $5, $0
    /* 4131B8 005131B8 0000BFFF */  sd         $31, 0x0($29)
    /* 4131BC 005131BC 6053140C */  jal        func_00514d80
    /* 4131C0 005131C0 0C20858C */   lw        $5, 0x200C($4)
    /* 4131C4 005131C4 0000BFDF */  ld         $31, 0x0($29)
    /* 4131C8 005131C8 0800E003 */  jr         $31
    /* 4131CC 005131CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_005131b0, 0x20
