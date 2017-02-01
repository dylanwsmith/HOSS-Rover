/*
* AUTHOR:   Alec Selfridge
* VERSION:  1.0
* DATE:     10/22/2016
* NOTES:    This is an exhaustive list of all the registers found in
*           the LPC1768. Due to common names, double-check the register
*           names for Ethernet & RTC peripherals if used.
*/
#ifndef __LPC1768regmap_H
#define __LPC1768regmap_H

/**************System Control**************/
// External Interrupt Registers
#define EXTINT   (*(volatile unsigned int*)0x400FC140)
#define EXTMODE  (*(volatile unsigned int*)0x400FC148)
#define EXTPOLAR (*(volatile unsigned int*)0x400FC14C)
// Reset
#define RSID (*(volatile unsigned int*)0x400FC180)
// Syscon Misc Registers
#define SCS (*(volatile unsigned int*)0x400FC1A0)

/**************Clock Source Selection**************/
// Clock Source Select Register
#define CLKSRCSEL (*(volatile unsigned int*)0x400FC10C)
	
/**************Phase Locked Loop**************/
// Main PLL
#define PLL0CON  (*(volatile unsigned int*)0x400FC080)
#define PLL0CFG  (*(volatile unsigned int*)0x400FC084)
#define PLL0STAT (*(volatile unsigned int*)0x400FC088)
#define PLL0FEED (*(volatile unsigned int*)0x400FC08C)
// USB PLL
#define PLL1CON  (*(volatile unsigned int*)0x400FC0A0)
#define PLL1CFG  (*(volatile unsigned int*)0x400FC0A4)
#define PLL1STAT (*(volatile unsigned int*)0x400FC0A8)
#define PLL1FEED (*(volatile unsigned int*)0x400FC0AC)
// Clock Dividers
#define CCLKCFG   (*(volatile unsigned int*)0x400FC104)
#define USBCLKCFG (*(volatile unsigned int*)0x400FC108)
#define PCLKSEL0  (*(volatile unsigned int*)0x400FC1A8)
#define PCLKSEL1  (*(volatile unsigned int*)0x400FC1AC)
// Power Control
#define PCON  (*(volatile unsigned int*)0x400FC0C0)
#define PCONP (*(volatile unsigned int*)0x400FC0C4)
// Utility
#define CLKOUTCFG (*(volatile unsigned int*)0x400FC1C8)

/**************Flash Accelerator**************/
// Flash Accelerator Configuration Register
#define FLASHCFG (*(volatile unsigned int*)0x400FC000)

/**************NVIC**************/
// Interrupt Set-Enable Registers
#define ISER0 (*(volatile unsigned int*)0xE000E100)
#define ISER1 (*(volatile unsigned int*)0xE000E104)
// Interrupt Clear-Enable Registers
#define ICER0 (*(volatile unsigned int*)0xE000E180)
#define ICER1 (*(volatile unsigned int*)0xE000E184)
// Interrupt Set-Pending Registers
#define ISPR0 (*(volatile unsigned int*)0xE000E200)
#define ISPR1 (*(volatile unsigned int*)0xE000E204)
// Interrupt Clear-Pending Registers
#define ICPR0 (*(volatile unsigned int*)0xE000E280)
#define ICPR1 (*(volatile unsigned int*)0xE000E284)
// Interrupt Active Bit Registers
#define IABR0 (*(volatile unsigned int*)0xE000E300)
#define IABR1 (*(volatile unsigned int*)0xE000E304)
// Interrupt Priority Registers
#define IPR0 (*(volatile unsigned int*)0xE000E400)
#define IPR1 (*(volatile unsigned int*)0xE000E404)
#define IPR2 (*(volatile unsigned int*)0xE000E408)
#define IPR3 (*(volatile unsigned int*)0xE000E40C)
#define IPR4 (*(volatile unsigned int*)0xE000E410)
#define IPR5 (*(volatile unsigned int*)0xE000E414)
#define IPR6 (*(volatile unsigned int*)0xE000E418)
#define IPR7 (*(volatile unsigned int*)0xE000E41C)
#define IPR8 (*(volatile unsigned int*)0xE000E420)
// Software Trigger Interrupt Register
#define STIR (*(volatile unsigned int*)0xE000EF00)

/**************Pin Control**************/
// Pin Select Registers
#define PINSEL0  (*(volatile unsigned int*)0x4002C000)
#define PINSEL1  (*(volatile unsigned int*)0x4002C004)
#define PINSEL2  (*(volatile unsigned int*)0x4002C008)
#define PINSEL3  (*(volatile unsigned int*)0x4002C00C)
#define PINSEL4  (*(volatile unsigned int*)0x4002C010)
#define PINSEL7  (*(volatile unsigned int*)0x4002C01C)
#define PINSEL8  (*(volatile unsigned int*)0x4002C020)
#define PINSEL9  (*(volatile unsigned int*)0x4002C024)
#define PINSEL10 (*(volatile unsigned int*)0x4002C028)
// Pin Mode Registers
#define PINMODE0 (*(volatile unsigned int*)0x4002C040)
#define PINMODE1 (*(volatile unsigned int*)0x4002C044)
#define PINMODE2 (*(volatile unsigned int*)0x4002C048)
#define PINMODE3 (*(volatile unsigned int*)0x4002C04C)
#define PINMODE4 (*(volatile unsigned int*)0x4002C050)
#define PINMODE5 (*(volatile unsigned int*)0x4002C054)
#define PINMODE6 (*(volatile unsigned int*)0x4002C058)
#define PINMODE7 (*(volatile unsigned int*)0x4002C05C)
#define PINMODE9 (*(volatile unsigned int*)0x4002C064)
// Open Drain Mode Control Registers
#define PINMODE_OD0 (*(volatile unsigned int*)0x4002C068)
#define PINMODE_OD1 (*(volatile unsigned int*)0x4002C06C)
#define PINMODE_OD2 (*(volatile unsigned int*)0x4002C070)
#define PINMODE_OD3 (*(volatile unsigned int*)0x4002C074)
#define PINMODE_OD4 (*(volatile unsigned int*)0x4002C078)
// I2C Pin Configuration Register
#define I2CPADCFG (*(volatile unsigned int*)0x4002C07C)
	
