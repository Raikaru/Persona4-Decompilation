.section .text
.set noat
.set noreorder
glabel func_0051b990
    /* 41B990 0051B990 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 41B994 0051B994 2D188000 */  daddu      $3, $4, $0
    /* 41B998 0051B998 3000B0FF */  sd         $16, 0x30($29)
    /* 41B99C 0051B99C 6C0D7024 */  addiu      $16, $3, 0xD6C
    /* 41B9A0 0051B9A0 3800BFFF */  sd         $31, 0x38($29)
    /* 41B9A4 0051B9A4 2D100000 */  daddu      $2, $0, $0
    /* 41B9A8 0051B9A8 980D658C */  lw         $5, 0xD98($3)
    /* 41B9AC 0051B9AC 0B00A010 */  beqz       $5, .L0051B9DC
    /* 41B9B0 0051B9B0 9C0D6424 */   addiu     $4, $3, 0xD9C
    /* 41B9B4 0051B9B4 A272140C */  jal        func_0051ca88
    /* 41B9B8 0051B9B8 2D28A003 */   daddu     $5, $29, $0
    /* 41B9BC 0051B9BC 2D20A003 */  daddu      $4, $29, $0
    /* 41B9C0 0051B9C0 2000A527 */  addiu      $5, $29, 0x20
    /* 41B9C4 0051B9C4 2400A627 */  addiu      $6, $29, 0x24
    /* 41B9C8 0051B9C8 4099140C */  jal        func_00526500
    /* 41B9CC 0051B9CC 1800A0AF */   sw        $0, 0x18($29)
    /* 41B9D0 0051B9D0 2400038E */  lw         $3, 0x24($16)
    /* 41B9D4 0051B9D4 2000A28F */  lw         $2, 0x20($29)
    /* 41B9D8 0051B9D8 23104300 */  subu       $2, $2, $3
  .L0051B9DC:
    /* 41B9DC 0051B9DC 3000B0DF */  ld         $16, 0x30($29)
    /* 41B9E0 0051B9E0 3800BFDF */  ld         $31, 0x38($29)
    /* 41B9E4 0051B9E4 0800E003 */  jr         $31
    /* 41B9E8 0051B9E8 4000BD27 */   addiu     $29, $29, 0x40
    /* 41B9EC 0051B9EC 00000000 */  nop
.size func_0051b990, 0x60
