// Type your code here, or load an example.
int main(void)
{
    volatile int * LED_ptr       = (int *)(0xFF200000);
    volatile int * HEX3_HEX0_ptr = (int *)(0xFF200020);
    volatile int * SW_switch_ptr = (int *)(0xFF200040);
    volatile int * KEY_ptr       = (int *)(0xFF200050);

    int HEX_bits = 0x0F;
    int SW_value;
    volatile int delay_count;

    while (1)
    {
        SW_value = *SW_switch_ptr;
        *(LED_ptr) = SW_value;

        if (*KEY_ptr != 0)
        {
            HEX_bits = SW_value;
            while (*KEY_ptr != 0);
        }
        *(HEX3_HEX0_ptr) = HEX_bits;

        /* rotate the pattern on the hex displays */
        if (HEX_bits & 0x80000000)
            HEX_bits = (HEX_bits << 1) | 1;
        else
            HEX_bits = HEX_bits << 1;

        for (delay_count = 5000; delay_count != 0; --delay_count);
    }
}