/**************GPIO**************/
// Direction Control Registers
#define FIO0DIR (*(volatile unsigned int*)0x2009C000)
#define FIO1DIR (*(volatile unsigned int*)0x2009C020)
#define FIO2DIR (*(volatile unsigned int*)0x2009C040)
#define FIO3DIR (*(volatile unsigned int*)0x2009C060)
#define FIO4DIR (*(volatile unsigned int*)0x2009C080)
// Mask Registers
#define FIO0MASK (*(volatile unsigned int*)0x2009C010)	
#define FIO1MASK (*(volatile unsigned int*)0x2009C030)
#define FIO2MASK (*(volatile unsigned int*)0x2009C050)
#define FIO3MASK (*(volatile unsigned int*)0x2009C070)
#define FIO4MASK (*(volatile unsigned int*)0x2009C090)
// Pin Value Registers
#define FIO0PIN (*(volatile unsigned int*)0x2009C014)
#define FIO1PIN (*(volatile unsigned int*)0x2009C034)
#define FIO2PIN (*(volatile unsigned int*)0x2009C054)
#define FIO3PIN (*(volatile unsigned int*)0x2009C074)
#define FIO4PIN (*(volatile unsigned int*)0x2009C094)
// Output Set Registers
#define FIO0SET (*(volatile unsigned int*)0x2009C018)
#define FIO1SET (*(volatile unsigned int*)0x2009C038)
#define FIO2SET (*(volatile unsigned int*)0x2009C058)
#define FIO3SET (*(volatile unsigned int*)0x2009C078)
#define FIO4SET (*(volatile unsigned int*)0x2009C098)
// Output Clear Registers
#define FIO0CLR (*(volatile unsigned int*)0x2009C01C)
#define FIO1CLR (*(volatile unsigned int*)0x2009C03C)
#define FIO2CLR (*(volatile unsigned int*)0x2009C05C)
#define FIO3CLR (*(volatile unsigned int*)0x2009C07C)
#define FIO4CLR (*(volatile unsigned int*)0x2009C09C)
// Interrupt Registers
#define IO0INTENR   (*(volatile unsigned int*)0x40028090)
#define IO2INTENR   (*(volatile unsigned int*)0x400280B0)
#define IO0INTENF   (*(volatile unsigned int*)0x40028094)
#define IO2INTENF   (*(volatile unsigned int*)0x400280B4)
#define IO0STATR    (*(volatile unsigned int*)0x40028084)
#define IO2STATR    (*(volatile unsigned int*)0x400280A4)
#define IO0STATF    (*(volatile unsigned int*)0x40028088)
#define IO2STATF    (*(volatile unsigned int*)0x400280A8)
#define IO0INTCLR   (*(volatile unsigned int*)0x4002808C)
#define IO2INTCLR   (*(volatile unsigned int*)0x400280AC)
#define IOINTSTATUS (*(volatile unsigned int*)0x40028080)

/**************Ethernet**************/
// MAC Registers
#define MAC1 (*(volatile unsigned int*)0x50000000)
#define MAC2 (*(volatile unsigned int*)0x50000004)
#define IPGT (*(volatile unsigned int*)0x50000008)
#define IPGR (*(volatile unsigned int*)0x5000000C)
#define CLRT (*(volatile unsigned int*)0x50000010)
#define MAXF (*(volatile unsigned int*)0x50000014)
#define SUPP (*(volatile unsigned int*)0x50000018)
#define TEST (*(volatile unsigned int*)0x5000001C)
#define MCFG (*(volatile unsigned int*)0x50000020)
#define MCMD (*(volatile unsigned int*)0x50000024)
#define MADR (*(volatile unsigned int*)0x50000028)
#define MWTD (*(volatile unsigned int*)0x5000002C)
#define MRDD (*(volatile unsigned int*)0x50000030)
#define MIND (*(volatile unsigned int*)0x50000034)
#define SA0  (*(volatile unsigned int*)0x50000040)
#define SA1  (*(volatile unsigned int*)0x50000044)
#define SA2  (*(volatile unsigned int*)0x50000048)
// Control Registers
#define ETHCOMMAND         (*(volatile unsigned int*)0x50000100)
#define ETHSTATUS          (*(volatile unsigned int*)0x50000104)
#define RXDESCRIPTOR       (*(volatile unsigned int*)0x50000108)
#define RXSTATUS           (*(volatile unsigned int*)0x5000010C)
#define RXDESCRIPTORNUMBER (*(volatile unsigned int*)0x50000110)
#define RXPRODUCEINDEX     (*(volatile unsigned int*)0x50000114)
#define RXCONSUMEINDEX     (*(volatile unsigned int*)0x50000118)
#define TXDESCRIPTOR       (*(volatile unsigned int*)0x5000011C)
#define TXSTATUS           (*(volatile unsigned int*)0x50000120)
#define TXDESCRIPTORNUMBER (*(volatile unsigned int*)0x50000124)
#define TXPRODUCEINDEX     (*(volatile unsigned int*)0x50000128)
#define TXCONSUMEINDEX     (*(volatile unsigned int*)0x5000012C)
#define TSV0               (*(volatile unsigned int*)0x50000158)
#define TSV1               (*(volatile unsigned int*)0x5000015C)
#define RSV                (*(volatile unsigned int*)0x50000160)
#define FLOWCONTROLCOUNTER (*(volatile unsigned int*)0x50000170)
#define FLOWCONTROLSTATUS  (*(volatile unsigned int*)0x50000174)
// Rx Filter Registers
#define RXFILTERCTRL      (*(volatile unsigned int*)0x50000200)
#define RXFILTERWOLSTATUS (*(volatile unsigned int*)0x50000204)
#define RXFILTERWOLCLEAR  (*(volatile unsigned int*)0x50000208)
#define HASHFILTERL       (*(volatile unsigned int*)0x50000210)
#define HASHFILTERH       (*(volatile unsigned int*)0x50000214)
// Module Control Registers
#define INTSTATUS (*(volatile unsigned int*)0x50000FE0)
#define INTENABLE (*(volatile unsigned int*)0x50000FE4)
#define INTCLEAR  (*(volatile unsigned int*)0x50000FE8)
#define INTSET    (*(volatile unsigned int*)0x50000FEC)
#define POWERDOWN (*(volatile unsigned int*)0x50000FF4)

