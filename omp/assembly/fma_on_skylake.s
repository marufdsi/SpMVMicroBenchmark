# mark_description "Intel(R) C++ Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 19.0.0.117 Build 20180804";
# mark_description "";
# mark_description "-fopenmp -O3 -Wall -xCORE-AVX512 -qopt-zmm-usage=high -DVECTOR_WIDTH=8 -S -o assembly/fma_on_skylake.s";
	.file "fma_on_skylake.cpp"
	.text
..TXTST0:
.L_2__routine_start_main_0:
# -- Begin  main, L_main_10__par_region0_2.0, L_main_14__par_region1_2.1
	.text
# mark_begin;
       .align    16,0x90
	.globl main
# --- main()
main:
..B1.1:                         # Preds ..B1.0
                                # Execution count [0.00e+00]
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
..___tag_value_main.1:
..L2:
                                                          #8.12
        pushq     %rbp                                          #8.12
	.cfi_def_cfa_offset 16
        movq      %rsp, %rbp                                    #8.12
	.cfi_def_cfa 6, 16
	.cfi_offset 6, -16
        andq      $-128, %rsp                                   #8.12
        subq      $640, %rsp                                    #8.12
        movq      $0x20064199d9ffe, %rsi                        #8.12
        movl      $3, %edi                                      #8.12
        movq      %rbx, 40(%rsp)                                #8.12[spill]
        movq      %r15, 8(%rsp)                                 #8.12[spill]
        movq      %r14, 16(%rsp)                                #8.12[spill]
        movq      %r13, 24(%rsp)                                #8.12[spill]
        movq      %r12, 32(%rsp)                                #8.12[spill]
        call      __intel_new_feature_proc_init                 #8.12
	.cfi_escape 0x10, 0x03, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xa8, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0c, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xa0, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0d, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x98, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0e, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x90, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0f, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x88, 0xfd, 0xff, 0xff, 0x22
                                # LOE
..B1.28:                        # Preds ..B1.1
                                # Execution count [0.00e+00]
        vstmxcsr  (%rsp)                                        #8.12
        movl      $.2.3_2_kmpc_loc_struct_pack.4, %edi          #8.12
        xorl      %esi, %esi                                    #8.12
        orl       $32832, (%rsp)                                #8.12
        xorl      %eax, %eax                                    #8.12
        vldmxcsr  (%rsp)                                        #8.12
..___tag_value_main.16:
        call      __kmpc_begin                                  #8.12
..___tag_value_main.17:
                                # LOE
..B1.2:                         # Preds ..B1.28
                                # Execution count [1.00e+00]
        movl      $.2.3_2_kmpc_loc_struct_pack.15, %edi         #10.1
        call      __kmpc_global_thread_num                      #10.1
                                # LOE eax
..B1.30:                        # Preds ..B1.2
                                # Execution count [1.00e+00]
        movl      %eax, 56(%rsp)                                #10.1
        movl      $.2.3_2_kmpc_loc_struct_pack.31, %edi         #10.1
        xorl      %eax, %eax                                    #10.1
..___tag_value_main.18:
        call      __kmpc_ok_to_fork                             #10.1
..___tag_value_main.19:
                                # LOE eax
..B1.3:                         # Preds ..B1.30
                                # Execution count [1.00e+00]
        testl     %eax, %eax                                    #10.1
        je        ..B1.5        # Prob 50%                      #10.1
                                # LOE
..B1.4:                         # Preds ..B1.3
                                # Execution count [0.00e+00]
        movl      $L_main_10__par_region0_2.0, %edx             #10.1
        movl      $.2.3_2_kmpc_loc_struct_pack.31, %edi         #10.1
        xorl      %esi, %esi                                    #10.1
        xorl      %eax, %eax                                    #10.1
..___tag_value_main.20:
        call      __kmpc_fork_call                              #10.1
..___tag_value_main.21:
        jmp       ..B1.8        # Prob 100%                     #10.1
                                # LOE
