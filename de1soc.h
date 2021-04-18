/*
 *  File: de1soc.h
 *
 *   This header file is for use with the CPUlator simulation of a DE1 SOC
 *   board using an ARM Cortex-A9 processor. All of the relevant definitions
 *   are provided as a single header file so it can be easily included in
 *   C code that is compiled using Godbolt's Compiler Explorer.
 *
 *    Author: K. J. Hass
 *    Created: 2020-01-28
 *    Last Modified: 2020-01-28
 *
 */
#ifndef __DE1SOC_H__
#define __DE1SOC_H__

/* #include <stdint.h */
/*
   Fixed-size types, underlying types depend on word size and compiler.
   These are appropriate for the ARMv7 architecture.
*/
typedef signed char        int8_t;
typedef unsigned char      uint8_t;
typedef signed short int   int16_t;
typedef unsigned short int uint16_t;
typedef signed int         int32_t;
typedef unsigned int       uint32_t;
typedef signed long int    int64_t;
typedef unsigned long int  uint64_t;

/*
   From ARM CMSIS headers
   All I/O device registers are defined as volatile. Read-only registers
   are also defined as const so we can't write to them.
*/
#define  __I   volatile const /* Defines 'read only' permissions      */
#define  __O   volatile       /* Defines 'write only' permissions     */
#define  __IO  volatile       /* Defines 'read / write' permissions   */

/*
   Define the fixed address for the peripherals that are supported by the
   CPUlator simulation of an Altera (Intel) DE1 SOC board.
*/
#define PERIPH_BASE ((uint32_t)0xFF200000)  /* Peripherals start address */

#define LEDS_BASE   (PERIPH_BASE +0x0000)   /* Base of LEDs registers */
/******************************************************************************
* LEDS Registers
******************************************************************************/
typedef struct {
  __IO uint32_t Data;      /* Write 1 to turn on an LED */
} LEDS_Type;

#define LEDS              ((LEDS_Type *) LEDS_BASE)   

#define DISP7SEG_BASE     (PERIPH_BASE +0x0020) /* Base of display registers */
/******************************************************************************
* DISP7SEG Registers
******************************************************************************/
typedef struct {
  __IO uint32_t Digits3to0;     /* Eight bits for each digit */
  __I  uint32_t DUMMY0;         /* Unused address            */
  __I  uint32_t DUMMY1;         /* Unused address            */
  __I  uint32_t DUMMY2;         /* Unused address            */
  __IO uint32_t Digits7to4;     /* Eight bits for each digit */
} DISP7SEG_Type;

#define DISP7SEG           ((DISP7SEG_Type *) DISP7SEG_BASE)   
/******************************************************************************
* DISP7SEG Constants
******************************************************************************/
#define DIGIT0_OFS    0
#define DIGIT1_OFS    8
#define DIGIT2_OFS   16
#define DIGIT3_OFS   24
#define DIGIT4_OFS    0
#define DIGIT5_OFS    8
#define DIGIT6_OFS   16
#define DIGIT7_OFS   24
#define DIGIT_MSK    0x7F
#define DIGIT0_MSK   ((uint32_t)(DIGIT_MSK << DIGIT0_Pos))
#define DIGIT1_MSK   ((uint32_t)(DIGIT_MSK << DIGIT1_Pos))
#define DIGIT2_MSK   ((uint32_t)(DIGIT_MSK << DIGIT2_Pos))
#define DIGIT3_MSK   ((uint32_t)(DIGIT_MSK << DIGIT3_Pos))
#define DIGIT4_MSK   ((uint32_t)(DIGIT_MSK << DIGIT4_Pos))
#define DIGIT5_MSK   ((uint32_t)(DIGIT_MSK << DIGIT5_Pos))
#define DIGIT6_MSK   ((uint32_t)(DIGIT_MSK << DIGIT6_Pos))
#define DIGIT7_MSK   ((uint32_t)(DIGIT_MSK << DIGIT7_Pos))

#define SWITCHES_BASE   (PERIPH_BASE +0x0040) /* Base of switches registers */
/******************************************************************************
* SWITCHES Registers
******************************************************************************/
typedef struct {
  __I uint32_t Data;         /* Read state of each switch */
} SWITCHES_Type;

#define SWITCHES             ((SWITCHES_Type *) SWITCHES_BASE)   