/**************USB Device Controller**************/
// Clock Control Registers
#define USBCLKCTRL (*(volatile unsigned int*)0x5000CFF4)
#define USBCLKST   (*(volatile unsigned int*)0x5000CFF8)
// Device Interrupt Registers
#define USBINTST     (*(volatile unsigned int*)0x400FC1C0)
#define USBDEVINTST  (*(volatile unsigned int*)0x5000C200)
#define USBDEVINTEN  (*(volatile unsigned int*)0x5000C204)
#define USBDEVINTCLR (*(volatile unsigned int*)0x5000C208)
#define USBDEVINTSET (*(volatile unsigned int*)0x5000C20C)
#define USBDEVINTPRI (*(volatile unsigned int*)0x5000C22C)
// Endpoint Interrupt Registers
#define USBEPINTST  (*(volatile unsigned int*)0x5000C230)
#define USBEPINTEN  (*(volatile unsigned int*)0x5000C234)
#define USBEPINTCLR (*(volatile unsigned int*)0x5000C238)
#define USBEPINTSET (*(volatile unsigned int*)0x5000C23C)
#define USBEPINTPRI (*(volatile unsigned int*)0x5000C240)
// Endpoint Realization Registers
#define USBREEP     (*(volatile unsigned int*)0x5000C244)
#define USBEPIN     (*(volatile unsigned int*)0x5000C248)
#define USBMAXPSIZE (*(volatile unsigned int*)0x5000C24C)
// USB Transfer Registers
#define USBRXDATA (*(volatile unsigned int*)0x5000C218)
#define USBRXPLEN (*(volatile unsigned int*)0x5000C220)
#define USBTXDATA (*(volatile unsigned int*)0x5000C21C)
#define USBTXPLEN (*(volatile unsigned int*)0x5000C224)
#define USBCTRL   (*(volatile unsigned int*)0x5000C228)
// SIE Command Registers
#define USBCMDCODE (*(volatile unsigned int*)0x5000C210)
#define USBCMDDATA (*(volatile unsigned int*)0x5000C214)
// DMA Registers
#define USBDMARST       (*(volatile unsigned int*)0x5000C250)
#define USBDMARCLR      (*(volatile unsigned int*)0x5000C254)
#define USBDMARSET      (*(volatile unsigned int*)0x5000C258)
#define USBUDCAH        (*(volatile unsigned int*)0x5000C280)
#define USBEPDMAST      (*(volatile unsigned int*)0x5000C284)
#define USBEPDMAEN      (*(volatile unsigned int*)0x5000C288)
#define USBEPDMADIS     (*(volatile unsigned int*)0x5000C28C)
#define USBDMAINTST     (*(volatile unsigned int*)0x5000C290)
#define USBDMAINTEN     (*(volatile unsigned int*)0x5000C294)
#define USBEOTINTST     (*(volatile unsigned int*)0x5000C2A0)
#define USBEOTINTCLR    (*(volatile unsigned int*)0x5000C2A4)
#define USBEOTINTSET    (*(volatile unsigned int*)0x5000C2A8)
#define USBNDDRINTST    (*(volatile unsigned int*)0x5000C2AC)
#define USBNDDRINTCLR   (*(volatile unsigned int*)0x5000C2B0)
#define USBNDDRINTSET   (*(volatile unsigned int*)0x5000C2B4)
#define USBSYSERRINTST  (*(volatile unsigned int*)0x5000C2B8)
#define USBSYSERRINTCLR (*(volatile unsigned int*)0x5000C2BC)
#define USBSYSERRINTSET (*(volatile unsigned int*)0x5000C2C0)

/**************USB Host Controller**************/
#define HCREVISION         (*(volatile unsigned int*)0x5000C000)
#define HCCONTROL          (*(volatile unsigned int*)0x5000C004)
#define HCCOMMANDSTATUS    (*(volatile unsigned int*)0x5000C008)
#define HCINTERRUPTSTATUS  (*(volatile unsigned int*)0x5000C00C)
#define HCINTERRUPTENABLE  (*(volatile unsigned int*)0x5000C010)
#define HCINTERRUPTDISABLE (*(volatile unsigned int*)0x5000C014)
#define HCHCCA             (*(volatile unsigned int*)0x5000C018)
#define HCPERIODCURRENTED  (*(volatile unsigned int*)0x5000C01C)
#define HCCONTROLHEADED    (*(volatile unsigned int*)0x5000C020)
#define HCCONTROLCURRENTED (*(volatile unsigned int*)0x5000C024)
#define HCBULKHEADED       (*(volatile unsigned int*)0x5000C028)
#define HCBULKCURRENTED    (*(volatile unsigned int*)0x5000C02C)
#define HCDONEHEAD         (*(volatile unsigned int*)0x5000C030)
#define HCFMINTERVAL       (*(volatile unsigned int*)0x5000C034)
#define HCFMREMAINING      (*(volatile unsigned int*)0x5000C038)
#define HCFMNUMBER         (*(volatile unsigned int*)0x5000C03C)
#define HCPERIODICSTART    (*(volatile unsigned int*)0x5000C040)
#define HCLSTHRESHOLD      (*(volatile unsigned int*)0x5000C044)
#define HCRHDESCRIPTORA    (*(volatile unsigned int*)0x5000C048)
#define HCRHDESCRIPTORB    (*(volatile unsigned int*)0x5000C04C)
#define HCRHSTATUS         (*(volatile unsigned int*)0x5000C050)
#define HCRHPORTSTATUS1    (*(volatile unsigned int*)0x5000C054)
#define HCRHPORTSTATUS2    (*(volatile unsigned int*)0x5000C058)
#define MODULEIDVERREVID   (*(volatile unsigned int*)0x5000C0FC)

/**************USB OTG**************/
// Interrupt Register
#define USBINTST (*(volatile unsigned int*)0x400FC1C0)
// OTG Registers
#define OTGINTST  (*(volatile unsigned int*)0x5000C100)
#define OTGINTEN  (*(volatile unsigned int*)0x5000C104)
#define OTGINTSET (*(volatile unsigned int*)0x5000C108)
#define OTGINTCLR (*(volatile unsigned int*)0x5000C10C)
#define OTGSTCTRL (*(volatile unsigned int*)0x5000C110)
#define OTGTMR    (*(volatile unsigned int*)0x5000C114)
// I2C Registers
#define I2CRX    (*(volatile unsigned int*)0x5000C300)
#define I2CTX    (*(volatile unsigned int*)0x5000C300)
#define I2CSTS   (*(volatile unsigned int*)0x5000C304)
#define I2CCTL   (*(volatile unsigned int*)0x5000C308)
#define I2CCLKHI (*(volatile unsigned int*)0x5000C30C)
#define I2CCLKLO (*(volatile unsigned int*)0x5000C310)
// Clock Control Registers
#define OTGCLKCTRL (*(volatile unsigned int*)0x5000CFF4)
#define OTGCLKST   (*(volatile unsigned int*)0x5000CFF8)

