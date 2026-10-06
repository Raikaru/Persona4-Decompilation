004b8350 addiu $sp, $sp, -0x100
004b8354 sd $ra, 0x90($sp)
004b8358 sq $fp, 0x80($sp)
004b835c sq $s7, 0x70($sp)
004b8360 sq $s6, 0x60($sp)
004b8364 sq $s5, 0x50($sp)
004b8368 sq $s4, 0x40($sp)
004b836c sq $s3, 0x30($sp)
004b8370 sq $s2, 0x20($sp)
004b8374 sq $s1, 0x10($sp)
004b8378 sq $s0, 0x0($sp)
004b837c move $s5, $a0
004b8380 sw $a1, 0xec($sp)
004b8384 addiu $a2, $zero, 0x4a
004b8388 lw $v0, ($a0)
004b838c lw $v0, 4($v0)
004b8390 lw $v0, ($v0)
004b8394 andi $v0, $v0, 1
004b8398 beqz $v0, 0x4b83a4
004b839c nop 
004b83a0 ori $a2, $a2, 4
004b83a4 move $s7, $zero
004b83a8 move $s2, $zero
004b83ac lh $v1, 0x38($s5)
004b83b0 addiu $v0, $zero, 2
004b83b4 beq $v1, $v0, 0x4b8420
004b83b8 nop 
004b83bc addiu $v0, $zero, 1
004b83c0 beq $v1, $v0, 0x4b83fc
004b83c4 nop 
004b83c8 beqz $v1, 0x4b83d8
004b83cc nop 
004b83d0 b 0x4b843c
004b83d4 nop 
004b83d8 lw $v0, ($s5)
004b83dc lw $v1, 0xc($v0)
004b83e0 addiu $v0, $v1, -1
004b83e4 sll $v0, $v0, 1
004b83e8 addiu $s7, $v0, 1
004b83ec sll $v0, $v1, 1
004b83f0 addiu $s2, $v0, 1
004b83f4 b 0x4b843c
004b83f8 nop 
004b83fc lw $v0, ($s5)
004b8400 lw $v1, 0xc($v0)
004b8404 sll $v0, $v1, 2
004b8408 addiu $s7, $v0, 4
004b840c sll $v0, $v1, 1
004b8410 addu $v0, $v0, $v1
004b8414 addiu $s2, $v0, 6
004b8418 b 0x4b843c
004b841c nop 
004b8420 lw $v0, ($s5)
004b8424 lw $v1, 0xc($v0)
004b8428 sll $v0, $v1, 2
004b842c addiu $s7, $v0, 4
004b8430 sll $v0, $v1, 1
004b8434 addu $v0, $v0, $v1
004b8438 addiu $s2, $v0, 6
004b843c move $a0, $s2
004b8440 move $a1, $s7
004b8444 jal 0x3c2630
004b8448 nop 
004b844c move $s4, $v0
004b8450 lw $s3, 0x2c($v0)
004b8454 lh $v1, 0x38($s5)
004b8458 addiu $t0, $zero, 2
004b845c beq $v1, $t0, 0x4b8678
004b8460 nop 
004b8464 addiu $v0, $zero, 1
004b8468 beq $v1, $v0, 0x4b8524
004b846c nop 
004b8470 beqz $v1, 0x4b8480
004b8474 nop 
004b8478 b 0x4b87c4
004b847c nop 
004b8480 move $s1, $zero
004b8484 b 0x4b84dc
004b8488 nop 
004b848c sll $s0, $s1, 1
004b8490 addiu $s6, $s0, 2
004b8494 addiu $fp, $s0, 1
004b8498 andi $a2, $s0, 0xffff
004b849c andi $a3, $fp, 0xffff
004b84a0 andi $t0, $s6, 0xffff
004b84a4 move $a0, $s4
004b84a8 move $a1, $s3
004b84ac jal 0x3c2130
004b84b0 nop 
004b84b4 andi $a2, $fp, 0xffff
004b84b8 addiu $v0, $s0, 3
004b84bc andi $a3, $v0, 0xffff
004b84c0 andi $t0, $s6, 0xffff
004b84c4 move $a0, $s4
004b84c8 addiu $a1, $s3, 8
004b84cc jal 0x3c2130
004b84d0 nop 
004b84d4 addiu $s3, $s3, 0x10
004b84d8 addiu $s1, $s1, 1
004b84dc lw $v0, ($s5)
004b84e0 lw $v0, 0xc($v0)
004b84e4 addiu $v0, $v0, -1
004b84e8 slt $v0, $s1, $v0
004b84ec bnez $v0, 0x4b848c
004b84f0 nop 
004b84f4 sll $v1, $s1, 1
004b84f8 andi $a2, $v1, 0xffff
004b84fc addiu $v0, $v1, 1
004b8500 andi $a3, $v0, 0xffff
004b8504 addiu $v0, $v1, 2
004b8508 andi $t0, $v0, 0xffff
004b850c move $a0, $s4
004b8510 move $a1, $s3
004b8514 jal 0x3c2130
004b8518 nop 
004b851c b 0x4b87c4
004b8520 nop 
004b8524 move $a0, $s4
004b8528 move $a1, $s3
004b852c move $a2, $zero
004b8530 addiu $a3, $zero, 3
004b8534 jal 0x3c2130
004b8538 nop 
004b853c move $a0, $s4
004b8540 addiu $a1, $s3, 8
004b8544 addiu $a2, $zero, 2
004b8548 addiu $a3, $zero, 4
004b854c addiu $t0, $zero, 1
004b8550 jal 0x3c2130
004b8554 nop 
004b8558 addiu $s3, $s3, 0x10
004b855c daddiu $s1, $zero, 2
004b8560 move $fp, $zero
004b8564 b 0x4b8614
004b8568 nop 
004b856c andi $s0, $s1, 0xffff
004b8570 addiu $s6, $s0, 3
004b8574 addiu $v0, $s0, 1
004b8578 sq $v0, 0xd0($sp)
004b857c andi $a3, $v0, 0xffff
004b8580 andi $t0, $s6, 0xffff
004b8584 move $a0, $s4
004b8588 move $a1, $s3
004b858c move $a2, $s1
004b8590 jal 0x3c2130
004b8594 nop 
004b8598 addiu $v0, $s0, 2
004b859c sq $v0, 0xc0($sp)
004b85a0 andi $a3, $s6, 0xffff
004b85a4 andi $t0, $v0, 0xffff
004b85a8 move $a0, $s4
004b85ac addiu $a1, $s3, 8
004b85b0 move $a2, $s1
004b85b4 jal 0x3c2130
004b85b8 nop 
004b85bc lq $v0, 0xd0($sp)
004b85c0 andi $a2, $v0, 0xffff
004b85c4 addiu $v0, $s0, 4
004b85c8 andi $a3, $v0, 0xffff
004b85cc andi $t0, $s6, 0xffff
004b85d0 move $a0, $s4
004b85d4 addiu $a1, $s3, 0x10
004b85d8 jal 0x3c2130
004b85dc nop 
004b85e0 lq $v0, 0xc0($sp)
004b85e4 andi $a2, $v0, 0xffff
004b85e8 andi $a3, $s6, 0xffff
004b85ec addiu $v0, $s0, 5
004b85f0 andi $t0, $v0, 0xffff
004b85f4 move $a0, $s4
004b85f8 addiu $a1, $s3, 0x18
004b85fc jal 0x3c2130
004b8600 nop 
004b8604 addiu $s3, $s3, 0x20
004b8608 addiu $v0, $s1, 3
004b860c andi $s1, $v0, 0xffff
004b8610 addiu $fp, $fp, 1
004b8614 lw $v0, ($s5)
004b8618 lw $v0, 0xc($v0)
004b861c slt $v0, $fp, $v0
004b8620 bnez $v0, 0x4b856c
004b8624 nop 
004b8628 andi $s0, $s1, 0xffff
004b862c addiu $s6, $s0, 3
004b8630 addiu $v0, $s0, 1
004b8634 andi $a3, $v0, 0xffff
004b8638 andi $t0, $s6, 0xffff
004b863c move $a0, $s4
004b8640 move $a1, $s3
004b8644 move $a2, $s1
004b8648 jal 0x3c2130
004b864c nop 
004b8650 andi $a3, $s6, 0xffff
004b8654 addiu $v0, $s0, 2
004b8658 andi $t0, $v0, 0xffff
004b865c move $a0, $s4
004b8660 addiu $a1, $s3, 8
004b8664 move $a2, $s1
004b8668 jal 0x3c2130
004b866c nop 
004b8670 b 0x4b87c4
004b8674 nop 
004b8678 move $a0, $s4
004b867c move $a1, $s3
004b8680 move $a2, $zero
004b8684 addiu $a3, $zero, 3
004b8688 jal 0x3c2130
004b868c nop 
004b8690 move $a0, $s4
004b8694 addiu $a1, $s3, 8
004b8698 addiu $a2, $zero, 2
004b869c addiu $a3, $zero, 4
004b86a0 addiu $t0, $zero, 1
004b86a4 jal 0x3c2130
004b86a8 nop 
004b86ac addiu $s3, $s3, 0x10
004b86b0 daddiu $s1, $zero, 2
004b86b4 move $fp, $zero
004b86b8 b 0x4b8768
004b86bc nop 
004b86c0 andi $s0, $s1, 0xffff
004b86c4 addiu $s6, $s0, 3
004b86c8 addiu $v0, $s0, 1
004b86cc sq $v0, 0xb0($sp)
004b86d0 andi $a3, $v0, 0xffff
004b86d4 andi $t0, $s6, 0xffff
004b86d8 move $a0, $s4
004b86dc move $a1, $s3
004b86e0 move $a2, $s1
004b86e4 jal 0x3c2130
004b86e8 nop 
004b86ec addiu $v0, $s0, 2
004b86f0 sq $v0, 0xa0($sp)
004b86f4 andi $a3, $s6, 0xffff
004b86f8 andi $t0, $v0, 0xffff
004b86fc move $a0, $s4
004b8700 addiu $a1, $s3, 8
004b8704 move $a2, $s1
004b8708 jal 0x3c2130
004b870c nop 
004b8710 lq $v0, 0xb0($sp)
004b8714 andi $a2, $v0, 0xffff
004b8718 addiu $v0, $s0, 4
004b871c andi $a3, $v0, 0xffff
004b8720 andi $t0, $s6, 0xffff
004b8724 move $a0, $s4
004b8728 addiu $a1, $s3, 0x10
004b872c jal 0x3c2130
004b8730 nop 
004b8734 lq $v0, 0xa0($sp)
004b8738 andi $a2, $v0, 0xffff
004b873c andi $a3, $s6, 0xffff
004b8740 addiu $v0, $s0, 5
004b8744 andi $t0, $v0, 0xffff
004b8748 move $a0, $s4
004b874c addiu $a1, $s3, 0x18
004b8750 jal 0x3c2130
004b8754 nop 
004b8758 addiu $s3, $s3, 0x20
004b875c addiu $v0, $s1, 3
004b8760 andi $s1, $v0, 0xffff
004b8764 addiu $fp, $fp, 1
004b8768 lw $v0, ($s5)
004b876c lw $v0, 0xc($v0)
004b8770 slt $v0, $fp, $v0
004b8774 bnez $v0, 0x4b86c0
004b8778 nop 
004b877c andi $s0, $s1, 0xffff
004b8780 addiu $s6, $s0, 3
004b8784 addiu $v0, $s0, 1
004b8788 andi $a3, $v0, 0xffff
004b878c andi $t0, $s6, 0xffff
004b8790 move $a0, $s4
004b8794 move $a1, $s3
004b8798 move $a2, $s1
004b879c jal 0x3c2130
004b87a0 nop 
004b87a4 andi $a3, $s6, 0xffff
004b87a8 addiu $v0, $s0, 2
004b87ac andi $t0, $v0, 0xffff
004b87b0 move $a0, $s4
004b87b4 addiu $a1, $s3, 8
004b87b8 move $a2, $s1
004b87bc jal 0x3c2130
004b87c0 nop 
004b87c4 lw $s1, 0x2c($s4)
004b87c8 move $s0, $zero
004b87cc b 0x4b87f0
004b87d0 nop 
004b87d4 move $a0, $s4
004b87d8 move $a1, $s1
004b87dc lw $a2, 0xec($sp)
004b87e0 jal 0x3c2150
004b87e4 nop 
004b87e8 addiu $s0, $s0, 1
004b87ec addiu $s1, $s1, 8
004b87f0 slt $v0, $s0, $s7
004b87f4 bnez $v0, 0x4b87d4
004b87f8 nop 
004b87fc lh $v1, 0x38($s5)
004b8800 addiu $v0, $zero, 2
004b8804 beq $v1, $v0, 0x4b8998
004b8808 nop 
004b880c addiu $v0, $zero, 1
004b8810 beq $v1, $v0, 0x4b895c
004b8814 nop 
004b8818 beqz $v1, 0x4b8828
004b881c nop 
004b8820 b 0x4b89cc
004b8824 nop 
004b8828 lw $s1, 0x30($s4)
004b882c move $s0, $zero
004b8830 b 0x4b88c0
004b8834 nop 
004b8838 bnez $s0, 0x4b8874
004b883c nop 
004b8840 mtc1 $s0, $f0
004b8844 nop 
004b8848 cvt.s.w $f1, $f0
004b884c addiu $v0, $v1, -1
004b8850 mtc1 $v0, $f0
004b8854 nop 
004b8858 cvt.s.w $f0, $f0
004b885c div.s $f12, $f1, $f0
004b8860 nop 
004b8864 nop 
004b8868 nop 
004b886c b 0x4b88a4
004b8870 nop 
004b8874 mtc1 $s0, $f0
004b8878 nop 
004b887c cvt.s.w $f1, $f0
004b8880 lui $v0, 0x3f00
004b8884 mtc1 $v0, $f0
004b8888 nop 
004b888c sub.s $f1, $f1, $f0
004b8890 addiu $v0, $v1, -1
004b8894 mtc1 $v0, $f0
004b8898 nop 
004b889c cvt.s.w $f0, $f0
004b88a0 div.s $f12, $f1, $f0
004b88a4 move $a0, $s5
004b88a8 move $a1, $zero
004b88ac move $a2, $s1
004b88b0 jal 0x4bc540
004b88b4 nop 
004b88b8 addiu $s0, $s0, 1
004b88bc addiu $s1, $s1, 8
004b88c0 lw $v0, ($s5)
004b88c4 lw $v1, 0xc($v0)
004b88c8 slt $v0, $s0, $v1
004b88cc bnez $v0, 0x4b8838
004b88d0 nop 
004b88d4 lui $v0, 0x3f80
004b88d8 mtc1 $v0, $f12
004b88dc move $a0, $s5
004b88e0 move $a1, $zero
004b88e4 move $a2, $s1
004b88e8 jal 0x4bc540
004b88ec nop 
004b88f0 lw $v0, 0x30($s4)
004b88f4 addiu $s0, $v0, 4
004b88f8 move $s1, $zero
004b88fc b 0x4b8940
004b8900 nop 
004b8904 mtc1 $s1, $f0
004b8908 nop 
004b890c cvt.s.w $f1, $f0
004b8910 addiu $v0, $v1, -1
004b8914 mtc1 $v0, $f0
004b8918 nop 
004b891c cvt.s.w $f0, $f0
004b8920 div.s $f12, $f1, $f0
004b8924 move $a0, $s5
004b8928 addiu $a1, $zero, 1
004b892c move $a2, $s0
004b8930 jal 0x4bc540
004b8934 nop 
004b8938 addiu $s1, $s1, 1
004b893c addiu $s0, $s0, 8
004b8940 lw $v0, ($s5)
004b8944 lw $v1, 0xc($v0)
004b8948 slt $v0, $s1, $v1
004b894c bnez $v0, 0x4b8904
004b8950 nop 
004b8954 b 0x4b89cc
004b8958 nop 
004b895c lw $v1, 0x30($s4)
004b8960 move $a0, $zero
004b8964 b 0x4b8984
004b8968 nop 
004b896c sb $zero, ($v1)
004b8970 sb $zero, 1($v1)
004b8974 sb $zero, 2($v1)
004b8978 sb $zero, 3($v1)
004b897c addiu $a0, $a0, 1
004b8980 addiu $v1, $v1, 4
004b8984 slt $v0, $a0, $s2
004b8988 bnez $v0, 0x4b896c
004b898c nop 
004b8990 b 0x4b89cc
004b8994 nop 
004b8998 lw $v1, 0x30($s4)
004b899c move $a0, $zero
004b89a0 b 0x4b89c0
004b89a4 nop 
004b89a8 sb $zero, ($v1)
004b89ac sb $zero, 1($v1)
004b89b0 sb $zero, 2($v1)
004b89b4 sb $zero, 3($v1)
004b89b8 addiu $a0, $a0, 1
004b89bc addiu $v1, $v1, 4
004b89c0 slt $v0, $a0, $s2
004b89c4 bnez $v0, 0x4b89a8
004b89c8 nop 
004b89cc lw $a0, ($s5)
004b89d0 lw $v0, 4($a0)
004b89d4 lw $v0, ($v0)
004b89d8 andi $v0, $v0, 1
004b89dc beqz $v0, 0x4b8d70
004b89e0 nop 
004b89e4 lh $v1, 0x38($s5)
004b89e8 addiu $v0, $zero, 2
004b89ec beq $v1, $v0, 0x4b8c78
004b89f0 nop 
004b89f4 addiu $v0, $zero, 1
004b89f8 beq $v1, $v0, 0x4b8b78
004b89fc nop 
004b8a00 beqz $v1, 0x4b8a10
004b8a04 nop 
004b8a08 b 0x4b8d70
004b8a0c nop 
004b8a10 lw $s1, 0x34($s4)
004b8a14 move $s0, $zero
004b8a18 b 0x4b8acc
004b8a1c nop 
004b8a20 addiu $v0, $v1, -1
004b8a24 bgtz $v0, 0x4b8a40
004b8a28 nop 
004b8a2c lui $a0, 0x71
004b8a30 addiu $a0, $a0, 0x46e0
004b8a34 addiu $a1, $zero, 0x226
004b8a38 jal 0x46d730
004b8a3c nop 
004b8a40 bnez $s0, 0x4b8a84
004b8a44 nop 
004b8a48 lw $v0, ($s5)
004b8a4c lw $v0, 0xc($v0)
004b8a50 addiu $v0, $v0, -1
004b8a54 mtc1 $v0, $f0
004b8a58 nop 
004b8a5c cvt.s.w $f1, $f0
004b8a60 mtc1 $s0, $f0
004b8a64 nop 
004b8a68 cvt.s.w $f0, $f0
004b8a6c div.s $f0, $f0, $f1
004b8a70 nop 
004b8a74 nop 
004b8a78 swc1 $f0, ($s1)
004b8a7c b 0x4b8ac0
004b8a80 nop 
004b8a84 lw $v0, ($s5)
004b8a88 lw $v0, 0xc($v0)
004b8a8c addiu $v0, $v0, -1
004b8a90 mtc1 $v0, $f0
004b8a94 nop 
004b8a98 cvt.s.w $f2, $f0
004b8a9c mtc1 $s0, $f0
004b8aa0 nop 
004b8aa4 cvt.s.w $f1, $f0
004b8aa8 lui $v0, 0x3f00
004b8aac mtc1 $v0, $f0
004b8ab0 nop 
004b8ab4 sub.s $f0, $f1, $f0
004b8ab8 div.s $f0, $f0, $f2
004b8abc swc1 $f0, ($s1)
004b8ac0 sw $zero, 4($s1)
004b8ac4 addiu $s0, $s0, 1
004b8ac8 addiu $s1, $s1, 0x10
004b8acc lw $v0, ($s5)
004b8ad0 lw $v1, 0xc($v0)
004b8ad4 slt $v0, $s0, $v1
004b8ad8 bnez $v0, 0x4b8a20
004b8adc nop 
004b8ae0 lui $v0, 0x3f80
004b8ae4 sw $v0, ($s1)
004b8ae8 sw $zero, 4($s1)
004b8aec lw $v0, 0x34($s4)
004b8af0 addiu $s0, $v0, 8
004b8af4 move $s1, $zero
004b8af8 b 0x4b8b5c
004b8afc nop 
004b8b00 addiu $v0, $v1, -1
004b8b04 bgtz $v0, 0x4b8b20
004b8b08 nop 
004b8b0c lui $a0, 0x71
004b8b10 addiu $a0, $a0, 0x46e0
004b8b14 addiu $a1, $zero, 0x234
004b8b18 jal 0x46d730
004b8b1c nop 
004b8b20 lw $v0, ($s5)
004b8b24 lw $v0, 0xc($v0)
004b8b28 addiu $v0, $v0, -1
004b8b2c mtc1 $v0, $f0
004b8b30 nop 
004b8b34 cvt.s.w $f1, $f0
004b8b38 mtc1 $s1, $f0
004b8b3c nop 
004b8b40 cvt.s.w $f0, $f0
004b8b44 div.s $f0, $f0, $f1
004b8b48 swc1 $f0, ($s0)
004b8b4c lui $v0, 0x3f80
004b8b50 sw $v0, 4($s0)
004b8b54 addiu $s1, $s1, 1
004b8b58 addiu $s0, $s0, 0x10
004b8b5c lw $v0, ($s5)
004b8b60 lw $v1, 0xc($v0)
004b8b64 slt $v0, $s1, $v1
004b8b68 bnez $v0, 0x4b8b00
004b8b6c nop 
004b8b70 b 0x4b8d70
004b8b74 nop 
004b8b78 lw $a1, 0x34($s4)
004b8b7c lw $v1, 0xc($a0)
004b8b80 sll $v0, $v1, 1
004b8b84 addu $v0, $v0, $v1
004b8b88 addiu $v0, $v0, 6
004b8b8c lui $a0, 0x3f00
004b8b90 mtc1 $a0, $f2
004b8b94 mtc1 $v1, $f0
004b8b98 nop 
004b8b9c cvt.s.w $f0, $f0
004b8ba0 add.s $f1, $f2, $f0
004b8ba4 sw $zero, ($a1)
004b8ba8 sw $zero, 4($a1)
004b8bac sw $zero, 8($a1)
004b8bb0 lui $v1, 0x3f80
004b8bb4 mtc1 $v1, $f0
004b8bb8 sw $v1, 0xc($a1)
004b8bbc sw $zero, 0x10($a1)
004b8bc0 sw $a0, 0x14($a1)
004b8bc4 sll $v0, $v0, 3
004b8bc8 addu $v0, $v0, $a1
004b8bcc sw $v1, -0x18($v0)
004b8bd0 sw $zero, -0x14($v0)
004b8bd4 sw $v1, -0x10($v0)
004b8bd8 sw $v1, -0xc($v0)
004b8bdc sw $v1, -8($v0)
004b8be0 sw $a0, -4($v0)
004b8be4 div.s $f0, $f0, $f1
004b8be8 mov.s $f3, $f0
004b8bec div.s $f1, $f2, $f1
004b8bf0 nop 
004b8bf4 addiu $a2, $a1, 0x18
004b8bf8 move $a0, $zero
004b8bfc b 0x4b8c20
004b8c00 nop 
004b8c04 swc1 $f1, ($a2)
004b8c08 sw $zero, 4($a2)
004b8c0c swc1 $f1, 8($a2)
004b8c10 sw $v1, 0xc($a2)
004b8c14 addiu $a2, $a2, 0x18
004b8c18 addiu $a0, $a0, 1
004b8c1c add.s $f1, $f1, $f3
004b8c20 lw $v0, ($s5)
004b8c24 lw $v0, 0xc($v0)
004b8c28 slt $v0, $a0, $v0
004b8c2c bnez $v0, 0x4b8c04
004b8c30 nop 
004b8c34 addiu $a0, $a1, 0x28
004b8c38 move $a1, $zero
004b8c3c lui $v1, 0x3f00
004b8c40 b 0x4b8c5c
004b8c44 nop 
004b8c48 swc1 $f0, ($a0)
004b8c4c sw $v1, 4($a0)
004b8c50 addiu $a1, $a1, 1
004b8c54 add.s $f0, $f0, $f3
004b8c58 addiu $a0, $a0, 0x18
004b8c5c lw $v0, ($s5)
004b8c60 lw $v0, 0xc($v0)
004b8c64 slt $v0, $a1, $v0
004b8c68 bnez $v0, 0x4b8c48
004b8c6c nop 
004b8c70 b 0x4b8d70
004b8c74 nop 
004b8c78 lw $a1, 0x34($s4)
004b8c7c lw $v1, 0xc($a0)
004b8c80 sll $v0, $v1, 1
004b8c84 addu $v0, $v0, $v1
004b8c88 addiu $v0, $v0, 6
004b8c8c lui $a0, 0x3f00
004b8c90 mtc1 $a0, $f2
004b8c94 mtc1 $v1, $f0
004b8c98 nop 
004b8c9c cvt.s.w $f0, $f0
004b8ca0 add.s $f1, $f2, $f0
004b8ca4 sw $zero, ($a1)
004b8ca8 sw $zero, 4($a1)
004b8cac sw $zero, 8($a1)
004b8cb0 lui $v1, 0x3f80
004b8cb4 mtc1 $v1, $f0
004b8cb8 sw $v1, 0xc($a1)
004b8cbc sw $zero, 0x10($a1)
004b8cc0 sw $a0, 0x14($a1)
004b8cc4 sll $v0, $v0, 3
004b8cc8 addu $v0, $v0, $a1
004b8ccc sw $v1, -0x18($v0)
004b8cd0 sw $zero, -0x14($v0)
004b8cd4 sw $v1, -0x10($v0)
004b8cd8 sw $v1, -0xc($v0)
004b8cdc sw $v1, -8($v0)
004b8ce0 sw $a0, -4($v0)
004b8ce4 div.s $f4, $f0, $f1
004b8ce8 mov.s $f3, $f4
004b8cec div.s $f0, $f2, $f1
004b8cf0 nop 
004b8cf4 addiu $a0, $a1, 0x18
004b8cf8 move $a2, $zero
004b8cfc b 0x4b8d20
004b8d00 nop 
004b8d04 swc1 $f0, ($a0)
004b8d08 sw $zero, 4($a0)
004b8d0c swc1 $f0, 8($a0)
004b8d10 sw $v1, 0xc($a0)
004b8d14 addiu $a0, $a0, 0x18
004b8d18 addiu $a2, $a2, 1
004b8d1c add.s $f0, $f0, $f3
004b8d20 lw $v0, ($s5)
004b8d24 lw $v0, 0xc($v0)
004b8d28 slt $v0, $a2, $v0
004b8d2c bnez $v0, 0x4b8d04
004b8d30 nop 
004b8d34 addiu $a0, $a1, 0x28
004b8d38 move $a1, $zero
004b8d3c lui $v1, 0x3f00
004b8d40 b 0x4b8d5c
004b8d44 nop 
004b8d48 swc1 $f4, ($a0)
004b8d4c sw $v1, 4($a0)
004b8d50 addiu $a1, $a1, 1
004b8d54 add.s $f4, $f4, $f3
004b8d58 addiu $a0, $a0, 0x18
004b8d5c lw $v0, ($s5)
004b8d60 lw $v0, 0xc($v0)
004b8d64 slt $v0, $a1, $v0
004b8d68 bnez $v0, 0x4b8d48
004b8d6c nop 
004b8d70 sw $zero, 0xf0($sp)
004b8d74 sw $zero, 0xf4($sp)
004b8d78 sw $zero, 0xf8($sp)
004b8d7c lui $v0, 0x3b9a
004b8d80 ori $v0, $v0, 0xca00
004b8d84 mtc1 $v0, $f0
004b8d88 nop 
004b8d8c cvt.s.w $f0, $f0
004b8d90 swc1 $f0, 0xfc($sp)
004b8d94 lw $v0, 0x5c($s4)
004b8d98 lwc1 $f3, 0xf0($sp)
004b8d9c lwc1 $f2, 0xf4($sp)
004b8da0 lwc1 $f1, 0xf8($sp)
004b8da4 lwc1 $f0, 0xfc($sp)
004b8da8 swc1 $f3, 4($v0)
004b8dac swc1 $f2, 8($v0)
004b8db0 swc1 $f1, 0xc($v0)
004b8db4 swc1 $f0, 0x10($v0)
004b8db8 move $v0, $s4
004b8dbc ld $ra, 0x90($sp)
004b8dc0 lq $fp, 0x80($sp)
004b8dc4 lq $s7, 0x70($sp)
004b8dc8 lq $s6, 0x60($sp)
004b8dcc lq $s5, 0x50($sp)
004b8dd0 lq $s4, 0x40($sp)
004b8dd4 lq $s3, 0x30($sp)
004b8dd8 lq $s2, 0x20($sp)
004b8ddc lq $s1, 0x10($sp)
004b8de0 lq $s0, 0x0($sp)
004b8de4 addiu $sp, $sp, 0x100
004b8de8 jr $ra
004b8dec nop 
