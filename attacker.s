	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function probability
LCPI0_0:
	.quad	4607182418800017408     ## double 1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_probability
	.p2align	4, 0x90
_probability:                           ## @probability
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$80, %rsp
	movsd	LCPI0_0(%rip), %xmm1    ## xmm1 = mem[0],zero
	movsd	%xmm0, -8(%rbp)
	movl	%edi, -12(%rbp)
	movaps	%xmm1, %xmm0
	subsd	-8(%rbp), %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	-12(%rbp), %edi
	cvtsi2sdl	%edi, %xmm0
	movsd	-24(%rbp), %xmm2        ## xmm2 = mem[0],zero
	divsd	-8(%rbp), %xmm2
	mulsd	%xmm2, %xmm0
	movsd	%xmm0, -32(%rbp)
	movsd	%xmm1, -40(%rbp)
	movl	$0, -48(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	movl	-48(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jg	LBB0_8
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movsd	-32(%rbp), %xmm0        ## xmm0 = mem[0],zero
	movq	%xmm0, %rax
	movabsq	$-9223372036854775808, %rcx ## imm = 0x8000000000000000
	xorq	%rcx, %rax
	movq	%rax, %xmm0
	callq	_exp
	movsd	%xmm0, -56(%rbp)
	movl	$1, -44(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	-44(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jg	LBB0_6
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=2
	movsd	-32(%rbp), %xmm0        ## xmm0 = mem[0],zero
	movl	-44(%rbp), %eax
	cvtsi2sdl	%eax, %xmm1
	divsd	%xmm1, %xmm0
	mulsd	-56(%rbp), %xmm0
	movsd	%xmm0, -56(%rbp)
## %bb.5:                               ##   in Loop: Header=BB0_3 Depth=2
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	jmp	LBB0_3
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	movsd	LCPI0_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movsd	-56(%rbp), %xmm1        ## xmm1 = mem[0],zero
	movsd	-8(%rbp), %xmm2         ## xmm2 = mem[0],zero
	divsd	-24(%rbp), %xmm2
	movl	-12(%rbp), %eax
	subl	-48(%rbp), %eax
	cvtsi2sdl	%eax, %xmm3
	movsd	%xmm0, -64(%rbp)        ## 8-byte Spill
	movaps	%xmm2, %xmm0
	movsd	%xmm1, -72(%rbp)        ## 8-byte Spill
	movaps	%xmm3, %xmm1
	callq	_pow
	movsd	-64(%rbp), %xmm1        ## 8-byte Reload
                                        ## xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	-72(%rbp), %xmm0        ## 8-byte Reload
                                        ## xmm0 = mem[0],zero
	mulsd	%xmm1, %xmm0
	movsd	-40(%rbp), %xmm1        ## xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, -40(%rbp)
## %bb.7:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-48(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	jmp	LBB0_1
LBB0_8:
	movsd	-40(%rbp), %xmm0        ## xmm0 = mem[0],zero
	addq	$80, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__literal8,8byte_literals
	.p2align	3               ## -- Begin function main
LCPI1_0:
	.quad	4636737291354636288     ## double 100
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10, -8(%rbp)
	jge	LBB1_4
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movsd	LCPI1_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	movl	-8(%rbp), %edi
	callq	_probability
	movsd	%xmm0, -16(%rbp)
	movl	-8(%rbp), %esi
	movsd	-16(%rbp), %xmm0        ## xmm0 = mem[0],zero
	leaq	L_.str(%rip), %rdi
	movb	$1, %al
	callq	_printf
	movl	%eax, -20(%rbp)         ## 4-byte Spill
## %bb.3:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB1_1
LBB1_4:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"[%d] %f\n"


.subsections_via_symbols
