.section .text
.set noat
.set noreorder
glabel func_001ef8c0
    /* EF8C0 001EF8C0 ACB3858F */  lw         $5, -0x4C54($28)
    /* EF8C4 001EF8C4 680CA28C */  lw         $2, 0xC68($5)
    /* EF8C8 001EF8C8 08004394 */  lhu        $3, 0x8($2)
    /* EF8CC 001EF8CC 40100300 */  sll        $2, $3, 1
    /* EF8D0 001EF8D0 21104300 */  addu       $2, $2, $3
    /* EF8D4 001EF8D4 C0180200 */  sll        $3, $2, 3
    /* EF8D8 001EF8D8 14B4828F */  lw         $2, -0x4BEC($28)
    /* EF8DC 001EF8DC 21204300 */  addu       $4, $2, $3
    /* EF8E0 001EF8E0 0C00A38C */  lw         $3, 0xC($5)
    /* EF8E4 001EF8E4 0020023C */  lui        $2, (0x20000000 >> 16)
    /* EF8E8 001EF8E8 24106200 */  and        $2, $3, $2
    /* EF8EC 001EF8EC 04004010 */  beqz       $2, .L001EF900
    /* EF8F0 001EF8F0 00000000 */   nop
    /* EF8F4 001EF8F4 2D100000 */  daddu      $2, $0, $0
    /* EF8F8 001EF8F8 24000010 */  b          .L001EF98C
    /* EF8FC 001EF8FC 00000000 */   nop
  .L001EF900:
    /* EF900 001EF900 0000838C */  lw         $3, 0x0($4)
    /* EF904 001EF904 08006230 */  andi       $2, $3, 0x8
    /* EF908 001EF908 04004010 */  beqz       $2, .L001EF91C
    /* EF90C 001EF90C 00000000 */   nop
    /* EF910 001EF910 2D100000 */  daddu      $2, $0, $0
    /* EF914 001EF914 1D000010 */  b          .L001EF98C
    /* EF918 001EF918 00000000 */   nop
  .L001EF91C:
    /* EF91C 001EF91C 10006230 */  andi       $2, $3, 0x10
    /* EF920 001EF920 04004010 */  beqz       $2, .L001EF934
    /* EF924 001EF924 00000000 */   nop
    /* EF928 001EF928 02000224 */  addiu      $2, $0, 0x2
    /* EF92C 001EF92C 17000010 */  b          .L001EF98C
    /* EF930 001EF930 00000000 */   nop
  .L001EF934:
    /* EF934 001EF934 00086230 */  andi       $2, $3, 0x800
    /* EF938 001EF938 04004010 */  beqz       $2, .L001EF94C
    /* EF93C 001EF93C 00000000 */   nop
    /* EF940 001EF940 01000224 */  addiu      $2, $0, 0x1
    /* EF944 001EF944 11000010 */  b          .L001EF98C
    /* EF948 001EF948 00000000 */   nop
  .L001EF94C:
    /* EF94C 001EF94C 700CA394 */  lhu        $3, 0xC70($5)
    /* EF950 001EF950 04006230 */  andi       $2, $3, 0x4
    /* EF954 001EF954 04004010 */  beqz       $2, .L001EF968
    /* EF958 001EF958 00000000 */   nop
    /* EF95C 001EF95C 2D100000 */  daddu      $2, $0, $0
    /* EF960 001EF960 0A000010 */  b          .L001EF98C
    /* EF964 001EF964 00000000 */   nop
  .L001EF968:
    /* EF968 001EF968 01006230 */  andi       $2, $3, 0x1
    /* EF96C 001EF96C 04004010 */  beqz       $2, .L001EF980
    /* EF970 001EF970 00000000 */   nop
    /* EF974 001EF974 02000224 */  addiu      $2, $0, 0x2
    /* EF978 001EF978 04000010 */  b          .L001EF98C
    /* EF97C 001EF97C 00000000 */   nop
  .L001EF980:
    /* EF980 001EF980 10006230 */  andi       $2, $3, 0x10
    /* EF984 001EF984 2B100200 */  sltu       $2, $0, $2
    /* EF988 001EF988 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L001EF98C:
    /* EF98C 001EF98C 0800E003 */  jr         $31
    /* EF990 001EF990 00000000 */   nop
    /* EF994 001EF994 00000000 */  nop
    /* EF998 001EF998 00000000 */  nop
    /* EF99C 001EF99C 00000000 */  nop
.size func_001ef8c0, 0xe0
