#ifndef __LAYER_H__
#define __LAYER_H__

#include "matrix_constructor.h"

typedef struct __layer_s
{
    matrix __weights;
    matrix __bias;
    matrix __input;
    size_t __count_synapses;
} layer;


void layer_construct(struct __layer_s* layer, size_t __count_synapses);

#endif