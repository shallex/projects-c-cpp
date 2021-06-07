

section .bss
    x resq 1 
    ans resq 1
section .data
    v1 dq 1.0
    v2 dq 0.5
    v3 dq 3.0
    v4 dq 2.5
    v5 dq 9.5
    v6 dq 5.0
    v7 dq 2.0
    v8 dq -3.0
    v9 dq -5.0
section .text

;global CMAIN
;CMAIN:
;    ;write your code here
;   
;    xor eax, eax
;    ret

global f1
global f2
global f3
global proiz1
global proiz2
global proiz3
global sum

  
sum:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8]
    fld qword[ebp+16]
    faddp 
    
    mov esp, ebp
    pop ebp
    ret
    
f1:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8]
    fld qword[v1]
    faddp
    fld qword[v2]
    fdivrp
    fld qword[v1]
    faddp 
    fld qword[v3]
    fmulp
    mov esp, ebp
    pop ebp
    ret
    
f2:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8]
    fld qword[v4]
    fmulp
    fld qword[v5]
    fsubp
    mov esp, ebp
    pop ebp
    ret 
    
  f3:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8]
    fld qword[v6]
    fdivrp
    mov esp, ebp
    pop ebp
    ret   
 
 proiz1:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8]
    fld qword[v1]
    faddp
    fst qword[x]
    fld qword[x]
    fmulp
    fld qword[v7]
    fmulp 
    fld qword[v8]
    fdivrp
    mov esp, ebp
    pop ebp
    ret
 
 proiz2:
    push ebp
    mov ebp, esp
    mov esp, ebp
    finit
    fld qword[v4]
    pop ebp
    ret
    
 proiz3:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp+8]
    fld qword[ebp+8]
    fmulp
    fld qword[v9]
    fdivrp
    mov esp, ebp
    pop ebp
    ret
    
    
    
    
    
    
    
    