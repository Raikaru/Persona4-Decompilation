.section .text
.set noat
.set noreorder
glabel func_0043bec8
    /* 33BEC8 0043BEC8 4D008010 */  beqz       $4, .L0043C000
    /* 33BECC 0043BECC 71000A3C */   lui       $10, %hi(D_0070FC58)
    /* 33BED0 0043BED0 0080033C */  lui        $3, (0x80000000 >> 16)
    /* 33BED4 0043BED4 58FC458D */  lw         $5, %lo(D_0070FC58)($10)
    /* 33BED8 0043BED8 2D30A000 */  daddu      $6, $5, $0
    /* 33BEDC 0043BEDC 0000A28C */  lw         $2, 0x0($5)
  .L0043BEE0:
    /* 33BEE0 0043BEE0 04004454 */  bnel       $2, $4, .L0043BEF4
    /* 33BEE4 0043BEE4 2D30A000 */   daddu     $6, $5, $0
    /* 33BEE8 0043BEE8 25104300 */  or         $2, $2, $3
    /* 33BEEC 0043BEEC 04000010 */  b          .L0043BF00
    /* 33BEF0 0043BEF0 0000A2AC */   sw        $2, 0x0($5)
  .L0043BEF4:
    /* 33BEF4 0043BEF4 0800A58C */  lw         $5, 0x8($5)
    /* 33BEF8 0043BEF8 F9FFA054 */  bnel       $5, $0, .L0043BEE0
    /* 33BEFC 0043BEFC 0000A28C */   lw        $2, 0x0($5)
  .L0043BF00:
    /* 33BF00 0043BF00 0E00C510 */  beq        $6, $5, .L0043BF3C
    /* 33BF04 0043BF04 00000000 */   nop
    /* 33BF08 0043BF08 0000C28C */  lw         $2, 0x0($6)
    /* 33BF0C 0043BF0C 0B004104 */  bgez       $2, .L0043BF3C
    /* 33BF10 0043BF10 00000000 */   nop
    /* 33BF14 0043BF14 0400C28C */  lw         $2, 0x4($6)
    /* 33BF18 0043BF18 0400A38C */  lw         $3, 0x4($5)
    /* 33BF1C 0043BF1C 0800A48C */  lw         $4, 0x8($5)
    /* 33BF20 0043BF20 21104300 */  addu       $2, $2, $3
    /* 33BF24 0043BF24 0400C2AC */  sw         $2, 0x4($6)
    /* 33BF28 0043BF28 0800C4AC */  sw         $4, 0x8($6)
    /* 33BF2C 0043BF2C 0800A0AC */  sw         $0, 0x8($5)
    /* 33BF30 0043BF30 0400A0AC */  sw         $0, 0x4($5)
    /* 33BF34 0043BF34 0000A0AC */  sw         $0, 0x0($5)
    /* 33BF38 0043BF38 2D28C000 */  daddu      $5, $6, $0
  .L0043BF3C:
    /* 33BF3C 0043BF3C 2400A010 */  beqz       $5, .L0043BFD0
    /* 33BF40 0043BF40 58FC438D */   lw        $3, %lo(D_0070FC58)($10)
    /* 33BF44 0043BF44 0800A78C */  lw         $7, 0x8($5)
    /* 33BF48 0043BF48 0D00E010 */  beqz       $7, .L0043BF80
    /* 33BF4C 0043BF4C 00000000 */   nop
    /* 33BF50 0043BF50 0000E28C */  lw         $2, 0x0($7)
    /* 33BF54 0043BF54 0A004104 */  bgez       $2, .L0043BF80
    /* 33BF58 0043BF58 2D30E000 */   daddu     $6, $7, $0
    /* 33BF5C 0043BF5C 0400A28C */  lw         $2, 0x4($5)
    /* 33BF60 0043BF60 0400E38C */  lw         $3, 0x4($7)
    /* 33BF64 0043BF64 0800C48C */  lw         $4, 0x8($6)
    /* 33BF68 0043BF68 21104300 */  addu       $2, $2, $3
    /* 33BF6C 0043BF6C 0400A2AC */  sw         $2, 0x4($5)
    /* 33BF70 0043BF70 0800A4AC */  sw         $4, 0x8($5)
    /* 33BF74 0043BF74 0800C0AC */  sw         $0, 0x8($6)
    /* 33BF78 0043BF78 0400E0AC */  sw         $0, 0x4($7)
    /* 33BF7C 0043BF7C 0000E0AC */  sw         $0, 0x0($7)
  .L0043BF80:
    /* 33BF80 0043BF80 1200A010 */  beqz       $5, .L0043BFCC
    /* 33BF84 0043BF84 FF7F023C */   lui       $2, (0x7FFFFFFF >> 16)
    /* 33BF88 0043BF88 0000A38C */  lw         $3, 0x0($5)
    /* 33BF8C 0043BF8C FFFF4234 */  ori        $2, $2, (0x7FFFFFFF & 0xFFFF)
    /* 33BF90 0043BF90 7100083C */  lui        $8, %hi(D_0070FC78)
    /* 33BF94 0043BF94 24306200 */  and        $6, $3, $2
    /* 33BF98 0043BF98 0400A78C */  lw         $7, 0x4($5)
    /* 33BF9C 0043BF9C 78FC038D */  lw         $3, %lo(D_0070FC78)($8)
    /* 33BFA0 0043BFA0 2110C700 */  addu       $2, $6, $7
    /* 33BFA4 0043BFA4 09004314 */  bne        $2, $3, .L0043BFCC
    /* 33BFA8 0043BFA8 78FC0925 */   addiu     $9, $8, %lo(D_0070FC78)
    /* 33BFAC 0043BFAC 0400228D */  lw         $2, 0x4($9)
    /* 33BFB0 0043BFB0 7100033C */  lui        $3, %hi(D_0070FC70)
    /* 33BFB4 0043BFB4 70FC648C */  lw         $4, %lo(D_0070FC70)($3)
    /* 33BFB8 0043BFB8 2110E200 */  addu       $2, $7, $2
    /* 33BFBC 0043BFBC 0400A2AC */  sw         $2, 0x4($5)
    /* 33BFC0 0043BFC0 23208600 */  subu       $4, $4, $6
    /* 33BFC4 0043BFC4 040024AD */  sw         $4, 0x4($9)
    /* 33BFC8 0043BFC8 78FC06AD */  sw         $6, %lo(D_0070FC78)($8)
  .L0043BFCC:
    /* 33BFCC 0043BFCC 58FC438D */  lw         $3, %lo(D_0070FC58)($10)
  .L0043BFD0:
    /* 33BFD0 0043BFD0 0000628C */  lw         $2, 0x0($3)
    /* 33BFD4 0043BFD4 0A004104 */  bgez       $2, .L0043C000
    /* 33BFD8 0043BFD8 00000000 */   nop
    /* 33BFDC 0043BFDC 0800628C */  lw         $2, 0x8($3)
    /* 33BFE0 0043BFE0 07004014 */  bnez       $2, .L0043C000
    /* 33BFE4 0043BFE4 7100023C */   lui       $2, %hi(D_0070FC6C)
    /* 33BFE8 0043BFE8 7100033C */  lui        $3, %hi(D_0070FC78)
    /* 33BFEC 0043BFEC 6CFC458C */  lw         $5, %lo(D_0070FC6C)($2)
    /* 33BFF0 0043BFF0 78FC6424 */  addiu      $4, $3, %lo(D_0070FC78)
    /* 33BFF4 0043BFF4 10500224 */  addiu      $2, $0, 0x5010
    /* 33BFF8 0043BFF8 78FC62AC */  sw         $2, %lo(D_0070FC78)($3)
    /* 33BFFC 0043BFFC 040085AC */  sw         $5, 0x4($4)
  .L0043C000:
    /* 33C000 0043C000 0800E003 */  jr         $31
    /* 33C004 0043C004 00000000 */   nop
.size func_0043bec8, 0x140
