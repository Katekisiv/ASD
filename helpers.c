#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "helpers.h"

float Float(char* text)
{
    float res = 0;
    float error = 0;
    do {
        printf("%s", text);
        error = scanf("%f", &res);
        if (error != 1){
            printf("Wrong value!\n Try again: ");
        }
        fflush(stdin);
    } while(error != 1);
    return res;
}

int PositiveInteger(char* text)
{
    int res = 0;
    int error = 0;
    do {
        printf("%s", text);
        error = scanf("%d", &res);
        if (error != 1){
            printf("Wrong value! ");
        }
        fflush(stdin);
    } while(error != 1 || res <= 0);

    return res;
}

float *InputArray(int *n)
{
    *n = PositiveInteger("Enter the number of elements in array:\n ");

    float *array;
    int i;
    array = malloc(*n * sizeof(float));
    for (i = 0; i < *n; i++)
    {
        printf("a[%d]: ", i);
        array[i] = Float("");
    }

    printf("Your array is: ");
    PrintArray(array, *n);
    return array;
}

float **InputMatrix(int *n, int *m)
{
    *n = PositiveInteger("Enter the number of rows: ");
    *m = PositiveInteger("Enter the number of cols: ");

    float **matrix = malloc(*n * sizeof(float*));
    for (int i = 0; i < *n; i++)
    {
        matrix[i] = malloc(*m * sizeof(float));
        for (int j = 0; j < *m; j++)
        {
            printf("a[%d][%d]: ", i, j);
            matrix[i][j] = Float("");
        }
    }

    return matrix;
}

float *RandomArray (int *n)
{
    *n = PositiveInteger("Enter the number of elements in array:\n ");

    float *array;
    int i;
    array = malloc(*n * sizeof(float));
    srand(time(NULL));
    for (i = 0; i < *n; i++)
    {
        array[i] = rand();
    }

    printf("Your array is: ");
    PrintArray(array, *n);
    return array;
}

float **RandomMatrix(int *n, int *m)
{
    *n = PositiveInteger("Enter the number of rows: ");
    *m = PositiveInteger("Enter the number of cols: ");

    float **matrix = malloc(*n * sizeof(float*));
    srand(time(NULL));
    for (int i = 0; i < *n; i++)
    {
        matrix[i] = malloc(*m * sizeof(float));
        for (int j = 0; j < *m; j++)
        {
            matrix[i][j] = rand();
        }
    }

    return matrix;
}

void PrintArray(float *array, int n)
{
    printf("{");
    for (int i = 0; i < n; i++)
    {
        if ((i%13 != 0 || i == 0) && i != n - 1)
        {
            printf("%.2f, ", array[i]);
        }
        else if (i == n - 1)
        {
            printf("%.2f", array[i]);
        }
        else
        {
            printf("\n");
            printf("%.2f ", array[i]);
        }
    }
    printf("}\n\n");
}

void PrintMatrix(float **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != m - 1)
            {
                printf("%.1f, ", matrix[i][j]);
            }
            else
            {
                printf("%.1f ", matrix[i][j]);
                printf("\n");
            }
        }
    }
    printf("\n");
}

