#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void add(int *a, int *b, int *c)

{
    *c = *b + *a;
}



int main(void) {
    int a,b,c;
    int *d_a, *d_b, *d_c;
    // host copies of variables a, b , c;
    // device copies of variables a, b , c;
    int size = sizeof(int);

    // Allocate space for device copies of a, b,
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);

    // Setup input values

    a=3;
    b=5;

// Copy inputs to device

    cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

    // Launch add() kernel on GPU
    add<<<1,1>>>(d_a,d_b,d_c);
    cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);
    printf("Result : %d\n",c);    

    // Cleanup
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}
