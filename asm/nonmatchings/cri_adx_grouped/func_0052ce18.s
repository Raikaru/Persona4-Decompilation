.section .text
.set noat
.set noreorder
glabel func_0052ce18
    /* 42CE18 0052CE18 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 42CE1C 0052CE1C 7600053C */  lui        $5, %hi(D_00760FC8)
    /* 42CE20 0052CE20 1800B1FF */  sd         $17, 0x18($29)
    /* 42CE24 0052CE24 2D88C000 */  daddu      $17, $6, $0
    /* 42CE28 0052CE28 C80FA524 */  addiu      $5, $5, %lo(D_00760FC8)
    /* 42CE2C 0052CE2C 08000624 */  addiu      $6, $0, 0x8
    /* 42CE30 0052CE30 1000B0FF */  sd         $16, 0x10($29)
    /* 42CE34 0052CE34 2000BFFF */  sd         $31, 0x20($29)
    /* 42CE38 0052CE38 7A0B110C */  jal        func_00442de8
    /* 42CE3C 0052CE3C 2D808000 */   daddu     $16, $4, $0
    /* 42CE40 0052CE40 7600053C */  lui        $5, %hi(D_00760FD8)
    /* 42CE44 0052CE44 2D20A003 */  daddu      $4, $29, $0
    /* 42CE48 0052CE48 13000624 */  addiu      $6, $0, 0x13
    /* 42CE4C 0052CE4C 2208110C */  jal        func_00442088
    /* 42CE50 0052CE50 D80FA524 */   addiu     $5, $5, %lo(D_00760FD8)
    /* 42CE54 0052CE54 2D200002 */  daddu      $4, $16, $0
    /* 42CE58 0052CE58 2D28A003 */  daddu      $5, $29, $0
    /* 42CE5C 0052CE5C 0A09110C */  jal        func_00442428
    /* 42CE60 0052CE60 10001026 */   addiu     $16, $16, 0x10
    /* 42CE64 0052CE64 7600053C */  lui        $5, %hi(D_00760FE0)
    /* 42CE68 0052CE68 02000624 */  addiu      $6, $0, 0x2
    /* 42CE6C 0052CE6C 2D200002 */  daddu      $4, $16, $0
    /* 42CE70 0052CE70 7A0B110C */  jal        func_00442de8
    /* 42CE74 0052CE74 E00FA524 */   addiu     $5, $5, %lo(D_00760FE0)
    /* 42CE78 0052CE78 2D200002 */  daddu      $4, $16, $0
    /* 42CE7C 0052CE7C AAB3140C */  jal        func_0052cea8
    /* 42CE80 0052CE80 2D282002 */   daddu     $5, $17, $0
    /* 42CE84 0052CE84 7600053C */  lui        $5, %hi(D_00760FE8)
    /* 42CE88 0052CE88 2D200002 */  daddu      $4, $16, $0
    /* 42CE8C 0052CE8C 0A09110C */  jal        func_00442428
    /* 42CE90 0052CE90 E80FA524 */   addiu     $5, $5, %lo(D_00760FE8)
    /* 42CE94 0052CE94 1000B0DF */  ld         $16, 0x10($29)
    /* 42CE98 0052CE98 1800B1DF */  ld         $17, 0x18($29)
    /* 42CE9C 0052CE9C 2000BFDF */  ld         $31, 0x20($29)
    /* 42CEA0 0052CEA0 0800E003 */  jr         $31
    /* 42CEA4 0052CEA4 3000BD27 */   addiu     $29, $29, 0x30
.size func_0052ce18, 0x90
