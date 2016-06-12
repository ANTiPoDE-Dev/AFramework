/*******************************************************************************
*   @author:    Milazzo Giuseppe
*               Università KORE Enna
*   @e-mail:    milazzo.ga@gmail.com
*               info@antipode-dev.org
*******************************************************************************
*   Software Licence:
*******************************************************************************
*
*   This file is part of AFramework.
*
*   AFramework is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   AFramework is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with AFramework. If not, see <http://www.gnu.org/licenses/>.
*
*   Copyright 2015, 2016 Milazzo Giuseppe
*
*/

#ifndef AP32MX270F256D_H
#define AP32MX270F256D_H
/**
 * Generics Def
 */
#define __32MX__
#define __DEVCLASS1__
#define __HAS_TIMER1__                              0x00000001
#define __HAS_TIMER2__                              0x00000001
#define __HAS_TIMER3__                              0x00000001
#define __HAS_TIMER4__                              0x00000001
#define __HAS_TIMER5__                              0x00000001
#define __HAS__PORTA__                              0x00000001
#define __HAS__PORTB__                              0x00000001
#define __HAS__PORTC__                              0x00000001
#define __HAS__PORTD__                              0x00000000
#define __HAS__PORTE__                              0x00000000
#define __HAS__PORTF__                              0x00000000
#define __HAS__PORTG__                              0x00000000
#define __HAS__PORTH__                              0x00000000
#define __HAS__PORTJ__                              0x00000000
#define __HAS__PORTK__                              0x00000000
#define __PORTA_BITS__                              0x00000793   //0000 0111 1001 0011
#define __PORTB_BITS__                              0x0000EFAF   //1110 1111 1010 1111
#define __PORTC_BITS__                              0x000003FF   //0000 0011 1111 1111
#define __HAS_EXTOSC__                              0x00000000
/**
 * Timers
 */
#define _TxCON_ON_POSITION                          0x0000000F
#define _TxCON_ON_MASK                              0x00008000
#define _TxCON_ON_LENGTH                            0x00000001

#define _TxCON_SIDL_POSITION                        0x0000000D
#define _TxCON_SIDL_MASK                            0x00002000
#define _TxCON_SIDL_LENGTH                          0x00000001

#define _TxCON_TWDIS_POSITION                       0x0000000C
#define _TxCON_TWDIS_MASK                           0x00001000
#define _TxCON_TWDIS_LENGTH                         0x00000001

#define _TxCON_TWIP_POSITION                        0x0000000B
#define _TxCON_TWIP_MASK                            0x00000800
#define _TxCON_TWIP_LENGTH                          0x00000001

#define _TxCON_TGATE_POSITION                       0x00000007
#define _TxCON_TGATE_MASK                           0x00000080
#define _TxCON_TGATE_LENGTH                         0x00000001

#define _TxCON_16_TCKPS_POSITION                    0x00000004
#define _TxCON_16_TCKPS_MASK                        0x00000030
#define _TxCON_16_TCKPS_LENGTH                      0x00000002

#define _TxCON_32_TCKPS_POSITION                    0x00000004
#define _TxCON_32_TCKPS_MASK                        0x00000070
#define _TxCON_32_TCKPS_LENGTH                      0x00000003

#define _TxCON_T32_POSITION                         0x00000003
#define _TxCON_T32_MASK                             0x00000008
#define _TxCON_T32_LENGTH                           0x00000001

#define _TxCON_TSYNC_POSITION                       0x00000002
#define _TxCON_TSYNC_MASK                           0x00000004
#define _TxCON_TSYNC_LENGTH                         0x00000001

#define _TxCON_TCS_POSITION                         0x00000001
#define _TxCON_TCS_MASK                             0x00000002
#define _TxCON_TCS_LENGTH                           0x00000001
/**
 * Interrupt Controller
 */
#define _INTCON_INT0EP_POSITION                     0x00000000
#define _INTCON_INT0EP_MASK                         0x00000001
#define _INTCON_INT0EP_LENGTH                       0x00000001

#define _INTCON_INT1EP_POSITION                     0x00000001
#define _INTCON_INT1EP_MASK                         0x00000002
#define _INTCON_INT1EP_LENGTH                       0x00000001

#define _INTCON_INT2EP_POSITION                     0x00000002
#define _INTCON_INT2EP_MASK                         0x00000004
#define _INTCON_INT2EP_LENGTH                       0x00000001

#define _INTCON_INT3EP_POSITION                     0x00000003
#define _INTCON_INT3EP_MASK                         0x00000008
#define _INTCON_INT3EP_LENGTH                       0x00000001

#define _INTCON_INT4EP_POSITION                     0x00000004
#define _INTCON_INT4EP_MASK                         0x00000010
#define _INTCON_INT4EP_LENGTH                       0x00000001

#define _INTCON_TPC_POSITION                        0x00000008
#define _INTCON_TPC_MASK                            0x00000700
#define _INTCON_TPC_LENGTH                          0x00000003

#define _INTCON_MVEC_POSITION                       0x0000000C
#define _INTCON_MVEC_MASK                           0x00001000
#define _INTCON_MVEC_LENGTH                         0x00000001

#define _INTCON_SS0_POSITION                        0x00000010
#define _INTCON_SS0_MASK                            0x00010000
#define _INTCON_SS0_LENGTH                          0x00000001

#define _INTSTAT_VEC_POSITION                       0x00000000
#define _INTSTAT_VEC_MASK                           0x0000003F
#define _INTSTAT_VEC_LENGTH                         0x00000006

#define _INTSTAT_SRIPL_POSITION                     0x00000008
#define _INTSTAT_SRIPL_MASK                         0x00000700
#define _INTSTAT_SRIPL_LENGTH                       0x00000003

#define _IFSVEC_CTIF_POSITION                       0x00000000
#define _IFS_CTIF_POSITION                          0x00000000
#define _IFS_CTIF_MASK                              0x00000001
#define _IFS_CTIF_LENGTH                            0x00000001

#define _IFS0_CS0IF_POSITION                        0x00000001
#define _IFS0_CS0IF_MASK                            0x00000002
#define _IFS0_CS0IF_LENGTH                          0x00000001

#define _IFS0_CS1IF_POSITION                        0x00000002
#define _IFS0_CS1IF_MASK                            0x00000004
#define _IFS0_CS1IF_LENGTH                          0x00000001

#define _IFS0_INT0IF_POSITION                       0x00000003
#define _IFS0_INT0IF_MASK                           0x00000008
#define _IFS0_INT0IF_LENGTH                         0x00000001

#define _IFS0_T1IF_POSITION                         0x00000004
#define _IFS0_T1IF_MASK                             0x00000010
#define _IFS0_T1IF_LENGTH                           0x00000001

#define _IFS0_IC1EIF_POSITION                       0x00000005
#define _IFS0_IC1EIF_MASK                           0x00000020
#define _IFS0_IC1EIF_LENGTH                         0x00000001

#define _IFS0_IC1IF_POSITION                        0x00000006
#define _IFS0_IC1IF_MASK                            0x00000040
#define _IFS0_IC1IF_LENGTH                          0x00000001

#define _IFS0_OC1IF_POSITION                        0x00000007
#define _IFS0_OC1IF_MASK                            0x00000080
#define _IFS0_OC1IF_LENGTH                          0x00000001

#define _IFS0_INT1IF_POSITION                       0x00000008
#define _IFS0_INT1IF_MASK                           0x00000100
#define _IFS0_INT1IF_LENGTH                         0x00000001

#define _IFS0_T2IF_POSITION                         0x00000009
#define _IFS0_T2IF_MASK                             0x00000200
#define _IFS0_T2IF_LENGTH                           0x00000001

#define _IFS0_IC2EIF_POSITION                       0x0000000A
#define _IFS0_IC2EIF_MASK                           0x00000400
#define _IFS0_IC2EIF_LENGTH                         0x00000001

