.section .text
.set noat
.set noreorder
glabel func_004f3d68
    /* 3F3D68 004F3D68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F3D6C 004F3D6C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F3D70 004F3D70 2D808000 */  daddu      $16, $4, $0
    /* 3F3D74 004F3D74 0C000016 */  bnez       $16, .L004F3DA8
    /* 3F3D78 004F3D78 0800BFFF */   sd        $31, 0x8($29)
    /* 3F3D7C 004F3D7C 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3D80 004F3D80 7600063C */  lui        $6, %hi(D_0075D788)
    /* 3F3D84 004F3D84 0000B0DF */  ld         $16, 0x0($29)
    /* 3F3D88 004F3D88 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3D8C 004F3D8C 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3D90 004F3D90 88D7C624 */  addiu      $6, $6, %lo(D_0075D788)
    /* 3F3D94 004F3D94 7D040524 */  addiu      $5, $0, 0x47D
    /* 3F3D98 004F3D98 2D380000 */  daddu      $7, $0, $0
    /* 3F3D9C 004F3D9C 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F3DA0 004F3DA0 F0D41308 */  j          func_004f53c0
    /* 3F3DA4 004F3DA4 1000BD27 */   addiu     $29, $29, 0x10
  .L004F3DA8:
    /* 3F3DA8 004F3DA8 7600053C */  lui        $5, %hi(D_0075D6C0)
    /* 3F3DAC 004F3DAC BA09110C */  jal        func_004426e8
    /* 3F3DB0 004F3DB0 C0D6A524 */   addiu     $5, $5, %lo(D_0075D6C0)
    /* 3F3DB4 004F3DB4 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3DB8 004F3DB8 7600063C */  lui        $6, %hi(D_0075D788)
    /* 3F3DBC 004F3DBC C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3DC0 004F3DC0 88D7C624 */  addiu      $6, $6, %lo(D_0075D788)
    /* 3F3DC4 004F3DC4 82040524 */  addiu      $5, $0, 0x482
    /* 3F3DC8 004F3DC8 2D380000 */  daddu      $7, $0, $0
    /* 3F3DCC 004F3DCC 06004014 */  bnez       $2, .L004F3DE8
    /* 3F3DD0 004F3DD0 99FF0824 */   addiu     $8, $0, -0x67
    /* 3F3DD4 004F3DD4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F3DD8 004F3DD8 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3DDC 004F3DDC F0D41308 */  j          func_004f53c0
    /* 3F3DE0 004F3DE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F3DE4 004F3DE4 00000000 */  nop
  .L004F3DE8:
    /* 3F3DE8 004F3DE8 2D200002 */  daddu      $4, $16, $0
    /* 3F3DEC 004F3DEC 0000B0DF */  ld         $16, 0x0($29)
    /* 3F3DF0 004F3DF0 0800BFDF */  ld         $31, 0x8($29)
    /* 3F3DF4 004F3DF4 80CF1308 */  j          func_004f3e00
    /* 3F3DF8 004F3DF8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F3DFC 004F3DFC 00000000 */  nop
.size func_004f3d68, 0x98
