#ifndef __DIRECT_DISRT_H__
#define __DERICET_DISTR_H__

#include "matrix_constructor.h"
#include "function.h"

#include "act_func.h"
#include "layer.h"

matrix calc_ivalue(struct __layer_s layer);
void calc_ovalue(struct __layer_s layer, matrix* values, function __activate_func = sigmoid);

matrix direct_distr(struct __layer_s* neural_network, matrix input_values);
#endif