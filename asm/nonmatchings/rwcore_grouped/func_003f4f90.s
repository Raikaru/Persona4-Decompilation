.section .text
.set noat
.set noreorder
glabel func_003f4f90
    /* 2F4F90 003F4F90 0200A014 */  bnez       $5, .L003F4F9C
    /* 2F4F94 003F4F94 00000000 */   nop
    /* 2F4F98 003F4F98 D4AB8597 */  lhu        $5, -0x542C($28)
  .L003F4F9C:
    /* 2F4F9C 003F4F9C E8B7828F */  lw         $2, -0x4818($28)
    /* 2F4FA0 003F4FA0 08004014 */  bnez       $2, .L003F4FC4
    /* 2F4FA4 003F4FA4 00000000 */   nop
    /* 2F4FA8 003F4FA8 0900C010 */  beqz       $6, .L003F4FD0
    /* 2F4FAC 003F4FAC 00000000 */   nop
    /* 2F4FB0 003F4FB0 7F00C230 */  andi       $2, $6, 0x7F
    /* 2F4FB4 003F4FB4 05004010 */  beqz       $2, .L003F4FCC
    /* 2F4FB8 003F4FB8 00000000 */   nop
    /* 2F4FBC 003F4FBC 07000010 */  b          .L003F4FDC
    /* 2F4FC0 003F4FC0 2D100000 */   daddu     $2, $0, $0
  .L003F4FC4:
    /* 2F4FC4 003F4FC4 05000010 */  b          .L003F4FDC
    /* 2F4FC8 003F4FC8 2D100000 */   daddu     $2, $0, $0
  .L003F4FCC:
    /* 2F4FCC 003F4FCC F4B786AF */  sw         $6, -0x480C($28)
  .L003F4FD0:
    /* 2F4FD0 003F4FD0 F8B784AF */  sw         $4, -0x4808($28)
    /* 2F4FD4 003F4FD4 01000224 */  addiu      $2, $0, 0x1
    /* 2F4FD8 003F4FD8 D4AB85A7 */  sh         $5, -0x542C($28)
  .L003F4FDC:
    /* 2F4FDC 003F4FDC 0800E003 */  jr         $31
    /* 2F4FE0 003F4FE0 00000000 */   nop
    /* 2F4FE4 003F4FE4 00000000 */  nop
    /* 2F4FE8 003F4FE8 00000000 */  nop
    /* 2F4FEC 003F4FEC 00000000 */  nop
.size func_003f4f90, 0x60
