// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.


(INFINITE_LOOP)

//Save starting screen mem location to R0 so it can be incrimented later
@SCREEN
D=A
@R0
M=D

//Jump to All_white if no key code present in @KBD RAM location, black otherwise
@KBD
D=M
@ALL_WHITE
D;JEQ
@ALL_BLACK
D;JGT

(ALL_WHITE) 
@R0 //R0 contains SCREEN address
A=M //Look at address contained in R0
M=0 //Set value of first SCREEN lcation to 0

@R0 //Incriment screen memory location
M=M+1 
D=M

//KBD is the memory location directly after SCREEN memory map
//D = current memory location to write to, A = end of screen (+1)
//When end of screen minus current screen location is 0, loop to start of the program
@KBD
D=A-D 
@ALL_WHITE
D;JGT

@INFINITE_LOOP
0;JMP

//Same as (ALL_WHITE), except M=-1
(ALL_BLACK)
@R0 
A=M 
M=-1

@R0 
M=M+1 
D=M

@KBD
D=A-D 
@ALL_BLACK
D;JGT

@INFINITE_LOOP
0;JMP