/**************UART**************/
// Receive Buffer Registers
#define U0RBR (*(volatile unsigned int*)0x4000C000)
#define U1RBR (*(volatile unsigned int*)0x40010000)
#define U2RBR (*(volatile unsigned int*)0x40098000)
#define U3RBR (*(volatile unsigned int*)0x4009C000)
// Transmit Holding Registers
#define U0THR (*(volatile unsigned int*)0x4000C000)
#define U1THR (*(volatile unsigned int*)0x40010000)
#define U2THR (*(volatile unsigned int*)0x40098000)
#define U3THR (*(volatile unsigned int*)0x4009C000)
// Divisor Latch LSB
#define U0DLL (*(volatile unsigned int*)0x4000C000)
#define U1DLL (*(volatile unsigned int*)0x40010000)
#define U2DLL (*(volatile unsigned int*)0x40098000)
#define U3DLL (*(volatile unsigned int*)0x4009C000)
// Divisor Latch MSB
#define U0DLM (*(volatile unsigned int*)0x4000C004)
#define U1DLM (*(volatile unsigned int*)0x40010004)
#define U2DLM (*(volatile unsigned int*)0x40098004)
#define U3DLM (*(volatile unsigned int*)0x4009C004)
// Interrupt Enable Registers
#define U0IER (*(volatile unsigned int*)0x4000C004)
#define U1IER (*(volatile unsigned int*)0x40010004)
#define U2IER (*(volatile unsigned int*)0x40098004)
#define U3IER (*(volatile unsigned int*)0x4009C004)
// Interrupt ID Registers
#define U0IIR (*(volatile unsigned int*)0x4000C008)
#define U1IIR (*(volatile unsigned int*)0x40010008)
#define U2IIR (*(volatile unsigned int*)0x40098008)
#define U3IIR (*(volatile unsigned int*)0x4009C008)
// FIFO Control Registers
#define U0FCR (*(volatile unsigned int*)0x4000C008)
#define U1FCR (*(volatile unsigned int*)0x40010008)
#define U2FCR (*(volatile unsigned int*)0x40098008)
#define U3FCR (*(volatile unsigned int*)0x4009C008)
// Line Control Registers
#define U0LCR (*(volatile unsigned int*)0x4000C00C)
#define U1LCR (*(volatile unsigned int*)0x4001000C)
#define U2LCR (*(volatile unsigned int*)0x4009800C)
#define U3LCR (*(volatile unsigned int*)0x4009C00C)
// Line Status Registers
#define U0LSR (*(volatile unsigned int*)0x4000C014)
#define U1LSR (*(volatile unsigned int*)0x40010014)
#define U2LSR (*(volatile unsigned int*)0x40098014)
#define U3LSR (*(volatile unsigned int*)0x4009C014)
// Scratch Pad Register
#define U0SCR (*(volatile unsigned int*)0x4000C01C)
#define U1SCR (*(volatile unsigned int*)0x4001001C)
#define U2SCR (*(volatile unsigned int*)0x4009801C)
#define U3SCR (*(volatile unsigned int*)0x4009C01C)
// Auto-baud Control Registers
#define U0ACR (*(volatile unsigned int*)0x4000C020)
#define U1ACR (*(volatile unsigned int*)0x40010020)
#define U2ACR (*(volatile unsigned int*)0x40098020)
#define U3ACR (*(volatile unsigned int*)0x4009C020)
// IRDA Control Register
#define U0ICR (*(volatile unsigned int*)0x4000C024)
#define U2ICR (*(volatile unsigned int*)0x40098024)
#define U3ICR (*(volatile unsigned int*)0x4009C024)
// Fractional Divider Register
#define U0FDR (*(volatile unsigned int*)0x4000C028)
#define U1FDR (*(volatile unsigned int*)0x40010028)
#define U2FDR (*(volatile unsigned int*)0x40098028)
#define U3FDR (*(volatile unsigned int*)0x4009C028)
// Transmit Enable Register
#define U0TER (*(volatile unsigned int*)0x4000C030)
#define U1TER (*(volatile unsigned int*)0x40010030)
#define U2TER (*(volatile unsigned int*)0x40098030)
#define U3TER (*(volatile unsigned int*)0x4009C030)
// Modem Registers
#define U1MCR (*(volatile unsigned int*)0x40010010)
#define U1MSR (*(volatile unsigned int*)0x40010018)
// RS-485/EIA-485 Registers
#define U1RS485CTRL  (*(volatile unsigned int*)0x4001004C)
#define U1RS485MATCH (*(volatile unsigned int*)0x40010050)
#define U1RS485DLY   (*(volatile unsigned int*)0x40010054)

/**************CAN**************/
// Acceptance Filter and Central CAN Registers
#define AFMR       (*(volatile unsigned int*)0x4003C000)
#define SFFSA      (*(volatile unsigned int*)0x4003C004)
#define SFFGRPSA   (*(volatile unsigned int*)0x4003C008)
#define EFFSA      (*(volatile unsigned int*)0x4003C00C)
#define EFFGRPSA   (*(volatile unsigned int*)0x4003C010)
#define ENDOFTABLE (*(volatile unsigned int*)0x4003C014)
#define LUTERRAD   (*(volatile unsigned int*)0x4003C018)
#define LUTERR     (*(volatile unsigned int*)0x4003C01C)
#define CANTXSR    (*(volatile unsigned int*)0x40040000)
#define CANRXSR    (*(volatile unsigned int*)0x40040004)
#define CANMSR     (*(volatile unsigned int*)0x40040008)
// CAN1/2 Control Registers
#define CAN1MOD  (*(volatile unsigned int*)0x40044000)
#define CAN2MOD  (*(volatile unsigned int*)0x40048000)
#define CAN1CMR  (*(volatile unsigned int*)0x40044004)
#define CAN2CMR  (*(volatile unsigned int*)0x40048004)
#define CAN1GSR  (*(volatile unsigned int*)0x40044008)
#define CAN2GSR  (*(volatile unsigned int*)0x40048008)
#define CAN1ICR  (*(volatile unsigned int*)0x4004400C)
#define CAN2ICR  (*(volatile unsigned int*)0x4004800C)
#define CAN1IER  (*(volatile unsigned int*)0x40044010)
#define CAN2IER  (*(volatile unsigned int*)0x40048010)
#define CAN1BTR  (*(volatile unsigned int*)0x40044014)
#define CAN2BTR  (*(volatile unsigned int*)0x40048014)
#define CAN1EWL  (*(volatile unsigned int*)0x40044018)
#define CAN2EWL  (*(volatile unsigned int*)0x40048018)
#define CAN1SR   (*(volatile unsigned int*)0x4004401C)
#define CAN2SR   (*(volatile unsigned int*)0x4004801C)
#define CAN1RFS  (*(volatile unsigned int*)0x40044020)
#define CAN2RFS  (*(volatile unsigned int*)0x40048020)
#define CAN1RID  (*(volatile unsigned int*)0x40044024)
#define CAN2RID  (*(volatile unsigned int*)0x40048024)
#define CAN1RDA  (*(volatile unsigned int*)0x40044028)
#define CAN2RDA  (*(volatile unsigned int*)0x40048028)
#define CAN1RDB  (*(volatile unsigned int*)0x4004402C)
#define CAN2RDB  (*(volatile unsigned int*)0x4004802C)
#define CAN1TFI1 (*(volatile unsigned int*)0x40044030)
#define CAN2TFI1 (*(volatile unsigned int*)0x40048030)
#define CAN1TID1 (*(volatile unsigned int*)0x40044034)
#define CAN2TID1 (*(volatile unsigned int*)0x40048034)
#define CAN1TDA1 (*(volatile unsigned int*)0x40044038)
#define CAN2TDA1 (*(volatile unsigned int*)0x40048038)
#define CAN1TDB1 (*(volatile unsigned int*)0x4004403C)
#define CAN2TDB1 (*(volatile unsigned int*)0x4004803C)
#define CAN1TFI2 (*(volatile unsigned int*)0x40044040)
#define CAN2TFI2 (*(volatile unsigned int*)0x40048040)
#define CAN1TID2 (*(volatile unsigned int*)0x40044044)
#define CAN2TID2 (*(volatile unsigned int*)0x40048044)
#define CAN1TDA2 (*(volatile unsigned int*)0x40044048)
#define CAN2TDA2 (*(volatile unsigned int*)0x40048048)
#define CAN1TDB2 (*(volatile unsigned int*)0x4004404C)
#define CAN2TDB2 (*(volatile unsigned int*)0x4004804C)
#define CAN1TFI3 (*(volatile unsigned int*)0x40044050)
#define CAN2TFI3 (*(volatile unsigned int*)0x40048050)
#define CAN1TID3 (*(volatile unsigned int*)0x40044054)
#define CAN2TID3 (*(volatile unsigned int*)0x40048054)
#define CAN1TDA3 (*(volatile unsigned int*)0x40044058)
#define CAN2TDA3 (*(volatile unsigned int*)0x40048058)
#define CAN1TDB3 (*(volatile unsigned int*)0x4004405C)
#define CAN2TDB3 (*(volatile unsigned int*)0x4004805C)

