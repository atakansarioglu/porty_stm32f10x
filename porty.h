/**
 * @file      porty.h
 * @author    Atakan S.
 * @date      01/01/2018
 * @version   1.0
 * @brief     Provides general-purpose definitions and macros for the project.
 *
 * @copyright Copyright (c) 2018 Atakan SARIOGLU ~ www.atakansarioglu.com
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *  DEALINGS IN THE SOFTWARE.
 */

#ifndef _H_PORTY
#define _H_PORTY
    
// Includes.
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <platform.h>
#include <board.h>
#include <settings.h>
#include <project.h>

// Undefinitions.
#undef CLOCK_Hz
#undef CLOCK_kHz
#undef CLOCK_MHz

// Definitions.
#define CLOCK_Hz    				(CLOCK)						///< MCU clock in [Hz]
#define CLOCK_kHz   				(CLOCK_Hz/1000UL)			///< MCU clock in [kHz]
#define CLOCK_MHz   				(CLOCK_kHz/1000UL)			///< MCU clock in [MHz]

// Simple blocking delays.
#define mDelay_1cyc()				mNop();						///< 1cycle time delay.
#define mDelay_2cyc()				mDelay_1cyc();mDelay_1cyc();///< 2cycle time delay.
#define mDelay_4cyc()				mDelay_2cyc();mDelay_2cyc();///< 4cycle time delay.
#define mDelay_5cyc()				mDelay_4cyc();mDelay_1cyc();///< 5cycle time delay.
#define mDelay_8cyc()				mDelay_5cyc();mDelay_3cyc();///< 8cycle time delay.
#define mDelay_10cyc()				mDelay_5cyc();mDelay_5cyc();///< 10cycle time delay.

#endif
