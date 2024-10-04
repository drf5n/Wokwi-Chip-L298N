//  L298N.chip.c DaveX 2024-09-29
//  https://wokwi.com/projects/410302035690579969
//
// Code modified from
// https://wokwi.com/projects/351764383409373773 by Carlos Arino
/* Modifications:
  Switch to digital inputs and outputs
  Reorder pins

 */ 
// Note that the code from the  is written to use analog inputs and outputs, 
// which do not work with LEDs etc...
//The code came with this .json, which is not the 
// right pin ordering for a L298N.
/*
*/

#include "wokwi-api.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  pin_t pin_out1;
  pin_t pin_out2;
  pin_t pin_out3;
  pin_t pin_out4;
  pin_t pin_IN1;
  pin_t pin_IN2;
  pin_t pin_IN3;
  pin_t pin_IN4;
  pin_t pin_ENA;
  pin_t pin_ENB;
  uint32_t Vs_attr; 
} chip_state_t;

static void chip_pin_change(void *user_data, pin_t pin, uint32_t value);

void chip_init(void) {
  chip_state_t *chip = malloc(sizeof(chip_state_t));
  chip->pin_ENA = pin_init("EN A",INPUT);
  chip->pin_ENB = pin_init("EN B",INPUT);
  chip->pin_IN1 = pin_init("IN1",INPUT);
  chip->pin_IN2 = pin_init("IN2",INPUT);
  chip->pin_IN3 = pin_init("IN3",INPUT);
  chip->pin_IN4 = pin_init("IN4",INPUT);
  chip->pin_out1 = pin_init("OUT1",OUTPUT);
  chip->pin_out2 = pin_init("OUT2",OUTPUT);
  chip->pin_out3 = pin_init("OUT3",OUTPUT);
  chip->pin_out4 = pin_init("OUT4",OUTPUT);
  chip->Vs_attr = attr_init_float("Vs", 12.0);
  const pin_watch_config_t watch_config = {
    .edge = BOTH,
    .pin_change = chip_pin_change,
    .user_data = chip
  };
  pin_watch(chip->pin_ENA, &watch_config);
  pin_watch(chip->pin_ENB, &watch_config);
  pin_watch(chip->pin_IN1, &watch_config);
  pin_watch(chip->pin_IN2, &watch_config);
  pin_watch(chip->pin_IN3, &watch_config);
  pin_watch(chip->pin_IN4, &watch_config);
}

void chip_pin_change(void *user_data, pin_t pin, uint32_t value) {
  chip_state_t *chip = (chip_state_t*)user_data;
  int ENA = pin_read(chip->pin_ENA);
  int ENB = pin_read(chip->pin_ENB);
  int IN1 = pin_read(chip->pin_IN1);
  int IN2 = pin_read(chip->pin_IN2);
  int IN3 = pin_read(chip->pin_IN3);
  int IN4 = pin_read(chip->pin_IN4);
  float Vs = attr_read_float(chip->Vs_attr);
  
  // motor 1 control
  if (IN1) 
    pin_write(chip->pin_out1,ENA);
  else
    pin_write(chip->pin_out1,0);
  if (IN2)
    pin_write(chip->pin_out2,ENA);
  else
    pin_write(chip->pin_out2,0);
  //motor 2 control
  if (IN3) 
    pin_write(chip->pin_out3,ENB);
  else
    pin_write(chip->pin_out3,0);
  if (IN4)
    pin_write(chip->pin_out4,ENB);
  else
    pin_write(chip->pin_out4,0);
}


