#ifndef __ACT_FUNC_H__
#define __ACT_FUNC_H__

#include <cmath>

float linear(float* arg) {
    return *arg;
}
float sigmoid(float* arg) {
    return 1/(1+exp(-*arg));
}
float tan_hyp(float* arg) {
    return (exp(*arg) - exp(-*arg))/(exp(*arg) + exp(-*arg));
}


float devirate_linear(float* arg) {
    return 1;
}
float devirate_sigmoid(float* arg) {
    return sigmoid(arg) * (1 - sigmoid(arg));
}
float devirate_tan_hyp(float* arg) {
    return 1 - pow(tan_hyp(arg), 2);
}
#endif