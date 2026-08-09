.section .text
.set noat
.set noreorder
glabel func_004eaea8
    /* 3EAEA8 004EAEA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EAEAC 004EAEAC 06008014 */  bnez       $4, .L004EAEC8
    /* 3EAEB0 004EAEB0 0000BFFF */   sd        $31, 0x0($29)
    /* 3EAEB4 004EAEB4 7600043C */  lui        $4, %hi(D_0075C4F8)
    /* 3EAEB8 004EAEB8 0000BFDF */  ld         $31, 0x0($29)
    /* 3EAEBC 004EAEBC F8C48424 */  addiu      $4, $4, %lo(D_0075C4F8)
    /* 3EAEC0 004EAEC0 E6A91308 */  j          func_004ea798
    /* 3EAEC4 004EAEC4 1000BD27 */   addiu     $29, $29, 0x10
  .L004EAEC8:
    /* 3EAEC8 004EAEC8 7F00A324 */  addiu      $3, $5, 0x7F
    /* 3EAECC 004EAECC FF00622C */  sltiu      $2, $3, 0xFF
    /* 3EAED0 004EAED0 08004050 */  beql       $2, $0, .L004EAEF4
    /* 3EAED4 004EAED4 7600043C */   lui       $4, %hi(D_0075C520)
    /* 3EAED8 004EAED8 81FFC228 */  slti       $2, $6, -0x7F
    /* 3EAEDC 004EAEDC 05004054 */  bnel       $2, $0, .L004EAEF4
    /* 3EAEE0 004EAEE0 7600043C */   lui       $4, %hi(D_0075C520)
    /* 3EAEE4 004EAEE4 8000C228 */  slti       $2, $6, 0x80
    /* 3EAEE8 004EAEE8 07004014 */  bnez       $2, .L004EAF08
    /* 3EAEEC 004EAEEC 81FFA724 */   addiu     $7, $5, -0x7F
    /* 3EAEF0 004EAEF0 7600043C */  lui        $4, %hi(D_0075C520)
  .L004EAEF4:
    /* 3EAEF4 004EAEF4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EAEF8 004EAEF8 20C58424 */  addiu      $4, $4, %lo(D_0075C520)
    /* 3EAEFC 004EAEFC E6A91308 */  j          func_004ea798
    /* 3EAF00 004EAF00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EAF04 004EAF04 00000000 */  nop
  .L004EAF08:
    /* 3EAF08 004EAF08 02006104 */  bgez       $3, .L004EAF14
    /* 3EAF0C 004EAF0C 2D106000 */   daddu     $2, $3, $0
    /* 3EAF10 004EAF10 23100200 */  negu       $2, $2
  .L004EAF14:
    /* 3EAF14 004EAF14 0300E104 */  bgez       $7, .L004EAF24
    /* 3EAF18 004EAF18 1C0082AC */   sw        $2, 0x1C($4)
    /* 3EAF1C 004EAF1C 7F000224 */  addiu      $2, $0, 0x7F
    /* 3EAF20 004EAF20 23384500 */  subu       $7, $2, $5
  .L004EAF24:
    /* 3EAF24 004EAF24 7F00C224 */  addiu      $2, $6, 0x7F
    /* 3EAF28 004EAF28 81FFC324 */  addiu      $3, $6, -0x7F
    /* 3EAF2C 004EAF2C 01004204 */  bltzl      $2, .L004EAF34
    /* 3EAF30 004EAF30 23100200 */   negu      $2, $2
  .L004EAF34:
    /* 3EAF34 004EAF34 200087AC */  sw         $7, 0x20($4)
    /* 3EAF38 004EAF38 03006104 */  bgez       $3, .L004EAF48
    /* 3EAF3C 004EAF3C 240082AC */   sw        $2, 0x24($4)
    /* 3EAF40 004EAF40 7F000224 */  addiu      $2, $0, 0x7F
    /* 3EAF44 004EAF44 23184600 */  subu       $3, $2, $6
  .L004EAF48:
    /* 3EAF48 004EAF48 0000BFDF */  ld         $31, 0x0($29)
    /* 3EAF4C 004EAF4C 280083AC */  sw         $3, 0x28($4)
    /* 3EAF50 004EAF50 0800E003 */  jr         $31
    /* 3EAF54 004EAF54 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eaea8, 0xb0