/**************SPI**************/
#define S0SPCR  (*(volatile unsigned int*)0x40020000)
#define S0SPSR  (*(volatile unsigned int*)0x40020004)
#define S0SPDR  (*(volatile unsigned int*)0x40020008)
#define S0SPCCR (*(volatile unsigned int*)0x4002000C)
#define S0SPINT (*(volatile unsigned int*)0x4002001C)

/**************SSP**************/
#define SSP0CR0   (*(volatile unsigned int*)0x40088000)
#define SSP1CR0   (*(volatile unsigned int*)0x40030000)
#define SSP0CR1   (*(volatile unsigned int*)0x40088004)
#define SSP1CR1   (*(volatile unsigned int*)0x40030004)
#define SSP0DR    (*(volatile unsigned int*)0x40088008)
#define SSP1DR    (*(volatile unsigned int*)0x40030008)
#define SSP0SR    (*(volatile unsigned int*)0x4008800C)
#define SSP1SR    (*(volatile unsigned int*)0x4003000C)
#define SSP0CPSR  (*(volatile unsigned int*)0x40088010)
#define SSP1CPSR  (*(volatile unsigned int*)0x40030010)
#define SSP0IMSC  (*(volatile unsigned int*)0x40088014)
#define SSP1IMSC  (*(volatile unsigned int*)0x40030014)
#define SSP0RIS   (*(volatile unsigned int*)0x40088018)
#define SSP1RIS   (*(volatile unsigned int*)0x40030018)
#define SSP0MIS   (*(volatile unsigned int*)0x4008801C)
#define SSP1MIS   (*(volatile unsigned int*)0x4003001C)
#define SSP0ICR   (*(volatile unsigned int*)0x40088020)
#define SSP1ICR   (*(volatile unsigned int*)0x40030020)
#define SSP0DMACR (*(volatile unsigned int*)0x40088024)
#define SSP1DMACR (*(volatile unsigned int*)0x40030024)

/**************I2C**************/
// I2C Control Set Registers
#define I2C0CONSET (*(volatile unsigned int*)0x4001C000)
#define I2C1CONSET (*(volatile unsigned int*)0x4005C000)
#define I2C2CONSET (*(volatile unsigned int*)0x400A0000)
// I2C Status Registers	
#define I2C0STAT (*(volatile unsigned int*)0x4001C004)
#define I2C1STAT (*(volatile unsigned int*)0x4005C004)
#define I2C2STAT (*(volatile unsigned int*)0x400A0004)
// I2C Data Registers
#define I2C0DAT (*(volatile unsigned int*)0x4001C008)
#define I2C1DAT (*(volatile unsigned int*)0x4005C008)
#define I2C2DAT (*(volatile unsigned int*)0x400A0008)
// I2C Slave Address Registers 0
#define I2C0ADR0 (*(volatile unsigned int*)0x4001C00C)
#define I2C1ADR0 (*(volatile unsigned int*)0x4005C00C)
#define I2C2ADR0 (*(volatile unsigned int*)0x400A000C)
// SCH Duty Cycle Registers High
#define I2C0SCLH (*(volatile unsigned int*)0x4001C010)
#define I2C1SCLH (*(volatile unsigned int*)0x4005C010)
#define I2C2SCLH (*(volatile unsigned int*)0x400A0010)
// SCH Duty Cycle Registers Low
#define I2C0SCLL (*(volatile unsigned int*)0x4001C014)
#define I2C1SCLL (*(volatile unsigned int*)0x4005C014)
#define I2C2SCLL (*(volatile unsigned int*)0x400A0014)
// I2C Control Clear Registers
#define I2C0CONCLR (*(volatile unsigned int*)0x4001C018)
#define I2C1CONCLR (*(volatile unsigned int*)0x4005C018)
#define I2C2CONCLR (*(volatile unsigned int*)0x400A0018)
// Monitor Mode Control Registers
#define I2C0MMCTRL (*(volatile unsigned int*)0x4001C01C)
#define I2C1MMCTRL (*(volatile unsigned int*)0x4005C01C)
#define I2C2MMCTRL (*(volatile unsigned int*)0x400A001C)
// I2C Slave Address Registers 1
#define I2C0ADR1 (*(volatile unsigned int*)0x4001C020)
#define I2C1ADR1 (*(volatile unsigned int*)0x4005C020)
#define I2C2ADR1 (*(volatile unsigned int*)0x400A0020)
// I2C Slave Address Registers 2
#define I2C0ADR2 (*(volatile unsigned int*)0x4001C024)
#define I2C1ADR2 (*(volatile unsigned int*)0x4005C024)
#define I2C2ADR2 (*(volatile unsigned int*)0x400A0024)
// I2C Slave Address Registers 3
#define I2C0ADR3 (*(volatile unsigned int*)0x4001C028)
#define I2C1ADR3 (*(volatile unsigned int*)0x4005C028)
#define I2C2ADR3 (*(volatile unsigned int*)0x400A0028)
// Data Buffer Registers
#define I2C0DATABUFFER (*(volatile unsigned int*)0x4001C02C)
#define I2C1DATABUFFER (*(volatile unsigned int*)0x4005C02C)
#define I2C2DATABUFFER (*(volatile unsigned int*)0x400A002C)
// I2C Slave Address Mask Registers 0
#define I2C0MASK0 (*(volatile unsigned int*)0x4001C030)
#define I2C1MASK0 (*(volatile unsigned int*)0x4005C030)
#define I2C2MASK0 (*(volatile unsigned int*)0x400A0030)
// I2C Slave Address Mask Registers 1
#define I2C0MASK1 (*(volatile unsigned int*)0x4001C034)
#define I2C1MASK1 (*(volatile unsigned int*)0x4005C034)
#define I2C2MASK1 (*(volatile unsigned int*)0x400A0034)
// I2C Slave Address Mask Registers 2
#define I2C0MASK2 (*(volatile unsigned int*)0x4001C038)
#define I2C1MASK2 (*(volatile unsigned int*)0x4005C038)
#define I2C2MASK2 (*(volatile unsigned int*)0x400A0038)
// I2C Slave Address Mask Registers 3
#define I2C0MASK3 (*(volatile unsigned int*)0x4001C03C)
#define I2C1MASK3 (*(volatile unsigned int*)0x4005C03C)
#define I2C2MASK3 (*(volatile unsigned int*)0x400A003C)

