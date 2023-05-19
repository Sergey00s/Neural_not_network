#ifndef YAPAI_H
# define YAPAI_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>

#define EPSILON 1e-3
#define LEARNING_RATE 1e-3

typedef struct s_neuron
{
    int     nb_weights;
    float   *weights;
    float   bias;
} t_neuron;

float guess(t_neuron *self, float *input, int size);
t_neuron *neuron(int input_size, int bias);
float cost(float w, float b, float *test_x, float *test_y, int input_size);
void learn(t_neuron *self, float *test_x, float *test_y, int size, int epochs);
float sigmoid(float x);
float sigmoid_derivative(float x);
float random_float(float min, float max);

#endif