#define PBUTTONS_BASE   (PERIPH_BASE +0x0050) /* Base of switches registers */
/******************************************************************************
* PBUTTONS Registers
******************************************************************************/
typedef struct {
  __IO uint32_t Data;        /* Read/write each button                */
  __IO uint32_t Direction;   /* Set to 1 for output mode, 0 for input */
  __IO uint32_t IntrMsk;      /* Set to 1 to enable interrupt          */
  __IO uint32_t EdgeCapture;   /* Captures rising events in buttons     */
} PBUTTONS_Type;

#define PBUTTONS                  ((PBUTTONS_Type *) PBUTTONS_BASE)   
/******************************************************************************
* PBUTTONS Constants
******************************************************************************/
#define PBUTTONS_IRQ    73

#define JP1_BASE   (PERIPH_BASE +0x0060) /* Base of JP1 registers */
/******************************************************************************
* JP1 Registers
******************************************************************************/
typedef struct {
  __IO uint32_t Data;        /* Read/write each button                */
  __IO uint32_t Direction;   /* Set to 1 for output mode, 0 for input */
  __IO uint32_t IntrMsk;      /* Set to 1 to enable interrupt          */
  __IO uint32_t EdgeCapture;   /* Captures rising events in buttons     */
} JP1_Type;

#define JP1                  ((JP1_Type *) JP1_BASE)   
/******************************************************************************
* JP1 Constants
******************************************************************************/
#define JP1_IRQ    11

#define JP2_BASE   (PERIPH_BASE +0x0070) /* Base of JP2 registers */
/******************************************************************************
* JP2 Registers
******************************************************************************/
typedef struct {
  __IO uint32_t Data;        /* Read/write each button                */
  __IO uint32_t Direction;   /* Set to 1 for output mode, 0 for input */
  __IO uint32_t IntrMsk;     /* Set to 1 to enable interrupt          */
  __IO uint32_t EdgeCapture; /* Captures rising events in buttons     */
} JP2_Type;

#define JP2                  ((JP2_Type *) JP2_BASE)   
/******************************************************************************
* JP2 Constants
******************************************************************************/
#define JP2_IRQ    12

#define TIMER1_BASE (PERIPH_BASE+0x2000) /* Base of Interval Timer 1 */
#define TIMER2_BASE (PERIPH_BASE+0x2020) /* Base of Interval Timer 2 */
/******************************************************************************
* Interval Timer Registers
******************************************************************************/
typedef struct {
  __IO uint32_t Status;       /* RUN and TO status bits              */
  __IO uint32_t Control;      /* STOP, START, CONT, ITO control bits */
  __IO uint32_t StartLow;     /* Low half-word of start value        */
  __IO uint32_t StartHigh;    /* High half-word of start value       */
  __IO uint32_t SnapshotLow;  /* Low half-word of timer snapshot     */
  __IO uint32_t SnapshotHigh; /* High half-word of timer snapshot    */
} Timer_Type;

#define Timer1               ((Timer_Type *) TIMER1_BASE)   
#define Timer2               ((Timer_Type *) TIMER2_BASE)   
/******************************************************************************
* Interval Timer Constants
******************************************************************************/
#define TIMER1_IRQ    72
#define TIMER2_IRQ    74
#define TIMEOUT       (1 << 0)
#define RUN           (1 << 1)
#define INTERRUPTTO   (1 << 0)
#define CONTINUOUS    (1 << 1)
#define START         (1 << 2)
#define STOP          (1 << 3)

#define UART_BASE (PERIPH_BASE+0x1000) /* Base of UART */
/******************************************************************************
* UART Registers
******************************************************************************/
typedef struct {
  __IO uint32_t Data;
  __IO uint32_t Control;
} UART_Type;

#define UART               ((UART_Type *) UART_BASE)   
/******************************************************************************
* UART Constants
******************************************************************************/
#define UART_IRQ      80
#define DATA_MSK      (0xFF << 0)
#define RVALID        (1 << 15)
#define RAVAIL_MSK    (0xFF << 16)
#define RCV_INT_ENBL  (1 << 0)
#define WRT_INT_ENBL  (1 << 1)
#define RCV_INT_PEND  (1 << 8)
#define WRT_INT_PEND  (1 << 9)
#define AC            (1 << 10)
#define WSPACE_MSK    (0xFF << 16)


#define GIC_INTERFACE_BASE   (0xFFFEC100)
#define GIC_DISTRIBUTOR_BASE (0xFFFED000)

/**************************************************************************//**
 * @file     core_ca.h
 * @brief    CMSIS Cortex-A Core Peripheral Access Layer Header File
 * @version  V1.0.3
 * @date     28. January 2020
 ******************************************************************************/
