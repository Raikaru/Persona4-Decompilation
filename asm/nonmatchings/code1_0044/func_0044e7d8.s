.section .text
.set noat
.set noreorder
glabel func_0044e7d8
    /* 34E7D8 0044E7D8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 34E7DC 0044E7DC 2000A4FF */  sd         $4, 0x20($29)
    /* 34E7E0 0044E7E0 2D28A003 */  daddu      $5, $29, $0
    /* 34E7E4 0044E7E4 3000BFFF */  sd         $31, 0x30($29)
    /* 34E7E8 0044E7E8 7C37110C */  jal        func_0044ddf0
    /* 34E7EC 0044E7EC 2000A427 */   addiu     $4, $29, 0x20
    /* 34E7F0 0044E7F0 1000AEDF */  ld         $14, 0x10($29)
    /* 34E7F4 0044E7F4 FF3F0F3C */  lui        $15, (0x3FFFFFFF >> 16)
    /* 34E7F8 0044E7F8 FFFFEF35 */  ori        $15, $15, (0x3FFFFFFF & 0xFFFF)
    /* 34E7FC 0044E7FC 0000A48F */  lw         $4, 0x0($29)
    /* 34E800 0044E800 B8380E00 */  dsll       $7, $14, 2
    /* 34E804 0044E804 0400A58F */  lw         $5, 0x4($29)
    /* 34E808 0044E808 3F380700 */  dsra32     $7, $7, 0
    /* 34E80C 0044E80C 0800A68F */  lw         $6, 0x8($29)
    /* 34E810 0044E810 2470CF01 */  and        $14, $14, $15
    /* 34E814 0044E814 0100ED34 */  ori        $13, $7, 0x1
    /* 34E818 0044E818 2A37110C */  jal        func_0044dca8
    /* 34E81C 0044E81C 0B38AE01 */   movn      $7, $13, $14
    /* 34E820 0044E820 3000BFDF */  ld         $31, 0x30($29)
    /* 34E824 0044E824 0800E003 */  jr         $31
    /* 34E828 0044E828 4000BD27 */   addiu     $29, $29, 0x40
    /* 34E82C 0044E82C 00000000 */  nop
.size func_0044e7d8, 0x58
