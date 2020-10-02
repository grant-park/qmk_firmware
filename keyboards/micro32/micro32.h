#ifndef MICRO32_H
#define MICRO32_H

#include "quantum.h"
#include "matrix.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
  k19, k18, k17, k16, k29,           k20, k13, k12, k11, k10, \
  k09, k08, k07, k06, k28,           k21, k03, k02, k01, k00, \
  k05, k15, k25, k31, k27,           k22, k30, k24, k14, k04, \
                           k26, k23                           \
) \
{ \
	{ k04, k14, k24, k30, k31, k25, k15, k05 }, \
	{ k00, k01, k02, k03, k06, k07, k08, k09 }, \
	{ k10, k11, k12, k13, k16, k17, k18, k19 }, \
	{ k20, k21, k22, k23, k26, k27, k28, k29 } \
}

#endif
