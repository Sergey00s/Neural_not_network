#include "Yapai.h"


float sigmoid(float x)
{
    return 1.0 / (1.0 + exp(-x));
}

float sigmoid_derivative(float x)
{
    return x * (1.0 - x);
}

float random_float(float min, float max)
{
    srand(time(0));
    return ((float)rand() / (float)RAND_MAX) * (max - min) + min;
}



