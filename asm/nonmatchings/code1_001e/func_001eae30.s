.section .text
.set noat
.set noreorder
glabel func_001eae30
    /* EAE30 001EAE30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EAE34 001EAE34 0000BFFF */  sd         $31, 0x0($29)
    /* EAE38 001EAE38 ACB3828F */  lw         $2, -0x4C54($28)
    /* EAE3C 001EAE3C D00B44DC */  ld         $4, 0xBD0($2)
    /* EAE40 001EAE40 FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* EAE44 001EAE44 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* EAE48 001EAE48 3C180200 */  dsll32     $3, $2, 0
    /* EAE4C 001EAE4C FFFF0234 */  ori        $2, $0, 0xFFFF
    /* EAE50 001EAE50 38140200 */  dsll       $2, $2, 16
    /* EAE54 001EAE54 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* EAE58 001EAE58 25284300 */  or         $5, $2, $3
    /* EAE5C 001EAE5C DC4E060C */  jal        func_00193b70
    /* EAE60 001EAE60 00000000 */   nop
    /* EAE64 001EAE64 04004010 */  beqz       $2, .L001EAE78
    /* EAE68 001EAE68 00000000 */   nop
    /* EAE6C 001EAE6C 2D100000 */  daddu      $2, $0, $0
    /* EAE70 001EAE70 0E000010 */  b          .L001EAEAC
    /* EAE74 001EAE74 00000000 */   nop
  .L001EAE78:
    /* EAE78 001EAE78 ACB3828F */  lw         $2, -0x4C54($28)
    /* EAE7C 001EAE7C D80B44DC */  ld         $4, 0xBD8($2)
    /* EAE80 001EAE80 FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* EAE84 001EAE84 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* EAE88 001EAE88 3C180200 */  dsll32     $3, $2, 0
    /* EAE8C 001EAE8C FFFF0234 */  ori        $2, $0, 0xFFFF
    /* EAE90 001EAE90 38140200 */  dsll       $2, $2, 16
    /* EAE94 001EAE94 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* EAE98 001EAE98 25284300 */  or         $5, $2, $3
    /* EAE9C 001EAE9C DC4E060C */  jal        func_00193b70
    /* EAEA0 001EAEA0 00000000 */   nop
    /* EAEA4 001EAEA4 2B100200 */  sltu       $2, $0, $2
    /* EAEA8 001EAEA8 01004238 */  xori       $2, $2, 0x1
  .L001EAEAC:
    /* EAEAC 001EAEAC 0000BFDF */  ld         $31, 0x0($29)
    /* EAEB0 001EAEB0 1000BD27 */  addiu      $29, $29, 0x10
    /* EAEB4 001EAEB4 0800E003 */  jr         $31
    /* EAEB8 001EAEB8 00000000 */   nop
    /* EAEBC 001EAEBC 00000000 */  nop
.size func_001eae30, 0x90
