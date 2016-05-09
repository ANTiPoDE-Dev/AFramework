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

#ifndef APORT_A
#define APORT_A

#include "ACore.h"
#include "ACommons.h"
#include "ASystemConfig.h"

namespace AFramework{
    
    extern const uint32 All;
    extern const uint32 NoOne;

    class APort{
        friend class System;        
        public:
            /**
             * Costruttore di default, setta tutti i gpio come ingressi
             * digitali.
             */
            APort();
            /**
             * Effettua una diagnostica complessiva sulla configurazione 
             * dell'ADC tramite il registro specifico analog-select della porta
             * corrispondente (ANSELx, dove x può essere A, B o C a seconda 
             * dell'oggetto globale chiamante). In tale registro un bit a 
             * livello logico alto indica che il gpio corrispondete è impostato
             * come analogico mentre un bit a livello logico basso indica che
             * il gpio corrispondete è impostato come digitale.
             * @return  la maschera di bit del registro analog-select.
             */
            uint32 adcStatus() const volatile;
            /**
             * Effettua una diagnostica specifica sulla configurazione dell'ADC 
             * effettuando l'and bit a bit tra il gpio passato e il registro
             * analog-select della porta corrispondente (ANSELx, dove x può 
             * essere A, B o C a seconda dell'oggetto globale chiamante) e 
             * restituendo il risultato come bool.
             * @param   gpio il gpio di cui si vuole conoscere la configurazione.
             * @return  false se il gpio è configurato come digitale true
             * se il gpio è configurato come analogico.
             */
            bool isAnalog(const uint32 & gpio) const volatile;
            /**
             * Configura il gpio come digitale tramite il registro CLR associato 
             * al registro analog-select della porta corrispondente (ANSELxCLR, 
             * dove x può essere A, B o C a seconda dell'oggetto globale 
             * chiamante).
             * @param   gpio gpio che sarà impostato come digitale.
             */
            void setDigital(const uint32 & gpio) volatile;
            /**
             * Configura il gpio come analogico tramite il registro SET 
             * associato al registro analog-select della porta corrispondete 
             * (ANSELx, dove x può essere A, B o C a seconda dell'oggetto 
             * globale chiamante).
             * @param   gpio gpio che sarà impostato come analogico.
             */
            void setAnalog(const uint32 & gpio) volatile;
            /**
             * Effettua una diagnostica complessiva sulla configurazione 
             * input/output tramite il registro specifico tri-state della porta
             * corrispondente (TRISx, dove x può essere A, B, C a seconda 
             * dell'oggetto globale chiamante). In tale registro un bit a 
             * livello logico alto indica che il gpio corrispondente è 
             * configurato come ingresso mentre un bit a livello logico basso 
             * indica che il gpio corrispondente è configurato come uscita.
             * @return  la maschera di bit degli del registro tri-state.
             */
            uint32 ioStatus() const volatile;
            /**
             * Effettua una diagnostica specifica sulla configurazione 
             * input/output effettuando l'and bit a bit tra il gpio passato e il
             * registro tri-state della porta corrispondente (TRISx, dove x può
             * essere A, B o C a seconda dell'oggetto globale chiamante) e 
             * restituendo il risultato come bool.
             * @param   gpio il gpio di cui si vuole conoscere la configurazione.
             * @return  false se il gpio è configurato come uscita, true se il
             * gpio è configurato come ingresso.
             */
            bool isInput(const uint32 & gpio) const volatile;
            /**
             * Configura il gpio passato come ingresso tramite il registro SET
             * associato al registro tri-state della porta corrispondente 
             * (TRISxSET, dove x può essere A, B o C a seconda dell'oggetto
             * globale chiamante).
             * @param   gpio gpio che sarà impostato come ingresso.
             */
            void setInput(const uint32 & gpio) volatile;
            /**
             * Configura il gpio passato come uscita tramite il registro CLR
             * associato al registro tri-state della porta corrispondente
             * (TRISxCLR, dove x può essere A, B o C a seconda dell'oggetto
             * globale chiamante).
             * @param   gpio gpio che sarà impostato come uscita.
             */
            void setOutput(const uint32 & gpio) volatile;
            /**
             * Legge il contenuto del registro port della porta corrispondente
             * (PORTx, dove x può essere A, B o C a seconda dell'oggetto 
             * globale chiamante). In tale registro un bit a livello logico alto
             * indica che il gpio corrispondente si trova a livello logico alto
             * mentre un bit a livello logico basso indica che il gpio si trova
             * a livello logico basso. 
             * Si tiene a precistare che, a differenza del latch (LATx) il 
             * registro che questo metodo interroga da informazioni sullo stato 
             * fisico del gpio, ovvero su quale sia lo stato all'esterno del 
             * microcontrollore.
             * @return  la maschera di bit del registro port.
             */
            uint32 portRead() const volatile;
            /**
             * Legge il contenuto del registro port della porta corrispondente
             * (PORTx, dove x può essere A, B o C a seconda dell'oggetto globale
             * chiamante) ed effettua l'and bit a bit con il gpio passato.
             * Si tiene a precistare che, a differenza del latch (LATx) il 
             * registro che questo metodo interroga da informazioni sullo stato 
             * fisico del gpio, ovvero quale sia lo stato all'esterno del 
             * microcontrollore.
             * @param   gpio il gpio di cui si vuole conoscere lo stato
             * @return  LogicLeve::Hi se il livello del gpio è alto, 
             * LogicLevel::Lo se il livello logico del gpio è basso.
             */
            LogicLevel portRead(const uint32 & gpio) const volatile;
            /**
             * Scrive value sul registro port della porta corrispondente tramite
             * il registro SET associato (PORTxSET, dove x può essere A, B o C 
             * a seconda dell'oggetto globale chiamante) dopo aver azzerato lo
             * stesso registro tramite il registro CLR associato (PORTxCLR, dove
             * x può essere A, B o C a seconda dell'oggetto globale chiamante).
             * @param   value il valore che deve essere scritto.
             */
            void portWrite(const uint32 & value) volatile;
            /**
             * Scrive i bit specificati da gpios del registro port della porta
             * corrispondente tramite il registro SET associato, se value è 
             * LogicLevel::Hi, o tramite il registro CLR associato, se value è 
             * LogicLevel::Lo, (PORTxSET/PORTxCLR, dove x può essere A, B o C a
             * seconda dell'oggetto globale chiamante).
             * @param   gpios gpio che devono essere scritti.
             * @param   value livello logico dei gpio.
             */
            void portWrite(const uint32 & gpios, const LogicLevel & value) volatile;
            /**
             * Inverte i bit specificati da gpios del registro port della porta
             * corrispondente tramite il registro INV associato (PORTxINV, dove
             * x può essere A, B o C a seconda dell'oggetto globale chiamante).
             * @param   gpios i gpio di cui si vuole inverire lo stato.
             */
            void portInvert(const uint32 & gpios) volatile;
            /**
             * Legge il contenuto del latch della porta corrispondente (LATx,
             * dove x può essere A, B o C a seconda dell'oggetto globale 
             * chiamante). In tale registro un bit a livello logico alto indica
             * che il valore del latch di uscita per il gpio corrispondete è
             * alto mentre un bit a livello logico basso indica che il valore
             * del latch di uscita per il gpio corrispondente è basso.
             * Si tiene a precisare che, a differenza del registro port (PORTx)
             * il registro che questo metodo interroga da informazioni sullo 
             * stato del latch del gpio, ovvero su quale sia lo stato 
             * all'interno del microcontrollore.
             * @return  la maschera di bit del latch.
             */
            uint32 latchRead() const volatile;
            /**
             * Legge il contenuto del latch della porta corrispondente (LATx,
             * dove x può essere A, B o C a seconda del'oggetto globale 
             * chiamante) ed effettua l'and bit a bit con il gpio passato.
             * Si tiene a precisare che, a differenza del registro port (PORTx)
             * il registro che questo metodo interroga da informazioni sullo 
             * stato del latch del gpio, ovvero su quale sia lo stato 
             * all'interno del microcontrollore.
             * @param   gpio il gpio di cui si vuole conoscere lo stato.
             * @return  LogicLeve::Hi se il livello del gpio è alto, 
             * LogicLevel::Lo se il livello logico del gpio è basso.
             */
            LogicLevel latchRead(const uint32 & gpio) const volatile;
            /**
             * Scrive value sul latch della porta corrispondente tramite il 
             * registro SET associato (LATxSET, dove x può essere A, B o C a
             * seconda dell'oggetto globale chiamante) dopo aver azzerato lo
             * stesso  tramite il registro CLR associato (LATxCLR, dove x può 
             * essere A, B o C a seconda dell'oggetto globale chiamante).
             * @param   value il valore che deve essere scritto.
             */
            void latchWrite(const uint32 & value) volatile;
            /**
             * Scrive i bit specificati da gpios del latch della porta
             * corrispondente tramite il registro SET associato, se value è 
             * LogicLevel::Hi, o tramite il registro CLR associato, se value è 
             * LogicLevel::Lo, (LATxSET/LATxCLR, dove x può essere A, B o C a
             * seconda dell'oggetto globale chiamante).
             * @param   gpios gpio che devono essere scritti.
             * @param   value livello logico dei gpio.
             */
            void latchWrite(const uint32 & gpios, const LogicLevel & value) volatile;
            /**
             * Inverte i bit specificati da gpios del latch della porta
             * corrispondente tramite il registro INV associato (LATxINV, dove
             * x può essere A, B o C a seconda dell'oggetto globale chiamante).
             * @param   gpios i gpio di cui si vuole inverire lo stato.
             */
            void latchInvert(const uint32 & gpios) volatile;
            /**
             * Effettua una diagnostica complessiva sulla configurazione 
             * dell'open-drain tramite il registro specifico open-drain-config 
             * della porta corrispondente (ODCx, dove x può essere A, B o C a 
             * seconda dell'oggetto globale chiamante). In tale registro un bit 
             * a livello logico alto indica che il gpio corrispondete è 
             * impostato con open-drain attivo mentre un bit a livello logico 
             * basso indica che il gpio corrispondete è impostato con open-drain
             * disattivato.
             * Si tiene a precisare che la configurazione open-drain permette
             * di avere tensioni di uscita maggiori rispetto a quelle di 
             * alimentazione con l'uso di un pull-up esterno ed inoltre bisogna
             * ricordare che questa funzionalità è diponibile solo su i gpio che
             * sono 5.0V tolleranti. Si rimanda al datasheet del PIC32MX270F256D
             * per l'elenco dei gpio che supportano questa funzionalità.
             * @return  la maschera di bit del registro open-drain-config.
             */
            uint32 openDrainStatus() const volatile;
            /* Effettua una diagnostica specifica sulla configurazione 
             * dell'open-drain effettuando l'and bit a bit tra il gpio passato e 
             * il registro open-drain-config della porta corrispondente (ODCx, 
             * dove x può essere A, B o C a seconda dell'oggetto globale 
             * chiamante) e restituendo il risultato come bool.
             * @param   gpio il gpio di cui si vuole conoscere la configurazione.
             * @return  false se il gpio è configurato con open-drain 
             * disattivato, true se il gpio è configurato con open-drain attivo.
             */
            bool isOpenDrain(const uint32 & gpio) const volatile;
            /**
             * Configura il gpio passato con open drain attivo tramite il 
             * registro SET associato al registro open-drain-config della porta 
             * corrispondente (ODCxSET, dove x può essere A, B o C a seconda 
             * dell'oggetto globale chiamante).
             * Si tiene a precisare che la configurazione open-drain permette
             * di avere tensioni di uscita maggiori rispetto a quelle di 
             * alimentazione con l'uso di un pull-up esterno ed inoltre bisogna
             * ricordare che questa funzionalità è diponibile solo su i gpio che
             * sono 5.0V tolleranti. Si rimanda al datasheet del PIC32MX270F256D
             * per l'elenco dei gpio che supportano questa funzionalità.
             * @param   gpio gpio che sarà impostato come uscita.
             */
            void setOpenDrain(const uint32 & gpio) volatile;
            /**
             * Configura il gpio passato con open drain disattivato tramite il 
             * registro CLR associato al registro open-drain-config della porta 
             * corrispondente (ODCxCLR, dove x può essere A, B o C a seconda 
             * dell'oggetto globale chiamante).
             * @param   gpio gpio che sarà impostato come uscita.
             */            
            void setStandard(const uint32 & gpio) volatile;
            /**
             * Effettua una diagnostica complessiva sulla configurazione 
             * dei pull-up della periferica change-notice tramite il registro 
             * specifico change-notice-pull-up della porta corrispondente 
             * (CNPUx, dove x può essere A, B o C a seconda dell'oggetto globale 
             * chiamante). In tale registro un bit a livello logico alto indica 
             * che il gpio corrispondete ha il pull-up attivo mentre un bit a 
             * livello logico basso indica che il gpio corrispondete ha il
             * pull-up disattivato.
             * @return  la maschera di bit del registro change-notice-pull-up.
             */            
            uint32 pullUpStatus() const volatile;
            /* Effettua una diagnostica specifica sulla configurazione 
             * dei pull-up della periferica change-notice effettuando l'and bit 
             * a bit tra il gpio passato e il registro change-notice-pull-up 
             * della porta corrispondente (CNPUx, dove x può essere A, B o C a 
             * seconda dell'oggetto globale chiamante) e restituendo il 
             * risultato come bool.
             * @param   gpio il gpio di cui si vuole conoscere la configurazione.
             * @return  false se il gpio è configurato con pull-up disattivato 
             * true se il gpio è configurato con pull-up attivo.
             */
            bool isPullUpEnabled(const uint32 & gpio) const volatile;
            /**
             * Configura il gpio passato con pull-up attivo tramite il 
             * registro SET associato al registro change-notice-pull-up della 
             * porta corrispondente (CNPUxSET, dove x può essere A, B o C a 
             * seconda dell'oggetto globale chiamante).
             * @param   gpio gpio che sarà impostato con pull-up attivo.
             */
            void enablePullUp(const uint32 & gpio) volatile;
            /**
             * Configura il gpio passato con pull-up disattivato tramite il 
             * registro CLR associato al registro change-notice-pull-up della 
             * porta corrispondente (CNPUxCLR, dove x può essere A, B o C a 
             * seconda dell'oggetto globale chiamante).
             * @param   gpio gpio che sarà impostato con pull-up disattivato.
             */
            void disablePullUp(const uint32 & gpio) volatile;
            /* Effettua una diagnostica complessiva sulla configurazione 
             * dei pull-down della periferica change-notice tramite il registro 
             * specifico change-notice-pull-down della porta corrispondente 
             * (CNPDx, dove x può essere A, B o C a seconda dell'oggetto globale 
             * chiamante). In tale registro un bit a livello logico alto indica 
             * che il gpio corrispondete ha il pull-down attivo mentre un bit a 
             * livello logico basso indica che il gpio corrispondete ha il
             * pull-down disattivato.
             * @return  la maschera di bit del registro change-notice-pull-down.
             */     
            uint32 pullDownStatus() const volatile;
            /* Effettua una diagnostica specifica sulla configurazione 
             * dei pull-down della periferica change-notice effettuando l'and 
             * bit a bit tra il gpio passato e il registro 
             * change-notice-pull-down della porta corrispondente (CNPDx, dove 
             * x può essere A, B o C a seconda dell'oggetto globale chiamante) 
             * e restituendo il risultato come bool.
             * @param   gpio il gpio di cui si vuole conoscere la configurazione.
             * @return  false se il gpio è configurato con pull-down disattivato 
             * true se il gpio è configurato con pull-down attivo.
             */
            bool isPullDownEnabled(const uint32 & gpio) const volatile;
            /**
             * Configura il gpio passato con pull-down attivo tramite il 
             * registro SET associato al registro change-notice-pull-down della 
             * porta corrispondente (CNPDxSET, dove x può essere A, B o C a 
             * seconda dell'oggetto globale chiamante).
             * @param   gpio gpio che sarà impostato con pull-down attivo.
             */
            void enablePullDown(const uint32 & gpio) volatile;
            /**
             * Configura il gpio passato con pull-down disattivato tramite il 
             * registro CLR associato al registro change-notice-pull-down della 
             * porta corrispondente (CNPDxCLR, dove x può essere A, B o C a 
             * seconda dell'oggetto globale chiamante).
             * @param   gpio gpio che sarà impostato con pull-down disattivato.
             */
            void disablePullDown(const uint32 & gpio) volatile;
            /**
             * Effettua una diagnostica sullo stato di abilitazione 
             * dell'interrupt della periferica change-notice tramite il registro
             * specifico associato change-notice-config (CNCONx, dove x può
             * essere A, B o C a seconda dell'oggetto globale chiamante) e 
             * interrogando il controller degli interrupt.
             * @return  false se l'interrupt è disabilitato, true se l'interrupt
             * è abilitato.
             */
            bool isInterrutptEnabled() const volatile;
            /**
             * Abilità l'interrupt sui gpio passati con priorità pri e 
             * sotto-priorità sub eventualmente impostando lo stop della
             * periferica change-notice durante lo stand-by del 
             * microcontrollore.
             * @param gpios     i gpio su cui si vuole abilitare l'interrupt.
             * @param pri       la priorità dell'interrupt.
             * @param sub       la sottopriorità dell'interrutp.
             * @param idleStop  flag per lo stop in stand-by della periferica.
             */
            void enableInterrupt(const uint32 & gpios, const Priority & pri, const SubPriority & sub = SubPriority::Isp0, const bool & idleStop = false) volatile;
            /**
             * Disabilita l'interrupt della periferica change-notice sia dai 
             * registri propri che attraverso il controller degli interrupt.
             */
            void disableInterrupt() volatile;
            /* Effettua una diagnostica complessiva sulla stato dei gpio
             * che hanno l'interrupt abilitato sulla periferica change-notice 
             * tramite il registro specifico change-notice-status della porta 
             * corrispondente (CNSTATx, dove x può essere A, B o C a seconda 
             * dell'oggetto globale chiamante). In tale registro un bit a 
             * livello logico alto indica che il gpio corrispondete ha subito 
             * un cambio di stato mentre un bit a livello logico basso indica 
             * che il gpio corrispondete non ha subito un cambio di stato.
             * @return  la maschera di bit del registro change-notice-pull-down.
             */
            uint32 changeNoticeStatus() const volatile;
            /* Effettua una diagnostica specifica sullo stato dei gpio che hanno
             * l'interrupt abilitato periferica change-notice effettuando l'and 
             * bit a bit tra il gpio passato e il registro change-notice-status 
             * della porta corrispondente (CNSTATx, dove x può essere A, B o C 
             * a seconda dell'oggetto globale chiamante) e restituendo il 
             * risultato come bool.
             * @param   gpio il gpio di cui si vuole conoscere se ha subito 
             * un cambio di stato.
             * @return  false se il gpio è non ha subito un cambio di stato, 
             * true se il gpio ha subito un cambio di stato.
             */
            bool hasInterruptOccurred(const uint32 & gpio) const volatile;
            /**
             * Resetta il flag di interrupt dal controller degli interrupt e 
             * azzera i bit corrispondenti a gpios dal registro 
             * change-notice-status tramite il registro CLR associato 
             * (CNSTATxCLR, dove x può essere A, B o C a seconda dell'oggetto
             * globale chiamante). Generalmente questa operazione è effettuata
             * su tutti i bit, per cui, per comodità, chiamando questo metodo
             * senza parametri se effettua il reset su tutti i bit.
             * @param   gpios i gpio di cui si desidera azzerare i flag di 
             * interrupt.
             */
            void clearInterruptFlag(const uint32 & gpios = All) volatile;
        private:
            uint32 whois() const volatile;
            bool chkown(const uint32 & val) const volatile;
            
