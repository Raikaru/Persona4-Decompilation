004b6900 addiu $sp, $sp, -0x80
004b6904 sd $ra, 0x60($sp)
004b6908 sq $s5, 0x50($sp)
004b690c sq $s4, 0x40($sp)
004b6910 sq $s3, 0x30($sp)
004b6914 sq $s2, 0x20($sp)
004b6918 sq $s1, 0x10($sp)
004b691c sq $s0, 0x0($sp)
004b6920 move $s2, $a0
004b6924 move $s0, $zero
004b6928 addiu $v1, $s0, 0x24
004b692c lh $a0, 4($a0)
004b6930 sll $v0, $a0, 4
004b6934 subu $v0, $v0, $a0
004b6938 sll $v0, $v0, 2
004b693c addu $v1, $v1, $v0
004b6940 sll $v0, $a0, 3
004b6944 addu $v1, $v1, $v0
004b6948 sll $v0, $a0, 5
004b694c addu $v1, $v1, $v0
004b6950 sll $v0, $a0, 1
004b6954 addu $v0, $v0, $a0
004b6958 sll $v0, $v0, 3
004b695c addu $s0, $v1, $v0
004b6960 lui $a0, 0x71
004b6964 addiu $a0, $a0, 0x46b0
004b6968 addiu $a1, $zero, 0x287
004b696c jal 0x44ea90
004b6970 nop 
004b6974 move $a0, $s0
004b6978 lui $a1, 4
004b697c lui $v0, 0x88
004b6980 lw $v0, 0x73e8($v0)
004b6984 jalr $v0
004b6988 nop 
004b698c move $s1, $v0
004b6990 addiu $a1, $s1, 0x24
004b6994 sw $a1, 8($v0)
004b6998 lh $a0, 4($s2)
004b699c sll $v1, $a0, 4
004b69a0 subu $v1, $v1, $a0
004b69a4 sll $v1, $v1, 2
004b69a8 addu $a0, $a1, $v1
004b69ac sw $a0, 0xc($v0)
004b69b0 lh $v1, 4($s2)
004b69b4 sll $v1, $v1, 3
004b69b8 addu $a0, $a0, $v1
004b69bc sw $a0, 0x10($v0)
004b69c0 lh $v1, 4($s2)
004b69c4 sll $v1, $v1, 5
004b69c8 addu $v1, $a0, $v1
004b69cc sw $v1, 0x14($v0)
004b69d0 sw $zero, ($v0)
004b69d4 sw $s2, 4($v0)
004b69d8 addiu $a0, $zero, 0xff
004b69dc sb $a0, 0x20($v0)
004b69e0 sb $a0, 0x21($v0)
004b69e4 sb $a0, 0x22($v0)
004b69e8 addiu $v1, $zero, 0xfe
004b69ec sb $v1, 0x23($v0)
004b69f0 move $s0, $zero
004b69f4 lh $v0, 4($s2)
004b69f8 blez $v0, 0x4b6b84
004b69fc nop 
004b6a00 sb $a0, 0x7c($sp)
004b6a04 sb $a0, 0x7d($sp)
004b6a08 sb $a0, 0x7e($sp)
004b6a0c sb $v1, 0x7f($sp)
004b6a10 b 0x4b6b74
004b6a14 nop 
004b6a18 sll $v0, $s0, 4
004b6a1c subu $v0, $v0, $s0
004b6a20 sll $s4, $v0, 2
004b6a24 lw $v0, 8($s1)
004b6a28 addu $a0, $v0, $s4
004b6a2c sll $v0, $s0, 1
004b6a30 addu $v0, $v0, $s0
004b6a34 sll $v1, $v0, 3
004b6a38 lw $v0, 0xc($s2)
004b6a3c addu $a1, $v0, $v1
004b6a40 jal 0x4b8df0
004b6a44 nop 
004b6a48 sll $s3, $s0, 3
004b6a4c jal 0x3c4140
004b6a50 nop 
004b6a54 lw $v1, 0xc($s1)
004b6a58 addu $v1, $v1, $s3
004b6a5c sw $v0, 4($v1)
004b6a60 lw $v0, 8($s1)
004b6a64 addu $v0, $v0, $s4
004b6a68 lw $v0, ($v0)
004b6a6c lw $v1, 4($v0)
004b6a70 lw $v0, ($v1)
004b6a74 andi $v0, $v0, 1
004b6a78 beqz $v0, 0x4b6a98
004b6a7c nop 
004b6a80 lw $v0, 0xc($s1)
004b6a84 addu $v0, $v0, $s3
004b6a88 lw $a0, 4($v0)
004b6a8c lw $a1, 4($v1)
004b6a90 jal 0x3c42b0
004b6a94 nop 
004b6a98 sll $s4, $s0, 3
004b6a9c lw $v0, 0xc($s1)
004b6aa0 addu $v0, $v0, $s4
004b6aa4 lw $a2, 4($v0)
004b6aa8 lbu $a1, 0x7c($sp)
004b6aac lbu $a0, 0x7d($sp)
004b6ab0 lbu $v1, 0x7e($sp)
004b6ab4 lbu $v0, 0x7f($sp)
004b6ab8 sb $a1, 4($a2)
004b6abc sb $a0, 5($a2)
004b6ac0 sb $v1, 6($a2)
004b6ac4 sb $v0, 7($a2)
004b6ac8 sll $v0, $s0, 4
004b6acc subu $v0, $v0, $s0
004b6ad0 sll $s3, $v0, 2
004b6ad4 lw $v0, 8($s1)
004b6ad8 addu $a0, $v0, $s3
004b6adc lw $v0, 0xc($s1)
004b6ae0 addu $v0, $v0, $s4
004b6ae4 lw $a1, 4($v0)
004b6ae8 jal 0x4b8350
004b6aec nop 
004b6af0 move $s5, $v0
004b6af4 jal 0x3c00e0
004b6af8 nop 
004b6afc lw $v1, 0xc($s1)
004b6b00 addu $v1, $v1, $s4
004b6b04 sw $v0, ($v1)
004b6b08 lw $v0, 0xc($s1)
004b6b0c addu $v0, $v0, $s4
004b6b10 lw $a0, ($v0)
004b6b14 move $a1, $s5
004b6b18 move $a2, $zero
004b6b1c jal 0x3c0210
004b6b20 nop 
004b6b24 jal 0x3e9320
004b6b28 nop 
004b6b2c lw $v1, 0xc($s1)
004b6b30 addu $v1, $v1, $s4
004b6b34 lw $a0, ($v1)
004b6b38 move $a1, $v0
004b6b3c jal 0x3c1b90
004b6b40 nop 
004b6b44 move $a0, $s5
004b6b48 jal 0x3c2a80
004b6b4c nop 
004b6b50 lw $v0, 8($s1)
004b6b54 addu $a0, $v0, $s3
004b6b58 move $a1, $s5
004b6b5c jal 0x4bccf0
004b6b60 nop 
004b6b64 move $a0, $s5
004b6b68 jal 0x3c22f0
004b6b6c nop 
004b6b70 addiu $s0, $s0, 1
004b6b74 lh $v0, 4($s2)
004b6b78 slt $v0, $s0, $v0
004b6b7c bnez $v0, 0x4b6a18
004b6b80 nop 
004b6b84 move $v0, $s1
004b6b88 ld $ra, 0x60($sp)
004b6b8c lq $s5, 0x50($sp)
004b6b90 lq $s4, 0x40($sp)
004b6b94 lq $s3, 0x30($sp)
004b6b98 lq $s2, 0x20($sp)
004b6b9c lq $s1, 0x10($sp)
004b6ba0 lq $s0, 0x0($sp)
004b6ba4 addiu $sp, $sp, 0x80
004b6ba8 jr $ra
004b6bac nop 
