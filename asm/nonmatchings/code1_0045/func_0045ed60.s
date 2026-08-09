.section .text
.set noat
.set noreorder
glabel func_0045ed60
    /* 35ED60 0045ED60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 35ED64 0045ED64 0000BFFF */  sd         $31, 0x0($29)
    /* 35ED68 0045ED68 2D40C000 */  daddu      $8, $6, $0
    /* 35ED6C 0045ED6C 1000A927 */  addiu      $9, $29, 0x10
    /* 35ED70 0045ED70 00008790 */  lbu        $7, 0x0($4)
    /* 35ED74 0045ED74 01008690 */  lbu        $6, 0x1($4)
    /* 35ED78 0045ED78 02008390 */  lbu        $3, 0x2($4)
    /* 35ED7C 0045ED7C 03008290 */  lbu        $2, 0x3($4)
    /* 35ED80 0045ED80 1000A7A3 */  sb         $7, 0x10($29)
    /* 35ED84 0045ED84 1100A6A3 */  sb         $6, 0x11($29)
    /* 35ED88 0045ED88 1200A3A3 */  sb         $3, 0x12($29)
    /* 35ED8C 0045ED8C 1300A2A3 */  sb         $2, 0x13($29)
    /* 35ED90 0045ED90 00008790 */  lbu        $7, 0x0($4)
    /* 35ED94 0045ED94 01008690 */  lbu        $6, 0x1($4)
    /* 35ED98 0045ED98 02008390 */  lbu        $3, 0x2($4)
    /* 35ED9C 0045ED9C 03008290 */  lbu        $2, 0x3($4)
    /* 35EDA0 0045EDA0 1400A7A3 */  sb         $7, 0x14($29)
    /* 35EDA4 0045EDA4 1500A6A3 */  sb         $6, 0x15($29)
    /* 35EDA8 0045EDA8 1600A3A3 */  sb         $3, 0x16($29)
    /* 35EDAC 0045EDAC 1700A2A3 */  sb         $2, 0x17($29)
    /* 35EDB0 0045EDB0 00008790 */  lbu        $7, 0x0($4)
    /* 35EDB4 0045EDB4 01008690 */  lbu        $6, 0x1($4)
    /* 35EDB8 0045EDB8 02008390 */  lbu        $3, 0x2($4)
    /* 35EDBC 0045EDBC 03008290 */  lbu        $2, 0x3($4)
    /* 35EDC0 0045EDC0 1800A7A3 */  sb         $7, 0x18($29)
    /* 35EDC4 0045EDC4 1900A6A3 */  sb         $6, 0x19($29)
    /* 35EDC8 0045EDC8 1A00A3A3 */  sb         $3, 0x1A($29)
    /* 35EDCC 0045EDCC 1B00A2A3 */  sb         $2, 0x1B($29)
    /* 35EDD0 0045EDD0 2D202001 */  daddu      $4, $9, $0
    /* 35EDD4 0045EDD4 03000624 */  addiu      $6, $0, 0x3
    /* 35EDD8 0045EDD8 2D38C000 */  daddu      $7, $6, $0
    /* 35EDDC 0045EDDC F477110C */  jal        func_0045dfd0
    /* 35EDE0 0045EDE0 00000000 */   nop
    /* 35EDE4 0045EDE4 0000BFDF */  ld         $31, 0x0($29)
    /* 35EDE8 0045EDE8 2000BD27 */  addiu      $29, $29, 0x20
    /* 35EDEC 0045EDEC 0800E003 */  jr         $31
    /* 35EDF0 0045EDF0 00000000 */   nop
    /* 35EDF4 0045EDF4 00000000 */  nop
    /* 35EDF8 0045EDF8 00000000 */  nop
    /* 35EDFC 0045EDFC 00000000 */  nop
.size func_0045ed60, 0xa0
