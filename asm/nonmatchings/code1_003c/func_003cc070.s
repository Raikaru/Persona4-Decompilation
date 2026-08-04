.section .text
.set noat
.set noreorder
glabel func_003cc070
    /* 2CC070 003CC070 08008010 */  beqz       $4, .L003CC094
    /* 2CC074 003CC074 00000000 */   nop
  .L003CC078:
    /* 2CC078 003CC078 B8B9858F */  lw         $5, -0x4648($28)
  .L003CC07C:
    /* 2CC07C 003CC07C 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2CC080 003CC080 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2CC084 003CC084 2D108000 */  daddu      $2, $4, $0
    /* 2CC088 003CC088 21186500 */  addu       $3, $3, $5
    /* 2CC08C 003CC08C 0C000010 */  b          .L003CC0C0
    /* 2CC090 003CC090 3C0064AC */   sw        $4, 0x3C($3)
  .L003CC094:
    /* 2CC094 003CC094 B8B9838F */  lw         $3, -0x4648($28)
    /* 2CC098 003CC098 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CC09C 003CC09C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CC0A0 003CC0A0 21104300 */  addu       $2, $2, $3
    /* 2CC0A4 003CC0A4 5400448C */  lw         $4, 0x54($2)
    /* 2CC0A8 003CC0A8 03008010 */  beqz       $4, .L003CC0B8
    /* 2CC0AC 003CC0AC 00000000 */   nop
    /* 2CC0B0 003CC0B0 F2FF0010 */  b          .L003CC07C
    /* 2CC0B4 003CC0B4 B8B9858F */   lw        $5, -0x4648($28)
  .L003CC0B8:
    /* 2CC0B8 003CC0B8 EFFF0010 */  b          .L003CC078
    /* 2CC0BC 003CC0BC 2D200000 */   daddu     $4, $0, $0
  .L003CC0C0:
    /* 2CC0C0 003CC0C0 0800E003 */  jr         $31
    /* 2CC0C4 003CC0C4 00000000 */   nop
    /* 2CC0C8 003CC0C8 00000000 */  nop
    /* 2CC0CC 003CC0CC 00000000 */  nop
.size func_003cc070, 0x60
