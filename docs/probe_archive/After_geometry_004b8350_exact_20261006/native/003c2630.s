003c2630 addiu $sp, $sp, -0x90
003c2634 sd $ra, 0x70($sp)
003c2638 sq $s6, 0x60($sp)
003c263c sq $s5, 0x50($sp)
003c2640 sq $s4, 0x40($sp)
003c2644 move $s5, $a0
003c2648 sq $s3, 0x30($sp)
003c264c move $s4, $a1
003c2650 sq $s2, 0x20($sp)
003c2654 move $s3, $a2
003c2658 sq $s1, 0x10($sp)
003c265c bltz $s5, 0x3c2764
003c2660 sq $s0, 0x0($sp)
003c2664 lui $at, 1
003c2668 slt $at, $s5, $at
003c266c beqz $at, 0x3c2764
003c2670 nop 
003c2674 bltz $s4, 0x3c2764
003c2678 nop 
003c267c lui $v0, 0x71
003c2680 lw $a0, -0x5050($v0)
003c2684 lui $v0, 0xff
003c2688 and $v0, $s3, $v0
003c268c beqz $v0, 0x3c269c
003c2690 andi $a2, $s3, 0xff
003c2694 b 0x3c26b8
003c2698 srl $s1, $v0, 0x10
003c269c andi $v0, $s3, 0x80
003c26a0 beqz $v0, 0x3c26b0
003c26a4 nop 
003c26a8 b 0x3c26b8
003c26ac addiu $s1, $zero, 2
003c26b0 andi $v0, $s3, 4
003c26b4 sltu $s1, $zero, $v0
003c26b8 addiu $v0, $zero, 1
003c26bc bne $s1, $v0, 0x3c26cc
003c26c0 nop 
003c26c4 b 0x3c26e4
003c26c8 addiu $a1, $zero, 4
003c26cc sltiu $at, $s1, 2
003c26d0 bnez $at, 0x3c26e0
003c26d4 nop 
003c26d8 b 0x3c26e4
003c26dc addiu $a1, $zero, 0x80
003c26e0 move $a1, $zero
003c26e4 addiu $v1, $zero, -0x85
003c26e8 lui $v0, 0x100
003c26ec and $v1, $a2, $v1
003c26f0 and $s6, $s3, $v0
003c26f4 bnez $s6, 0x3c272c
003c26f8 or $s0, $v1, $a1
003c26fc andi $v0, $s0, 8
003c2700 beqz $v0, 0x3c2710
003c2704 nop 
003c2708 sll $v0, $s5, 2
003c270c addu $a0, $a0, $v0
003c2710 beqz $s1, 0x3c2724
003c2714 nop 
003c2718 sll $v0, $s5, 3
003c271c mult $v0, $s1, $v0
003c2720 addu $a0, $a0, $v0
003c2724 sll $v0, $s4, 3
003c2728 addu $a0, $a0, $v0
003c272c lui $v0, 0x88
003c2730 lui $v1, 3
003c2734 lw $v0, 0x73e8($v0)
003c2738 jalr $v0
003c273c ori $a1, $v1, 0xf
003c2740 move $s2, $v0
003c2744 beqz $s2, 0x3c27a0
003c2748 nop 
003c274c jal 0x3c4a40
003c2750 addiu $a0, $s2, 0x20
003c2754 bnez $v0, 0x3c27a8
003c2758 nop 
003c275c b 0x3c2a38
003c2760 move $v0, $zero
003c2764 bltz $s5, 0x3c2798
003c2768 nop 
003c276c lui $v0, 1
003c2770 slt $v0, $s5, $v0
003c2774 bnez $v0, 0x3c2798
003c2778 nop 
003c277c addiu $v0, $zero, 2
003c2780 addiu $a0, $zero, 6
003c2784 jal 0x3df590
003c2788 sw $v0, 0x88($sp)
003c278c sw $v0, 0x8c($sp)
003c2790 jal 0x3df4d0
003c2794 addiu $a0, $sp, 0x88
003c2798 b 0x3c2a38
003c279c move $v0, $zero
003c27a0 b 0x3c2a38
003c27a4 move $v0, $zero
003c27a8 sw $zero, 0x5c($s2)
003c27ac addiu $v1, $zero, 8
003c27b0 sw $zero, 0x18($s2)
003c27b4 addiu $v0, $zero, 1
003c27b8 sb $v1, ($s2)
003c27bc addiu $a0, $s2, 0x34
003c27c0 sb $zero, 1($s2)
003c27c4 move $a1, $zero
003c27c8 sb $zero, 2($s2)
003c27cc addiu $a2, $zero, 0x20
003c27d0 sb $zero, 3($s2)
003c27d4 sw $zero, 4($s2)
003c27d8 sw $zero, 0x58($s2)
003c27dc sh $zero, 0xc($s2)
003c27e0 sh $v0, 0xe($s2)
003c27e4 sw $zero, 0x54($s2)
003c27e8 jal 0x43f9c8
003c27ec sw $s1, 0x1c($s2)
003c27f0 sw $zero, 0x30($s2)
003c27f4 lui $v0, 0xf00
003c27f8 and $v0, $s3, $v0
003c27fc sw $zero, 0x2c($s2)
003c2800 or $v0, $s0, $v0
003c2804 sw $s4, 0x10($s2)
003c2808 sw $v0, 8($s2)
003c280c bnez $s6, 0x3c29f0
003c2810 sw $s5, 0x14($s2)
003c2814 lui $v0, 0x71
003c2818 andi $v1, $s0, 8
003c281c lw $v0, -0x5050($v0)
003c2820 beqz $v1, 0x3c283c
003c2824 addu $a3, $s2, $v0
003c2828 beqz $s5, 0x3c283c
003c282c nop 
003c2830 sw $a3, 0x30($s2)
003c2834 sll $v0, $s5, 2
003c2838 addu $a3, $a3, $v0
003c283c beqz $s1, 0x3c28f8
003c2840 nop 
003c2844 beqz $s5, 0x3c28f8
003c2848 nop 
003c284c sltu $at, $zero, $s1
003c2850 beqz $at, 0x3c28f8
003c2854 move $a2, $zero
003c2858 sltiu $at, $s1, 9
003c285c bnez $at, 0x3c28c0
003c2860 addiu $a0, $s1, -8
003c2864 move $a1, $s2
003c2868 sll $v1, $s5, 3
003c286c sw $a3, 0x34($a1)
003c2870 addu $v0, $a3, $v1
003c2874 sw $v0, 0x38($a1)
003c2878 addiu $a2, $a2, 8
003c287c addu $v0, $v0, $v1
003c2880 sw $v0, 0x3c($a1)
003c2884 addu $v0, $v0, $v1
003c2888 sw $v0, 0x40($a1)
003c288c addu $v0, $v0, $v1
003c2890 sw $v0, 0x44($a1)
003c2894 addu $v0, $v0, $v1
003c2898 sw $v0, 0x48($a1)
003c289c addu $v0, $v0, $v1
003c28a0 sw $v0, 0x4c($a1)
003c28a4 addu $v0, $v0, $v1
003c28a8 sw $v0, 0x50($a1)
003c28ac addu $a3, $v0, $v1
003c28b0 sltu $v0, $a2, $a0
003c28b4 bnez $v0, 0x3c286c
003c28b8 addiu $a1, $a1, 0x20
003c28bc nop 
003c28c0 sltu $at, $a2, $s1
003c28c4 beqz $at, 0x3c28f8
003c28c8 nop 
003c28cc sll $v0, $a2, 2
003c28d0 sll $v1, $s5, 3
003c28d4 addu $a0, $s2, $v0
003c28d8 addiu $a2, $a2, 1
003c28dc sw $a3, 0x34($a0)
003c28e0 sltu $v0, $a2, $s1
003c28e4 addu $a3, $a3, $v1
003c28e8 addiu $a0, $a0, 4
003c28ec bnez $v0, 0x3c28d8
003c28f0 nop 
003c28f4 nop 
003c28f8 beqz $s4, 0x3c29f0
003c28fc nop 
003c2900 slt $at, $zero, $s4
003c2904 sw $a3, 0x2c($s2)
003c2908 beqz $at, 0x3c29f0
003c290c move $v0, $zero
003c2910 slti $at, $s4, 9
003c2914 bnez $at, 0x3c29c0
003c2918 addiu $a2, $s4, -8
003c291c slt $at, $s4, $zero
003c2920 bnez $at, 0x3c2940
003c2924 move $v1, $zero
003c2928 lui $at, 0x7fff
003c292c ori $at, $at, 0xffff
003c2930 slt $at, $s4, $at
003c2934 beqz $at, 0x3c2940
003c2938 nop 
003c293c addiu $v1, $zero, 1
003c2940 beqz $v1, 0x3c29c0
003c2944 nop 
003c2948 move $a3, $zero
003c294c ori $a1, $zero, 0xffff
003c2950 lw $a0, 0x2c($s2)
003c2954 addiu $v0, $v0, 8
003c2958 slt $v1, $v0, $a2
003c295c addu $a0, $a0, $a3
003c2960 sh $a1, 6($a0)
003c2964 lw $a0, 0x2c($s2)
003c2968 addu $a0, $a0, $a3
003c296c sh $a1, 0xe($a0)
003c2970 lw $a0, 0x2c($s2)
003c2974 addu $a0, $a0, $a3
003c2978 sh $a1, 0x16($a0)
003c297c lw $a0, 0x2c($s2)
003c2980 addu $a0, $a0, $a3
003c2984 sh $a1, 0x1e($a0)
003c2988 lw $a0, 0x2c($s2)
003c298c addu $a0, $a0, $a3
003c2990 sh $a1, 0x26($a0)
003c2994 lw $a0, 0x2c($s2)
003c2998 addu $a0, $a0, $a3
003c299c sh $a1, 0x2e($a0)
003c29a0 lw $a0, 0x2c($s2)
003c29a4 addu $a0, $a0, $a3
003c29a8 sh $a1, 0x36($a0)
003c29ac lw $a0, 0x2c($s2)
003c29b0 addu $a0, $a0, $a3
003c29b4 sh $a1, 0x3e($a0)
003c29b8 bnez $v1, 0x3c2950
003c29bc addiu $a3, $a3, 0x40
003c29c0 slt $at, $v0, $s4
003c29c4 beqz $at, 0x3c29f0
003c29c8 nop 
003c29cc sll $a2, $v0, 3
003c29d0 ori $a1, $zero, 0xffff
003c29d4 lw $a0, 0x2c($s2)
003c29d8 addiu $v0, $v0, 1
003c29dc slt $v1, $v0, $s4
003c29e0 addu $a0, $a0, $a2
003c29e4 sh $a1, 6($a0)
003c29e8 bnez $v1, 0x3c29d4
003c29ec addiu $a2, $a2, 8
003c29f0 move $a0, $s2
003c29f4 jal 0x3c1ea0
003c29f8 addiu $a1, $zero, 1
003c29fc bltz $v0, 0x3c2a1c
003c2a00 nop 
003c2a04 lui $a0, 0x71
003c2a08 move $a1, $s2
003c2a0c jal 0x3e3b70
003c2a10 addiu $a0, $a0, -0x5050
003c2a14 b 0x3c2a38
003c2a18 move $v0, $s2
003c2a1c jal 0x3c49a0
003c2a20 addiu $a0, $s2, 0x20
003c2a24 lui $v0, 0x88
003c2a28 lw $v0, 0x73ec($v0)
003c2a2c jalr $v0
003c2a30 move $a0, $s2
003c2a34 move $v0, $zero
003c2a38 ld $ra, 0x70($sp)
003c2a3c lq $s6, 0x60($sp)
003c2a40 lq $s5, 0x50($sp)
003c2a44 lq $s4, 0x40($sp)
003c2a48 lq $s3, 0x30($sp)
003c2a4c lq $s2, 0x20($sp)
003c2a50 lq $s1, 0x10($sp)
003c2a54 lq $s0, 0x0($sp)
003c2a58 jr $ra
003c2a5c addiu $sp, $sp, 0x90
