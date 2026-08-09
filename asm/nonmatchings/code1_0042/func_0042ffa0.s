.section .text
.set noat
.set noreorder
glabel func_0042ffa0
    /* 32FFA0 0042FFA0 2D388000 */  daddu      $7, $4, $0
    /* 32FFA4 0042FFA4 70000324 */  addiu      $3, $0, 0x70
    /* 32FFA8 0042FFA8 1C000424 */  addiu      $4, $0, 0x1C
    /* 32FFAC 0042FFAC 1818E370 */  mult1      $3, $7, $3
    /* 32FFB0 0042FFB0 1820A400 */  mult       $4, $5, $4
    /* 32FFB4 0042FFB4 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 32FFB8 0042FFB8 8900023C */  lui        $2, %hi(D_00894F90)
    /* 32FFBC 0042FFBC 8000B0FF */  sd         $16, 0x80($29)
    /* 32FFC0 0042FFC0 9000BFFF */  sd         $31, 0x90($29)
    /* 32FFC4 0042FFC4 904F4224 */  addiu      $2, $2, %lo(D_00894F90)
    /* 32FFC8 0042FFC8 21208300 */  addu       $4, $4, $3
    /* 32FFCC 0042FFCC 21104400 */  addu       $2, $2, $4
    /* 32FFD0 0042FFD0 1000438C */  lw         $3, 0x10($2)
    /* 32FFD4 0042FFD4 03006014 */  bnez       $3, .L0042FFE4
    /* 32FFD8 0042FFD8 2D80C000 */   daddu     $16, $6, $0
    /* 32FFDC 0042FFDC 09000010 */  b          .L00430004
    /* 32FFE0 0042FFE0 2D100000 */   daddu     $2, $0, $0
  .L0042FFE4:
    /* 32FFE4 0042FFE4 2D20E000 */  daddu      $4, $7, $0
    /* 32FFE8 0042FFE8 7CBF100C */  jal        func_0042fdf0
    /* 32FFEC 0042FFEC 2D30A003 */   daddu     $6, $29, $0
    /* 32FFF0 0042FFF0 6000A68F */  lw         $6, 0x60($29)
    /* 32FFF4 0042FFF4 2D200002 */  daddu      $4, $16, $0
    /* 32FFF8 0042FFF8 04FE100C */  jal        func_0043f810
    /* 32FFFC 0042FFFC 2D28A003 */   daddu     $5, $29, $0
    /* 330000 00430000 6000A28F */  lw         $2, 0x60($29)
  .L00430004:
    /* 330004 00430004 9000BFDF */  ld         $31, 0x90($29)
    /* 330008 00430008 8000B0DF */  ld         $16, 0x80($29)
    /* 33000C 0043000C 0800E003 */  jr         $31
    /* 330010 00430010 A000BD27 */   addiu     $29, $29, 0xA0
    /* 330014 00430014 00000000 */  nop
.size func_0042ffa0, 0x78
