
// automatically generated by m4 from headers in proto subdir


#ifndef _Z80_H
#define _Z80_H

#include <stdint.h>

extern void im2_init(void *im2_table_address);
extern void im2_init_fastcall(void *im2_table_address) __z88dk_fastcall;
#define im2_init(a) im2_init_fastcall(a)


extern void *im2_install_isr(uint16_t vector,void *isr);
extern void *im2_install_isr_callee(uint16_t vector,void *isr) __z88dk_callee;
#define im2_install_isr(a,b) im2_install_isr_callee(a,b)


extern void *im2_create_generic_isr(uint16_t num_callbacks,void *address);
extern void *im2_create_generic_isr_callee(uint16_t num_callbacks,void *address) __z88dk_callee;
#define im2_create_generic_isr(a,b) im2_create_generic_isr_callee(a,b)


extern void *im2_create_generic_isr_8080(uint16_t num_callbacks,void *address);
extern void *im2_create_generic_isr_8080_callee(uint16_t num_callbacks,void *address) __z88dk_callee;
#define im2_create_generic_isr_8080(a,b) im2_create_generic_isr_8080_callee(a,b)


extern void im2_append_generic_callback(uint16_t vector,void *callback);
extern void im2_append_generic_callback_callee(uint16_t vector,void *callback) __z88dk_callee;
#define im2_append_generic_callback(a,b) im2_append_generic_callback_callee(a,b)


extern void im2_prepend_generic_callback(uint16_t vector,void *callback);
extern void im2_prepend_generic_callback_callee(uint16_t vector,void *callback) __z88dk_callee;
#define im2_prepend_generic_callback(a,b) im2_prepend_generic_callback_callee(a,b)


extern int im2_remove_generic_callback(uint16_t vector,void *callback);
extern int im2_remove_generic_callback_callee(uint16_t vector,void *callback) __z88dk_callee;
#define im2_remove_generic_callback(a,b) im2_remove_generic_callback_callee(a,b)



extern void z80_delay_ms(uint16_t ms);
extern void z80_delay_ms_fastcall(uint16_t ms) __z88dk_fastcall;
#define z80_delay_ms(a) z80_delay_ms_fastcall(a)


extern void z80_delay_tstate(uint16_t tstates);
extern void z80_delay_tstate_fastcall(uint16_t tstates) __z88dk_fastcall;
#define z80_delay_tstate(a) z80_delay_tstate_fastcall(a)


extern uint16_t z80_get_int_state(void);


extern void z80_set_int_state(uint16_t state);
extern void z80_set_int_state_fastcall(uint16_t state) __z88dk_fastcall;
#define z80_set_int_state(a) z80_set_int_state_fastcall(a)



extern uint8_t z80_inp(uint16_t port);
extern uint8_t z80_inp_fastcall(uint16_t port) __z88dk_fastcall;
#define z80_inp(a) z80_inp_fastcall(a)


extern void *z80_inir(void *dst,uint16_t port);
extern void *z80_inir_callee(void *dst,uint16_t port) __z88dk_callee;
#define z80_inir(a,b) z80_inir_callee(a,b)


extern void *z80_indr(void *dst,uint16_t port);
extern void *z80_indr_callee(void *dst,uint16_t port) __z88dk_callee;
#define z80_indr(a,b) z80_indr_callee(a,b)


extern void z80_outp(uint16_t port,uint16_t data);
extern void z80_outp_callee(uint16_t port,uint16_t data) __z88dk_callee;
#define z80_outp(a,b) z80_outp_callee(a,b)


extern void *z80_otir(void *src,uint16_t port);
extern void *z80_otir_callee(void *src,uint16_t port) __z88dk_callee;
#define z80_otir(a,b) z80_otir_callee(a,b)


extern void *z80_otdr(void *src,uint16_t port);
extern void *z80_otdr_callee(void *src,uint16_t port) __z88dk_callee;
#define z80_otdr(a,b) z80_otdr_callee(a,b)



#define z80_bpoke(a,b)  (*(unsigned char *)(a) = b)
#define z80_wpoke(a,b)  (*(unsigned int *)(a) = b)
#define z80_lpoke(a,b)  (*(unsigned long *)(a) = b)

#define z80_bpeek(a) (*(unsigned char *)(a))
#define z80_wpeek(a) (*(unsigned int *)(a))
#define z80_lpeek(a) (*(unsigned long *)(a))

#endif
