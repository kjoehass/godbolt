/*
   A little program to demonstrate programming the DE1 SOC board in C.
*/
#include <https://raw.githubusercontent.com/kjoehass/godbolt/main/de1soc.h>

int main(void)
{
    int HEX_bits = 0x0F;
    int SW_value;
    volatile int delay_count;

    while (1)
    {
        /* Read the value of the slide switches and display on the LEDs */
        SW_value = SWITCHES->Data;
        LEDS->Data = SW_value;

        /* If a pushbutton is pressed, use the value of the switches as
           the new pattern for the 7-segment displays. */
        if (PBUTTONS->Data != 0)
        {
            HEX_bits = SW_value;
            while (PBUTTONS->Data != 0);
        }
        DISP7SEG->Digits3to0 = HEX_bits;

        /* Rotate the pattern on the hex displays */
        if (HEX_bits & 0x80000000)
            HEX_bits = (HEX_bits << 1) | 1;
        else
            HEX_bits = HEX_bits << 1;

        /* Wait a bit so the human can see what we did. */
        for (delay_count = 50; delay_count != 0; --delay_count);
    }
}
