.section .text
.set noat
.set noreorder
glabel func_004be178
    /* 3BE178 004BE178 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BE17C 004BE17C 2D18E000 */  daddu      $3, $7, $0
    /* 3BE180 004BE180 0000B0FF */  sd         $16, 0x0($29)
    /* 3BE184 004BE184 2D80A000 */  daddu      $16, $5, $0
    /* 3BE188 004BE188 0800B1FF */  sd         $17, 0x8($29)
    /* 3BE18C 004BE18C 2D888000 */  daddu      $17, $4, $0
    /* 3BE190 004BE190 1000BFFF */  sd         $31, 0x10($29)
    /* 3BE194 004BE194 F0FF6724 */  addiu      $7, $3, -0x10
    /* 3BE198 004BE198 0800028E */  lw         $2, 0x8($16)
    /* 3BE19C 004BE19C 06004010 */  beqz       $2, .L004BE1B8
    /* 3BE1A0 004BE1A0 2D28C000 */   daddu     $5, $6, $0
    /* 3BE1A4 004BE1A4 0400048E */  lw         $4, 0x4($16)
    /* 3BE1A8 004BE1A8 5079130C */  jal        func_004de540
    /* 3BE1AC 004BE1AC 2D30E000 */   daddu     $6, $7, $0
    /* 3BE1B0 004BE1B0 05000010 */  b          .L004BE1C8
    /* 3BE1B4 004BE1B4 040022AE */   sw        $2, 0x4($17)
  .L004BE1B8:
    /* 3BE1B8 004BE1B8 0400048E */  lw         $4, 0x4($16)
    /* 3BE1BC 004BE1BC 3079130C */  jal        func_004de4c0
    /* 3BE1C0 004BE1C0 0000058E */   lw        $5, 0x0($16)
    /* 3BE1C4 004BE1C4 040022AE */  sw         $2, 0x4($17)
  .L004BE1C8:
    /* 3BE1C8 004BE1C8 0400228E */  lw         $2, 0x4($17)
    /* 3BE1CC 004BE1CC 06004054 */  bnel       $2, $0, .L004BE1E8
    /* 3BE1D0 004BE1D0 0400048E */   lw        $4, 0x4($16)
    /* 3BE1D4 004BE1D4 7500043C */  lui        $4, %hi(D_00756B00)
    /* 3BE1D8 004BE1D8 A8F5120C */  jal        func_004bd6a0
    /* 3BE1DC 004BE1DC 006B8424 */   addiu     $4, $4, %lo(D_00756B00)
    /* 3BE1E0 004BE1E0 05000010 */  b          .L004BE1F8
    /* 3BE1E4 004BE1E4 2D100000 */   daddu     $2, $0, $0
  .L004BE1E8:
    /* 3BE1E8 004BE1E8 01000224 */  addiu      $2, $0, 0x1
    /* 3BE1EC 004BE1EC 0C0024AE */  sw         $4, 0xC($17)
    /* 3BE1F0 004BE1F0 0000038E */  lw         $3, 0x0($16)
    /* 3BE1F4 004BE1F4 080023AE */  sw         $3, 0x8($17)
  .L004BE1F8:
    /* 3BE1F8 004BE1F8 0000B0DF */  ld         $16, 0x0($29)
    /* 3BE1FC 004BE1FC 0800B1DF */  ld         $17, 0x8($29)
    /* 3BE200 004BE200 1000BFDF */  ld         $31, 0x10($29)
    /* 3BE204 004BE204 0800E003 */  jr         $31
    /* 3BE208 004BE208 2000BD27 */   addiu     $29, $29, 0x20
    /* 3BE20C 004BE20C 00000000 */  nop
.size func_004be178, 0x98