..B1.5:                         # Preds ..B1.3
                                # Execution count [0.00e+00]
        movl      $.2.3_2_kmpc_loc_struct_pack.31, %edi         #10.1
        xorl      %eax, %eax                                    #10.1
        movl      56(%rsp), %esi                                #10.1
..___tag_value_main.22:
        call      __kmpc_serialized_parallel                    #10.1
..___tag_value_main.23:
                                # LOE
..B1.6:                         # Preds ..B1.5
                                # Execution count [0.00e+00]
        movl      $___kmpv_zeromain_0, %esi                     #10.1
        lea       56(%rsp), %rdi                                #10.1
..___tag_value_main.24:
        call      L_main_10__par_region0_2.0                    #10.1
..___tag_value_main.25:
                                # LOE
..B1.7:                         # Preds ..B1.6
                                # Execution count [0.00e+00]
        movl      $.2.3_2_kmpc_loc_struct_pack.31, %edi         #10.1
        xorl      %eax, %eax                                    #10.1
        movl      56(%rsp), %esi                                #10.1
..___tag_value_main.26:
        call      __kmpc_end_serialized_parallel                #10.1
..___tag_value_main.27:
                                # LOE
..B1.8:                         # Preds ..B1.4 ..B1.7
                                # Execution count [1.00e+00]
..___tag_value_main.28:
#       omp_get_wtime()
        call      omp_get_wtime                                 #13.21
..___tag_value_main.29:
                                # LOE xmm0
..B1.31:                        # Preds ..B1.8
                                # Execution count [1.00e+00]
        vmovsd    %xmm0, 48(%rsp)                               #13.21[spill]
                                # LOE
..B1.9:                         # Preds ..B1.31
                                # Execution count [1.00e+00]
        movl      $.2.3_2_kmpc_loc_struct_pack.41, %edi         #14.1
        xorl      %eax, %eax                                    #14.1
..___tag_value_main.31:
        call      __kmpc_ok_to_fork                             #14.1
..___tag_value_main.32:
                                # LOE eax
..B1.10:                        # Preds ..B1.9
                                # Execution count [1.00e+00]
        testl     %eax, %eax                                    #14.1
        je        ..B1.12       # Prob 50%                      #14.1
                                # LOE
..B1.11:                        # Preds ..B1.10
                                # Execution count [0.00e+00]
        movl      $L_main_14__par_region1_2.1, %edx             #14.1
        movl      $.2.3_2_kmpc_loc_struct_pack.41, %edi         #14.1
        xorl      %esi, %esi                                    #14.1
        xorl      %eax, %eax                                    #14.1
..___tag_value_main.33:
        call      __kmpc_fork_call                              #14.1
..___tag_value_main.34:
        jmp       ..B1.15       # Prob 100%                     #14.1
                                # LOE
..B1.12:                        # Preds ..B1.10
                                # Execution count [0.00e+00]
        movl      $.2.3_2_kmpc_loc_struct_pack.41, %edi         #14.1
        xorl      %eax, %eax                                    #14.1
        movl      56(%rsp), %esi                                #14.1
..___tag_value_main.35:
        call      __kmpc_serialized_parallel                    #14.1
..___tag_value_main.36:
                                # LOE
..B1.13:                        # Preds ..B1.12
                                # Execution count [0.00e+00]
        movl      $___kmpv_zeromain_1, %esi                     #14.1
        lea       56(%rsp), %rdi                                #14.1
..___tag_value_main.37:
        call      L_main_14__par_region1_2.1                    #14.1
..___tag_value_main.38:
                                # LOE
..B1.14:                        # Preds ..B1.13
                                # Execution count [0.00e+00]
        movl      $.2.3_2_kmpc_loc_struct_pack.41, %edi         #14.1
        xorl      %eax, %eax                                    #14.1
        movl      56(%rsp), %esi                                #14.1
..___tag_value_main.39:
        call      __kmpc_end_serialized_parallel                #14.1
