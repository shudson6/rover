#ifndef __INCLUDE_ATMEGA328P_REGISTERS
#define __INCLUDE_ATMEGA328P_REGISTERS

#define SREG      (*((volatile unsigned char *) 0x5f))

/*******************************************************************************
 * I/O Ports
 ******************************************************************************/

/* Data Registers: PORTx */
#define PORTB     (*((volatile unsigned char *) 0x25))
#define PORTC     (*((volatile unsigned char *) 0x28))
#define PORTD     (*((volatile unsigned char *) 0x2b))

/* Data Direction Registers: DDRx */
#define DDRB      (*((volatile unsigned char *) 0x24))
#define DDRC      (*((volatile unsigned char *) 0x27))
#define DDRD      (*((volatile unsigned char *) 0x2a))

/* Port Input Registers: PINx */
#define PINB      (*((volatile unsigned char *) 0x23))
#define PINC      (*((volatile unsigned char *) 0x26))
#define PIND      (*((volatile unsigned char *) 0x29))

/* Pin Masks */
#define PIN0      0x01
#define PIN1      0x02
#define PIN2      0x04
#define PIN3      0x08
#define PIN4      0x10
#define PIN5      0x20
#define PIN6      0x40
#define PIN7      0x80

/* Bit Masks, if "PIN" doesn't make sense in context */
#define BIT0      0x01
#define BIT1      0x02
#define BIT2      0x04
#define BIT3      0x08
#define BIT4      0x10
#define BIT5      0x20
#define BIT6      0x40
#define BIT7      0x80

/*******************************************************************************
 * Timer/Counters
 ******************************************************************************/

/* General Timer/Counter Control Register (Datasheet p.214) */
#define GTCCR     (*((volatile unsigned char *) 0x43))
#define TSM       0x80
#define PSRASY    0x02
#define PSRSYNC   0x01

/*******************************************************************************
 * TC0 - 8-bit Timer/Counter 0 + PWM
 ******************************************************************************/

/* TC0 Control Register A (Datasheet p.138) */
#define TCCR0A	  (*((volatile unsigned char *) 0x44))
#define COM0A1    0x80
#define COM0A0    0x40
#define COM0B1    0x20
#define COM0B0    0x10
#define WGM01     0x02
#define WGM00     0x01

/* TC0 Control Register B (Datasheet p.141) */
#define TCCR0B    (*((volatile unsigned char *) 0x45))
#define FOC0A     0x80
#define FOCOB     0x40
#define WGM02     0x08
#define CS02      0x04
#define CS01      0x02
#define CS00      0x01

/* TC0 Interrupt Mask Register (Datasheet p.143) */
#define TIMSK0    (*((volatile unsigned char *) 0x6e))
#define OCIEB     0x04    /* Output Compare Match B Interrupt Enable */
#define OCIEA     0x02    /* Output Compare Match A Interrupt Enable */
#define TOIE      0x01    /* Overflow Interrupt Enable */

/* TC0 Interrupt Flag Register (Datasheet p.148) */
#define TIFR0     (*((volatile unsigned char *) 0x35))
#define OCFB      0x04    /* Output Compare B Match */
#define OCFA      0x02    /* Output Compare A Match */
#define TOV       0x01    /* Overflow */

/* TC0 Counter Value Register */
#define TCNT0     (*((volatile unsigned char *) 0x46))

/* TC0 Output Compare Registers */
#define OCR0A     (*((volatile unsigned char *) 0x47))
#define OCR0B     (*((volatile unsigned char *) 0x48))

/*******************************************************************************
 * Timer/Counter 2 with PWM and Aysnc Ops (8-bit) (Datasheet p.189)
 ******************************************************************************/

/* TC2 Control Register A (Datasheet p.203) */
#define TCCR2A    (*((volatile unsigned char *) 0xb0))
#define COM2A1    0x80
#define COM2A0    0x40
#define COM2B1    0x20
#define COM2B0    0x10
#define WGM21     0x02
#define WGM20     0x01

/* TC2 Control Register B (Datasheet p.206) */
#define TCCR2B    (*((volatile unsigned char *) 0xb1))
#define FOC2A     0x80
#define FOC2B     0x40
#define WGM22     0x08
#define CS22      0x04
#define CS21      0x02
#define CS20      0x01

/* TC2 Counter Value Register */
#define TCNT2     (*((volatile unsigned char *) 0xb2))

/* TC2 Output Compare Registers */
#define OCR2A     (*((volatile unsigned char *) 0xb3))
#define OCR2B     (*((volatile unsigned char *) 0xb4))

/* TC2 Interrupt Mask Register (Datasheet p.211) */
/* For bit position names, see TIMSK0 above */
#define TIMSK2    (*((volatile unsigned char *) 0x70))

/* TC2 Interrupt Flag Register (Datasheet p.212) */
/* For bit position names, see TIFR0 above */
#define TIFR2     (*((volatile unsigned char *) 0x37))

/* Asynchronous Status Register (Datasheet p.213) */
#define ASSR      (*((volatile unsigned char *) 0xb6))
#define EXCLK     0x40      /* external clock */
#define AS2       0x20
#define TCN2UB    0x10
#define OCR2AUB   0x08
#define OCR2BUB   0x04
#define TCR2AUB   0x02
#define TCR2BUB   0x01

/*******************************************************************************
 * Power Reduction Register
 ******************************************************************************/

#define PRR       (*((volatile unsigned char *) 0x64))
#define PRTWI0    0x80
#define PRTIM2    0x40
#define PRTIM0    0x20
#define PRTIM1    0x08
#define PRTSPI0   0x04
#define PRUSART0  0x02
#define PRADC     0x01


/*******************************************************************************
 * USART
 ******************************************************************************/

/* I/O Data Register 0 
 * This register reads from the receive buffer
 * and writes to the transmit buffer
 */
#define UDR0      (*((volatile unsigned char *) 0xc6))

/* Control and Status Register 0A */
#define UCSR0A    (*((volatile unsigned char *) 0xc0))
#define RXC0      0x80
#define TXC0      0x40
#define UDRE0     0x20
#define FE0       0x10
#define DOR0      0x08
#define UPE0      0x04
#define U2X0      0x02
#define MPCM0     0x01

/* Control and Status Register 0B */
#define UCSR0B    (*((volatile unsigned char *) 0xc1))
#define RXCIE0    0x80
#define TXCIE0    0x40
#define UDRIE0    0x20
#define RXEN0     0x10
#define TXEN0     0x08
#define UCSZ02    0x04
#define RXB80     0x02
#define TXB80     0x01

/* Control and Status Register 0C */
#define UCSR0C    (*((volatile unsigned char *) 0xc2))
#define UMSEL01   0x80
#define UMSEL00   0x40
#define UPM01     0x20
#define UPM00     0x10
#define USBS0     0x08
#define UCSZ01    0x04
#define UCSZ00    0x02
#define UDORD0    0x04
#define UCPHA0    0x02
#define UCPOL0    0x01

/* Baud Rate 0 Registers - Low, High */
#define UBRR0     (*((volatile unsigned int *) 0xc4))
#define UBRR0L    (*((volatile unsigned char *) 0xc4))
#define UBRR0H    (*((volatile unsigned char *) 0xc5))

#endif // __INCLUDE_ATMEGA328P_REGISTERS
