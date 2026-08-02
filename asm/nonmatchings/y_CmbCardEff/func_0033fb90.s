.section .text
.set noat
.set noreorder
glabel func_0033fb90
    /* 23FB90 0033FB90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 23FB94 0033FB94 0000BFFF */  sd         $31, 0x0($29)
    /* 23FB98 0033FB98 1800A6FF */  sd         $6, 0x18($29)
    /* 23FB9C 0033FB9C 3800828C */  lw         $2, 0x38($4)
    /* 23FBA0 0033FBA0 0400448C */  lw         $4, 0x4($2)
    /* 23FBA4 0033FBA4 3C1E0500 */  dsll32     $3, $5, 24
    /* 23FBA8 0033FBA8 3F1E0300 */  dsra32     $3, $3, 24
    /* 23FBAC 0033FBAC 80110300 */  sll        $2, $3, 6
    /* 23FBB0 0033FBB0 23104300 */  subu       $2, $2, $3
    /* 23FBB4 0033FBB4 80100200 */  sll        $2, $2, 2
    /* 23FBB8 0033FBB8 23104300 */  subu       $2, $2, $3
    /* 23FBBC 0033FBBC 00190200 */  sll        $3, $2, 4
    /* 23FBC0 0033FBC0 3800828C */  lw         $2, 0x38($4)
    /* 23FBC4 0033FBC4 21104300 */  addu       $2, $2, $3
    /* 23FBC8 0033FBC8 98E30134 */  ori        $1, $0, 0xE398
    /* 23FBCC 0033FBCC 21204100 */  addu       $4, $2, $1
    /* 23FBD0 0033FBD0 B442023C */  lui        $2, (0x42B40000 >> 16)
    /* 23FBD4 0033FBD4 00008244 */  mtc1       $2, $f0
    /* 23FBD8 0033FBD8 00000000 */  nop
    /* 23FBDC 0033FBDC 02030C46 */  mul.s      $f12, $f0, $f12
    /* 23FBE0 0033FBE0 1800A527 */  addiu      $5, $29, 0x18
    /* 23FBE4 0033FBE4 44B70D0C */  jal        func_0036dd10
    /* 23FBE8 0033FBE8 00000000 */   nop
    /* 23FBEC 0033FBEC 0000BFDF */  ld         $31, 0x0($29)
    /* 23FBF0 0033FBF0 2000BD27 */  addiu      $29, $29, 0x20
    /* 23FBF4 0033FBF4 0800E003 */  jr         $31
    /* 23FBF8 0033FBF8 00000000 */   nop
    /* 23FBFC 0033FBFC 00000000 */  nop
.size func_0033fb90, 0x70
