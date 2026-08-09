.section .text
.set noat
.set noreorder
glabel func_004d8668
    /* 3D8668 004D8668 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D866C 004D866C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D8670 004D8670 0800BFFF */  sd         $31, 0x8($29)
    /* 3D8674 004D8674 3615130C */  jal        func_004c54d8
    /* 3D8678 004D8678 2D808000 */   daddu     $16, $4, $0
    /* 3D867C 004D867C A661130C */  jal        func_004d8698
    /* 3D8680 004D8680 2D200002 */   daddu     $4, $16, $0
    /* 3D8684 004D8684 0000B0DF */  ld         $16, 0x0($29)
    /* 3D8688 004D8688 0800BFDF */  ld         $31, 0x8($29)
    /* 3D868C 004D868C 38151308 */  j          func_004c54e0
    /* 3D8690 004D8690 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8694 004D8694 00000000 */  nop
.size func_004d8668, 0x30
