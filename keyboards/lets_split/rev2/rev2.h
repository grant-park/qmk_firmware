#ifndef REV2_H
#define REV2_H

#include "lets_split.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"


#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);

// Standard Keymap
// (TRRS jack on the left half is to the right, TRRS jack on the right half is to the left)
#define LAYOUT( \
	L10, L11, L12, L13, L00,           R00, R13, R12, R11, R10,  \
	L20, L21, L22, L23, L01,           R01, R23, R22, R21, R20, \
	L30, L31, L32, L33, L02, L03, R03, R02, R33, R32, R31, R30 \
	) \
	{ \
		{ L00, L01, L02, L03 }, \
		{ L10, L11, L12, L13 }, \
		{ L20, L21, L22, L23 }, \
		{ L30, L31, L32, L33 }, \
		{ R00, R01, R02, R03 }, \
		{ R10, R11, R12, R13 }, \
		{ R20, R21, R22, R23 }, \
		{ R30, R31, R32, R33 } \
	}

#define LAYOUT_ortho_4x4 LAYOUT

#endif
