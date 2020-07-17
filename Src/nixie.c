/*
  *****************************************************************************
  * @file    nixie.c
  * @author  
  * @brief   Source file for nixie tube clock.
  *****************************************************************************
*/

#include <stdint.h>
#include "nixie.h"
#include "stm32f1xx_hal.h"

extern SPI_HandleTypeDef hspi1;

uint8_t Nixie_Buffer[13] = {};
uint32_t Alpha_Worldlines[12] = {571082, 571046, 571024, 571015,
                               523307, 523299, 456914, 456903,
                               409431, 409420, 334581, 337187};

/**
  * @brief  Displays the rightmost digit on Nixie8
  */
void Nixie8(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[0] = 0x40;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[0] = 0x00;
    Nixie_Buffer[1] = 0x28;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[0] = 0x00;
    Nixie_Buffer[1] = 0x48;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[0] = 0x00;
    Nixie_Buffer[1] = 0x88;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[0] = 0x01;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[0] = 0x02;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[0] = 0x04;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[0] = 0x08;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[0] = 0x10;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[0] = 0x20;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10:
    Nixie_Buffer[0] = 0x80;
    Nixie_Buffer[1] = 0x08;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11:
    Nixie_Buffer[0] = 0x00;
    Nixie_Buffer[1] = 0x18;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}

void Nixie7(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[1] = 0x02;
    Nixie_Buffer[2] = 0x00;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x01;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x02;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x04;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x08;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x10;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x20;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x40;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x80;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[1] = 0x01;
    Nixie_Buffer[2] = 0x00;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10:
    Nixie_Buffer[1] = 0x04;
    Nixie_Buffer[2] = 0x00;
    Nixie_Buffer[3] = 0x40;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11:
    Nixie_Buffer[1] = 0x00;
    Nixie_Buffer[2] = 0x00;
    Nixie_Buffer[3] = 0xC0;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}


void Nixie6(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[3] = 0x10;
    Nixie_Buffer[4] = 0x02;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[3] = 0x00;
    Nixie_Buffer[4] = 0x0A;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[3] = 0x00;
    Nixie_Buffer[4] = 0x12;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[3] = 0x00;
    Nixie_Buffer[4] = 0x22;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[3] = 0x00;
    Nixie_Buffer[4] = 0x42;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[3] = 0x00;
    Nixie_Buffer[4] = 0x82;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[3] = 0x01;
    Nixie_Buffer[4] = 0x02;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[3] = 0x02;
    Nixie_Buffer[4] = 0x02;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[3] = 0x04;
    Nixie_Buffer[4] = 0x02;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[3] = 0x08;
    Nixie_Buffer[4] = 0x02;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10: //RP
    Nixie_Buffer[3] = 0x20;
    Nixie_Buffer[4] = 0x02;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11: //LP
    Nixie_Buffer[3] = 0x00;
    Nixie_Buffer[4] = 0x06;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}


void Nixie5(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[5] = 0x80;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[5] = 0x00;
    Nixie_Buffer[6] = 0x50;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[5] = 0x00;
    Nixie_Buffer[6] = 0x90;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[5] = 0x01;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[5] = 0x02;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[5] = 0x04;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[5] = 0x08;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[5] = 0x10;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[5] = 0x20;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[5] = 0x40;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10: //RP
    Nixie_Buffer[4] = 0x01;
    Nixie_Buffer[5] = 0x00;
    Nixie_Buffer[6] = 0x10;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11: //LP
    Nixie_Buffer[4] = 0x00;
    Nixie_Buffer[5] = 0x00;
    Nixie_Buffer[6] = 0x30;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}

void Nixie4(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[6] = 0x04;
    Nixie_Buffer[7] = 0x00;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x02;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x04;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x08;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x10;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x20;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x40;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x80;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[6] = 0x01;
    Nixie_Buffer[7] = 0x00;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[6] = 0x02;
    Nixie_Buffer[7] = 0x00;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10: //RP
    Nixie_Buffer[6] = 0x08;
    Nixie_Buffer[7] = 0x00;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11: //LP
    Nixie_Buffer[6] = 0x00;
    Nixie_Buffer[7] = 0x01;
    Nixie_Buffer[8] = 0x80;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}


void Nixie3(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[8] = 0x20;
    Nixie_Buffer[9] = 0x04;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[8] = 0x00;
    Nixie_Buffer[9] = 0x14;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[8] = 0x00;
    Nixie_Buffer[9] = 0x24;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[8] = 0x00;
    Nixie_Buffer[9] = 0x44;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[8] = 0x00;
    Nixie_Buffer[9] = 0x88;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[0] = 0x01;
    Nixie_Buffer[1] = 0x04;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[8] = 0x02;
    Nixie_Buffer[9] = 0x04;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[8] = 0x04;
    Nixie_Buffer[8] = 0x04;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[8] = 0x08;
    Nixie_Buffer[9] = 0x04;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[8] = 0x10;
    Nixie_Buffer[9] = 0x04;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10: //RP
    Nixie_Buffer[8] = 0x40;
    Nixie_Buffer[9] = 0x04;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11: //LP
    Nixie_Buffer[4] = 0x00;
    Nixie_Buffer[5] = 0x0C;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}


