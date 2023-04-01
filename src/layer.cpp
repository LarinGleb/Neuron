#include <time.h>
#include <stdlib.h> 

#include "matrix_constructor.h"
#include "matrix_defines.h"

#include "layer.h"

void layer_construct(struct __layer_s* layer, size_t __count_synapses) {
    srand(time(NULL));

    layer->__count_synapses = __count_synapses;

    matrix* bias = (matrix*) malloc(sizeof(matrix));
    matrix_constructor(bias, __count_synapses, 1);

    matrix* weights = (matrix*) malloc(sizeof(matrix));
    matrix_constructor(weights, __count_synapses, __count_synapses);

    for(size_t i = 0; i < __count_synapses; i ++) {
        *ptr_value(bias, i, 1) = rand() % 100;
        for (size_t j = 0; j < __count_synapses; j ++) {
            *ptr_value(weights, i, j) = rand() % 100;
        }
    }

    matrix* input = (matrix*) malloc(sizeof(matrix));
    
    layer->__bias = *bias;
    layer->__input = *input;
    layer->__weights = *weights;
    
    free(bias);
    free(weights);
    free(input);
}