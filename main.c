#include <stm32f10x.h>		//we use stm32f103 chips

//test fake bluepill boards by reading cpuid and dbgmcu_idcode
//cpuid - authentic stm32f103 chips are r0p0
//expect 0x410FC230
//  0x41-> ARM
//  0x1 -> revision 1: expect 0
//  0xF -> constant
//  0xC23> Cortex M3. 0xC20> Cortex M0. 0xC60> Cortex M0+, 0xC21> Cortex M1, 0xC24> Cortex M4
//  0x1 -> patch 1: expect 0
#define CPUID		(SCB->CPUID)		//access cpuid

//dbgmcu_idcode
//dbgmcuid - authentic stm32f103 chips have a bug that dbgmcu_idcode can only be read with a debug probe attached.
// it reads 0x00000000 in run time
//0x440	STM32F030x8
//0x442	STM32F030xC
//0x444	STM32F03xx4
//0x444	STM32F03xx6
//0x445	STM32F04xxx
//0x440	STM32F05xxx
//0x445	STM32F070x6
//0x448	STM32F070xB
//0x448	STM32F071xx
//0x448	STM32F072xx
//0x442	STM32F09xxx
//0x412	STM32F10x: Low-Density
//0x410	STM32F10x: Medium-Density
//0x414	STM32F10x: High-Density
//0x418	STM32F105xx
//0x420	STM32F107: Medium-Density
//0x428	STM32F107: High_Density
//0x430	STM32F107: XL-Density
#define DBGMCUID	(DBGMCU->IDCODE)

int main(void) {
	volatile uint32_t tmp;				//to read the ids

    while(1) {
    	//read the ids - go through this in debug
    	tmp = CPUID;					//read: 0x411fc231, expect: 0x410fc230
    	tmp = DBGMCUID;					//read: 0x20036410, expect: 0x00000000 at run time
    }
}