void Nixie2(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[9] = 0x01;
    Nixie_Buffer[10] = 0x00;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x00;
    Nixie_Buffer[11] = 0xA0;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x01;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x02;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x04;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x08;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x10;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x20;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x40;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x80;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10: //RP
    Nixie_Buffer[9] = 0x02;
    Nixie_Buffer[10] = 0x00;
    Nixie_Buffer[11] = 0x20;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11: //LP
    Nixie_Buffer[9] = 0x00;
    Nixie_Buffer[10] = 0x00;
    Nixie_Buffer[11] = 0x60;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}

void Nixie1(uint8_t digit)
{
  switch (digit)
  {
  case 0:
    Nixie_Buffer[11] = 0x08;
    Nixie_Buffer[12] = 0x01;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 1:
    Nixie_Buffer[11] = 0x00;
    Nixie_Buffer[12] = 0x05;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 2:
    Nixie_Buffer[11] = 0x00;
    Nixie_Buffer[12] = 0x09;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 3:
    Nixie_Buffer[11] = 0x00;
    Nixie_Buffer[12] = 0x11;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 4:
    Nixie_Buffer[11] = 0x00;
    Nixie_Buffer[12] = 0x21;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 5:
    Nixie_Buffer[11] = 0x00;
    Nixie_Buffer[12] = 0x41;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 6:
    Nixie_Buffer[11] = 0x00;
    Nixie_Buffer[12] = 0x81;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 7:
    Nixie_Buffer[11] = 0x01;
    Nixie_Buffer[12] = 0x01;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 8:
    Nixie_Buffer[11] = 0x02;
    Nixie_Buffer[12] = 0x01;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 9:
    Nixie_Buffer[11] = 0x04;
    Nixie_Buffer[12] = 0x01;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 10: //RP
    Nixie_Buffer[11] = 0x10;
    Nixie_Buffer[12] = 0x01;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;

  case 11: //LP
    Nixie_Buffer[11] = 0x00;
    Nixie_Buffer[12] = 0x03;
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, Nixie_Buffer, sizeof(Nixie_Buffer), HAL_MAX_DELAY);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
    HAL_Delay(delay);
    break;
  }
}

void Clear_Nixie_Buffer(void)
{
  for (uint8_t i = 0; i < sizeof(Nixie_Buffer); i++)
  {
    Nixie_Buffer[i] = 0x00;
  }
}

void Display_AlphaWorldlines(){
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
  uint8_t e;
  uint8_t f;

  for(uint8_t i = 0; i <12 ; i++){
    a =  Alpha_Worldlines[i] / 100000;
    b = (Alpha_Worldlines[i] % 100000) / 10000;
    c = (Alpha_Worldlines[i] % 10000) / 1000;
    d = (Alpha_Worldlines[i] % 1000) / 100;
    e = (Alpha_Worldlines[i] % 100) / 10;
    f =  Alpha_Worldlines[i] % 10;
    Loop_All_Digits();
    for(uint8_t j = 0; j < 100; j++){
      Nixie3(11);
      Clear_Nixie_Buffer();
      Nixie3(a);
      Clear_Nixie_Buffer();
      Nixie4(b);
      Clear_Nixie_Buffer();
      Nixie5(c);
      Clear_Nixie_Buffer();
      Nixie6(d);
      Clear_Nixie_Buffer();
      Nixie7(e);
      Clear_Nixie_Buffer();
      Nixie8(f);
      Clear_Nixie_Buffer();
    }
  }
}

void Loop_All_Digits(){
  for(uint8_t j = 0; j <= 5; j++){
    for(uint8_t i = 0; i < 10; i++){
      Nixie8(i);
      HAL_Delay(1);
      Clear_Nixie_Buffer();
      Nixie7(i);
      HAL_Delay(1);
      Clear_Nixie_Buffer();
      Nixie6(i);
      HAL_Delay(1);
      Clear_Nixie_Buffer();
      Nixie5(i);
      HAL_Delay(1);
      Clear_Nixie_Buffer();
      Nixie4(i);
      HAL_Delay(1);
      Clear_Nixie_Buffer();
      Nixie3(i);
      HAL_Delay(1);
      Clear_Nixie_Buffer();
    }
  }
}