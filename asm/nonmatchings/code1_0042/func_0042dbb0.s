.section .text
.set noat
.set noreorder
glabel func_0042dbb0
    /* 32DBB0 0042DBB0 08008304 */  bgezl      $4, .L0042DBD4
    /* 32DBB4 0042DBB4 7100023C */   lui       $2, %hi(D_0070DCB0)
    /* 32DBB8 0042DBB8 FF7F023C */  lui        $2, (0x7FFFFFFF >> 16)
    /* 32DBBC 0042DBBC 8900033C */  lui        $3, %hi(D_00894A48)
    /* 32DBC0 0042DBC0 FFFF4234 */  ori        $2, $2, (0x7FFFFFFF & 0xFFFF)
    /* 32DBC4 0042DBC4 484A6524 */  addiu      $5, $3, %lo(D_00894A48)
    /* 32DBC8 0042DBC8 24208200 */  and        $4, $4, $2
    /* 32DBCC 0042DBCC 04000010 */  b          .L0042DBE0
    /* 32DBD0 0042DBD0 20000224 */   addiu     $2, $0, 0x20
  .L0042DBD4:
    /* 32DBD4 0042DBD4 7100033C */  lui        $3, %hi(D_0070DCB4)
    /* 32DBD8 0042DBD8 B0DC458C */  lw         $5, %lo(D_0070DCB0)($2)
    /* 32DBDC 0042DBDC B4DC628C */  lw         $2, %lo(D_0070DCB4)($3)
  .L0042DBE0:
    /* 32DBE0 0042DBE0 2B108200 */  sltu       $2, $4, $2
    /* 32DBE4 0042DBE4 03004014 */  bnez       $2, .L0042DBF4
    /* 32DBE8 0042DBE8 00190400 */   sll       $3, $4, 4
    /* 32DBEC 0042DBEC 0800E003 */  jr         $31
    /* 32DBF0 0042DBF0 97FF0224 */   addiu     $2, $0, -0x69
  .L0042DBF4:
    /* 32DBF4 0042DBF4 2D100000 */  daddu      $2, $0, $0
    /* 32DBF8 0042DBF8 21186500 */  addu       $3, $3, $5
    /* 32DBFC 0042DBFC 0800E003 */  jr         $31
    /* 32DC00 0042DC00 000060AC */   sw        $0, 0x0($3)
    /* 32DC04 0042DC04 00000000 */  nop
.size func_0042dbb0, 0x58
