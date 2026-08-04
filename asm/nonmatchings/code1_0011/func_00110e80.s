.section .text
.set noat
.set noreorder
glabel func_00110e80
    /* 10E80 00110E80 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 10E84 00110E84 2000BFFF */  sd         $31, 0x20($29)
    /* 10E88 00110E88 1000B17F */  sq         $17, 0x10($29)
    /* 10E8C 00110E8C 0000B07F */  sq         $16, 0x0($29)
    /* 10E90 00110E90 2D200000 */  daddu      $4, $0, $0
    /* 10E94 00110E94 3C00A527 */  addiu      $5, $29, 0x3C
    /* 10E98 00110E98 01000624 */  addiu      $6, $0, 0x1
    /* 10E9C 00110E9C F035040C */  jal        func_0010d7c0
    /* 10EA0 00110EA0 00000000 */   nop
    /* 10EA4 00110EA4 2D884000 */  daddu      $17, $2, $0
    /* 10EA8 00110EA8 3C00B08F */  lw         $16, 0x3C($29)
    /* 10EAC 00110EAC 7C00043C */  lui        $4, %hi(D_007BBF00)
    /* 10EB0 00110EB0 00BF8424 */  addiu      $4, $4, %lo(D_007BBF00)
    /* 10EB4 00110EB4 2D282002 */  daddu      $5, $17, $0
    /* 10EB8 00110EB8 2D300002 */  daddu      $6, $16, $0
    /* 10EBC 00110EBC 04FE100C */  jal        func_0043f810
    /* 10EC0 00110EC0 00000000 */   nop
    /* 10EC4 00110EC4 B8B190AF */  sw         $16, -0x4E48($28)
    /* 10EC8 00110EC8 2D202002 */  daddu      $4, $17, $0
    /* 10ECC 00110ECC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 10ED0 00110ED0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 10ED4 00110ED4 09F84000 */  jalr       $2
    /* 10ED8 00110ED8 00000000 */   nop
    /* 10EDC 00110EDC 01000324 */  addiu      $3, $0, 0x1
    /* 10EE0 00110EE0 B4B183AF */  sw         $3, -0x4E4C($28)
    /* 10EE4 00110EE4 2000BFDF */  ld         $31, 0x20($29)
    /* 10EE8 00110EE8 1000B17B */  lq         $17, 0x10($29)
    /* 10EEC 00110EEC 0000B07B */  lq         $16, 0x0($29)
    /* 10EF0 00110EF0 4000BD27 */  addiu      $29, $29, 0x40
    /* 10EF4 00110EF4 0800E003 */  jr         $31
    /* 10EF8 00110EF8 00000000 */   nop
    /* 10EFC 00110EFC 00000000 */  nop
.size func_00110e80, 0x80
