;Display all ASCII characters at reverse order
ORG 0100H

.DATA
  
     
.CODE      
        
MAIN PROC
    MOV CX, 128  ; There are 128 ASCII characters from 0 to 127
    MOV DL, 127 
    MOV AH,2     ; For output function
    label_loop:
        INT 21H
        DEC DL
    JNZ label_loop    
    RET
MAIN ENDP
  
  
    
END MAIN