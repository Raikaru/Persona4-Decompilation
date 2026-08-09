.section .text
.set noat
.set noreorder
glabel func_0050cb08
    /* 40CB08 0050CB08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CB0C 0050CB0C 0000BFFF */  sd         $31, 0x0($29)
    /* 40CB10 0050CB10 4033140C */  jal        func_0050cd00
    /* 40CB14 0050CB14 08000424 */   addiu     $4, $0, 0x8
    /* 40CB18 0050CB18 0000BFDF */  ld         $31, 0x0($29)
    /* 40CB1C 0050CB1C 09000424 */  addiu      $4, $0, 0x9
    /* 40CB20 0050CB20 40331408 */  j          func_0050cd00
    /* 40CB24 0050CB24 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050cb08, 0x20
