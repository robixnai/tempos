/*
 * Copyright (C) 2009 Renê de Souza Pinto
 * Tempos - Tempos is an Educational and multi purpose Operating System
 *
 * File: i8259A.h
 *
 * This file is part of TempOS.
 *
 * TempOS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * TempOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef  ARCH_X86_PIC

	#define ARCH_X86_PIC

	#include <unistd.h>

	#define PIC_MASTER_CMD		0x20
	#define PIC_MASTER_DATA		0x21
	#define PIC_SLAVE_CMD		0xA0
	#define PIC_SLAVE_DATA		0xA1

	#define PIC_MASTER			PIC_MASTER_DATA /* Do not change this */
	#define PIC_SLAVE			PIC_SLAVE_DATA  /* Do not change this */

	/* Masks for PIC commands */
	#define PIC_ICW1_IC4		0x01
	#define PIC_ICW1_INIT		0x10

	#define PIC_ICW4_8086		0x01
	#define PIC_ICW4_AEOI		0x02
	#define PIC_EOI				0x20

	#define PIC_ICW3_M_CASCADE  0x04
	#define PIC_ICW3_S_CASCADE  0x02

	#define IRQ0_VECTOR			0x20
	#define IRQ8_VECTOR			0x28

	#define PIC_MASTER_MASK		0xFB /* We can't disable IRQ2 because slave it's there */
	#define PIC_SLAVE_MASK		0xFF


	/** A simple wait for io operations */
	#define pic_delay()	asm volatile("nop; nop; nop");


	void init_PIC(void);

	uchar8_t get_picmask(uchar8_t pic);

	void set_picmask(uchar8_t mask, uchar8_t pic);

#endif /* ARCH_X86_PIC */

