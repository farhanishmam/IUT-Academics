ORG 0100H

.DATA
  ARR DB 5 DUP(0)
  avg_var DB ?
  max_var DB ?
  min_var DB ?
     
.CODE      
        
MAIN PROC
    MOV AX, @DATA       ;Moving the segment value of string to Data Segment
    MOV DS, AX
    MOV SI, OFFSET ARR 
         
    MOV CX,5
    MOV AH,1
    
    loop_main:  
            INT 21h
            SUB AL, 48
            MOV [SI], AL
            ADD SI, 1
            LOOP loop_main
    CALL AVG
    CALL MAX
    CALL MIN
    RET
MAIN ENDP
  
AVG PROC
    MOV CX, 5
    MOV SI, OFFSET ARR
    XOR AX, AX
    loop_avg:  
            ADD AL, [SI]
            ADD SI, 1
            LOOP loop_avg
    MOV DL,5
    DIV DL
    MOV avg_var,AL
    RET   
AVG ENDP

MAX PROC 
    MOV CX, 6           ;CX has value 6 because the value will be decremented in the beginning
                        ;So, the loop will still run 5 times
    MOV SI, OFFSET ARR   
    MOV AX,0  
    max_lab:
            MOV max_var, AL
            DEC CX 
    loop_max:         
            MOV AL, [SI]
            ADD SI, 1
            CMP AL, max_var
            JG max_lab
            LOOP loop_max 
    RET                      
MAX ENDP

MIN PROC 
    MOV CX, 6           ;CX has value 6 because the value will be decremented in the beginning
                        ;So, the loop will still run 5 times
    MOV SI, OFFSET ARR   
    MOV AX,10 
    min_lab:
            MOV min_var, AL
            DEC CX 
    loop_min:       
            MOV AL, [SI]
            ADD SI, 1
            CMP AL, min_var
            JL min_lab
            LOOP loop_min 
    RET   
MIN ENDP   
    
END MAIN