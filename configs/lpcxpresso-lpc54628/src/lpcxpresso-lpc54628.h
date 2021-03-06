/****************************************************************************
 * configs/lpcxpresso-lpc54628/src/lpcxpresso-lpc54628.h
 *
 *   Copyright (C) 2017 Gregory Nutt. All rights reserved.
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

#ifndef _CONFIGS_LPCXPRESSO_LPC54628_SRC_LPCXPRESSO_LPC54628_H
#define _CONFIGS_LPCXPRESSO_LPC54628_SRC_LPCXPRESSO_LPC54628_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/compiler.h>

#include "lpc54_config.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define HAVE_I2CTOOL  1
#define HAVE_FT5x06   1

/* Do we need to register I2C drivers on behalf of the I2C tool? */

#if !defined(CONFIG_SYSTEM_I2CTOOL) || !defined(CONFIG_I2C_DRIVER) || \
    !defined(HAVE_I2C_MASTER_DEVICE)
#  undef HAVE_I2CTOOL
#endif

/* Do we need to register FT5x06 touch panel driver? */

#if !defined(CONFIG_INPUT_FT5X06) || !defined(CONFIG_LPC54_I2C2_MASTER) || \
    !defined(CONFIG_LPC54_GPIOIRQ)
#  undef HAVE_FT5x06
#endif

/* Indices into a sparse I2C array.  Used with lpc54_i2c_handle() */

#ifdef CONFIG_LPC54_I2C0_MASTER
#  define I2C0NDX  0
#  define I2C0CNT  1
#  define __I2C1NX 1
#else
#  define I2C0CNT  0
#  define __I2C1NX 0
#endif

#ifdef CONFIG_LPC54_I2C1_MASTER
#  define I2C1NDX  __I2C1NX
#  define I2C1CNT   1
#  define __I2C2NX (__I2C1NX + 1)
#else
#  define I2C1CNT  0
#  define __I2C2NX 0
#endif

#ifdef CONFIG_LPC54_I2C2_MASTER
#  define I2C2NDX  __I2C2NX
#  define I2C2CNT  1
#  define __I2C3NX (__I2C2NX + 1)
#else
#  define I2C2CNT  0
#  define __I2C3NX __I2C2NX
#endif

#ifdef CONFIG_LPC54_I2C3_MASTER
#  define I2C3NDX  __I2C3NX
#  define I2C3CNT  1
#  define __I2C4NX (__I2C3NX + 1)
#else
#  define I2C3CNT  0
#  define __I2C4NX __I2C3NX
#endif

#ifdef CONFIG_LPC54_I2C4_MASTER
#  define I2C4NDX  __I2C4NX
#  define I2C4CNT  1
#  define __I2C5NX (__I2C4NX + 1)
#else
#  define I2C4CNT  0
#  define __I2C5NX __I2C4NX
#endif

#ifdef CONFIG_LPC54_I2C5_MASTER
#  define I2C5NDX  __I2C5NX
#  define I2C5CNT  1
#  define __I2C6NX (__I2C5NX + 1)
#else
#  define I2C5CNT  0
#  define __I2C6NX __I2C5NX
#endif

#ifdef CONFIG_LPC54_I2C6_MASTER
#  define I2C6NDX  __I2C6NX
#  define I2C6CNT  1
#  define __I2C7NX (__I2C6NX + 1)
#else
#  define I2C6CNT  0
#  define __I2C7NX __I2C6NX
#endif

#ifdef CONFIG_LPC54_I2C7_MASTER
#  define I2C7NDX  __I2C7NX
#  define I2C7CNT  1
#  define __I2C8NX (__I2C7NX + 1)
#else
#  define I2C7CNT  0
#  define __I2C8NX __I2C7NX
#endif

#ifdef CONFIG_LPC54_I2C8_MASTER
#  define I2C8NDX   __I2C8NX
#  define I2C8CNT  1
#  define __I2C9NX (__I2C8NX + 1)
#else
#  define I2C8CNT  0
#  define __I2C9NX __I2C8NX
#endif

#ifdef CONFIG_LPC54_I2C9_MASTER
#  define I2CNDX   __I2C9NX
#  define I2C9CNT  1
#else
#  define I2C9CNT  0
#endif

#define NI2C (I2C0CNT + I2C1CNT + I2C2CNT + I2C3CNT + I2C4CNT + \
              I2C5CNT + I2C6CNT + I2C7CNT + I2C8CNT + I2C9CNT )

/* LED definitions **********************************************************/
/* The LPCXpress-LPC54628 has three user LEDs: D9, D11, and D12.  These
 * LEDs are for application use. They are illuminated when the driving
 * signal from the LPC546xx is low. The LEDs are driven by ports P2-2 (D9),
 * P3-3 (D11) and P3-14 (D12).
 */

#define GPIO_LED_D9 \
  (GPIO_PORT2 | GPIO_PIN2 | GPIO_VALUE_ONE | GPIO_OUTPUT | \
   GPIO_MODE_DIGITAL | GPIO_FILTER_OFF | GPIO_PUSHPULL | GPIO_PULLUP)

#define GPIO_LED_D11 \
  (GPIO_PORT3 | GPIO_PIN3 | GPIO_VALUE_ONE | GPIO_OUTPUT | \
   GPIO_MODE_DIGITAL | GPIO_FILTER_OFF | GPIO_PUSHPULL | GPIO_PULLUP)

