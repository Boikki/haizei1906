	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 11, 0	sdk_version 11, 3
	.globl	__Z1si                          ; -- Begin function _Z1si
	.p2align	2
__Z1si:                                 ; @_Z1si
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16                    ; =16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	w0, [x29, #-4]
	str	wzr, [sp, #8]
	ldur	w8, [x29, #-4]
	cbnz	w8, LBB0_2
; %bb.1:
	str	wzr, [sp, #8]
	b	LBB0_3
LBB0_2:
	adrp	x0, __ZNSt3__13cinE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__13cinE@GOTPAGEOFF]
	add	x1, sp, #4                      ; =4
	bl	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	ldur	w8, [x29, #-4]
	subs	w8, w8, #1                      ; =1
	mov	x0, x8
	bl	__Z1si
	ldr	w8, [sp, #4]
	add	w8, w0, w8
	str	w8, [sp, #8]
LBB0_3:
	ldr	w0, [sp, #8]
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32                     ; =32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32                     ; =32
	stp	x29, x30, [sp, #16]             ; 16-byte Folded Spill
	add	x29, sp, #16                    ; =16
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0
	stur	wzr, [x29, #-4]
	mov	w0, #4
	str	w8, [sp, #8]                    ; 4-byte Folded Spill
	bl	__Z1si
	ldr	w8, [sp, #8]                    ; 4-byte Folded Reload
	mov	x0, x8
	ldp	x29, x30, [sp, #16]             ; 16-byte Folded Reload
	add	sp, sp, #32                     ; =32
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
