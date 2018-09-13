/**
 * @file      platform.h
 * @author    Atakan S.
 * @date      01/01/2018
 * @version   1.0
 * @brief     Provides MCU/platform specific definitions and macros.
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

#ifndef _H_PLATFORM
#define _H_PLATFORM
    
// Includes.
#include "stm32f10x.h"

// General purpose macros.
#ifdef  WATCHDOG_ENABLED
#define mKickWatchdog()				IWDG_ReloadCounter()					///< MCU-specific watchdog reset function.
#else
#define mKickWatchdog()														///< Watchdog is disabled.
#endif
#define mNop()              		__NOP()									///< MCU/compiler specific Nop instruction
#define mIntEnable()        		__enable_irq()							///< MCU/compiler specific
#define mIntDisable()       		__disable_irq()							///< MCU/compiler specific
#define mIsIntEnabled()     		((__get_PRIMASK() & 0x01) == 0)			///< Check if IntEn before disabling
#define mEnterCritical()			mIntDisable()							///< Alias for mIntDisable()
#define mExitCritical()				mIntEnable()							///< Alias for mIntEnable()

// MCU Specific definitions and macros.
#define PINMODE_10MHz 				(0x1ul)									///< MCU specific I/O speed.
#define PINMODE_02MHz 				(0x2ul)									///< MCU specific I/O speed.
#define PINMODE_50MHz 				(0x3ul)									///< MCU specific I/O speed.
#define PINMODE_ANA					(0x0ul)									///< MCU specific I/O mode ANALOG
#define PINMODE_INP					(0x4ul)									///< MCU specific I/O mode INPUT
#define PINMODE_OUT					(0x0ul+PINMODE_02MHz)					///< MCU specific I/O mode OUTPUT
#define PINMODE_ALT					(0x8ul+PINMODE_02MHz)					///< MCU specific I/O mode ALTERNATIVE

// Pin macros (dynamic use)
#define mPinNum_(port, pin) 		pin                             		///< Get pin number/code.
#define mPinPort_(port, pin) 		port                            		///< Get port handle.
#define mPinMode_(port, pin, mode) 	((&port->CRL)[pin>=8])=((((&port->CRL)[pin>=8]))&(~(0x0000000F<<((pin&0x07)<<2))))|(mode<<((pin&0x07)<<2));///< Set I/O mode.
#define mPinOutput_(port, pin)		mPinMode_(port,pin,PINMODE_OUT) 		///< Make I/O output.
#define mPinInput_(port, pin)		mPinMode_(port,pin,PINMODE_INP) 		///< Make I/O input.
#define mPinAnalog_(port, pin)		mPinMode_(port,pin,PINMODE_ANA) 		///< Make I/O analog.
#define mPinAlternate_(port, pin)	mPinMode_(port,pin,PINMODE_ALT) 		///< Make I/O alternative.
#define mPinRead_(port, pin)      	(((port->IDR)>>pin)&0x0001)     		///< Read I/O value.
#define mPinWrite_(port, pin, val) 	((&port->BSRR)[val==0])=(0x0001<<pin);	///< Write I/O value.

// Pin macros (PORTA,0 compatible)
#define mPinNum(portpin)			mPinNum_(portpin)               		///< Get pin number/code.
#define mPinPort(portpin)			mPinPort_(portpin)              		///< Get port handle
#define mPinMode(portpin, mode)		mPinMode_(portpin,mode)         		///< Set I/O mode.
#define mPinOutput(portpin)			mPinOutput_(portpin)            		///< Make I/O output.
#define mPinInput(portpin)			mPinInput_(portpin)             		///< Make I/O input.
#define mPinAnalog(portpin)			mPinAnalog_(portpin)            		///< Make I/O analog.
#define mPinAlternate(portpin)		mPinAlternate_(portpin)         		///< Make I/O alternative.
#define mPinRead(portpin)       	mPinRead_(portpin)              		///< Read I/O value.
#define mPinWrite(portpin, val) 	mPinWrite_(portpin,val)         		///< Write I/O value.

#endif
