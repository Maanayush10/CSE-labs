/*Write a program in CUDA to add two vectors of length N using N threads*/



#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

// #define N 6

__global__ void add(int *a, int *b, int *c)

{
    c[threadIdx.x] = b[threadIdx.x] + a[threadIdx.x];
}



int main(void) {
    int N;
    printf("Enter the value of N :\t");
    scanf("%d", &N);


    int a[N],b[N],c[N];
    int *d_a, *d_b, *d_c;
    // host copies of variables a, b , c;
    // device copies of variables a, b , c;
    int size = N*sizeof(int);

    // Allocate space for device copies of a, b,
    cudaMalloc((void **)&d_a, size);
    cudaMalloc((void **)&d_b, size);
    cudaMalloc((void **)&d_c, size);

    // Setup input values
    printf("Enter A values :\t");
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter B values :\t");
    for(int i=0; i<N; i++)
    {
        scanf("%d", &b[i]);
    }
// Copy inputs to device

    cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

    // Launch add() kernel on GPU
    add<<<1,N>>>(d_a,d_b,d_c);
    cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost); 
    
    //result output
    printf("\nA[i]+ b[i]= c[i]\n");
    for(int i=0; i<N; i++)
    {
        printf("\n%d + %d = %d\n", a[i], b[i], c[i]);
    }
    // Cleanup
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}