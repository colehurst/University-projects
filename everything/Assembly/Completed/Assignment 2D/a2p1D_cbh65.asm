###########################################################################		
 #<Cole Hurst>, CS 2318-251, Assignment 2 Part 1 Program D 		
###########################################################################		
#Takes in 3 Exam scores from the user then displays them back to the user		
#then aplies a curve to calculate an average then displays average to the user.		
#############################data segment##################################		
		.data	
InputEx1:	.asciiz		"Enter Exam 1 Score: "    	
InputEx2:	.asciiz		"Enter Exam 2 Score: "	
InputExF:	.asciiz		"Enter the Final Exam Score: "   	
OutputEx1:	.asciiz  	"Exam 1 Score is "   	
OutputEx2:	.asciiz  	"Exam 2 Score is "
OutputExF:	.asciiz  	"Final Exam Score is "
OutputAVG:	.asciiz  	"The Average is "   	
#############################code segment##################################		
		.text	
		.globl main	
main:		
	 	li $v0, 4 		#ask user for exam 1
	 	la $a0, InputEx1 	
		syscall	
	 	li $v0, 5 	
		syscall	
	 	move $t1, $v0 	
		
	 	li $v0, 4 		#ask user for exam 2
	 	la $a0, InputEx2 	
		syscall	
	 	li $v0, 5 	
		syscall	
	 	move $t2, $v0 	
		
		li $v0, 4 	
		la $a0, InputExF 	#ask user for final exam
		syscall	
	 	li $v0, 5 	
		syscall	
	 	move $t3, $v0 	
		
	 	li $v0, 4 	
	 	la $a0, OutputEx1 	
		syscall	
	 	li $v0, 1 	
	 	move $a0, $t1 	
		syscall			#displays contents of exam 1 ($t1)
	 	li $v0, 11 	
	 	li $a0, '\n' 	
		syscall	
		
	 	li $v0, 4 	
	 	la $a0, OutputEx2 	
		syscall	
	 	li $v0, 1 	
	 	move $a0, $t2 	
		syscall			#displays contents of exam 2 ($t2)
	 	li $v0, 11 	
	 	li $a0, '\n' 	
		syscall	
		
	 	li $v0, 4 	
	 	la $a0, OutputExF 	
		syscall	
	 	li $v0, 1 	
	 	move $a0, $t3 	
		syscall			#displays contents of final exam ($t3)
	 	li $v0, 11 	
	 	li $a0, '\n' 	
		syscall	
		
	 	li $t0, 0x73 		#step 1: multiply exam 1 and 115 
	 	mul $t1, $t1, $t0 	
	 	srl $t1, $t1, 9 	#step 2: taking product of step 1 and divide using right bit shifting
		
	 	sll $t2, $t2, 3 	#step 3: multiplying Exam 2 by using left bit shifting
	 	li $t0, 0x1D 		#step 4: taking proudct of step 3 and dividing by 29
	 	div $t2, $t2, $t0 	
		
	 	srl $t3, $t3, 1 	#step 5: dividing final Exam by right bit shifting
		
	 	add $t1, $t1, $t2 	
	 	add $t1, $t1, $t3 	#step 6: adding all weighted tests together
		
	 	li $v0, 4 	
	 	la $a0, OutputAVG 	# displays new wheighted average
		syscall	
	 	li $v0, 1 	
		move $a0, $t1 	
		syscall	
		
	 	li $v0, 10 		#gracefully exits the program
		syscall	
