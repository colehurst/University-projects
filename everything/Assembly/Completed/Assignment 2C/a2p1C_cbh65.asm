###########################################################################		
#<Cole Hurst>, CS 2318-251, Assignment 2 Part 1 Program C		
###########################################################################		
#Diplay an interger of 5 numbers and then swap position 1 and 4; 2 and 5		
#then display in reverse order to the user.		
#############################data segment##################################		
		.data	
arrMsg1to5:	.asciiz "Integer array from 1st to 5th element"	
arrMsg5to1:	.asciiz "Integer array from 5th to 1st element"	
		
intArr:		.word   44, 99, 33, 11, 55	
#############################code segment##################################		
		.text	
		.globl main	
main:		
		li $v0, 4	
		la $a0, arrMsg1to5        	
		syscall	
		
		li $v0, 11	
		li $a0, '\n'	
		syscall	
		
		la $t0, intArr	#initializing array
		li $v0, 1	
		lw $a0, 0($t0)	#displaying contents of array
		syscall	
		lw $a0, 4($t0)	
		syscall	
		lw $a0, 8($t0)	
		syscall	
		lw $a0, 12($t0)	
		syscall	
		lw $a0, 16($t0)	
		syscall	
				
		li $v0, 11	
		li $a0, '\n'	
		syscall	
		
		lw $t1, 0($t0)
		lw $t3, 12($t0)	
		
		sw $t3, 0($t0)	#swapping 1st spot with 4th
		sw $t1, 12($t0)	
 		
 		lw $t1, 4($t0)	
		lw $t3, 16($t0)	
		
		sw $t3, 4($t0)	#swapping 2nd spot with 5th
		sw $t1, 16($t0)	
#########################################################################################		
		li $v0, 4	
		la $a0, arrMsg5to1        	
		syscall	
		li $v0, 11	
		li $a0, '\n'	
		syscall	
		
		li $v0, 1	#displaying contents of Array backwards
		lw $a0, 16($t0)	
		syscall	
		lw $a0, 12($t0)	
		syscall	
		lw $a0, 8($t0)	
		syscall	
		lw $a0, 4($t0)
		syscall	
		lw $a0, 0($t0)
		syscall	
		
		li $v0, 10	#gentle and elegant exit
		syscall	
#############################################################################################		
