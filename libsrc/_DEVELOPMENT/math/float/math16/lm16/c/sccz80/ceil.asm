
	SECTION	code_fp_math16
	PUBLIC	ceil
	EXTERN	cm16_sccz80_ceil

	defc	ceil = cm16_sccz80_ceil


; SDCC bridge for Classic
IF __CLASSIC
PUBLIC _ceil
EXTERN cm16_sdcc_ceil
defc _ceil = cm16_sdcc_ceil
ENDIF

