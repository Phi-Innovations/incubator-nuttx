/****************************************************************************
 * drivers/timers/pcf8563.h
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __DRIVERS_TIMERS_PCF8563_H
#define __DRIVERS_TIMERS_PCF8563_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/compiler.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* RTC time and date registers */

#define PCF8563_RTC_CTRL_STATUS1          0x00      /* RTC Control Status 1 register */
                                                    /* Bits 7: TEST1 */
                                                    /* Bits 5: STOP */
                                                    /* Bits 3: TESTC */

#define PCF8563_RTC_CTRL_STATUS2          0x01      /* RTC Control Status 2 register */
                                                    /* Bits 4: TI_TP */
                                                    /* Bits 3: AF */
                                                    /* Bits 2: TF */
                                                    /* Bits 1: AIE */
                                                    /* Bits 0: TIE */

#define PCF8563_RTC_SECONDS               0x02      /* RTC seconds register */
#  define PCF8563_RTC_SECONDS_MASK        (0x7f)    /* Bits 0-6: Seconds (0-59 BCD) */
#  define PCF8563_RTC_SECONDS_VL          (1 << 7)  /* Bit 7: Valid Bit */

#define PCF8563_RTC_MINUTES               0x03      /* RTC minutes register */
#  define PCF8563_RTC_MINUTES_MASK        (0x7f)    /* Bits 0-6: Minutes (0-59 BCD) */
#  define PCF8563_RTC_MINUTES_EMON        (1 << 7)  /* Bit 7: Event monitor */

#define PCF8563_RTC_HOURS                 0x04      /* RTC hours register */
#  define PCF8563_RTC_HOURS12_MASK        0x1f      /* Bits 0-4: Hours (1-12 BCD) */
#  define PCF8563_RTC_AMPM                (1 << 5)  /* Bit 5: AM/PM */
#  define PCF8563_RTC_HOURS24_MASK        0x3f      /* Bits 0-5: Hours (0-23  BCD) */

#define PCF8563_RTC_DAYS                  0x05      /* RTC days register */
#  define PCF8563_RTC_DAYS_MASK           0x3f      /* Bit 0-5: Day of the month (1-31 BCD) */

#define PCF8563_RTC_WEEKDAYS              0x06      /* RTC day-of-week register */
#  define PCF8563_RTC_WEEKDAYS_MASK       0x07      /* Bits 0-2: Day of the week (0-6) */

#define PCF8563_RTC_MONTHS                0x07      /* RTC month register */
#  define PCF8563_RTC_CENTURY             (1 << 7)  /* Bit 7: Century */
#  define PCF8563_RTC_MONTHS_MASK         0x1f      /* Bits 0-4: Month (1-12 BCD) */

#define PCF8563_RTC_YEARS                 0x08      /* RTC year register */
                                                    /* Bits 0-7: Year (0-99 BCD) */

/* RTC alarm */

#define PCF8563_RTC_MINUTE_ALARM          0x09      /* RTC alarm minutes register */
#define PCF8563_RTC_MINUTE_ALARM_E        (1 << 7)  /* Bit 7: RTC alarm minutes enable bit */
#  define PCF8563_RTC_MINUTE_ALARM_MASK   0x7f      /* Bits 0-6:  Minutes (0-59 BCD) */
 
#define PCF8563_RTC_HOUR_ALARM            0x0a      /* RTC alarm hours register */
#define PCF8563_RTC_HOUR_ALARM_E          (1 << 7)  /* Bit 7: RTC alarm hours enable bit */
#  define PCF8563_RTC_HOURS12_ALARM_MASK  0x1f      /* Bits 0-4: Hours (1-12 BCD) */
#  define PCF8563_RTC_AMPM_ALARM          (1 << 5)  /* Bit 5: AM/PM */
#  define PCF8563_RTC_HOURS24_ALARM_MASK  0x3f      /* Bits 0-5: Hours (0-23  BCD) */
 
#define PCF8563_RTC_DAY_ALARM             0x0b      /* RTC alarm days register */
#define PCF8563_RTC_DAY_ALARM_E           (1 << 7)  /* Bit 7: RTC alarm days enable bit */
#  define PCF8563_RTC_DAY_ALARM_MASK      0x3f      /* Bits 0-5: Days (1-31 BCD) */
 
#define PCF8563_RTC_WEEK_ALARM            0x0c      /* RTC week register */
#define PCF8563_RTC_WEEK_ALARM_E          (1 << 7)  /* Bit 7: RTC week days enable bit */
#  define PCF8563_RTC_WEEK_ALARM_MASK     0x1f      /* Bits 0-2: Month (0-6 BCD) */

/* CLKOUT control registers */

#define PCF8563_CLKOUT_CONTROL            0x0d      /* Clock out control register */
#  define PCF8563_CLKOUT_FE               (1 << 7)  /* Bit 7: ClkOut FE Bit */
#  define PCF8563_CLKOUT_FD               0x03      /* Bit 0-1: ClkOut FD Bit */

/* Timer register */

#define PCF8563_TIMER_CONTROL             0x0e      /* Clock timer control register */
#  define PCF8563_TIMER_TE                (1 << 7)  /* Bit 7: Timer Control TE Bit */
#  define PCF8563_TIMER_TD                0x03      /* Bit 0-1: Timer Control TD */

#define PCF8563_TIMER                     0x0f      /* Clock timer register */

#endif /* __DRIVERS_TIMERS_PCF8563_H */
