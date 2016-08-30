//
// exceptionstub.h
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2014-2016  R. Stange <rsta2@o2online.de>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#ifndef _circle_exceptionstub_h
#define _circle_exceptionstub_h

#include <circle/macros.h>
#include <circle/types.h>

#ifdef __cplusplus
extern "C" {
#endif

struct TAbortFrame
{
	u64	esr_el1;
	u64	spsr_el1;
	u64	x30;		// lr
	u64	elr_el1;
	u64	sp_el0;
	u64	sp_el1;
	u64	far_el1;
	u64	unused;
}
PACKED;

void ExceptionHandler (u64 nException, TAbortFrame *pFrame);

void InterruptHandler (void);

#ifdef __cplusplus
}
#endif

#endif
