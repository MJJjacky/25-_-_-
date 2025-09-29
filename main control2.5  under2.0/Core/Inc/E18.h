#ifndef __E18_H
#define __E18_H

#include "stdint.h"

uint8_t Read_right_front_edge(void);
uint8_t Read_right_back_edge(void);
uint8_t Read_left_front_edge(void);
uint8_t Read_left_back_edge(void);

uint8_t Read_attack_right(void);
uint8_t Read_attack_left(void);

uint8_t Read_wall_left(void);
uint8_t Read_wall_right(void);

#endif
