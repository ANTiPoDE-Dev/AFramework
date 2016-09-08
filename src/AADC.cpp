#include "AADC.h"

#   if  (__HAS__ADC1__)
        extern volatile AFramework::AADC_w ADC_w __asm__("ADC_w") __attribute__((section("sfrs")));
        volatile AFramework::AADC AFramework::ADC(&ADC_w);
#   endif

AFramework::AADC::AADC(volatile AADC_w * reg) : m_reg(reg){
    /*  nulla da commentare                                                     */
}
            
AFramework::uint32 AFramework::AADC::read(const Channel ch) volatile{

    uint32 res = 0;
    
    m_reg->AD1CON1.REG = _ADxCON1_SSRC_MASK;
    m_reg->AD1CHS.REG  = static_cast<uint32>(ch) << _ADxCHS_CH0SA_POSITION;
    m_reg->AD1CSSL.REG = 0x0000;
    m_reg->AD1CON3.REG = 0x1F02;
    m_reg->AD1CON2.REG = 0x0000;
    m_reg->AD1CON1.SET = _ADxCON1_ADON_MASK;
    m_reg->AD1CON1.SET = _ADxCON1_SAMP_MASK;
    
    while(!(m_reg->AD1CON1.REG & _ADxCON1_DONE_MASK));
    
    res = m_reg->ADCxBUF[0x00].REG;
    
    m_reg->AD1CON1.CLR = _ADxCON1_ADON_MASK;
    
    return res;
}