#define _IFS0_IC2IF_POSITION                        0x0000000B
#define _IFS0_IC2IF_MASK                            0x00000800
#define _IFS0_IC2IF_LENGTH                          0x00000001

#define _IFS0_OC2IF_POSITION                        0x0000000C
#define _IFS0_OC2IF_MASK                            0x00001000
#define _IFS0_OC2IF_LENGTH                          0x00000001

#define _IFS0_INT2IF_POSITION                       0x0000000D
#define _IFS0_INT2IF_MASK                           0x00002000
#define _IFS0_INT2IF_LENGTH                         0x00000001

#define _IFS0_T3IF_POSITION                         0x0000000E
#define _IFS0_T3IF_MASK                             0x00004000
#define _IFS0_T3IF_LENGTH                           0x00000001

#define _IFS0_IC3EIF_POSITION                       0x0000000F
#define _IFS0_IC3EIF_MASK                           0x00008000
#define _IFS0_IC3EIF_LENGTH                         0x00000001

#define _IFS0_IC3IF_POSITION                        0x00000010
#define _IFS0_IC3IF_MASK                            0x00010000
#define _IFS0_IC3IF_LENGTH                          0x00000001

#define _IFS0_OC3IF_POSITION                        0x00000011
#define _IFS0_OC3IF_MASK                            0x00020000
#define _IFS0_OC3IF_LENGTH                          0x00000001

#define _IFS0_INT3IF_POSITION                       0x00000012
#define _IFS0_INT3IF_MASK                           0x00040000
#define _IFS0_INT3IF_LENGTH                         0x00000001

#define _IFS0_T4IF_POSITION                         0x00000013
#define _IFS0_T4IF_MASK                             0x00080000
#define _IFS0_T4IF_LENGTH                           0x00000001

#define _IFS0_IC4EIF_POSITION                       0x00000014
#define _IFS0_IC4EIF_MASK                           0x00100000
#define _IFS0_IC4EIF_LENGTH                         0x00000001

#define _IFS0_IC4IF_POSITION                        0x00000015
#define _IFS0_IC4IF_MASK                            0x00200000
#define _IFS0_IC4IF_LENGTH                          0x00000001

#define _IFS0_OC4IF_POSITION                        0x00000016
#define _IFS0_OC4IF_MASK                            0x00400000
#define _IFS0_OC4IF_LENGTH                          0x00000001

#define _IFS0_INT4IF_POSITION                       0x00000017
#define _IFS0_INT4IF_MASK                           0x00800000
#define _IFS0_INT4IF_LENGTH                         0x00000001

#define _IFS0_T5IF_POSITION                         0x00000018
#define _IFS0_T5IF_MASK                             0x01000000
#define _IFS0_T5IF_LENGTH                           0x00000001

#define _IFS0_IC5EIF_POSITION                       0x00000019
#define _IFS0_IC5EIF_MASK                           0x02000000
#define _IFS0_IC5EIF_LENGTH                         0x00000001

#define _IFS0_IC5IF_POSITION                        0x0000001A
#define _IFS0_IC5IF_MASK                            0x04000000
#define _IFS0_IC5IF_LENGTH                          0x00000001

#define _IFS0_OC5IF_POSITION                        0x0000001B
#define _IFS0_OC5IF_MASK                            0x08000000
#define _IFS0_OC5IF_LENGTH                          0x00000001

#define _IFS0_AD1IF_POSITION                        0x0000001C
#define _IFS0_AD1IF_MASK                            0x10000000
#define _IFS0_AD1IF_LENGTH                          0x00000001

#define _IFS0_FSCMIF_POSITION                       0x0000001D
#define _IFS0_FSCMIF_MASK                           0x20000000
#define _IFS0_FSCMIF_LENGTH                         0x00000001

#define _IFS0_RTCCIF_POSITION                       0x0000001E
#define _IFS0_RTCCIF_MASK                           0x40000000
#define _IFS0_RTCCIF_LENGTH                         0x00000001

#define _IFS0_FCEIF_POSITION                        0x0000001F
#define _IFS0_FCEIF_MASK                            0x80000000
#define _IFS0_FCEIF_LENGTH                          0x00000001

#define _IFS1_CMP1IF_POSITION                       0x00000000
#define _IFS1_CMP1IF_MASK                           0x00000001
#define _IFS1_CMP1IF_LENGTH                         0x00000001

#define _IFS1_CMP2IF_POSITION                       0x00000001
#define _IFS1_CMP2IF_MASK                           0x00000002
#define _IFS1_CMP2IF_LENGTH                         0x00000001

#define _IFS1_CMP3IF_POSITION                       0x00000002
#define _IFS1_CMP3IF_MASK                           0x00000004
#define _IFS1_CMP3IF_LENGTH                         0x00000001

#define _IFS1_USBIF_POSITION                        0x00000003
#define _IFS1_USBIF_MASK                            0x00000008
#define _IFS1_USBIF_LENGTH                          0x00000001

#define _IFS1_SPI1EIF_POSITION                      0x00000004
#define _IFS1_SPI1EIF_MASK                          0x00000010
#define _IFS1_SPI1EIF_LENGTH                        0x00000001

#define _IFS1_SPI1RXIF_POSITION                     0x00000005
#define _IFS1_SPI1RXIF_MASK                         0x00000020
#define _IFS1_SPI1RXIF_LENGTH                       0x00000001

#define _IFS1_SPI1TXIF_POSITION                     0x00000006
#define _IFS1_SPI1TXIF_MASK                         0x00000040
#define _IFS1_SPI1TXIF_LENGTH                       0x00000001

#define _IFS1_U1EIF_POSITION                        0x00000007
#define _IFS1_U1EIF_MASK                            0x00000080
#define _IFS1_U1EIF_LENGTH                          0x00000001

#define _IFS1_U1RXIF_POSITION                       0x00000008
#define _IFS1_U1RXIF_MASK                           0x00000100
#define _IFS1_U1RXIF_LENGTH                         0x00000001

#define _IFS1_U1TXIF_POSITION                       0x00000009
#define _IFS1_U1TXIF_MASK                           0x00000200
#define _IFS1_U1TXIF_LENGTH                         0x00000001

#define _IFS1_I2C1BIF_POSITION                      0x0000000A
#define _IFS1_I2C1BIF_MASK                          0x00000400
#define _IFS1_I2C1BIF_LENGTH                        0x00000001

#define _IFS1_I2C1SIF_POSITION                      0x0000000B
#define _IFS1_I2C1SIF_MASK                          0x00000800
#define _IFS1_I2C1SIF_LENGTH                        0x00000001

#define _IFS1_I2C1MIF_POSITION                      0x0000000C
#define _IFS1_I2C1MIF_MASK                          0x00001000
#define _IFS1_I2C1MIF_LENGTH                        0x00000001

#define _IFS1_CNAIF_POSITION                        0x0000000D
#define _IFS1_CNAIF_MASK                            0x00002000
#define _IFS1_CNAIF_LENGTH                          0x00000001

#define _IFS1_CNBIF_POSITION                        0x0000000E
#define _IFS1_CNBIF_MASK                            0x00004000
#define _IFS1_CNBIF_LENGTH                          0x00000001

#define _IFS1_CNCIF_POSITION                        0x0000000F
#define _IFS1_CNCIF_MASK                            0x00008000
#define _IFS1_CNCIF_LENGTH                          0x00000001

#define _IFS1_PMPIF_POSITION                        0x00000010
#define _IFS1_PMPIF_MASK                            0x00010000
#define _IFS1_PMPIF_LENGTH                          0x00000001

#define _IFS1_PMPEIF_POSITION                       0x00000011
#define _IFS1_PMPEIF_MASK                           0x00020000
#define _IFS1_PMPEIF_LENGTH                         0x00000001

#define _IFS1_SPI2EIF_POSITION                      0x00000012
#define _IFS1_SPI2EIF_MASK                          0x00040000
#define _IFS1_SPI2EIF_LENGTH                        0x00000001