..___tag_value_main.40:
                                # LOE
..B1.15:                        # Preds ..B1.11 ..B1.14
                                # Execution count [0.00e+00]
..___tag_value_main.41:
#       omp_get_wtime()
        call      omp_get_wtime                                 #51.21
..___tag_value_main.42:
                                # LOE xmm0
..B1.33:                        # Preds ..B1.15
                                # Execution count [0.00e+00]
        vmovsd    %xmm0, (%rsp)                                 #51.21[spill]
                                # LOE
..B1.16:                        # Preds ..B1.33
                                # Execution count [0.00e+00]
#       omp_get_max_threads()
        call      omp_get_max_threads                           #54.13
                                # LOE eax
..B1.17:                        # Preds ..B1.16
                                # Execution count [0.00e+00]
        vxorpd    %xmm2, %xmm2, %xmm2                           #54.13
        movl      $8, %esi                                      #55.3
        vcvtsi2sd %eax, %xmm2, %xmm2                            #54.13
        vmovsd    (%rsp), %xmm3                                 #56.46[spill]
        movl      $.L_2__STRING.0, %edi                         #55.3
        vmulsd    .L_2il0floatpacket.5(%rip), %xmm2, %xmm0      #54.35
        movl      %esi, %edx                                    #55.3
        vsubsd    48(%rsp), %xmm3, %xmm1                        #56.46[spill]
        movl      $3, %eax                                      #55.3
        vdivsd    %xmm1, %xmm0, %xmm2                           #55.3
..___tag_value_main.46:
#       printf(const char *, ...)
        call      printf                                        #55.3
..___tag_value_main.47:
                                # LOE
..B1.18:                        # Preds ..B1.17
                                # Execution count [0.00e+00]
        movl      $.2.3_2_kmpc_loc_struct_pack.23, %edi         #57.1
        xorl      %eax, %eax                                    #57.1
..___tag_value_main.48:
        call      __kmpc_end                                    #57.1
..___tag_value_main.49:
                                # LOE
..B1.19:                        # Preds ..B1.18
                                # Execution count [0.00e+00]
        xorl      %eax, %eax                                    #57.1
        movq      8(%rsp), %r15                                 #57.1[spill]
	.cfi_restore 15
        movq      16(%rsp), %r14                                #57.1[spill]
	.cfi_restore 14
        movq      24(%rsp), %r13                                #57.1[spill]
	.cfi_restore 13
        movq      32(%rsp), %r12                                #57.1[spill]
	.cfi_restore 12
        movq      40(%rsp), %rbx                                #57.1[spill]
	.cfi_restore 3
        movq      %rbp, %rsp                                    #57.1
        popq      %rbp                                          #57.1
	.cfi_def_cfa 7, 8
	.cfi_restore 6
        ret                                                     #57.1
	.cfi_def_cfa 6, 16
                                # LOE
L_main_14__par_region1_2.1:
# parameter 1: %rdi
# parameter 2: %rsi
..B1.20:                        # Preds ..B1.0
                                # Execution count [1.00e+00]
        pushq     %rbp                                          #14.1
	.cfi_def_cfa 7, 16
        movq      %rsp, %rbp                                    #14.1
	.cfi_def_cfa 6, 16
	.cfi_offset 6, -16
        andq      $-128, %rsp                                   #14.1
        subq      $640, %rsp                                    #14.1
        movq      %rbx, 40(%rsp)                                #14.1[spill]
        movq      %r15, 8(%rsp)                                 #14.1[spill]
        movq      %r14, 16(%rsp)                                #14.1[spill]
        movq      %r13, 24(%rsp)                                #14.1[spill]
        movq      %r12, 32(%rsp)                                #14.1[spill]
        vmovups   .L_2il0floatpacket.2(%rip), %zmm1             #19.26
        vmovups   .L_2il0floatpacket.3(%rip), %zmm0             #20.26
        vpxord    %zmm11, %zmm11, %zmm11                        #18.41
        vmovupd   %zmm11, 64(%rsp)                              #18.10
        vmovupd   %zmm11, 128(%rsp)                             #18.10
        vmovupd   %zmm11, 192(%rsp)                             #18.10
        vmovupd   %zmm11, 256(%rsp)                             #18.10
        vmovupd   %zmm11, 320(%rsp)                             #18.10
        vmovupd   %zmm11, 384(%rsp)                             #18.10
        vmovupd   %zmm11, 448(%rsp)                             #18.10
        vmovupd   %zmm11, 512(%rsp)                             #18.10
	.cfi_escape 0x10, 0x03, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xa8, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0c, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xa0, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0d, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x98, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0e, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x90, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0f, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x88, 0xfd, 0xff, 0xff, 0x22
                                # LOE zmm0 zmm1 zmm11
