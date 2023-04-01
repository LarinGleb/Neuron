#include "matrix_constructor.h"
#include "matrix_defines.h"
#include "function.h"

#include "layer.h"
#include "direct_distribution.h"
#include "neural_network.h"

matrix calc_ivalue(struct __layer_s layer) {
    matrix* ivalue = (matrix*) malloc(sizeof(matrix));
    matrix_constructor(ivalue, ivalue->__c_row, 1);

    mul_s(&(layer.__input), &(layer.__weights), ivalue);
    add_s(ivalue, &(layer.__bias));

    return *ivalue;
}

void calc_ovalue(struct __layer_s layer, matrix output_values, matrix input_values, function __activate_func = sigmoid) {
    for (size_t i = 0; i < layer.__count_synapses; i ++) {
        *ptr_value(&output_values, i, 1) = __activate_func(ptr_value(&input_values, i, 1));
    }
}

matrix direct_distr(struct __neural_network_s* neural_network, matrix input_values, matrix* ouput) {
    neural_network->__layers->__input = input_values;

    for (size_t i = 1; i < neural_network->__count_layers-1; i ++) {
        calc_ovalue(*(neural_network->__layers+i), (neural_network->__layers+i)->__input, calc_ivalue(*(neural_network->__layers+i-1)));
    }

    
}