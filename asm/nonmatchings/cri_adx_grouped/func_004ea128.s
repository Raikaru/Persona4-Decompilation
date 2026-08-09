.section .text
.set noat
.set noreorder
glabel func_004ea128
    /* 3EA128 004EA128 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EA12C 004EA12C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EA130 004EA130 2D888000 */  daddu      $17, $4, $0
    /* 3EA134 004EA134 0000B0FF */  sd         $16, 0x0($29)
    /* 3EA138 004EA138 05002016 */  bnez       $17, .L004EA150
    /* 3EA13C 004EA13C 1000BFFF */   sd        $31, 0x10($29)
    /* 3EA140 004EA140 7600053C */  lui        $5, %hi(D_0075BE80)
    /* 3EA144 004EA144 0F000010 */  b          .L004EA184
    /* 3EA148 004EA148 80BEA524 */   addiu     $5, $5, %lo(D_0075BE80)
    /* 3EA14C 004EA14C 00000000 */  nop
  .L004EA150:
    /* 3EA150 004EA150 0500C010 */  beqz       $6, .L004EA168
    /* 3EA154 004EA154 7600053C */   lui       $5, %hi(D_0075BEA8)
    /* 3EA158 004EA158 2D200000 */  daddu      $4, $0, $0
    /* 3EA15C 004EA15C 09000010 */  b          .L004EA184
    /* 3EA160 004EA160 A8BEA524 */   addiu     $5, $5, %lo(D_0075BEA8)
    /* 3EA164 004EA164 00000000 */  nop
  .L004EA168:
    /* 3EA168 004EA168 10A8130C */  jal        func_004ea040
    /* 3EA16C 004EA16C 00000000 */   nop
    /* 3EA170 004EA170 7600053C */  lui        $5, %hi(D_0075BED0)
    /* 3EA174 004EA174 2D804000 */  daddu      $16, $2, $0
    /* 3EA178 004EA178 D0BEA524 */  addiu      $5, $5, %lo(D_0075BED0)
    /* 3EA17C 004EA17C 06000016 */  bnez       $16, .L004EA198
    /* 3EA180 004EA180 2D200000 */   daddu     $4, $0, $0
  .L004EA184:
    /* 3EA184 004EA184 9AA7130C */  jal        func_004e9e68
    /* 3EA188 004EA188 00000000 */   nop
    /* 3EA18C 004EA18C 08000010 */  b          .L004EA1B0
    /* 3EA190 004EA190 2D100000 */   daddu     $2, $0, $0
    /* 3EA194 004EA194 00000000 */  nop
  .L004EA198:
    /* 3EA198 004EA198 2D282002 */  daddu      $5, $17, $0
    /* 3EA19C 004EA19C 0C0A110C */  jal        func_00442830
    /* 3EA1A0 004EA1A0 1C000426 */   addiu     $4, $16, 0x1C
    /* 3EA1A4 004EA1A4 2EA8130C */  jal        func_004ea0b8
    /* 3EA1A8 004EA1A8 2D200002 */   daddu     $4, $16, $0
    /* 3EA1AC 004EA1AC 2D100002 */  daddu      $2, $16, $0
  .L004EA1B0:
    /* 3EA1B0 004EA1B0 0000B0DF */  ld         $16, 0x0($29)
    /* 3EA1B4 004EA1B4 0800B1DF */  ld         $17, 0x8($29)
    /* 3EA1B8 004EA1B8 1000BFDF */  ld         $31, 0x10($29)
    /* 3EA1BC 004EA1BC 0800E003 */  jr         $31
    /* 3EA1C0 004EA1C0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EA1C4 004EA1C4 00000000 */  nop
.size func_004ea128, 0xa0
