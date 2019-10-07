#ifndef _KERNEL_TIME_TIMEKEEPING_H
#define _KERNEL_TIME_TIMEKEEPING_H
/*
 * Internal interfaces for kernel/time/
 */
extern ktime_t ktime_get_update_offsets_now(unsigned int *cwsseq,
					    ktime_t *offs_real,
					    ktime_t *offs_boot,
					    ktime_t *offs_tai);

extern int timekeeping_valid_for_hres(void);
extern u64 timekeeping_max_deferment(void);
extern int timekeeping_inject_offset(struct timespec *ts);
extern s32 timekeeping_get_tai_offset(void);
extern void timekeeping_set_tai_offset(s32 tai_offset);
extern int timekeeping_suspend(void);
extern void timekeeping_resume(void);

extern void do_timer(unsigned long ticks);
extern void update_wall_time(void);

extern raw_spinlock_t jiffies_lock;
extern seqcount_t jiffies_seq;

#define CS_NAME_LEN	32

#endif