#define _IFS1_SPI2RXIF_POSITION                     0x00000013
#define _IFS1_SPI2RXIF_MASK                         0x00080000
#define _IFS1_SPI2RXIF_LENGTH                       0x00000001

#define _IFS1_SPI2TXIF_POSITION                     0x00000014
#define _IFS1_SPI2TXIF_MASK                         0x00100000
#define _IFS1_SPI2TXIF_LENGTH                       0x00000001

#define _IFS1_U2EIF_POSITION                        0x00000015
#define _IFS1_U2EIF_MASK                            0x00200000
#define _IFS1_U2EIF_LENGTH                          0x00000001

#define _IFS1_U2RXIF_POSITION                       0x00000016
#define _IFS1_U2RXIF_MASK                           0x00400000
#define _IFS1_U2RXIF_LENGTH                         0x00000001

#define _IFS1_U2TXIF_POSITION                       0x00000017
#define _IFS1_U2TXIF_MASK                           0x00800000
#define _IFS1_U2TXIF_LENGTH                         0x00000001

#define _IFS1_I2C2BIF_POSITION                      0x00000018
#define _IFS1_I2C2BIF_MASK                          0x01000000
#define _IFS1_I2C2BIF_LENGTH                        0x00000001

#define _IFS1_I2C2SIF_POSITION                      0x00000019
#define _IFS1_I2C2SIF_MASK                          0x02000000
#define _IFS1_I2C2SIF_LENGTH                        0x00000001

#define _IFS1_I2C2MIF_POSITION                      0x0000001A
#define _IFS1_I2C2MIF_MASK                          0x04000000
#define _IFS1_I2C2MIF_LENGTH                        0x00000001

#define _IFS1_CTMUIF_POSITION                       0x0000001B
#define _IFS1_CTMUIF_MASK                           0x08000000
#define _IFS1_CTMUIF_LENGTH                         0x00000001

#define _IFS1_DMA0IF_POSITION                       0x0000001C
#define _IFS1_DMA0IF_MASK                           0x10000000
#define _IFS1_DMA0IF_LENGTH                         0x00000001

#define _IFS1_DMA1IF_POSITION                       0x0000001D
#define _IFS1_DMA1IF_MASK                           0x20000000
#define _IFS1_DMA1IF_LENGTH                         0x00000001

#define _IFS1_DMA2IF_POSITION                       0x0000001E
#define _IFS1_DMA2IF_MASK                           0x40000000
#define _IFS1_DMA2IF_LENGTH                         0x00000001

#define _IFS1_DMA3IF_POSITION                       0x0000001F
#define _IFS1_DMA3IF_MASK                           0x80000000
#define _IFS1_DMA3IF_LENGTH                         0x00000001

#define _IECVEC_CTIE_POSITION                       0x00000000
#define _IEC_CTIE_POSITION                         0x00000000
#define _IEC_CTIE_MASK                             0x00000001
#define _IEC_CTIE_LENGTH                           0x00000001

#define _IEC0_CS0IE_POSITION                        0x00000001
#define _IEC0_CS0IE_MASK                            0x00000002
#define _IEC0_CS0IE_LENGTH                          0x00000001

#define _IEC0_CS1IE_POSITION                        0x00000002
#define _IEC0_CS1IE_MASK                            0x00000004
#define _IEC0_CS1IE_LENGTH                          0x00000001

#define _IEC0_INT0IE_POSITION                       0x00000003
#define _IEC0_INT0IE_MASK                           0x00000008
#define _IEC0_INT0IE_LENGTH                         0x00000001

#define _IEC0_T1IE_POSITION                         0x00000004
#define _IEC0_T1IE_MASK                             0x00000010
#define _IEC0_T1IE_LENGTH                           0x00000001

#define _IEC0_IC1EIE_POSITION                       0x00000005
#define _IEC0_IC1EIE_MASK                           0x00000020
#define _IEC0_IC1EIE_LENGTH                         0x00000001

#define _IEC0_IC1IE_POSITION                        0x00000006
#define _IEC0_IC1IE_MASK                            0x00000040
#define _IEC0_IC1IE_LENGTH                          0x00000001

#define _IEC0_OC1IE_POSITION                        0x00000007
#define _IEC0_OC1IE_MASK                            0x00000080
#define _IEC0_OC1IE_LENGTH                          0x00000001

#define _IEC0_INT1IE_POSITION                       0x00000008
#define _IEC0_INT1IE_MASK                           0x00000100
#define _IEC0_INT1IE_LENGTH                         0x00000001

#define _IEC0_T2IE_POSITION                         0x00000009
#define _IEC0_T2IE_MASK                             0x00000200
#define _IEC0_T2IE_LENGTH                           0x00000001

#define _IEC0_IC2EIE_POSITION                       0x0000000A
#define _IEC0_IC2EIE_MASK                           0x00000400
#define _IEC0_IC2EIE_LENGTH                         0x00000001

#define _IEC0_IC2IE_POSITION                        0x0000000B
#define _IEC0_IC2IE_MASK                            0x00000800
#define _IEC0_IC2IE_LENGTH                          0x00000001

#define _IEC0_OC2IE_POSITION                        0x0000000C
#define _IEC0_OC2IE_MASK                            0x00001000
#define _IEC0_OC2IE_LENGTH                          0x00000001

#define _IEC0_INT2IE_POSITION                       0x0000000D
#define _IEC0_INT2IE_MASK                           0x00002000
#define _IEC0_INT2IE_LENGTH                         0x00000001

#define _IEC0_T3IE_POSITION                         0x0000000E
#define _IEC0_T3IE_MASK                             0x00004000
#define _IEC0_T3IE_LENGTH                           0x00000001

#define _IEC0_IC3EIE_POSITION                       0x0000000F
#define _IEC0_IC3EIE_MASK                           0x00008000
#define _IEC0_IC3EIE_LENGTH                         0x00000001

#define _IEC0_IC3IE_POSITION                        0x00000010
#define _IEC0_IC3IE_MASK                            0x00010000
#define _IEC0_IC3IE_LENGTH                          0x00000001

#define _IEC0_OC3IE_POSITION                        0x00000011
#define _IEC0_OC3IE_MASK                            0x00020000
#define _IEC0_OC3IE_LENGTH                          0x00000001

#define _IEC0_INT3IE_POSITION                       0x00000012
#define _IEC0_INT3IE_MASK                           0x00040000
#define _IEC0_INT3IE_LENGTH                         0x00000001

#define _IEC0_T4IE_POSITION                         0x00000013
#define _IEC0_T4IE_MASK                             0x00080000
#define _IEC0_T4IE_LENGTH                           0x00000001

#define _IEC0_IC4EIE_POSITION                       0x00000014
#define _IEC0_IC4EIE_MASK                           0x00100000
#define _IEC0_IC4EIE_LENGTH                         0x00000001

#define _IEC0_IC4IE_POSITION                        0x00000015
#define _IEC0_IC4IE_MASK                            0x00200000
#define _IEC0_IC4IE_LENGTH                          0x00000001

#define _IEC0_OC4IE_POSITION                        0x00000016
#define _IEC0_OC4IE_MASK                            0x00400000
#define _IEC0_OC4IE_LENGTH                          0x00000001

#define _IEC0_INT4IE_POSITION                       0x00000017
#define _IEC0_INT4IE_MASK                           0x00800000
#define _IEC0_INT4IE_LENGTH                         0x00000001

#define _IEC0_T5IE_POSITION                         0x00000018
#define _IEC0_T5IE_MASK                             0x01000000
#define _IEC0_T5IE_LENGTH                           0x00000001

#define _IEC0_IC5EIE_POSITION                       0x00000019
#define _IEC0_IC5EIE_MASK                           0x02000000
#define _IEC0_IC5EIE_LENGTH                         0x00000001

#define _IEC0_IC5IE_POSITION                        0x0000001A
#define _IEC0_IC5IE_MASK                            0x04000000
#define _IEC0_IC5IE_LENGTH                          0x00000001