..B1.22:                        # Preds ..B1.20
                                # Execution count [5.00e+03]
        vmovaps   %zmm11, %zmm10                                #39.19
        xorl      %eax, %eax                                    #35.5
        vmovaps   %zmm10, %zmm9                                 #40.19
        vmovaps   %zmm9, %zmm8                                  #41.19
        vmovaps   %zmm8, %zmm7                                  #42.19
        vmovaps   %zmm7, %zmm6                                  #43.19
        vmovaps   %zmm6, %zmm5                                  #44.19
        vmovaps   %zmm5, %zmm4                                  #45.19
        vmovups   576(%rsp), %zmm3                              #46.19
        vmovups   640(%rsp), %zmm2                              #47.19
        .align    16,0x90
                                # LOE eax zmm0 zmm1 zmm2 zmm3 zmm4 zmm5 zmm6 zmm7 zmm8 zmm9 zmm10 zmm11
..B1.23:                        # Preds ..B1.23 ..B1.22
                                # Execution count [1.00e+06]
        incl      %eax                                          #35.5
        vfmadd213pd %zmm0, %zmm1, %zmm11                        #38.35
        vfmadd213pd %zmm0, %zmm1, %zmm10                        #39.35
        vfmadd213pd %zmm0, %zmm1, %zmm9                         #40.35
        vfmadd213pd %zmm0, %zmm1, %zmm8                         #41.35
        vfmadd213pd %zmm0, %zmm1, %zmm7                         #42.35
        vfmadd213pd %zmm0, %zmm1, %zmm6                         #43.35
        vfmadd213pd %zmm0, %zmm1, %zmm5                         #44.35
        vfmadd213pd %zmm0, %zmm1, %zmm4                         #45.35
        vfmadd213pd %zmm0, %zmm1, %zmm3                         #46.35
        vfmadd213pd %zmm0, %zmm1, %zmm2                         #47.35
        cmpl      $1000000000, %eax                             #35.5
        jb        ..B1.23       # Prob 99%                      #35.5
                                # LOE eax zmm0 zmm1 zmm2 zmm3 zmm4 zmm5 zmm6 zmm7 zmm8 zmm9 zmm10 zmm11
