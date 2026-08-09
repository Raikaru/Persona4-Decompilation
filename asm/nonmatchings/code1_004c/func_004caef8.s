.section .text
.set noat
.set noreorder
glabel func_004caef8
    /* 3CAEF8 004CAEF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CAEFC 004CAEFC 06008014 */  bnez       $4, .L004CAF18
    /* 3CAF00 004CAF00 0000BFFF */   sd        $31, 0x0($29)
    /* 3CAF04 004CAF04 7600043C */  lui        $4, %hi(D_007587E8)
    /* 3CAF08 004CAF08 0000BFDF */  ld         $31, 0x0($29)
    /* 3CAF0C 004CAF0C E8878424 */  addiu      $4, $4, %lo(D_007587E8)
    /* 3CAF10 004CAF10 A61A1308 */  j          func_004c6a98
    /* 3CAF14 004CAF14 1000BD27 */   addiu     $29, $29, 0x10
  .L004CAF18:
    /* 3CAF18 004CAF18 9400848C */  lw         $4, 0x94($4)
    /* 3CAF1C 004CAF1C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CAF20 004CAF20 FAA51308 */  j          func_004e97e8
    /* 3CAF24 004CAF24 1000BD27 */   addiu     $29, $29, 0x10
.size func_004caef8, 0x30