#define _IEC0_OC5IE_POSITION                        0x0000001B
#define _IEC0_OC5IE_MASK                            0x08000000
#define _IEC0_OC5IE_LENGTH                          0x00000001

#define _IEC0_AD1IE_POSITION                        0x0000001C
#define _IEC0_AD1IE_MASK                            0x10000000
#define _IEC0_AD1IE_LENGTH                          0x00000001

#define _IEC0_FSCMIE_POSITION                       0x0000001D
#define _IEC0_FSCMIE_MASK                           0x20000000
#define _IEC0_FSCMIE_LENGTH                         0x00000001

#define _IEC0_RTCCIE_POSITION                       0x0000001E
#define _IEC0_RTCCIE_MASK                           0x40000000
#define _IEC0_RTCCIE_LENGTH                         0x00000001

#define _IEC0_FCEIE_POSITION                        0x0000001F
#define _IEC0_FCEIE_MASK                            0x80000000
#define _IEC0_FCEIE_LENGTH                          0x00000001

#define _IEC1_CMP1IE_POSITION                       0x00000000
#define _IEC1_CMP1IE_MASK                           0x00000001
#define _IEC1_CMP1IE_LENGTH                         0x00000001

#define _IEC1_CMP2IE_POSITION                       0x00000001
#define _IEC1_CMP2IE_MASK                           0x00000002
#define _IEC1_CMP2IE_LENGTH                         0x00000001

#define _IEC1_CMP3IE_POSITION                       0x00000002
#define _IEC1_CMP3IE_MASK                           0x00000004
#define _IEC1_CMP3IE_LENGTH                         0x00000001

#define _IEC1_USBIE_POSITION                        0x00000003
#define _IEC1_USBIE_MASK                            0x00000008
#define _IEC1_USBIE_LENGTH                          0x00000001

#define _IEC1_SPI1EIE_POSITION                      0x00000004
#define _IEC1_SPI1EIE_MASK                          0x00000010
#define _IEC1_SPI1EIE_LENGTH                        0x00000001

#define _IEC1_SPI1RXIE_POSITION                     0x00000005
#define _IEC1_SPI1RXIE_MASK                         0x00000020
#define _IEC1_SPI1RXIE_LENGTH                       0x00000001

#define _IEC1_SPI1TXIE_POSITION                     0x00000006
#define _IEC1_SPI1TXIE_MASK                         0x00000040
#define _IEC1_SPI1TXIE_LENGTH                       0x00000001

#define _IEC1_U1EIE_POSITION                        0x00000007
#define _IEC1_U1EIE_MASK                            0x00000080
#define _IEC1_U1EIE_LENGTH                          0x00000001

#define _IEC1_U1RXIE_POSITION                       0x00000008
#define _IEC1_U1RXIE_MASK                           0x00000100
#define _IEC1_U1RXIE_LENGTH                         0x00000001

#define _IEC1_U1TXIE_POSITION                       0x00000009
#define _IEC1_U1TXIE_MASK                           0x00000200
#define _IEC1_U1TXIE_LENGTH                         0x00000001

#define _IEC1_I2C1BIE_POSITION                      0x0000000A
#define _IEC1_I2C1BIE_MASK                          0x00000400
#define _IEC1_I2C1BIE_LENGTH                        0x00000001

#define _IEC1_I2C1SIE_POSITION                      0x0000000B
#define _IEC1_I2C1SIE_MASK                          0x00000800
#define _IEC1_I2C1SIE_LENGTH                        0x00000001

#define _IEC1_I2C1MIE_POSITION                      0x0000000C
#define _IEC1_I2C1MIE_MASK                          0x00001000
#define _IEC1_I2C1MIE_LENGTH                        0x00000001

#define _IEC1_CNAIE_POSITION                        0x0000000D
#define _IEC1_CNAIE_MASK                            0x00002000
#define _IEC1_CNAIE_LENGTH                          0x00000001

#define _IEC1_CNBIE_POSITION                        0x0000000E
#define _IEC1_CNBIE_MASK                            0x00004000
#define _IEC1_CNBIE_LENGTH                          0x00000001

#define _IEC1_CNCIE_POSITION                        0x0000000F
#define _IEC1_CNCIE_MASK                            0x00008000
#define _IEC1_CNCIE_LENGTH                          0x00000001

#define _IEC1_PMPIE_POSITION                        0x00000010
#define _IEC1_PMPIE_MASK                            0x00010000
#define _IEC1_PMPIE_LENGTH                          0x00000001

#define _IEC1_PMPEIE_POSITION                       0x00000011
#define _IEC1_PMPEIE_MASK                           0x00020000
#define _IEC1_PMPEIE_LENGTH                         0x00000001

#define _IEC1_SPI2EIE_POSITION                      0x00000012
#define _IEC1_SPI2EIE_MASK                          0x00040000
#define _IEC1_SPI2EIE_LENGTH                        0x00000001

#define _IEC1_SPI2RXIE_POSITION                     0x00000013
#define _IEC1_SPI2RXIE_MASK                         0x00080000
#define _IEC1_SPI2RXIE_LENGTH                       0x00000001

#define _IEC1_SPI2TXIE_POSITION                     0x00000014
#define _IEC1_SPI2TXIE_MASK                         0x00100000
#define _IEC1_SPI2TXIE_LENGTH                       0x00000001

#define _IEC1_U2EIE_POSITION                        0x00000015
#define _IEC1_U2EIE_MASK                            0x00200000
#define _IEC1_U2EIE_LENGTH                          0x00000001

#define _IEC1_U2RXIE_POSITION                       0x00000016
#define _IEC1_U2RXIE_MASK                           0x00400000
#define _IEC1_U2RXIE_LENGTH                         0x00000001

#define _IEC1_U2TXIE_POSITION                       0x00000017
#define _IEC1_U2TXIE_MASK                           0x00800000
#define _IEC1_U2TXIE_LENGTH                         0x00000001

#define _IEC1_I2C2BIE_POSITION                      0x00000018
#define _IEC1_I2C2BIE_MASK                          0x01000000
#define _IEC1_I2C2BIE_LENGTH                        0x00000001

#define _IEC1_I2C2SIE_POSITION                      0x00000019
#define _IEC1_I2C2SIE_MASK                          0x02000000
#define _IEC1_I2C2SIE_LENGTH                        0x00000001

#define _IEC1_I2C2MIE_POSITION                      0x0000001A
#define _IEC1_I2C2MIE_MASK                          0x04000000
#define _IEC1_I2C2MIE_LENGTH                        0x00000001

#define _IEC1_CTMUIE_POSITION                       0x0000001B
#define _IEC1_CTMUIE_MASK                           0x08000000
#define _IEC1_CTMUIE_LENGTH                         0x00000001

#define _IEC1_DMA0IE_POSITION                       0x0000001C
#define _IEC1_DMA0IE_MASK                           0x10000000
#define _IEC1_DMA0IE_LENGTH                         0x00000001

#define _IEC1_DMA1IE_POSITION                       0x0000001D
#define _IEC1_DMA1IE_MASK                           0x20000000
#define _IEC1_DMA1IE_LENGTH                         0x00000001

#define _IEC1_DMA2IE_POSITION                       0x0000001E
#define _IEC1_DMA2IE_MASK                           0x40000000
#define _IEC1_DMA2IE_LENGTH                         0x00000001

#define _IEC1_DMA3IE_POSITION                       0x0000001F
#define _IEC1_DMA3IE_MASK                           0x80000000
#define _IEC1_DMA3IE_LENGTH                         0x00000001

#define _IPCVEC_CTIP_POSITION                       0x00000000
#define _IPC_CTIS_POSITION                          0x00000000
#define _IPC_CTIS_MASK                              0x00000003
#define _IPC_CTIS_LENGTH                            0x00000002

#define _IPC_CTIP_POSITION                          0x00000002
#define _IPC_CTIP_MASK                              0x0000001C
#define _IPC_CTIP_LENGTH                            0x00000003

