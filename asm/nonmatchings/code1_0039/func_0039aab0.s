.section .text
.set noat
.set noreorder
glabel func_0039aab0
    /* 29AAB0 0039AAB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 29AAB4 0039AAB4 1000BFFF */  sd         $31, 0x10($29)
    /* 29AAB8 0039AAB8 0000B07F */  sq         $16, 0x0($29)
    /* 29AABC 0039AABC 1800828C */  lw         $2, 0x18($4)
    /* 29AAC0 0039AAC0 0800428C */  lw         $2, 0x8($2)
    /* 29AAC4 0039AAC4 80004230 */  andi       $2, $2, 0x80
    /* 29AAC8 0039AAC8 06004010 */  beqz       $2, .L0039AAE4
    /* 29AACC 0039AACC 2D808000 */   daddu     $16, $4, $0
    /* 29AAD0 0039AAD0 0100023C */  lui        $2, (0x1100E >> 16)
    /* 29AAD4 0039AAD4 B86D0E0C */  jal        func_0039b6e0
    /* 29AAD8 0039AAD8 0E104434 */   ori       $4, $2, (0x1100E & 0xFFFF)
    /* 29AADC 0039AADC 05000010 */  b          .L0039AAF4
    /* 29AAE0 0039AAE0 6C0002AE */   sw        $2, 0x6C($16)
  .L0039AAE4:
    /* 29AAE4 0039AAE4 0100023C */  lui        $2, (0x1100D >> 16)
    /* 29AAE8 0039AAE8 B86D0E0C */  jal        func_0039b6e0
    /* 29AAEC 0039AAEC 0D104434 */   ori       $4, $2, (0x1100D & 0xFFFF)
    /* 29AAF0 0039AAF0 6C0002AE */  sw         $2, 0x6C($16)
  .L0039AAF4:
    /* 29AAF4 0039AAF4 2D100002 */  daddu      $2, $16, $0
    /* 29AAF8 0039AAF8 1000BFDF */  ld         $31, 0x10($29)
    /* 29AAFC 0039AAFC 0000B07B */  lq         $16, 0x0($29)
    /* 29AB00 0039AB00 0800E003 */  jr         $31
    /* 29AB04 0039AB04 2000BD27 */   addiu     $29, $29, 0x20
    /* 29AB08 0039AB08 00000000 */  nop
    /* 29AB0C 0039AB0C 00000000 */  nop
.size func_0039aab0, 0x60
