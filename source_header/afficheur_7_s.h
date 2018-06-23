/*
 * afficheur_7_s.h
 *
 *  Created on: 23 juin 2018
 *      Author: Grégoire
 */

#ifndef AFFICHEUR_7_S_H_
#define AFFICHEUR_7_S_H_

#define A0 0xC0
#define A1 0xF9
#define A2 0xA4
#define A3 0xB0
#define A4 0x99
#define A5 0x92
#define A6 0x02
#define A7 0xf8
#define A8 0x80
#define A9 0x10
#define AA 0x88
#define AB 0x00
#define AC 0xC6
#define AD 0xC0
#define AE 0x86
#define AF 0x8E

void startTaskAfficheur(const void* args);
void shiftOut(uint8_t* pdata, uint16_t size, SPI_HandleTypeDef* handle_spi);

#endif /* AFFICHEUR_7_S_H_ */
