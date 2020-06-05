
; half __div (half left, half right)

SECTION code_fp_math16

PUBLIC cm16_sccz80_div

EXTERN asm_f24_f16
EXTERN asm_f16_f24

EXTERN asm_f24_inv
EXTERN asm_f24_mul_f24

.cm16_sccz80_div

    ; divide sccz80 half by sccz80 half
    ;
    ; enter : stack = sccz80_half left, sccz80_half right, ret
    ;
    ; exit  :    HL = sccz80_half(left/right)
    ;
    ; uses  : af, bc, de, hl, af', bc', de', hl'

    pop bc                      ; pop return address
    pop hl                      ; get right operand off of the stack
    exx

    pop hl                      ; get left operand off of the stack
    push hl
    exx

    push hl
    push bc                     ; return address on stack
    call asm_f24_f16            ; expand to dehl
    call asm_f24_inv

    exx                         ; 1/y   d'  = eeeeeeee e' = s-------
                                ;       hl' = 1mmmmmmm mmmmmmmm
    call asm_f24_f16            ; expand to dehl
                                ; x      d  = eeeeeeee e  = s-------
                                ;        hl = 1mmmmmmm mmmmmmmm
    call asm_f24_mul_f24
    jp asm_f16_f24              ; enter stack = sccz80_half right, sccz80_half left, ret
                                ;        HL = sccz80_half right
                                ; return HL = sccz80_half

