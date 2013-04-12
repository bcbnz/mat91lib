/** @file   pit.h
    @author M. P. Hayes, UCECE
    @date   3 June 2007
    @brief 
*/
#ifndef PIT_H
#define PIT_H

#include "config.h"

/* This is fixed.  */
#define PIT_CLOCK_DIVISOR 16

/** Rate in Hz that the pit is incremented.  */
#define PIT_RATE (F_CPU / PIT_CLOCK_DIVISOR)


/** The maximum overrun period (s).  */
#define PIT_OVERRUN_PERIOD 10


/** The maximum overrun (in ticks).  */
#define PIT_OVERRUN_MAX (PIT_OVERRUN_PERIOD * PIT_RATE)


/** The maximum delay (in ticks).  */
#define PIT_DELAY_MAX (~0u - PIT_OVERRUN_MAX + 1)


/** Define pit ticks.  */
typedef uint32_t pit_tick_t;


/** Get current time:
    @return current time in ticks.  */
pit_tick_t pit_get (void);


/** Wait until specified time:
    @param when time to sleep until
    @return current time.  */
pit_tick_t pit_wait_until (pit_tick_t when);


/** Wait for specified period:
    @param period how long to wait
    @return current time.  */
pit_tick_t pit_wait (pit_tick_t period);


/** Initialise pit.  */
int pit_init (void);

#endif
