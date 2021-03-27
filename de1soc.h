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

#define TIMER1_BASE (PERIPH_BASE +0x2000) /* Base of Interval Timer 1 */
#define TIMER2_BASE (PERIPH_BASE +0x2020) /* Base of Interval Timer 2 */
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

#endif
