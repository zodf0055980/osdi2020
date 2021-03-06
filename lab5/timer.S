#define CORE0_TIMER_IRQ_CTRL 0x40000040
#define EXPIRE_PERIOD 0xfffffff

.globl core_timer_enable
core_timer_enable:
  mov x0, #1
  msr cntp_ctl_el0, x0 // enable timer
  mov x0, EXPIRE_PERIOD
  msr cntp_tval_el0, x0  // set expired time
  mov x0, #2
  ldr x1, =CORE0_TIMER_IRQ_CTRL
  str x0, [x1] // enable timer interrupt
	ret


.globl core_timer_disable
core_timer_disable:
    mov x0, 0
    msr cntp_ctl_el0, x0
    mov x0, 0
    ldr x1, =CORE0_TIMER_IRQ_CTRL
    str x0, [x1]          // disable timer interrupt
    ret