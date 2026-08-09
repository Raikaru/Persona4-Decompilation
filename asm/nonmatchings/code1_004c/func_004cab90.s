.section .text
.set noat
.set noreorder
glabel func_004cab90
    /* 3CAB90 004CAB90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CAB94 004CAB94 0000B0FF */  sd         $16, 0x0($29)
    /* 3CAB98 004CAB98 2D808000 */  daddu      $16, $4, $0
    /* 3CAB9C 004CAB9C 0800B1FF */  sd         $17, 0x8($29)
    /* 3CABA0 004CABA0 1000BFFF */  sd         $31, 0x10($29)
    /* 3CABA4 004CABA4 3615130C */  jal        func_004c54d8
    /* 3CABA8 004CABA8 2D88A000 */   daddu     $17, $5, $0
    /* 3CABAC 004CABAC 2D200002 */  daddu      $4, $16, $0
    /* 3CABB0 004CABB0 F42A130C */  jal        func_004cabd0
    /* 3CABB4 004CABB4 2D282002 */   daddu     $5, $17, $0
    /* 3CABB8 004CABB8 0000B0DF */  ld         $16, 0x0($29)
    /* 3CABBC 004CABBC 0800B1DF */  ld         $17, 0x8($29)
    /* 3CABC0 004CABC0 1000BFDF */  ld         $31, 0x10($29)
    /* 3CABC4 004CABC4 38151308 */  j          func_004c54e0
    /* 3CABC8 004CABC8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CABCC 004CABCC 00000000 */  nop
.size func_004cab90, 0x40
