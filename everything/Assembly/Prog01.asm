# Assignment 2 part 1A
#Cole Hurst sec.251
			.data
name:			.space 21			
intPrmpt:		.asciiz "Enter interger: "
yaiLab:			.asciiz "Your interger is "
charPrmpt:		.asciiz "Enter character: "
ygiLab:			.asciiz "Your character is "
strPrmpt:		.asciiz "Enter string: "
yniLab:			.asciiz "Your string is "

			.text
			.globl main
main:
			
			li $v0, 11
			li $a0, '\n'
			syscall
			
			li $v0,4
			la $a0, intPrmpt
			syscall
			li $v0,5
			syscall
			move $t0, $v0			# copy integer read (in $v0) to $t0
			li $v0,4
			la $a0, yaiLab
			syscall
			li $v0,1
			move $a0, $t0
			syscall
			
			li $v0, 11
			li $a0, '\n'
			syscall
			
			li $v0,4
			la $a0, charPrmpt
			syscall
			li $v0,12
			syscall
			move $t0, $v0
			
			li $v0, 11
			li $a0, '\n'
			syscall
			
			li $v0,4
			la $a0, ygiLab
			syscall
			li $v0,11
			move $a0, $t0
			syscall
			
			li $v0, 11
			li $a0, '\n'
			syscall
			
			li $v0,4
			la $a0, strPrmpt
			syscall
			li $v0, 8
			la $a0, name
			li $a1, 21
			syscall

			li $v0, 11
			li $a0, '\n'
			syscall
			
			li $v0,4
			la $a0, yniLab
			syscall
			#li $v0,4
			la $a0, name
			syscall

			li $v0, 10			# graceful exit
			syscall
			