..B1.24:                        # Preds ..B1.23
                                # Execution count [0.00e+00]
        vmovups   .L_2il0floatpacket.4(%rip), %zmm0             #49.42
        xorl      %eax, %eax                                    #14.1
        lea       640(%rsp), %rdx                               #47.9
        vmovupd   %zmm2, (%rdx)                                 #47.9
        vmovupd   %zmm3, -64(%rdx)                              #46.9
        vmulpd    %zmm0, %zmm11, %zmm11                         #49.10
        vmulpd    %zmm0, %zmm10, %zmm10                         #49.10
        vmulpd    %zmm0, %zmm9, %zmm9                           #49.10
        vmulpd    %zmm0, %zmm8, %zmm8                           #49.10
        vmulpd    %zmm0, %zmm7, %zmm7                           #49.10
        vmulpd    %zmm0, %zmm6, %zmm6                           #49.10
        vmulpd    %zmm0, %zmm5, %zmm5                           #49.10
        vmulpd    %zmm0, %zmm4, %zmm1                           #49.10
        vmovupd   %zmm11, -576(%rdx)                            #49.10
        vmovupd   %zmm10, -512(%rdx)                            #49.10
        vmovupd   %zmm9, -448(%rdx)                             #49.10
        vmovupd   %zmm8, -384(%rdx)                             #49.10
        vmovupd   %zmm7, -320(%rdx)                             #49.10
        vmovupd   %zmm6, -256(%rdx)                             #49.10
        vmovupd   %zmm5, -192(%rdx)                             #49.10
        vmovupd   %zmm1, -128(%rdx)                             #49.10
        vzeroupper                                              #14.1
        movq      8(%rsp), %r15                                 #14.1[spill]
	.cfi_restore 15
        movq      16(%rsp), %r14                                #14.1[spill]
	.cfi_restore 14
        movq      24(%rsp), %r13                                #14.1[spill]
	.cfi_restore 13
        movq      32(%rsp), %r12                                #14.1[spill]
	.cfi_restore 12
        movq      40(%rsp), %rbx                                #14.1[spill]
	.cfi_restore 3
        movq      %rbp, %rsp                                    #14.1
        popq      %rbp                                          #14.1
	.cfi_def_cfa 7, 8
	.cfi_restore 6
        ret                                                     #14.1
	.cfi_def_cfa 6, 16
                                # LOE
L_main_10__par_region0_2.0:
# parameter 1: %rdi
# parameter 2: %rsi
..B1.25:                        # Preds ..B1.0
                                # Execution count [0.00e+00]
        pushq     %rbp                                          #10.1
	.cfi_def_cfa 7, 16
        movq      %rsp, %rbp                                    #10.1
	.cfi_def_cfa 6, 16
	.cfi_offset 6, -16
        andq      $-128, %rsp                                   #10.1
        subq      $640, %rsp                                    #10.1
        xorl      %eax, %eax                                    #10.1
        movq      %r15, 8(%rsp)                                 #10.1[spill]
        movq      %r14, 16(%rsp)                                #10.1[spill]
        movq      %r13, 24(%rsp)                                #10.1[spill]
        movq      %r12, 32(%rsp)                                #10.1[spill]
        movq      %rbx, 40(%rsp)                                #10.1[spill]
        movq      8(%rsp), %r15                                 #10.1[spill]
	.cfi_escape 0x10, 0x03, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xa8, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0c, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0xa0, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0d, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x98, 0xfd, 0xff, 0xff, 0x22
	.cfi_escape 0x10, 0x0e, 0x0e, 0x38, 0x1c, 0x0d, 0x80, 0xff, 0xff, 0xff, 0x1a, 0x0d, 0x90, 0xfd, 0xff, 0xff, 0x22
        movq      16(%rsp), %r14                                #10.1[spill]
	.cfi_restore 14
        movq      24(%rsp), %r13                                #10.1[spill]
	.cfi_restore 13
        movq      32(%rsp), %r12                                #10.1[spill]
	.cfi_restore 12
        movq      40(%rsp), %rbx                                #10.1[spill]
	.cfi_restore 3
        movq      %rbp, %rsp                                    #10.1
        popq      %rbp                                          #10.1
	.cfi_def_cfa 7, 8
	.cfi_restore 6
        ret                                                     #10.1
        .align    16,0x90
                                # LOE
	.cfi_endproc
# mark_end;
	.type	main,@function
	.size	main,.-main
..LNmain.0:
	.data
	.align 4
	.align 4
.2.3_2_kmpc_loc_struct_pack.4:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.3
	.align 4
.2.3_2__kmpc_loc_pack.3:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	56
	.byte	59
	.byte	56
	.byte	59
	.byte	59
	.space 1, 0x00 	# pad
	.align 4
.2.3_2_kmpc_loc_struct_pack.15:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.14
	.align 4
