ORG  100h
START:      MOV AH,1
            INT 21H
            MOV BL,AL
    
            MOV AH,2
            MOV DL, 0AH
            INT 21H

            MOV DL, 0DH
            INT 21H
        
            CMP BL,5CH
            JL LABEL_UPPER
            JG LABEL_LOWER
        
LABEL_UPPER: MOV AL,BL
            ADD AL,20H
            MOV DL,AL
            INT 21H
RET

LABEL_LOWER:  MOV AL,BL
            SUB AL,20H
            MOV DL,AL
            INT 21H
RET