/**************I2S**************/
#define I2SDAO       (*(volatile unsigned int*)0x400A8000)
#define I2SDAI       (*(volatile unsigned int*)0x400A8004)
#define I2STXFIFO    (*(volatile unsigned int*)0x400A8008)
#define I2SRXFIFO    (*(volatile unsigned int*)0x400A800C)
#define I2SSTATE     (*(volatile unsigned int*)0x400A8010)
#define I2SDMA1      (*(volatile unsigned int*)0x400A8014)
#define I2SDMA2      (*(volatile unsigned int*)0x400A8018)
#define I2SIRQ       (*(volatile unsigned int*)0x400A801C)
#define I2STXRATE    (*(volatile unsigned int*)0x400A8020)
#define I2SRXRATE    (*(volatile unsigned int*)0x400A8024)
#define I2STXBITRATE (*(volatile unsigned int*)0x400A8028)
#define I2SRXBITRATE (*(volatile unsigned int*)0x400A802C)
#define I2STXMODE    (*(volatile unsigned int*)0x400A8030)
#define I2SRXMODE    (*(volatile unsigned int*)0x400A8034)

/**************Timers/Counters**************/
// Interrupt Registers
#define T0IR (*(volatile unsigned int*)0x40004000)
#define T1IR (*(volatile unsigned int*)0x40008000)
#define T2IR (*(volatile unsigned int*)0x40090000)
#define T3IR (*(volatile unsigned int*)0x40094000)
// Timer Control Registers
#define T0TCR (*(volatile unsigned int*)0x40004004)
#define T1TCR (*(volatile unsigned int*)0x40008004)
#define T2TCR (*(volatile unsigned int*)0x40090004)
#define T3TCR (*(volatile unsigned int*)0x40094004)
// Timer Counters
#define T0TC (*(volatile unsigned int*)0x40004008)
#define T1TC (*(volatile unsigned int*)0x40008008)
#define T2TC (*(volatile unsigned int*)0x40090008)
#define T3TC (*(volatile unsigned int*)0x40094008)
// Prescale Registers
#define T0PR (*(volatile unsigned int*)0x4000400C)
#define T1PR (*(volatile unsigned int*)0x4000800C)
#define T2PR (*(volatile unsigned int*)0x4009000C)
#define T3PR (*(volatile unsigned int*)0x4009400C)
// Prescale Counters
#define T0PC (*(volatile unsigned int*)0x40004010)
#define T1PC (*(volatile unsigned int*)0x40008010)
#define T2PC (*(volatile unsigned int*)0x40090010)
#define T3PC (*(volatile unsigned int*)0x40094010)
// Match Control Registers
#define T0MCR (*(volatile unsigned int*)0x40004014)
#define T1MCR (*(volatile unsigned int*)0x40008014)
#define T2MCR (*(volatile unsigned int*)0x40090014)
#define T3MCR (*(volatile unsigned int*)0x40094014)
// Match Registers 0
#define T0MR0 (*(volatile unsigned int*)0x40004018)
#define T1MR0 (*(volatile unsigned int*)0x40008018)
#define T2MR0 (*(volatile unsigned int*)0x40090018)
#define T3MR0 (*(volatile unsigned int*)0x40094018)
// Match Registers 1
#define T0MR1 (*(volatile unsigned int*)0x4000401C)
#define T1MR1 (*(volatile unsigned int*)0x4000801C)
#define T2MR1 (*(volatile unsigned int*)0x4009001C)
#define T3MR1 (*(volatile unsigned int*)0x4009401C)
// Match Registers 2
#define T0MR2 (*(volatile unsigned int*)0x40004020)
#define T1MR2 (*(volatile unsigned int*)0x40008020)
#define T2MR2 (*(volatile unsigned int*)0x40090020)
#define T3MR2 (*(volatile unsigned int*)0x40094020)
// Match Registers 3
#define T0MR3 (*(volatile unsigned int*)0x40004024)
#define T1MR3 (*(volatile unsigned int*)0x40008024)
#define T2MR3 (*(volatile unsigned int*)0x40090024)
#define T3MR3 (*(volatile unsigned int*)0x40094024)
// Capture Control Registers
#define T0CCR (*(volatile unsigned int*)0x40004028)
#define T1CCR (*(volatile unsigned int*)0x40008028)
#define T2CCR (*(volatile unsigned int*)0x40090028)
#define T3CCR (*(volatile unsigned int*)0x40094028)
// Capture Registers 0
#define T0CR0 (*(volatile unsigned int*)0x4000402C)
#define T1CR0 (*(volatile unsigned int*)0x4000802C)
#define T2CR0 (*(volatile unsigned int*)0x4009002C)
#define T3CR0 (*(volatile unsigned int*)0x4009402C)
// Capture Registers 1
#define T0CR1 (*(volatile unsigned int*)0x40004030)
#define T1CR1 (*(volatile unsigned int*)0x40008030)
#define T2CR1 (*(volatile unsigned int*)0x40090030)
#define T3CR1 (*(volatile unsigned int*)0x40094030)
// External Match Registers
#define T0EMR (*(volatile unsigned int*)0x4000403C)
#define T1EMR (*(volatile unsigned int*)0x4000803C)
#define T2EMR (*(volatile unsigned int*)0x4009003C)
#define T3EMR (*(volatile unsigned int*)0x4009403C)
// Count Control Registers
#define T0CTCR (*(volatile unsigned int*)0x40004070)
#define T1CTCR (*(volatile unsigned int*)0x40008070)
#define T2CTCR (*(volatile unsigned int*)0x40090070)
#define T3CTCR (*(volatile unsigned int*)0x40094070)

/**************RIT**************/
#define RICOMPVAL (*(volatile unsigned int*)0x400B0000)
#define RIMASK    (*(volatile unsigned int*)0x400B0004)
#define RICTRL    (*(volatile unsigned int*)0x400B0008)
#define RICOUNTER (*(volatile unsigned int*)0x400B000C)

/**************System Tick Timer**************/
#define STCTRL   (*(volatile unsigned int*)0xE000E010)
#define STRELOAD (*(volatile unsigned int*)0xE000E014)
#define STCURR   (*(volatile unsigned int*)0xE000E018)
#define STCALIB  (*(volatile unsigned int*)0xE000E01C)

/**************PWM**************/
#define PWM1IR   (*(volatile unsigned int*)0x40018000)
#define PWM1TCR  (*(volatile unsigned int*)0x40018004)
#define PWM1TC   (*(volatile unsigned int*)0x40018008)
#define PWM1PR   (*(volatile unsigned int*)0x4001800C)
#define PWM1PC   (*(volatile unsigned int*)0x40018010)
#define PWM1MCR  (*(volatile unsigned int*)0x40018014)
#define PWM1MR0  (*(volatile unsigned int*)0x40018018)
#define PWM1MR1  (*(volatile unsigned int*)0x4001801C)
#define PWM1MR2  (*(volatile unsigned int*)0x40018020)
#define PWM1MR3  (*(volatile unsigned int*)0x40018024)
#define PWM1CCR  (*(volatile unsigned int*)0x40018028)
#define PWM1CR0  (*(volatile unsigned int*)0x4001802C)
#define PWM1CR1  (*(volatile unsigned int*)0x40018030)
#define PWM1CR2  (*(volatile unsigned int*)0x40018034)
#define PWM1CR3  (*(volatile unsigned int*)0x40018038)
#define PWM1MR4  (*(volatile unsigned int*)0x40018040)
#define PWM1MR5  (*(volatile unsigned int*)0x40018044)
#define PWM1MR6  (*(volatile unsigned int*)0x40018048)
#define PWM1PCR  (*(volatile unsigned int*)0x4001804C)
#define PWM1LER  (*(volatile unsigned int*)0x40018050)
#define PWM1CTCR (*(volatile unsigned int*)0x40018070)