#define _IPC0_CS0IS_POSITION                        0x00000008
#define _IPC0_CS0IS_MASK                            0x00000300
#define _IPC0_CS0IS_LENGTH                          0x00000002

#define _IPC0_CS0IP_POSITION                        0x0000000A
#define _IPC0_CS0IP_MASK                            0x00001C00
#define _IPC0_CS0IP_LENGTH                          0x00000003

#define _IPC0_CS1IS_POSITION                        0x00000010
#define _IPC0_CS1IS_MASK                            0x00030000
#define _IPC0_CS1IS_LENGTH                          0x00000002

#define _IPC0_CS1IP_POSITION                        0x00000012
#define _IPC0_CS1IP_MASK                            0x001C0000
#define _IPC0_CS1IP_LENGTH                          0x00000003

#define _IPC0_INT0IS_POSITION                       0x00000018
#define _IPC0_INT0IS_MASK                           0x03000000
#define _IPC0_INT0IS_LENGTH                         0x00000002

#define _IPC0_INT0IP_POSITION                       0x0000001A
#define _IPC0_INT0IP_MASK                           0x1C000000
#define _IPC0_INT0IP_LENGTH                         0x00000003

#define _IPC1_T1IS_POSITION                         0x00000000
#define _IPC1_T1IS_MASK                             0x00000003
#define _IPC1_T1IS_LENGTH                           0x00000002

#define _IPC1_T1IP_POSITION                         0x00000002
#define _IPC1_T1IP_MASK                             0x0000001C
#define _IPC1_T1IP_LENGTH                           0x00000003

#define _IPC1_IC1IS_POSITION                        0x00000008
#define _IPC1_IC1IS_MASK                            0x00000300
#define _IPC1_IC1IS_LENGTH                          0x00000002

#define _IPC1_IC1IP_POSITION                        0x0000000A
#define _IPC1_IC1IP_MASK                            0x00001C00
#define _IPC1_IC1IP_LENGTH                          0x00000003

#define _IPC1_OC1IS_POSITION                        0x00000010
#define _IPC1_OC1IS_MASK                            0x00030000
#define _IPC1_OC1IS_LENGTH                          0x00000002

#define _IPC1_OC1IP_POSITION                        0x00000012
#define _IPC1_OC1IP_MASK                            0x001C0000
#define _IPC1_OC1IP_LENGTH                          0x00000003

#define _IPC1_INT1IS_POSITION                       0x00000018
#define _IPC1_INT1IS_MASK                           0x03000000
#define _IPC1_INT1IS_LENGTH                         0x00000002

#define _IPC1_INT1IP_POSITION                       0x0000001A
#define _IPC1_INT1IP_MASK                           0x1C000000
#define _IPC1_INT1IP_LENGTH                         0x00000003

#define _IPC2_T2IS_POSITION                         0x00000000
#define _IPC2_T2IS_MASK                             0x00000003
#define _IPC2_T2IS_LENGTH                           0x00000002

#define _IPC2_T2IP_POSITION                         0x00000002
#define _IPC2_T2IP_MASK                             0x0000001C
#define _IPC2_T2IP_LENGTH                           0x00000003

#define _IPC2_IC2IS_POSITION                        0x00000008
#define _IPC2_IC2IS_MASK                            0x00000300
#define _IPC2_IC2IS_LENGTH                          0x00000002

#define _IPC2_IC2IP_POSITION                        0x0000000A
#define _IPC2_IC2IP_MASK                            0x00001C00
#define _IPC2_IC2IP_LENGTH                          0x00000003

#define _IPC2_OC2IS_POSITION                        0x00000010
#define _IPC2_OC2IS_MASK                            0x00030000
#define _IPC2_OC2IS_LENGTH                          0x00000002

#define _IPC2_OC2IP_POSITION                        0x00000012
#define _IPC2_OC2IP_MASK                            0x001C0000
#define _IPC2_OC2IP_LENGTH                          0x00000003

#define _IPC2_INT2IS_POSITION                       0x00000018
#define _IPC2_INT2IS_MASK                           0x03000000
#define _IPC2_INT2IS_LENGTH                         0x00000002

#define _IPC2_INT2IP_POSITION                       0x0000001A
#define _IPC2_INT2IP_MASK                           0x1C000000
#define _IPC2_INT2IP_LENGTH                         0x00000003

#define _IPC3_T3IS_POSITION                         0x00000000
#define _IPC3_T3IS_MASK                             0x00000003
#define _IPC3_T3IS_LENGTH                           0x00000002

#define _IPC3_T3IP_POSITION                         0x00000002
#define _IPC3_T3IP_MASK                             0x0000001C
#define _IPC3_T3IP_LENGTH                           0x00000003

#define _IPC3_IC3IS_POSITION                        0x00000008
#define _IPC3_IC3IS_MASK                            0x00000300
#define _IPC3_IC3IS_LENGTH                          0x00000002

#define _IPC3_IC3IP_POSITION                        0x0000000A
#define _IPC3_IC3IP_MASK                            0x00001C00
#define _IPC3_IC3IP_LENGTH                          0x00000003

#define _IPC3_OC3IS_POSITION                        0x00000010
#define _IPC3_OC3IS_MASK                            0x00030000
#define _IPC3_OC3IS_LENGTH                          0x00000002

#define _IPC3_OC3IP_POSITION                        0x00000012
#define _IPC3_OC3IP_MASK                            0x001C0000
#define _IPC3_OC3IP_LENGTH                          0x00000003

#define _IPC3_INT3IS_POSITION                       0x00000018
#define _IPC3_INT3IS_MASK                           0x03000000
#define _IPC3_INT3IS_LENGTH                         0x00000002

#define _IPC3_INT3IP_POSITION                       0x0000001A
#define _IPC3_INT3IP_MASK                           0x1C000000
#define _IPC3_INT3IP_LENGTH                         0x00000003

#define _IPC4_T4IS_POSITION                         0x00000000
#define _IPC4_T4IS_MASK                             0x00000003
#define _IPC4_T4IS_LENGTH                           0x00000002

#define _IPC4_T4IP_POSITION                         0x00000002
#define _IPC4_T4IP_MASK                             0x0000001C
#define _IPC4_T4IP_LENGTH                           0x00000003

#define _IPC4_IC4IS_POSITION                        0x00000008
#define _IPC4_IC4IS_MASK                            0x00000300
#define _IPC4_IC4IS_LENGTH                          0x00000002

#define _IPC4_IC4IP_POSITION                        0x0000000A
#define _IPC4_IC4IP_MASK                            0x00001C00
#define _IPC4_IC4IP_LENGTH                          0x00000003

#define _IPC4_OC4IS_POSITION                        0x00000010
#define _IPC4_OC4IS_MASK                            0x00030000
#define _IPC4_OC4IS_LENGTH                          0x00000002

#define _IPC4_OC4IP_POSITION                        0x00000012
#define _IPC4_OC4IP_MASK                            0x001C0000
#define _IPC4_OC4IP_LENGTH                          0x00000003

#define _IPC4_INT4IS_POSITION                       0x00000018
#define _IPC4_INT4IS_MASK                           0x03000000
#define _IPC4_INT4IS_LENGTH                         0x00000002

#define _IPC4_INT4IP_POSITION                       0x0000001A
#define _IPC4_INT4IP_MASK                           0x1C000000
#define _IPC4_INT4IP_LENGTH                         0x00000003

#define _IPC5_T5IS_POSITION                         0x00000000
#define _IPC5_T5IS_MASK                             0x00000003
#define _IPC5_T5IS_LENGTH                           0x00000002

#define _IPC5_T5IP_POSITION                         0x00000002
#define _IPC5_T5IP_MASK                             0x0000001C
#define _IPC5_T5IP_LENGTH                           0x00000003

#define _IPC5_IC5IS_POSITION                        0x00000008
#define _IPC5_IC5IS_MASK                            0x00000300
#define _IPC5_IC5IS_LENGTH                          0x00000002

