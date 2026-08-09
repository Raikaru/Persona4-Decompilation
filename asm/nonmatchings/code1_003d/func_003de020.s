.section .text
.set noat
.set noreorder
glabel func_003de020
    /* 2DE020 003DE020 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2DE024 003DE024 0000BFFF */  sd         $31, 0x0($29)
    /* 2DE028 003DE028 5000838C */  lw         $3, 0x50($4)
    /* 2DE02C 003DE02C 3000828C */  lw         $2, 0x30($4)
    /* 2DE030 003DE030 28004014 */  bnez       $2, .L003DE0D4
    /* 2DE034 003DE034 28006824 */   addiu     $8, $3, 0x28
  .L003DE038:
    /* 2DE038 003DE038 1A00C010 */  beqz       $6, .L003DE0A4
    /* 2DE03C 003DE03C 00000000 */   nop
    /* 2DE040 003DE040 02000724 */  addiu      $7, $0, 0x2
    /* 2DE044 003DE044 0E00C710 */  beq        $6, $7, .L003DE080
    /* 2DE048 003DE048 00000000 */   nop
    /* 2DE04C 003DE04C 01000224 */  addiu      $2, $0, 0x1
    /* 2DE050 003DE050 0300C210 */  beq        $6, $2, .L003DE060
    /* 2DE054 003DE054 00000000 */   nop
    /* 2DE058 003DE058 1C000010 */  b          .L003DE0CC
    /* 2DE05C 003DE05C FFFF0224 */   addiu     $2, $0, -0x1
  .L003DE060:
    /* 2DE060 003DE060 1000028D */  lw         $2, 0x10($8)
    /* 2DE064 003DE064 3C300500 */  dsll32     $6, $5, 0
    /* 2DE068 003DE068 2D288000 */  daddu      $5, $4, $0
    /* 2DE06C 003DE06C 3F300600 */  dsra32     $6, $6, 0
    /* 2DE070 003DE070 09F84000 */  jalr       $2
    /* 2DE074 003DE074 3000A427 */   addiu     $4, $29, 0x30
    /* 2DE078 003DE078 12000010 */  b          .L003DE0C4
    /* 2DE07C 003DE07C 2D100000 */   daddu     $2, $0, $0
  .L003DE080:
    /* 2DE080 003DE080 1000028D */  lw         $2, 0x10($8)
    /* 2DE084 003DE084 3C300500 */  dsll32     $6, $5, 0
    /* 2DE088 003DE088 2D288000 */  daddu      $5, $4, $0
    /* 2DE08C 003DE08C 3F300600 */  dsra32     $6, $6, 0
    /* 2DE090 003DE090 2000A427 */  addiu      $4, $29, 0x20
    /* 2DE094 003DE094 09F84000 */  jalr       $2
    /* 2DE098 003DE098 03000724 */   addiu     $7, $0, 0x3
    /* 2DE09C 003DE09C 08000010 */  b          .L003DE0C0
    /* 2DE0A0 003DE0A0 00000000 */   nop
  .L003DE0A4:
    /* 2DE0A4 003DE0A4 1000028D */  lw         $2, 0x10($8)
    /* 2DE0A8 003DE0A8 3C300500 */  dsll32     $6, $5, 0
    /* 2DE0AC 003DE0AC 2D288000 */  daddu      $5, $4, $0
    /* 2DE0B0 003DE0B0 3F300600 */  dsra32     $6, $6, 0
    /* 2DE0B4 003DE0B4 1000A427 */  addiu      $4, $29, 0x10
    /* 2DE0B8 003DE0B8 09F84000 */  jalr       $2
    /* 2DE0BC 003DE0BC 01000724 */   addiu     $7, $0, 0x1
  .L003DE0C0:
    /* 2DE0C0 003DE0C0 2D100000 */  daddu      $2, $0, $0
  .L003DE0C4:
    /* 2DE0C4 003DE0C4 09000010 */  b          .L003DE0EC
    /* 2DE0C8 003DE0C8 0000BFDF */   ld        $31, 0x0($29)
  .L003DE0CC:
    /* 2DE0CC 003DE0CC 06000010 */  b          .L003DE0E8
    /* 2DE0D0 003DE0D0 00000000 */   nop
  .L003DE0D4:
    /* 2DE0D4 003DE0D4 04000324 */  addiu      $3, $0, 0x4
    /* 2DE0D8 003DE0D8 03000224 */  addiu      $2, $0, 0x3
    /* 2DE0DC 003DE0DC 400083AC */  sw         $3, 0x40($4)
    /* 2DE0E0 003DE0E0 D5FF0010 */  b          .L003DE038
    /* 2DE0E4 003DE0E4 380082AC */   sw        $2, 0x38($4)
  .L003DE0E8:
    /* 2DE0E8 003DE0E8 0000BFDF */  ld         $31, 0x0($29)
  .L003DE0EC:
    /* 2DE0EC 003DE0EC 0800E003 */  jr         $31
    /* 2DE0F0 003DE0F0 4000BD27 */   addiu     $29, $29, 0x40
    /* 2DE0F4 003DE0F4 00000000 */  nop
    /* 2DE0F8 003DE0F8 00000000 */  nop
    /* 2DE0FC 003DE0FC 00000000 */  nop
.size func_003de020, 0xe0