/**************Motor Control PWM**************/
#define MCCON       (*(volatile unsigned int*)0x400B8000)
#define MCCONSET    (*(volatile unsigned int*)0x400B8004)
#define MCCONCLR    (*(volatile unsigned int*)0x400B8008)
#define MCCAPCON    (*(volatile unsigned int*)0x400B800C)
#define MCCAPCONSET (*(volatile unsigned int*)0x400B8010)
#define MCCAPCONCLR (*(volatile unsigned int*)0x400B8014)
#define MCTC0       (*(volatile unsigned int*)0x400B8018)
#define MCTC1       (*(volatile unsigned int*)0x400B801C)
#define MCTC2       (*(volatile unsigned int*)0x400B8020)
#define MCLIM0      (*(volatile unsigned int*)0x400B8024)
#define MCLIM1      (*(volatile unsigned int*)0x400B8028)
#define MCLIM2      (*(volatile unsigned int*)0x400B802C)
#define MCMAT0      (*(volatile unsigned int*)0x400B8030)
#define MCMAT1      (*(volatile unsigned int*)0x400B8034)
#define MCMAT2      (*(volatile unsigned int*)0x400B8038)
#define MCDT        (*(volatile unsigned int*)0x400B803C)
#define MCCP        (*(volatile unsigned int*)0x400B8040)
#define MCCAP0      (*(volatile unsigned int*)0x400B8044)
#define MCCAP1      (*(volatile unsigned int*)0x400B8048)
#define MCCAP2      (*(volatile unsigned int*)0x400B804C)
#define MCINTEN     (*(volatile unsigned int*)0x400B8050)
#define MCINTENSET  (*(volatile unsigned int*)0x400B8054)
#define MCINTENCLR  (*(volatile unsigned int*)0x400B8058)
#define MCCNTCON    (*(volatile unsigned int*)0x400B805C)
#define MCCNTCONSET (*(volatile unsigned int*)0x400B8060)
#define MCCNTCONCLR (*(volatile unsigned int*)0x400B8064)
#define MCINTF      (*(volatile unsigned int*)0x400B8068)
#define MCINTFSET   (*(volatile unsigned int*)0x400B806C)
#define MCINTFCLR   (*(volatile unsigned int*)0x400B8070)
#define MCCAPCLR    (*(volatile unsigned int*)0x400B8074)

/**************Quadrature Encoder**************/
// Control Registers
#define QEICON  (*(volatile unsigned int*)0x400BC000)
#define QEICONF (*(volatile unsigned int*)0x400BC008)
#define QEISTAT (*(volatile unsigned int*)0x400BC004)
//Position, Index, and Timer Registers
#define QEIPOS    (*(volatile unsigned int*)0x400BC00C)
#define QEIMAXPOS (*(volatile unsigned int*)0x400BC010)
#define CMPOS0    (*(volatile unsigned int*)0x400BC014)
#define CMPOS1    (*(volatile unsigned int*)0x400BC018)
#define CMPOS2    (*(volatile unsigned int*)0x400BC01C)
#define INXCNT    (*(volatile unsigned int*)0x400BC020)
#define INXCMP    (*(volatile unsigned int*)0x400BC024)
#define QEILOAD   (*(volatile unsigned int*)0x400BC028)
#define QEITIME   (*(volatile unsigned int*)0x400BC02C)
#define QEIVEL    (*(volatile unsigned int*)0x400BC030)
#define QEICAP    (*(volatile unsigned int*)0x400BC034)
#define VELCOMP   (*(volatile unsigned int*)0x400BC038)
#define FILTER    (*(volatile unsigned int*)0x400BC03C)
// Interrupt Registers
#define QEIINTSTAT (*(volatile unsigned int*)0x400BCFE0)
#define QEISET     (*(volatile unsigned int*)0x400BCFEC)
#define QEICLR     (*(volatile unsigned int*)0x400BCFE8)
#define QEIIE      (*(volatile unsigned int*)0x400BCFE4)
#define QEIIES     (*(volatile unsigned int*)0x400BCFDC)
#define QEIIEC     (*(volatile unsigned int*)0x400BCFD8)

/**************RTC**************/
// Misc Registers
#define ILR      (*(volatile unsigned int*)0x40024000)
#define CCR      (*(volatile unsigned int*)0x40024008)
#define CIIR     (*(volatile unsigned int*)0x4002400C)
#define AMR      (*(volatile unsigned int*)0x40024010)
#define RTCAUX   (*(volatile unsigned int*)0x4002405C)
#define RTCAUXEN (*(volatile unsigned int*)0x40024058)
// Consolidated Time Registers
#define CTIME0 (*(volatile unsigned int*)0x40024014)
#define CTIME1 (*(volatile unsigned int*)0x40024018)
#define CTIME2 (*(volatile unsigned int*)0x4002401C)
// Timer Counter Registers
#define RTCSEC         (*(volatile unsigned int*)0x40024020)
#define RTCMIN         (*(volatile unsigned int*)0x40024024)
#define RTCHOUR        (*(volatile unsigned int*)0x40024028)
#define RTCDOM         (*(volatile unsigned int*)0x4002402C)
#define RTCDOW         (*(volatile unsigned int*)0x40024030)
#define RTCDOY         (*(volatile unsigned int*)0x40024034)
#define RTCMONTH       (*(volatile unsigned int*)0x40024038)
#define RTCYEAR        (*(volatile unsigned int*)0x4002403C)
#define RTCCALIBRATION (*(volatile unsigned int*)0x40024040)
// General Purpose Registers
#define GPREG0 (*(volatile unsigned int*)0x40024044)
#define GPREG1 (*(volatile unsigned int*)0x40024048)
#define GPREG2 (*(volatile unsigned int*)0x4002404C)
#define GPREG3 (*(volatile unsigned int*)0x40024050)
#define GPREG4 (*(volatile unsigned int*)0x40024054)
// Alarm Register Group
#define RTCALSEC  (*(volatile unsigned int*)0x40024060)
#define RTCALMIN  (*(volatile unsigned int*)0x40024064)
#define RTCALHOUR (*(volatile unsigned int*)0x40024068)
#define RTCALDOM  (*(volatile unsigned int*)0x4002406C)
#define RTCALDOW  (*(volatile unsigned int*)0x40024070)
#define RTCALDOY  (*(volatile unsigned int*)0x40024074)
#define RTCALMON  (*(volatile unsigned int*)0x40024078)
#define RTCALYEAR (*(volatile unsigned int*)0x4002407C)