#define _IPC5_IC5IP_POSITION                        0x0000000A
#define _IPC5_IC5IP_MASK                            0x00001C00
#define _IPC5_IC5IP_LENGTH                          0x00000003

#define _IPC5_OC5IS_POSITION                        0x00000010
#define _IPC5_OC5IS_MASK                            0x00030000
#define _IPC5_OC5IS_LENGTH                          0x00000002

#define _IPC5_OC5IP_POSITION                        0x00000012
#define _IPC5_OC5IP_MASK                            0x001C0000
#define _IPC5_OC5IP_LENGTH                          0x00000003

#define _IPC5_AD1IS_POSITION                        0x00000018
#define _IPC5_AD1IS_MASK                            0x03000000
#define _IPC5_AD1IS_LENGTH                          0x00000002

#define _IPC5_AD1IP_POSITION                        0x0000001A
#define _IPC5_AD1IP_MASK                            0x1C000000
#define _IPC5_AD1IP_LENGTH                          0x00000003

#define _IPC6_FSCMIS_POSITION                       0x00000000
#define _IPC6_FSCMIS_MASK                           0x00000003
#define _IPC6_FSCMIS_LENGTH                         0x00000002

#define _IPC6_FSCMIP_POSITION                       0x00000002
#define _IPC6_FSCMIP_MASK                           0x0000001C
#define _IPC6_FSCMIP_LENGTH                         0x00000003

#define _IPC6_RTCCIS_POSITION                       0x00000008
#define _IPC6_RTCCIS_MASK                           0x00000300
#define _IPC6_RTCCIS_LENGTH                         0x00000002

#define _IPC6_RTCCIP_POSITION                       0x0000000A
#define _IPC6_RTCCIP_MASK                           0x00001C00
#define _IPC6_RTCCIP_LENGTH                         0x00000003

#define _IPC6_FCEIS_POSITION                        0x00000010
#define _IPC6_FCEIS_MASK                            0x00030000
#define _IPC6_FCEIS_LENGTH                          0x00000002

#define _IPC6_FCEIP_POSITION                        0x00000012
#define _IPC6_FCEIP_MASK                            0x001C0000
#define _IPC6_FCEIP_LENGTH                          0x00000003

#define _IPC6_CMP1IS_POSITION                       0x00000018
#define _IPC6_CMP1IS_MASK                           0x03000000
#define _IPC6_CMP1IS_LENGTH                         0x00000002

#define _IPC6_CMP1IP_POSITION                       0x0000001A
#define _IPC6_CMP1IP_MASK                           0x1C000000
#define _IPC6_CMP1IP_LENGTH                         0x00000003

#define _IPC7_CMP2IS_POSITION                       0x00000000
#define _IPC7_CMP2IS_MASK                           0x00000003
#define _IPC7_CMP2IS_LENGTH                         0x00000002

#define _IPC7_CMP2IP_POSITION                       0x00000002
#define _IPC7_CMP2IP_MASK                           0x0000001C
#define _IPC7_CMP2IP_LENGTH                         0x00000003

#define _IPC7_CMP3IS_POSITION                       0x00000008
#define _IPC7_CMP3IS_MASK                           0x00000300
#define _IPC7_CMP3IS_LENGTH                         0x00000002

#define _IPC7_CMP3IP_POSITION                       0x0000000A
#define _IPC7_CMP3IP_MASK                           0x00001C00
#define _IPC7_CMP3IP_LENGTH                         0x00000003

#define _IPC7_USBIS_POSITION                        0x00000010
#define _IPC7_USBIS_MASK                            0x00030000
#define _IPC7_USBIS_LENGTH                          0x00000002

#define _IPC7_USBIP_POSITION                        0x00000012
#define _IPC7_USBIP_MASK                            0x001C0000
#define _IPC7_USBIP_LENGTH                          0x00000003

#define _IPC7_SPI1IS_POSITION                       0x00000018
#define _IPC7_SPI1IS_MASK                           0x03000000
#define _IPC7_SPI1IS_LENGTH                         0x00000002

#define _IPC7_SPI1IP_POSITION                       0x0000001A
#define _IPC7_SPI1IP_MASK                           0x1C000000
#define _IPC7_SPI1IP_LENGTH                         0x00000003

#define _IPC8_U1IS_POSITION                         0x00000000
#define _IPC8_U1IS_MASK                             0x00000003
#define _IPC8_U1IS_LENGTH                           0x00000002

#define _IPC8_U1IP_POSITION                         0x00000002
#define _IPC8_U1IP_MASK                             0x0000001C
#define _IPC8_U1IP_LENGTH                           0x00000003

#define _IPC8_I2C1IS_POSITION                       0x00000008
#define _IPC8_I2C1IS_MASK                           0x00000300
#define _IPC8_I2C1IS_LENGTH                         0x00000002

#define _IPC8_I2C1IP_POSITION                       0x0000000A
#define _IPC8_I2C1IP_MASK                           0x00001C00
#define _IPC8_I2C1IP_LENGTH                         0x00000003

#define _IPC8_CNIS_POSITION                         0x00000010
#define _IPC8_CNIS_MASK                             0x00030000
#define _IPC8_CNIS_LENGTH                           0x00000002

#define _IPC8_CNIP_POSITION                         0x00000012
#define _IPC8_CNIP_MASK                             0x001C0000
#define _IPC8_CNIP_LENGTH                           0x00000003

#define _IPC8_PMPIS_POSITION                        0x00000018
#define _IPC8_PMPIS_MASK                            0x03000000
#define _IPC8_PMPIS_LENGTH                          0x00000002

#define _IPC8_PMPIP_POSITION                        0x0000001A
#define _IPC8_PMPIP_MASK                            0x1C000000
#define _IPC8_PMPIP_LENGTH                          0x00000003

#define _IPC9_SPI2IS_POSITION                       0x00000000
#define _IPC9_SPI2IS_MASK                           0x00000003
#define _IPC9_SPI2IS_LENGTH                         0x00000002

#define _IPC9_SPI2IP_POSITION                       0x00000002
#define _IPC9_SPI2IP_MASK                           0x0000001C
#define _IPC9_SPI2IP_LENGTH                         0x00000003

#define _IPC9_U2IS_POSITION                         0x00000008
#define _IPC9_U2IS_MASK                             0x00000300
#define _IPC9_U2IS_LENGTH                           0x00000002

#define _IPC9_U2IP_POSITION                         0x0000000A
#define _IPC9_U2IP_MASK                             0x00001C00
#define _IPC9_U2IP_LENGTH                           0x00000003

#define _IPC9_I2C2IS_POSITION                       0x00000010
#define _IPC9_I2C2IS_MASK                           0x00030000
#define _IPC9_I2C2IS_LENGTH                         0x00000002

#define _IPC9_I2C2IP_POSITION                       0x00000012
#define _IPC9_I2C2IP_MASK                           0x001C0000
#define _IPC9_I2C2IP_LENGTH                         0x00000003

#define _IPC9_CTMUIS_POSITION                       0x00000018
#define _IPC9_CTMUIS_MASK                           0x03000000
#define _IPC9_CTMUIS_LENGTH                         0x00000002

#define _IPC9_CTMUIP_POSITION                       0x0000001A
#define _IPC9_CTMUIP_MASK                           0x1C000000
#define _IPC9_CTMUIP_LENGTH                         0x00000003

#define _IPC10_DMA0IS_POSITION                      0x00000000
#define _IPC10_DMA0IS_MASK                          0x00000003
#define _IPC10_DMA0IS_LENGTH                        0x00000002

#define _IPC10_DMA0IP_POSITION                      0x00000002
#define _IPC10_DMA0IP_MASK                          0x0000001C
#define _IPC10_DMA0IP_LENGTH                        0x00000003

#define _IPC10_DMA1IS_POSITION                      0x00000008
#define _IPC10_DMA1IS_MASK                          0x00000300
#define _IPC10_DMA1IS_LENGTH                        0x00000002

