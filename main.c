#include "Yapai.h"


#define DATA_SIZE (sizeof(data) / sizeof(data[0]))






float test_x[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
float test_y[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};



int main(int argc, char const *argv[])
{
    t_neuron *n = neuron(5, sigmoid(random_float(0, 1)));

    learn(n, test_x, test_y, 1, 300);

    float test = 21;
    float g = guess(n, &test, 1);
    printf("w = %f b = %f, guessed = %f\n", n->weights[0], n->bias, g);
    return 0;
}