/*
 * Copyright (c) 2009-2020 ARM Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define RESERVED(N, T) T RESERVED##N; // placeholder for "reserved" areas

/*
   Structure type to access the Generic Interrupt Controller Distributor (GICD)
*/
typedef struct
{
  __IO uint32_t CTLR;            // Distributor Control Register
  __I  uint32_t TYPER;           // Interrupt Controller Type Register
  __I  uint32_t IIDR;            // Distributor Implementer ID Register
  RESERVED(0, uint32_t)
  __IO uint32_t STATUSR;         // Error Reporting Status Register, optional
  RESERVED(1[11], uint32_t)
  __O  uint32_t SETSPI_NSR;      // Set SPI Register
  RESERVED(2, uint32_t)
  __O  uint32_t CLRSPI_NSR;      // Clear SPI Register
  RESERVED(3, uint32_t)
  __O  uint32_t SETSPI_SR;       // Set SPI, Secure Register
  RESERVED(4, uint32_t)
  __O  uint32_t CLRSPI_SR;       // Clear SPI, Secure Register
  RESERVED(5[9], uint32_t)
  __IO uint32_t IGROUPR[32];     // Interrupt Group Registers
  __IO uint32_t ISENABLER[32];   // Interrupt Set-Enable Registers
  __IO uint32_t ICENABLER[32];   // Interrupt Clear-Enable Registers
  __IO uint32_t ISPENDR[32];     // Interrupt Set-Pending Registers
  __IO uint32_t ICPENDR[32];     // Interrupt Clear-Pending Registers
  __IO uint32_t ISACTIVER[32];   // Interrupt Set-Active Registers
  __IO uint32_t ICACTIVER[32];   // Interrupt Clear-Active Registers
  __IO uint32_t IPRIORITYR[255]; // Interrupt Priority Registers
  RESERVED(6, uint32_t)
  __IO uint32_t ITARGETSR[255];  // Interrupt Targets Registers
  RESERVED(7, uint32_t)
  __IO uint32_t ICFGR[64];       // Interrupt Configuration Registers
  __IO uint32_t IGRPMODR[32];    // Interrupt Group Modifier Registers
  RESERVED(8[32], uint32_t)
  __IO uint32_t NSACR[64];       // Non-secure Access Control Registers
  __O  uint32_t SGIR;            // Software Generated Interrupt Register
  RESERVED(9[3], uint32_t)
  __IO uint32_t CPENDSGIR[4];    // SGI Clear-Pending Registers
  __IO uint32_t SPENDSGIR[4];    // SGI Set-Pending Registers
  __IO uint64_t IROUTER[988];    // Interrupt Routing Registers
}  GICDistributor_Type;

//GIC Distributor register set access pointer
#define GICDistributor ((GICDistributor_Type *) GIC_DISTRIBUTOR_BASE )

/*
   Structure type to access the Generic Interrupt Controller Interface (GICC)
*/
typedef struct
{
  __IO uint32_t CTLR;         // CPU Interface Control Register
  __IO uint32_t PMR;          // Interrupt Priority Mask Register
  __IO uint32_t BPR;          // Binary Point Register
  __I  uint32_t IAR;          // Interrupt Acknowledge Register
  __O  uint32_t EOIR;         // End Of Interrupt Register
  __I  uint32_t RPR;          // Running Priority Register
  __I  uint32_t HPPIR;        // Highest Priority Pending Interrupt Register
  __IO uint32_t ABPR;         // Aliased Binary Point Register
  __I  uint32_t AIAR;         // Aliased Interrupt Acknowledge Register
  __O  uint32_t AEOIR;        // Aliased End Of Interrupt Register
  __I  uint32_t AHPPIR;       // Aliased Highest Priority Pending Interrupt Reg
  __IO uint32_t STATUSR;      // Error Reporting Status Register, optional
  RESERVED(1[40], uint32_t)
  __IO uint32_t APR[4];       // Active Priority Register
  __IO uint32_t NSAPR[4];     // Non-secure Active Priority Register
  RESERVED(2[3], uint32_t)
  __I  uint32_t IIDR;         // CPU Interface Identification Register
  RESERVED(3[960], uint32_t)
  __O  uint32_t DIR;          // Deactivate Interrupt Register
}  GICInterface_Type;

//GIC Interface register set access pointer
#define GICInterface ((GICInterface_Type *) GIC_INTERFACE_BASE )
#endif
