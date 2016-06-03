#if   defined (__32MX270F256B__)

    TMR1_w = 0xBF800600
        .global TMR1_w
    TMR2_w = 0xBF800800
        .global TMR2_w
    TMR3_w = 0xBF800A00
        .global TMR3_w
    TMR4_w = 0xBF800C00
        .global TMR4_w
    TMR5_w = 0xBF800E00
        .global TMR5_w

#elif defined (__32MX270F256D__)

    TMR1_w = 0xBF800600
        .global TMR1_w
    TMR2_w = 0xBF800800
        .global TMR2_w
    TMR3_w = 0xBF800A00
        .global TMR3_w
    TMR4_w = 0xBF800C00
        .global TMR4_w
    TMR5_w = 0xBF800E00
        .global TMR5_w

#endif
	
PORTA_w = 0xBF886000
	.global PORTA_w
PORTB_w = 0xBF886100
	.global PORTB_w
PORTC_w = 0xBF886200
	.global PORTC_w
	
ADC_w = 0xBF809000
	.global ADC_w