            volatile uint32 m_ANSEL;         //registro per impostare gli ingressi analogici
            volatile uint32 m_ANSEL_CLR;     //      CLR associato
            volatile uint32 m_ANSEL_SET;     //      SET associato
            volatile uint32 m_ANSEL_INV;     //      INV associato
            volatile uint32 m_TRIS;          //registro per impostare la direzione (1 ingresso - 0 uscita)
            volatile uint32 m_TRIS_CLR;      //      CLR associato
            volatile uint32 m_TRIS_SET;      //      SET associato
            volatile uint32 m_TRIS_INV;      //      INV associato
            volatile uint32 m_PORT;          //registro per lettura del pin fisico
            volatile uint32 m_PORT_CLR;      //      CLR associato
            volatile uint32 m_PORT_SET;      //      SET associato
            volatile uint32 m_PORT_INV;      //      INV associato
            volatile uint32 m_LAT;           //registro per controllare il latch
            volatile uint32 m_LAT_CLR;       //      CLR associato
            volatile uint32 m_LAT_SET;       //      SET associato
            volatile uint32 m_LAT_INV;       //      INV associato
            volatile uint32 m_ODC;           //registro per configurare l'open drain collecton (tensioni di ~5v anche con alimentazione a 3.3v)
            volatile uint32 m_ODC_CLR;       //      CLR associato
            volatile uint32 m_ODC_SET;       //      SET associato
            volatile uint32 m_ODC_INV;       //      INV associato
            volatile uint32 m_CNPU;          //registro per i resistori di pull-up (periferica change notice)
            volatile uint32 m_CNPU_CLR;      //      CLR associato
            volatile uint32 m_CNPU_SET;      //      SET associato
            volatile uint32 m_CNPU_INV;      //      INV associato
            volatile uint32 m_CNPD;          //registro per i resitori di pull-down (periferica change notice)
            volatile uint32 m_CNPD_CLR;      //      CLR associato
            volatile uint32 m_CNPD_SET;      //      SET associato
            volatile uint32 m_CNPD_INV;      //      INV associato
            volatile uint32 m_CNCON;         //registro per abilitare la periferica change notice
            volatile uint32 m_CNCON_CLR;     //      CLR associato
            volatile uint32 m_CNCON_SET;     //      SET associato
            volatile uint32 m_CNCON_INV;     //      INV associato
            volatile uint32 m_CNEN;          //registro per abilitare i pin da configurare con il change notice
            volatile uint32 m_CNEN_CLR;      //      CLR associato
            volatile uint32 m_CNEN_SET;      //      SET associato
            volatile uint32 m_CNEN_INV;      //      INV associato
            volatile uint32 m_CNSTAT;        //registro per controllare quale pin è cambiato di stato (periferica change notice)
            volatile uint32 m_CNSTAT_CLR;    //      CLR associato
            volatile uint32 m_CNSTAT_SET;    //      SET associato
            volatile uint32 m_CNSTAT_INV;    //      INV associato
    };
    
    #ifdef ANTIPODE32MR
        extern volatile APort PortA;
        extern volatile APort PortB;
        extern volatile APort PortC;
        extern const uint32 A0;
        extern const uint32 A1;
        extern const uint32 A4;
        extern const uint32 A7;
        extern const uint32 A8;
        extern const uint32 A9;
        extern const uint32 A10;
        extern const uint32 B0;
        extern const uint32 B1;
        extern const uint32 B2;
        extern const uint32 B3;
        extern const uint32 TW;
        extern const uint32 B5;
        extern const uint32 B7;
        extern const uint32 B8;
        extern const uint32 B9;
        extern const uint32 B10;
        extern const uint32 B11;
        extern const uint32 B13;
        extern const uint32 B14;
        extern const uint32 B15;
        extern const uint32 C0;
        extern const uint32 C1;
        extern const uint32 C2;
        extern const uint32 C3;
        extern const uint32 C4;
        extern const uint32 C5;
        extern const uint32 C6;
        extern const uint32 C7;
        extern const uint32 C8;
        extern const uint32 C9;
    #endif
}
#endif // APORT_A