.2.3_2__kmpc_loc_pack.14:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	49
	.byte	48
	.byte	59
	.byte	49
	.byte	48
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.3_2_kmpc_loc_struct_pack.31:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.30
	.align 4
.2.3_2__kmpc_loc_pack.30:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	49
	.byte	48
	.byte	59
	.byte	49
	.byte	49
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.3_2_kmpc_loc_struct_pack.41:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.40
	.align 4
.2.3_2__kmpc_loc_pack.40:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	49
	.byte	52
	.byte	59
	.byte	53
	.byte	48
	.byte	59
	.byte	59
	.space 3, 0x00 	# pad
	.align 4
.2.3_2_kmpc_loc_struct_pack.23:
	.long	0
	.long	2
	.long	0
	.long	0
	.quad	.2.3_2__kmpc_loc_pack.22
	.align 4
.2.3_2__kmpc_loc_pack.22:
	.byte	59
	.byte	117
	.byte	110
	.byte	107
	.byte	110
	.byte	111
	.byte	119
	.byte	110
	.byte	59
	.byte	109
	.byte	97
	.byte	105
	.byte	110
	.byte	59
	.byte	53
	.byte	55
	.byte	59
	.byte	53
	.byte	55
	.byte	59
	.byte	59
	.data
# -- End  main, L_main_10__par_region0_2.0, L_main_14__par_region1_2.1
	.bss
	.align 4
	.align 4
___kmpv_zeromain_0:
	.type	___kmpv_zeromain_0,@object
	.size	___kmpv_zeromain_0,4
	.space 4	# pad
	.align 4
___kmpv_zeromain_1:
	.type	___kmpv_zeromain_1,@object
	.size	___kmpv_zeromain_1,4
	.space 4	# pad
	.section .rodata, "a"
	.align 64
	.align 64
.L_2il0floatpacket.2:
	.long	0x00000000,0x3fe00000,0x00000000,0x3fe00000,0x00000000,0x3fe00000,0x00000000,0x3fe00000,0x00000000,0x3fe00000,0x00000000,0x3fe00000,0x00000000,0x3fe00000,0x00000000,0x3fe00000
	.type	.L_2il0floatpacket.2,@object
	.size	.L_2il0floatpacket.2,64
	.align 64
.L_2il0floatpacket.3:
	.long	0x00000000,0x3ff00000,0x00000000,0x3ff00000,0x00000000,0x3ff00000,0x00000000,0x3ff00000,0x00000000,0x3ff00000,0x00000000,0x3ff00000,0x00000000,0x3ff00000,0x00000000,0x3ff00000
	.type	.L_2il0floatpacket.3,@object
	.size	.L_2il0floatpacket.3,64
	.align 64
.L_2il0floatpacket.4:
	.long	0x00000000,0x40000000,0x00000000,0x40000000,0x00000000,0x40000000,0x00000000,0x40000000,0x00000000,0x40000000,0x00000000,0x40000000,0x00000000,0x40000000,0x00000000,0x40000000
	.type	.L_2il0floatpacket.4,@object
	.size	.L_2il0floatpacket.4,64
	.align 8
.L_2il0floatpacket.5:
	.long	0x00000000,0x40600000
	.type	.L_2il0floatpacket.5,@object
	.size	.L_2il0floatpacket.5,8
	.section .rodata.str1.32, "aMS",@progbits,1
	.align 32
	.align 32
.L_2__STRING.0:
	.long	1767991363
	.long	543450478
	.long	1933659462
	.long	744760637
	.long	1667593760
	.long	544370548
	.long	1952737655
	.long	1680162152
	.long	1179066412
	.long	1934643020
	.long	825107773
	.long	1948265574
	.long	1030057321
	.long	1714826789
	.long	539783968
	.long	1718773104
	.long	1634562671
	.long	1030054766
	.long	1714499109
	.long	1279674144
	.long	1932480591
	.word	10
	.type	.L_2__STRING.0,@object
	.size	.L_2__STRING.0,86
	.data
	.section .note.GNU-stack, ""
# End
