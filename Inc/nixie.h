/*
  *****************************************************************************
  * @file    nixie.h
  * @author  
  * @brief   Header file for nixie tube clock.
  *****************************************************************************
*/

#ifndef NIXIE_H_
#define NIXIE_H_

#define delay 1

void Nixie8(uint8_t digit);
void Nixie7(uint8_t digit);
void Nixie6(uint8_t digit);
void Nixie5(uint8_t digit);
void Nixie4(uint8_t digit);
void Nixie3(uint8_t digit);
void Nixie2(uint8_t digit);
void Nixie1(uint8_t digit);
void Display_AlphaWorldlines();
void Clear_Nixie_Buffer(void);
void Loop_All_Digits();

#endif /* NIXIE_H_ */