#define _IPC10_DMA1IP_POSITION                      0x0000000A
#define _IPC10_DMA1IP_MASK                          0x00001C00
#define _IPC10_DMA1IP_LENGTH                        0x00000003

#define _IPC10_DMA2IS_POSITION                      0x00000010
#define _IPC10_DMA2IS_MASK                          0x00030000
#define _IPC10_DMA2IS_LENGTH                        0x00000002

#define _IPC10_DMA2IP_POSITION                      0x00000012
#define _IPC10_DMA2IP_MASK                          0x001C0000
#define _IPC10_DMA2IP_LENGTH                        0x00000003

#define _IPC10_DMA3IS_POSITION                      0x00000018
#define _IPC10_DMA3IS_MASK                          0x03000000
#define _IPC10_DMA3IS_LENGTH                        0x00000002

#define _IPC10_DMA3IP_POSITION                      0x0000001A
#define _IPC10_DMA3IP_MASK                          0x1C000000
#define _IPC10_DMA3IP_LENGTH                        0x00000003

/**
 * Vector Numbers 
 */
#define _CORE_TIMER_VECTOR                       0
#define _CORE_SOFTWARE_0_VECTOR                  1
#define _CORE_SOFTWARE_1_VECTOR                  2
#define _EXTERNAL_0_VECTOR                       3
#define _TIMER_1_VECTOR                          4
#define _INPUT_CAPTURE_1_VECTOR                  5
#define _OUTPUT_COMPARE_1_VECTOR                 6
#define _EXTERNAL_1_VECTOR                       7
#define _TIMER_2_VECTOR                          8
#define _INPUT_CAPTURE_2_VECTOR                  9
#define _OUTPUT_COMPARE_2_VECTOR                 10
#define _EXTERNAL_2_VECTOR                       11
#define _TIMER_3_VECTOR                          12
#define _INPUT_CAPTURE_3_VECTOR                  13
#define _OUTPUT_COMPARE_3_VECTOR                 14
#define _EXTERNAL_3_VECTOR                       15
#define _TIMER_4_VECTOR                          16
#define _INPUT_CAPTURE_4_VECTOR                  17
#define _OUTPUT_COMPARE_4_VECTOR                 18
#define _EXTERNAL_4_VECTOR                       19
#define _TIMER_5_VECTOR                          20
#define _INPUT_CAPTURE_5_VECTOR                  21
#define _OUTPUT_COMPARE_5_VECTOR                 22
#define _ADC_VECTOR                              23
#define _FAIL_SAFE_MONITOR_VECTOR                24
#define _RTCC_VECTOR                             25
#define _FCE_VECTOR                              26
#define _COMPARATOR_1_VECTOR                     27
#define _COMPARATOR_2_VECTOR                     28
#define _COMPARATOR_3_VECTOR                     29
#define _USB_1_VECTOR                            30
#define _SPI_1_VECTOR                            31
#define _UART_1_VECTOR                           32
#define _I2C_1_VECTOR                            33
#define _CHANGE_NOTICE_VECTOR                    34
#define _PMP_VECTOR                              35
#define _SPI_2_VECTOR                            36
#define _UART_2_VECTOR                           37
#define _I2C_2_VECTOR                            38
#define _CTMU_VECTOR                             39
#define _DMA_0_VECTOR                            40
#define _DMA_1_VECTOR                            41
#define _DMA_2_VECTOR                            42
#define _DMA_3_VECTOR                            43

/**
 * IRQ Numbers
 */
#define _CORE_TIMER_IRQ                          0
#define _CORE_SOFTWARE_0_IRQ                     1
#define _CORE_SOFTWARE_1_IRQ                     2
#define _EXTERNAL_0_IRQ                          3
#define _TIMER_1_IRQ                             4
#define _INPUT_CAPTURE_ERROR_1_IRQ               5
#define _INPUT_CAPTURE_1_IRQ                     6
#define _OUTPUT_COMPARE_1_IRQ                    7
#define _EXTERNAL_1_IRQ                          8
#define _TIMER_2_IRQ                             9
#define _INPUT_CAPTURE_ERROR_2_IRQ               10
#define _INPUT_CAPTURE_2_IRQ                     11
#define _OUTPUT_COMPARE_2_IRQ                    12
#define _EXTERNAL_2_IRQ                          13
#define _TIMER_3_IRQ                             14
#define _INPUT_CAPTURE_ERROR_3_IRQ               15
#define _INPUT_CAPTURE_3_IRQ                     16
#define _OUTPUT_COMPARE_3_IRQ                    17
#define _EXTERNAL_3_IRQ                          18
#define _TIMER_4_IRQ                             19
#define _INPUT_CAPTURE_ERROR_4_IRQ               20
#define _INPUT_CAPTURE_4_IRQ                     21
#define _OUTPUT_COMPARE_4_IRQ                    22
#define _EXTERNAL_4_IRQ                          23
#define _TIMER_5_IRQ                             24
#define _INPUT_CAPTURE_ERROR_5_IRQ               25
#define _INPUT_CAPTURE_5_IRQ                     26
#define _OUTPUT_COMPARE_5_IRQ                    27
#define _ADC_IRQ                                 28
#define _FAIL_SAFE_MONITOR_IRQ                   29
#define _RTCC_IRQ                                30
#define _FLASH_CONTROL_IRQ                       31
#define _COMPARATOR_1_IRQ                        32
#define _COMPARATOR_2_IRQ                        33
#define _COMPARATOR_3_IRQ                        34
#define _USB_IRQ                                 35
#define _SPI1_ERR_IRQ                            36
#define _SPI1_RX_IRQ                             37
#define _SPI1_TX_IRQ                             38
#define _UART1_ERR_IRQ                           39
#define _UART1_RX_IRQ                            40
#define _UART1_TX_IRQ                            41
#define _I2C1_BUS_IRQ                            42
#define _I2C1_SLAVE_IRQ                          43
#define _I2C1_MASTER_IRQ                         44
#define _CHANGE_NOTICE_A_IRQ                     45
#define _CHANGE_NOTICE_B_IRQ                     46
#define _CHANGE_NOTICE_C_IRQ                     47
#define _PMP_IRQ                                 48
#define _PMP_ERROR_IRQ                           49
#define _SPI2_ERR_IRQ                            50
#define _SPI2_RX_IRQ                             51
#define _SPI2_TX_IRQ                             52
#define _UART2_ERR_IRQ                           53
#define _UART2_RX_IRQ                            54
#define _UART2_TX_IRQ                            55
#define _I2C2_BUS_IRQ                            56
#define _I2C2_SLAVE_IRQ                          57
#define _I2C2_MASTER_IRQ                         58
#define _CTMU_IRQ                                59
#define _DMA0_IRQ                                60
#define _DMA1_IRQ                                61
#define _DMA2_IRQ                                62
#define _DMA3_IRQ                                63

/**
 * Peripheral Pin Select
 */
#define _GROUP_ONE                                  0x00000100
#define _GROUP_TWO                                  0x00000200
#define _GROUP_THREE                                0x00000400
#define _GROUP_FOUR                                 0x00000800

#define _INT1R_POSITION                             0x00000000
#define _INT2R_POSITION                             0x00000001
#define _INT3R_POSITION                             0x00000002
#define _INT4R_POSITION                             0x00000003
#define _T2CKR_POSITION                             0x00000005
#define _T3CKR_POSITION                             0x00000006
#define _T4CKR_POSITION                             0x00000007
#define _T5CKR_POSITION                             0x00000008
#define _IC1R_POSITION                              0x00000009
#define _IC2R_POSITION                              0x0000000A
#define _IC3R_POSITION                              0x0000000B
#define _IC4R_POSITION                              0x0000000C
#define _IC5R_POSITION                              0x0000000D
#define _OCFAR_POSITION                             0x00000011
#define _OCFBR_POSITION                             0x00000012
#define _U1RXR_POSITION                             0x00000013
#define _U1CTSR_POSITION                            0x00000014
#define _U2RXR_POSITION                             0x00000015
#define _U2CTSR_POSITION                            0x00000016
#define _SDI1R_POSITION                             0x00000020
#define _SS1R_POSITION                              0x00000021
#define _SDI2R_POSITION                             0x00000023
#define _SS2R_POSITION                              0x00000024
#define _REFCLKIR_POSITION                          0x0000002D

