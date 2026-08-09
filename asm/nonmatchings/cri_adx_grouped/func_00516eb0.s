.section .text
.set noat
.set noreorder
glabel func_00516eb0
    /* 416EB0 00516EB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 416EB4 00516EB4 0000BFFF */  sd         $31, 0x0($29)
    /* 416EB8 00516EB8 B65B140C */  jal        func_00516ed8
    /* 416EBC 00516EBC 00000000 */   nop
    /* 416EC0 00516EC0 BF014238 */  xori       $2, $2, 0x1BF
    /* 416EC4 00516EC4 0000BFDF */  ld         $31, 0x0($29)
    /* 416EC8 00516EC8 0100422C */  sltiu      $2, $2, 0x1
    /* 416ECC 00516ECC 0800E003 */  jr         $31
    /* 416ED0 00516ED0 1000BD27 */   addiu     $29, $29, 0x10
    /* 416ED4 00516ED4 00000000 */  nop
.size func_00516eb0, 0x28
