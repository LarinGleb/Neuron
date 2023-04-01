#ifndef __NEURAL_NETWORK_H__
#define __NEURAL_NETWORK_H__

#include "layer.h"

typedef struct __neural_network_s
{
    size_t __count_layers;
    struct __layer_s* __layers;

} neural_network;

void neural_network_constructor(struct __neural_network_s* neural_network, size_t __count_layers, size_t __count_first_layer, ...);

#endif