#define GPIO_LED_D12 \
  (GPIO_PORT3 | GPIO_PIN14 | GPIO_VALUE_ONE | GPIO_OUTPUT | \
   GPIO_MODE_DIGITAL | GPIO_FILTER_OFF | GPIO_PUSHPULL | GPIO_PULLUP)

/* Button definitions *******************************************************/
/* The LPCXpresso has four switches:
 *
 *   SW2 ISP2         P0.6
 *   SW3 ISP1         P0.5
 *   SW4 ISP0         P0.4
 *   SW5 User Button  P1.1
 *
 * In all cased, the signal is low when the button is pressed.
 *
 * SW2, SW3, SW4 can be used to force the LPC546xx in to ISP boot modes.
 * After boot these buttons could be used as user buttons.  However, they are
 * not available when the on-board SRDRAM is used because P0.4, P0.5, and
 * P0.6 are also used as EMC_D2, EMC_D3, and EMC_D4, respectively.
 *
 * So SW5 is really the only button that that is generally available for
 * software usage.  When pressed, it will be sensed low.
 *
 * P1.1 is a Type D pin.
 */

#define GPIO_BUTTON_USER \
  (GPIO_PORT1 | GPIO_PIN1 | GPIO_INTBOTH | GPIO_MODE_DIGITAL | GPIO_FILTER_ON)

/* LCD/TSC definitions ******************************************************/
/* The backlight is controlled by P3.31 and is intended to connect via PWM
 * to control the brightness level.  For simplicity here, it configured as a
 * simple GPIO output.
 *
 * The output goes to the enable (EN) pin of a AP5724 step-up DC/DC
 * converter designed to drive white LEDs with a constant current.  A high
 * input at EN turns the converter on, and a low input turns it off.
 */

#define GPIO_LCD_BL \
  (GPIO_PORT3 | GPIO_PIN31 | GPIO_VALUE_ZERO | GPIO_OUTPUT | \
   GPIO_MODE_DIGITAL | GPIO_FILTER_OFF | GPIO_PUSHPULL | GPIO_PULLUP)

/* The integrated touchscreen uses one GPIO out and one GPIO interrupting
 * GPIO input:
 *
 *   P2.27  CT_RSTn  Active low
 *   P4.0   INTR     On falling edge, I belieive
 *
 * The FT4x06's WAKE-UP interrupt pin is not brought out.
 */

#define GPIO_FT5x06_CTRSTn \
  (GPIO_PORT2 | GPIO_PIN27 | GPIO_VALUE_ZERO | GPIO_OUTPUT | \
   GPIO_MODE_DIGITAL | GPIO_FILTER_OFF | GPIO_PUSHPULL | GPIO_PULLUP)

#define GPIO_FT5x06_INTR \
  (GPIO_PORT4 | GPIO_PIN20 | GPIO_INTFE | GPIO_MODE_DIGITAL | GPIO_FILTER_OFF)

/* I2C addresses (7-bit): */

#define CODEC_I2C_ADDRESS   0x1a
#define ACCEL_I2C_ADDRESS   0x1d
#define FT5x06_I2C_ADDRESS  0x38

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public data
 ****************************************************************************/

#ifndef __ASSEMBLY__

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: lpc54_bringup
 *
 * Description:
 *   Perform architecture-specific initialization
 *
 *   CONFIG_BOARD_INITIALIZE=y :
 *     Called from board_initialize().
 *
 *   CONFIG_BOARD_INITIALIZE=n && CONFIG_LIB_BOARDCTL=y :
 *     Called from the NSH library
 *
 ****************************************************************************/

int lpc54_bringup(void);

/****************************************************************************
 * Name: lpc54_sdram_initialize
 *
 * Description:
 *   Initialize external SDRAM
 *
 ****************************************************************************/

#ifdef CONFIG_LPC54_EMC
void lpc54_sdram_initialize(void);
#endif

/****************************************************************************
 * Name: lpc54_lcd_initialize
 *
 * Description:
 *   Initialize the LCD.  Setup backlight (initially off)
 *
 ****************************************************************************/

void lpc54_lcd_initialize(void);

/****************************************************************************
 * Name: lpc54_i2ctool
 *
 * Description:
 *   Register I2C drivers for the I2C tool.
 *
 ****************************************************************************/

#ifdef HAVE_I2CTOOL
void lpc54_i2ctool(void);
#endif

/****************************************************************************
 * Name: lpc54_ft5x06_register
 *
 * Description:
 *   Register the FT5x06 touch panel driver
 *
 ****************************************************************************/

#ifdef HAVE_FT5x06
int lpc54_ft5x06_register(void);
#endif

/****************************************************************************
 * Name: lpc54_i2c_handle
 *
 * Description:
 *   Create (or reuse) an I2C handle
 *
 ****************************************************************************/

#if defined(HAVE_I2CTOOL) || defined(HAVE_FT5x06)
FAR struct i2c_master_s *lpc54_i2c_handle(int bus, int ndx);
#endif

/****************************************************************************
 * Name: lpc54_i2c_free
 *
 * Description:
 *   Free an I2C handle created by lpc54_i2c_handle
 *
 ****************************************************************************/

#if defined(HAVE_I2CTOOL) || defined(HAVE_FT5x06)
void lpc54_i2c_free(int ndx);
#endif

#endif /* __ASSEMBLY__ */
#endif /* _CONFIGS_LPCXPRESSO_LPC54628_SRC_LPCXPRESSO_LPC54628_H */