/**************WDT**************/
#define WDMOD    (*(volatile unsigned int*)0x40000000)
#define WDTC     (*(volatile unsigned int*)0x40000004)
#define WDFEED   (*(volatile unsigned int*)0x40000008)
#define WDTV     (*(volatile unsigned int*)0x4000000C)
#define WDCLKSEL (*(volatile unsigned int*)0x40000010)

/**************ADC**************/
#define AD0CR    (*(volatile unsigned int*)0x40034000)
#define AD0GDR   (*(volatile unsigned int*)0x40034004)
#define AD0INTEN (*(volatile unsigned int*)0x4003400C)
#define AD0DR0   (*(volatile unsigned int*)0x40034010)
#define AD0DR1   (*(volatile unsigned int*)0x40034014)
#define AD0DR2   (*(volatile unsigned int*)0x40034018)
#define AD0DR3   (*(volatile unsigned int*)0x4003401C)
#define AD0DR4   (*(volatile unsigned int*)0x40034020)
#define AD0DR5   (*(volatile unsigned int*)0x40034024)
#define AD0DR6   (*(volatile unsigned int*)0x40034028)
#define AD0DR7   (*(volatile unsigned int*)0x4003402C)
#define AD0STAT  (*(volatile unsigned int*)0x40034030)
#define AD0TRM   (*(volatile unsigned int*)0x40034034)

/**************DAC**************/
#define DACR      (*(volatile unsigned int*)0x4008C000)
#define DACCTRL   (*(volatile unsigned int*)0x4008C004)
#define DACCNTVAL (*(volatile unsigned int*)0x4008C008)

/**************GPDMA**************/
// General Registers
#define DMACINTSTAT       (*(volatile unsigned int*)0x50004000)
#define DMACINTTCSTAT     (*(volatile unsigned int*)0x50004004)
#define DMACINTTCCLEAR    (*(volatile unsigned int*)0x50004008)
#define DMACIntErrStat    (*(volatile unsigned int*)0x5000400C)
#define DMACINTERRCLR     (*(volatile unsigned int*)0x50004010)
#define DMACRAWINTTCSTAT  (*(volatile unsigned int*)0x50004014)
#define DMACRAWINTERRSTAT (*(volatile unsigned int*)0x50004018)
#define DMACENBLDCHNS     (*(volatile unsigned int*)0x5000401C)
#define DMACSOFTBREQ      (*(volatile unsigned int*)0x50004020)
#define DMACSOFTSREQ      (*(volatile unsigned int*)0x50004024)
#define DMACSOFTLBREQ     (*(volatile unsigned int*)0x50004028)
#define DMACSOFTLSREQ     (*(volatile unsigned int*)0x5000402C)
#define DMACCONFIG        (*(volatile unsigned int*)0x50004030)
#define DMACSYNC          (*(volatile unsigned int*)0x50004034)
#define DMAREQSEL         (*(volatile unsigned int*)0x400FC1C4)
// Channel 0 Registers
#define DMACC0SRCADDR  (*(volatile unsigned int*)0x50004100)
#define DMACC0DESTADDR (*(volatile unsigned int*)0x50004104)
#define DMACC0LLI      (*(volatile unsigned int*)0x50004108)
#define DMACC0CONTROL  (*(volatile unsigned int*)0x5000410C)
#define DMACC0CONFIG   (*(volatile unsigned int*)0x50004110)
// Channel 1 Registers
#define DMACC1SRCADDR  (*(volatile unsigned int*)0x50004120)
#define DMACC1DESTADDR (*(volatile unsigned int*)0x50004124)
#define DMACC1LLI      (*(volatile unsigned int*)0x50004128)
#define DMACC1CONTROL  (*(volatile unsigned int*)0x5000412C)
#define DMACC1CONFIG   (*(volatile unsigned int*)0x50004130)
// Channel 2 Registers
#define DMACC2SRCADDR  (*(volatile unsigned int*)0x50004140)
#define DMACC2DESTADDR (*(volatile unsigned int*)0x50004144)
#define DMACC2LLI      (*(volatile unsigned int*)0x50004148)
#define DMACC2CONTROL  (*(volatile unsigned int*)0x5000414C)
#define DMACC2CONFIG   (*(volatile unsigned int*)0x50004150)
// Channel 3 Registers
#define DMACC3SRCADDR  (*(volatile unsigned int*)0x50004160)
#define DMACC3DESTADDR (*(volatile unsigned int*)0x50004164)
#define DMACC3LLI      (*(volatile unsigned int*)0x50004168)
#define DMACC3CONTROL  (*(volatile unsigned int*)0x5000416C)
#define DMACC3CONFIG   (*(volatile unsigned int*)0x50004170)
// Channel 4 Registers
#define DMACC4SRCADDR  (*(volatile unsigned int*)0x50004180)
#define DMACC4DESTADDR (*(volatile unsigned int*)0x50004184)
#define DMACC4LLI      (*(volatile unsigned int*)0x50004188)
#define DMACC4CONTROL  (*(volatile unsigned int*)0x5000418C)
#define DMACC4CONFIG   (*(volatile unsigned int*)0x50004190)
// Channel 5 Registers
#define DMACC5SRCADDR  (*(volatile unsigned int*)0x500041A0)
#define DMACC5DESTADDR (*(volatile unsigned int*)0x500041A4)
#define DMACC5LLI      (*(volatile unsigned int*)0x500041A8)
#define DMACC5CONTROL  (*(volatile unsigned int*)0x500041AC)
#define DMACC5CONFIG   (*(volatile unsigned int*)0x500041B0)
// Channel 6 Registers
#define DMACC6SRCADDR  (*(volatile unsigned int*)0x500041C0)
#define DMACC6DESTADDR (*(volatile unsigned int*)0x500041C4)
#define DMACC6LLI      (*(volatile unsigned int*)0x500041C8)
#define DMACC6CONTROL  (*(volatile unsigned int*)0x500041CC)
#define DMACC6CONFIG   (*(volatile unsigned int*)0x500041D0)
// Channel 7 Registers
#define DMACC7SRCADDR  (*(volatile unsigned int*)0x500041E0)
#define DMACC7DESTADDR (*(volatile unsigned int*)0x500041E4)
#define DMACC7LLI      (*(volatile unsigned int*)0x500041E8)
#define DMACC7CONTROL  (*(volatile unsigned int*)0x500041EC)
#define DMACC7CONFIG   (*(volatile unsigned int*)0x500041F0)

/**************Flash Memory**************/
// JTAG Flash
#define FMSSTART  (*(volatile unsigned int*)0x40084020)
#define FMSSTOP   (*(volatile unsigned int*)0x40084024)
#define FMSW0     (*(volatile unsigned int*)0x4008402C)
#define FMSW1     (*(volatile unsigned int*)0x40084030)
#define FMSW2     (*(volatile unsigned int*)0x40084034)
#define FMSW3     (*(volatile unsigned int*)0x40084038)
#define FMSTAT    (*(volatile unsigned int*)0x40084FE0)
#define FMSTATCLR (*(volatile unsigned int*)0x40084FE8)

/**************Debug Memory Re-mapping**************/
// Memory Mapping Control Register
#define MEMMAP (*(volatile unsigned int*)0x400FC040)

#endif
