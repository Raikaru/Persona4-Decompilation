.section .text
.set noat
.set noreorder
glabel func_0039aa50
    /* 29AA50 0039AA50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 29AA54 0039AA54 1000BFFF */  sd         $31, 0x10($29)
    /* 29AA58 0039AA58 0000B07F */  sq         $16, 0x0($29)
    /* 29AA5C 0039AA5C 08270F0C */  jal        func_003c9c20
    /* 29AA60 0039AA60 2D808000 */   daddu     $16, $4, $0
    /* 29AA64 0039AA64 0800428C */  lw         $2, 0x8($2)
    /* 29AA68 0039AA68 80004230 */  andi       $2, $2, 0x80
    /* 29AA6C 0039AA6C 06004010 */  beqz       $2, .L0039AA88
    /* 29AA70 0039AA70 00000000 */   nop
    /* 29AA74 0039AA74 0100023C */  lui        $2, (0x11010 >> 16)
    /* 29AA78 0039AA78 B86D0E0C */  jal        func_0039b6e0
    /* 29AA7C 0039AA7C 10104434 */   ori       $4, $2, (0x11010 & 0xFFFF)
    /* 29AA80 0039AA80 05000010 */  b          .L0039AA98
    /* 29AA84 0039AA84 7C0002AE */   sw        $2, 0x7C($16)
  .L0039AA88:
    /* 29AA88 0039AA88 0100023C */  lui        $2, (0x1100F >> 16)
    /* 29AA8C 0039AA8C B86D0E0C */  jal        func_0039b6e0
    /* 29AA90 0039AA90 0F104434 */   ori       $4, $2, (0x1100F & 0xFFFF)
    /* 29AA94 0039AA94 7C0002AE */  sw         $2, 0x7C($16)
  .L0039AA98:
    /* 29AA98 0039AA98 2D100002 */  daddu      $2, $16, $0
    /* 29AA9C 0039AA9C 1000BFDF */  ld         $31, 0x10($29)
    /* 29AAA0 0039AAA0 0000B07B */  lq         $16, 0x0($29)
    /* 29AAA4 0039AAA4 0800E003 */  jr         $31
    /* 29AAA8 0039AAA8 2000BD27 */   addiu     $29, $29, 0x20
    /* 29AAAC 0039AAAC 00000000 */  nop
.size func_0039aa50, 0x60
