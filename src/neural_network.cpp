#include "neural_network.h"
#include "layer.h"

void neural_network_constructor(struct __neural_network_s* neural_network, size_t __count_layers, size_t __count_first_layer, ...) {
    neural_network->__count_layers = __count_layers;
    neural_network->__layers = (struct __layer_s*) calloc(__count_layers, sizeof(struct __layer_s));

    size_t* __count_in_layer = &__count_first_layer; 
    for(size_t i = 0; i < __count_layers; i ++) {
        layer_construct(neural_network->__layers+i, *__count_in_layer);
        __count_in_layer++;
    }
}
