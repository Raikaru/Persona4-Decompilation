.section .text
.set noat
.set noreorder
glabel func_004f8fe8
    /* 3F8FE8 004F8FE8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F8FEC 004F8FEC 1000B0FF */  sd         $16, 0x10($29)
    /* 3F8FF0 004F8FF0 2D80A000 */  daddu      $16, $5, $0
    /* 3F8FF4 004F8FF4 1800BFFF */  sd         $31, 0x18($29)
    /* 3F8FF8 004F8FF8 84E3130C */  jal        func_004f8e10
    /* 3F8FFC 004F8FFC 2D28A003 */   daddu     $5, $29, $0
    /* 3F9000 004F9000 2D280002 */  daddu      $5, $16, $0
    /* 3F9004 004F9004 9EE3130C */  jal        func_004f8e78
    /* 3F9008 004F9008 2D20A003 */   daddu     $4, $29, $0
    /* 3F900C 004F900C 0000A28F */  lw         $2, 0x0($29)
    /* 3F9010 004F9010 05004010 */  beqz       $2, .L004F9028
    /* 3F9014 004F9014 0400A28F */   lw        $2, 0x4($29)
    /* 3F9018 004F9018 04004050 */  beql       $2, $0, .L004F902C
    /* 3F901C 004F901C 1000B0DF */   ld        $16, 0x10($29)
    /* 3F9020 004F9020 B6E3130C */  jal        func_004f8ed8
    /* 3F9024 004F9024 2D200002 */   daddu     $4, $16, $0
  .L004F9028:
    /* 3F9028 004F9028 1000B0DF */  ld         $16, 0x10($29)
  .L004F902C:
    /* 3F902C 004F902C 2D100000 */  daddu      $2, $0, $0
    /* 3F9030 004F9030 1800BFDF */  ld         $31, 0x18($29)
    /* 3F9034 004F9034 0800E003 */  jr         $31
    /* 3F9038 004F9038 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F903C 004F903C 00000000 */  nop
.size func_004f8fe8, 0x58
