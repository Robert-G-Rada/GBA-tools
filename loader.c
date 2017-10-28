int main()
{
    volatile unsigned int *wram = (volatile unsigned int *)0x03000000;
    volatile unsigned int *rom = (volatile unsigned int *)0x08000000;
    unsigned int separator = 0x06060606;
    
    while (1)
    {
        if (*rom == separator)
        {
            if (rom[1] == separator && rom[2] == separator)
            {
                rom = rom + 3;
                break;
            }
        }
        rom++;
    }
    
    while (1)
    {
        if (*rom == separator)
        {
            if (rom[1] == separator && rom[2] == separator)
            {
                break;
            }
        }
        
        *wram = *rom;
        wram++;
        rom++;
    }
    
    __asm("mov r1, #0x3000000");
    __asm("bx r1");
}
