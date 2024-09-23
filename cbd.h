#ifndef CBD_H
#define CBD_H

#include "params.h"
#include "kernel.h"
__device__ void cbd2(poly *r,const uint8_t buf[FPTRU_COIN_BYTES / 2],uint16_t is_double,uint16_t is_add1);
__device__ void cbd3(poly *r, const uint8_t buf[FPTRU_COIN_BYTES / 2],uint16_t is_double,uint16_t is_add1);

#endif
