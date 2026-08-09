.section .text
.set noat
.set noreorder
glabel func_004fbfd8
    /* 3FBFD8 004FBFD8 2D288000 */  daddu      $5, $4, $0
    /* 3FBFDC 004FBFDC 03000324 */  addiu      $3, $0, 0x3
    /* 3FBFE0 004FBFE0 1801A28C */  lw         $2, 0x118($5)
    /* 3FBFE4 004FBFE4 04004354 */  bnel       $2, $3, .L004FBFF8
    /* 3FBFE8 004FBFE8 C803A28C */   lw        $2, 0x3C8($5)
    /* 3FBFEC 004FBFEC C803A0AC */  sw         $0, 0x3C8($5)
    /* 3FBFF0 004FBFF0 09000010 */  b          .L004FC018
    /* 3FBFF4 004FBFF4 C403A0AC */   sw        $0, 0x3C4($5)
  .L004FBFF8:
    /* 3FBFF8 004FBFF8 C21F0200 */  srl        $3, $2, 31
    /* 3FBFFC 004FBFFC 01004424 */  addiu      $4, $2, 0x1
    /* 3FC000 004FC000 21184300 */  addu       $3, $2, $3
    /* 3FC004 004FC004 C803A4AC */  sw         $4, 0x3C8($5)
    /* 3FC008 004FC008 43180300 */  sra        $3, $3, 1
    /* 3FC00C 004FC00C 40180300 */  sll        $3, $3, 1
    /* 3FC010 004FC010 23104300 */  subu       $2, $2, $3
    /* 3FC014 004FC014 C403A2AC */  sw         $2, 0x3C4($5)
  .L004FC018:
    /* 3FC018 004FC018 1401A28C */  lw         $2, 0x114($5)
    /* 3FC01C 004FC01C 80100200 */  sll        $2, $2, 2
    /* 3FC020 004FC020 7600033C */  lui        $3, %hi(D_0075DCF0)
    /* 3FC024 004FC024 21186200 */  addu       $3, $3, $2
    /* 3FC028 004FC028 F0DC638C */  lw         $3, %lo(D_0075DCF0)($3)
    /* 3FC02C 004FC02C 2003A3AC */  sw         $3, 0x320($5)
    /* 3FC030 004FC030 7600043C */  lui        $4, %hi(D_0075DD00)
    /* 3FC034 004FC034 21208200 */  addu       $4, $4, $2
    /* 3FC038 004FC038 00DD848C */  lw         $4, %lo(D_0075DD00)($4)
    /* 3FC03C 004FC03C 0800E003 */  jr         $31
    /* 3FC040 004FC040 3003A4AC */   sw        $4, 0x330($5)
    /* 3FC044 004FC044 00000000 */  nop
.size func_004fbfd8, 0x70
