.section .text
.set noat
.set noreorder
glabel func_004d9f50
    /* 3D9F50 004D9F50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D9F54 004D9F54 2D280000 */  daddu      $5, $0, $0
    /* 3D9F58 004D9F58 0000B0FF */  sd         $16, 0x0($29)
    /* 3D9F5C 004D9F5C 2D808000 */  daddu      $16, $4, $0
    /* 3D9F60 004D9F60 0800B1FF */  sd         $17, 0x8($29)
    /* 3D9F64 004D9F64 B4010426 */  addiu      $4, $16, 0x1B4
    /* 3D9F68 004D9F68 1000BFFF */  sd         $31, 0x10($29)
    /* 3D9F6C 004D9F6C 30000624 */  addiu      $6, $0, 0x30
    /* 3D9F70 004D9F70 72FE100C */  jal        func_0043f9c8
    /* 3D9F74 004D9F74 B001118E */   lw        $17, 0x1B0($16)
    /* 3D9F78 004D9F78 E4010426 */  addiu      $4, $16, 0x1E4
    /* 3D9F7C 004D9F7C 2D280000 */  daddu      $5, $0, $0
    /* 3D9F80 004D9F80 72FE100C */  jal        func_0043f9c8
    /* 3D9F84 004D9F84 3C000624 */   addiu     $6, $0, 0x3C
    /* 3D9F88 004D9F88 20020426 */  addiu      $4, $16, 0x220
    /* 3D9F8C 004D9F8C 2D280000 */  daddu      $5, $0, $0
    /* 3D9F90 004D9F90 72FE100C */  jal        func_0043f9c8
    /* 3D9F94 004D9F94 00010624 */   addiu     $6, $0, 0x100
    /* 3D9F98 004D9F98 20030426 */  addiu      $4, $16, 0x320
    /* 3D9F9C 004D9F9C 2D280000 */  daddu      $5, $0, $0
    /* 3D9FA0 004D9FA0 72FE100C */  jal        func_0043f9c8
    /* 3D9FA4 004D9FA4 00010624 */   addiu     $6, $0, 0x100
    /* 3D9FA8 004D9FA8 20040426 */  addiu      $4, $16, 0x420
    /* 3D9FAC 004D9FAC 2D280000 */  daddu      $5, $0, $0
    /* 3D9FB0 004D9FB0 72FE100C */  jal        func_0043f9c8
    /* 3D9FB4 004D9FB4 00030624 */   addiu     $6, $0, 0x300
    /* 3D9FB8 004D9FB8 0000048E */  lw         $4, 0x0($16)
    /* 3D9FBC 004D9FBC 2D280000 */  daddu      $5, $0, $0
    /* 3D9FC0 004D9FC0 72FE100C */  jal        func_0043f9c8
    /* 3D9FC4 004D9FC4 80010624 */   addiu     $6, $0, 0x180
    /* 3D9FC8 004D9FC8 20070426 */  addiu      $4, $16, 0x720
    /* 3D9FCC 004D9FCC 2D280000 */  daddu      $5, $0, $0
    /* 3D9FD0 004D9FD0 72FE100C */  jal        func_0043f9c8
    /* 3D9FD4 004D9FD4 00030624 */   addiu     $6, $0, 0x300
    /* 3D9FD8 004D9FD8 A50100A2 */  sb         $0, 0x1A5($16)
    /* 3D9FDC 004D9FDC B001028E */  lw         $2, 0x1B0($16)
    /* 3D9FE0 004D9FE0 A80100AE */  sw         $0, 0x1A8($16)
    /* 3D9FE4 004D9FE4 07004010 */  beqz       $2, .L004DA004
    /* 3D9FE8 004D9FE8 2D204000 */   daddu     $4, $2, $0
    /* 3D9FEC 004D9FEC 1076130C */  jal        func_004dd840
    /* 3D9FF0 004D9FF0 B00100AE */   sw        $0, 0x1B0($16)
    /* 3D9FF4 004D9FF4 2D202002 */  daddu      $4, $17, $0
    /* 3D9FF8 004D9FF8 DA75130C */  jal        func_004dd768
    /* 3D9FFC 004D9FFC 14100524 */   addiu     $5, $0, 0x1014
    /* 3DA000 004DA000 B00102AE */  sw         $2, 0x1B0($16)
  .L004DA004:
    /* 3DA004 004DA004 0000B0DF */  ld         $16, 0x0($29)
    /* 3DA008 004DA008 0800B1DF */  ld         $17, 0x8($29)
    /* 3DA00C 004DA00C 1000BFDF */  ld         $31, 0x10($29)
    /* 3DA010 004DA010 0800E003 */  jr         $31
    /* 3DA014 004DA014 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d9f50, 0xc8
