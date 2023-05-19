#include "Yapai.h"

t_neuron *neuron(int input_size, int bias)
{
    t_neuron *rtn;

    rtn = malloc(sizeof(t_neuron) * 1);
    rtn->bias = bias;
    rtn->nb_weights = input_size;
    rtn->weights = calloc(sizeof(float), rtn->nb_weights);

    for (int i = 0; i < rtn->nb_weights; i++)
    {
        float random = random_float(0.1, 1);
        rtn->weights[i] = random;
    }
    return (rtn);
}

float cost(float w, float b, float *test_x, float *test_y, int input_size)
{
    float sum = 0.0;

    for (int j = 0; j < input_size; j++)
    {
            float x = test_x[j];
            float y = test_y[j];
            float y_hat = x*w + b;
            sum = pow(y_hat - y, 2);
        
    }
    return sum;
}

void learn(t_neuron *self, float *test_x, float *test_y, int size, int epochs)
{
    for (int i = 0; i < epochs; i++)
    {
        for (int j = 0; j < self->nb_weights; j++)
        {
            float dw = 0.0;
            float db = 0.0;
            for (int z = 0; z < size; z++)
            {
                float w = self->weights[j];
                float b = self->bias;
                dw += (cost(w + EPSILON, b,test_x, test_y, size) - cost(w, b, test_x, test_y, size))/EPSILON;
                db += (cost(w, b + EPSILON, test_x, test_y, size) - cost(w, b, test_x, test_y, size))/EPSILON;
            }
            dw/=size;
            db/=size;
            self->weights[j] -= LEARNING_RATE * dw;
            self->bias  -= LEARNING_RATE * db;
        }
    }
}


float guess(t_neuron *self, float *input, int size)
{
    float res = 0;

    for (int i = 0; i < size; i++)
    {
        res += input[i] * self->weights[i] + self->bias; 
    }
    return res;
}