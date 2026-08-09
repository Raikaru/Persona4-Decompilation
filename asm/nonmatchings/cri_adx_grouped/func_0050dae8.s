.section .text
.set noat
.set noreorder
glabel func_0050dae8
    /* 40DAE8 0050DAE8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40DAEC 0050DAEC 0000B0FF */  sd         $16, 0x0($29)
    /* 40DAF0 0050DAF0 2D808000 */  daddu      $16, $4, $0
    /* 40DAF4 0050DAF4 0800B1FF */  sd         $17, 0x8($29)
    /* 40DAF8 0050DAF8 2D88A000 */  daddu      $17, $5, $0
    /* 40DAFC 0050DAFC 1000B2FF */  sd         $18, 0x10($29)
    /* 40DB00 0050DB00 1800BFFF */  sd         $31, 0x18($29)
    /* 40DB04 0050DB04 0A35140C */  jal        func_0050d428
    /* 40DB08 0050DB08 2D90C000 */   daddu     $18, $6, $0
    /* 40DB0C 0050DB0C 01000324 */  addiu      $3, $0, 0x1
    /* 40DB10 0050DB10 2D200002 */  daddu      $4, $16, $0
    /* 40DB14 0050DB14 2D282002 */  daddu      $5, $17, $0
    /* 40DB18 0050DB18 09004310 */  beq        $2, $3, .L0050DB40
    /* 40DB1C 0050DB1C 2D304002 */   daddu     $6, $18, $0
    /* 40DB20 0050DB20 7600043C */  lui        $4, %hi(D_0075F4B8)
    /* 40DB24 0050DB24 0000B0DF */  ld         $16, 0x0($29)
    /* 40DB28 0050DB28 0800B1DF */  ld         $17, 0x8($29)
    /* 40DB2C 0050DB2C B8F48424 */  addiu      $4, $4, %lo(D_0075F4B8)
    /* 40DB30 0050DB30 1000B2DF */  ld         $18, 0x10($29)
    /* 40DB34 0050DB34 1800BFDF */  ld         $31, 0x18($29)
    /* 40DB38 0050DB38 88441408 */  j          func_00511220
    /* 40DB3C 0050DB3C 2000BD27 */   addiu     $29, $29, 0x20
  .L0050DB40:
    /* 40DB40 0050DB40 0000B0DF */  ld         $16, 0x0($29)
    /* 40DB44 0050DB44 0800B1DF */  ld         $17, 0x8($29)
    /* 40DB48 0050DB48 1000B2DF */  ld         $18, 0x10($29)
    /* 40DB4C 0050DB4C 1800BFDF */  ld         $31, 0x18($29)
    /* 40DB50 0050DB50 38321408 */  j          func_0050c8e0
    /* 40DB54 0050DB54 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050dae8, 0x70