#define _INT4R_VALUE                                _GROUP_ONE
#define _T2CKR_VALUE                                _GROUP_ONE
#define _IC4R_VALUE                                 _GROUP_ONE
#define _SS1IN_VALUE                                _GROUP_ONE
#define _REFCLKIR_VALUE                             _GROUP_ONE

#define _INT3R_VALUE                                _GROUP_TWO
#define _T3CKR_VALUE                                _GROUP_TWO
#define _IC3R_VALUE                                 _GROUP_TWO
#define _U1CTSR_VALUE                               _GROUP_TWO
#define _U2RXR_VALUE                                _GROUP_TWO
#define _SDI1R_VALUE                                _GROUP_TWO

#define _INT2R_VALUE                                _GROUP_THREE
#define _T4CKR_VALUE                                _GROUP_THREE
#define _IC1R_VALUE                                 _GROUP_THREE
#define _IC5R_VALUE                                 _GROUP_THREE
#define _U1RXR_VALUE                                _GROUP_THREE
#define _U2CTSR_VALUE                               _GROUP_THREE
#define _SDI2R_VALUE                                _GROUP_THREE
#define _OCFBR_VALUE                                _GROUP_THREE

#define _INT1R_VALUE                                _GROUP_FOUR
#define _T5CKR_VALUE                                _GROUP_FOUR
#define _IC2R_VALUE                                 _GROUP_FOUR
#define _SS2IN_VALUE                                _GROUP_FOUR
#define _OCFAR_VALUE                                _GROUP_FOUR

#define _RPA0R_POSITION                             0x00000000
#define _RPA1R_POSITION                             0x00000001
#define _RPA2R_POSITION                             0x00000002
#define _RPA3R_POSITION                             0x00000003
#define _RPA4R_POSITION                             0x00000004
#define _RPA8R_POSITION                             0x00000008
#define _RPA9R_POSITION                             0x00000009

#define _RPB0R_POSITION                             0x0000000B
#define _RPB1R_POSITION                             0x0000000C
#define _RPB2R_POSITION                             0x0000000D
#define _RPB3R_POSITION                             0x0000000E
#define _RPB4R_POSITION                             0x0000000F
#define _RPB5R_POSITION                             0x00000010
#define _RPB7R_POSITION                             0x00000012
#define _RPB8R_POSITION                             0x00000013
#define _RPB9R_POSITION                             0x00000014
#define _RPB10R_POSITION                            0x00000015
#define _RPB11R_POSITION                            0x00000016
#define _RPB13R_POSITION                            0x00000018
#define _RPB14R_POSITION                            0x00000019
#define _RPB15R_POSITION                            0x0000001A

#define _RPC0R_POSITION                             0x0000001B
#define _RPC1R_POSITION                             0x0000001C
#define _RPC2R_POSITION                             0x0000001D
#define _RPC3R_POSITION                             0x0000001E
#define _RPC4R_POSITION                             0x0000001F
#define _RPC5R_POSITION                             0x00000020
#define _RPC6R_POSITION                             0x00000021
#define _RPC7R_POSITION                             0x00000022
#define _RPC8R_POSITION                             0x00000023
#define _RPC9R_POSITION                             0x00000024

#define _RPA0R_VALUE                                (_GROUP_ONE     | 0x00000000)
#define _RPB3R_VALUE                                (_GROUP_ONE     | 0x00000001)
#define _RPB4R_VALUE                                (_GROUP_ONE     | 0x00000002)
#define _RPB15R_VALUE                               (_GROUP_ONE     | 0x00000003)
#define _RPB7R_VALUE                                (_GROUP_ONE     | 0x00000004)
#define _RPC7R_VALUE                                (_GROUP_ONE     | 0x00000005)
#define _RPC0R_VALUE                                (_GROUP_ONE     | 0x00000006)
#define _RPC5R_VALUE                                (_GROUP_ONE     | 0x00000007)

#define _RPA1R_VALUE                                (_GROUP_TWO     | 0x00000000)
#define _RPB5R_VALUE                                (_GROUP_TWO     | 0x00000001)
#define _RPB1R_VALUE                                (_GROUP_TWO     | 0x00000002)
#define _RPB11R_VALUE                               (_GROUP_TWO     | 0x00000003)
#define _RPB8R_VALUE                                (_GROUP_TWO     | 0x00000004)
#define _RPA8R_VALUE                                (_GROUP_TWO     | 0x00000005)
#define _RPC8R_VALUE                                (_GROUP_TWO     | 0x00000006)
#define _RPA9R_VALUE                                (_GROUP_TWO     | 0x00000007)

#define _RPA2R_VALUE                                (_GROUP_THREE   | 0x00000000)
#define _RPA4R_VALUE                                (_GROUP_THREE   | 0x00000002)
#define _RPB13R_VALUE                               (_GROUP_THREE   | 0x00000003)
#define _RPB2R_VALUE                                (_GROUP_THREE   | 0x00000004)
#define _RPC6R_VALUE                                (_GROUP_THREE   | 0x00000005)
#define _RPC1R_VALUE                                (_GROUP_THREE   | 0x00000006)
#define _RPC3R_VALUE                                (_GROUP_THREE   | 0x00000007)

#define _RPA3R_VALUE                                (_GROUP_FOUR    | 0x00000000)
#define _RPB14R_VALUE                               (_GROUP_FOUR    | 0x00000001)
#define _RPB0R_VALUE                                (_GROUP_FOUR    | 0x00000002)
#define _RPB10R_VALUE                               (_GROUP_FOUR    | 0x00000003)
#define _RPB9R_VALUE                                (_GROUP_FOUR    | 0x00000004)
#define _RPC9R_VALUE                                (_GROUP_FOUR    | 0x00000005)
#define _RPC2R_VALUE                                (_GROUP_FOUR    | 0x00000006)
#define _RPC4R_VALUE                                (_GROUP_FOUR    | 0x00000007)

#define _NOCONNECT_VALUE                            (_GROUP_ONE     | _GROUP_TWO    | _GROUP_THREE  | _GROUP_FOUR)

#define _U1TXR_VALUE                                (_GROUP_ONE     | 0x00000001)
#define _U2RTSR_VALUE                               (_GROUP_ONE     | 0x00000002)
#define _SS1OUTR_VALUE                              (_GROUP_ONE     | 0x00000003)
#define _OC1R_VALUE                                 (_GROUP_ONE     | 0x00000005)
#define _C2OUTR_VALUE                               (_GROUP_ONE     | 0x00000007)

#define _SDO1R_VALUE                                (_GROUP_TWO     | _GROUP_THREE  | 0x00000003)
#define _SDO2R_VALUE                                (_GROUP_TWO     | _GROUP_THREE  | 0x00000004)
#define _OC2R_VALUE                                 (_GROUP_TWO     | 0x00000005)
#define _C3OUTR_VALUE                               (_GROUP_TWO     | 0x00000007)

#define _OC4R_VALUE                                 (_GROUP_THREE   | 0x00000005)
#define _OC5R_VALUE                                 (_GROUP_THREE   | 0x00000006)
#define _REFCLKOR_VALUE                             (_GROUP_THREE   | 0x00000007)

#define _U1RTSR_VALUE                               (_GROUP_FOUR    | 0x00000001)
#define _U2TXR_VALUE                                (_GROUP_FOUR    | 0x00000002)
#define _SS2OUTR_VALUE                              (_GROUP_FOUR    | 0x00000004)
#define _OC3R_VALUE                                 (_GROUP_FOUR    | 0x00000005)
#define _C1OUTR_VALUE                               (_GROUP_FOUR    | 0x00000007)

#endif // AP32MX270F256D_H