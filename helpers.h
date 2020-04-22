//
// Created by Kate on 21.04.2020.
//

#ifndef ASD_HELPERS_H
#define ASD_HELPERS_H

void PrintArray(float *array, int n);

void PrintMatrix(float **matrix, int n, int m);

float *InputArray(int *n);

float** InputMatrix(int *n, int *m);

float *RandomArray (int *n);

float **RandomMatrix(int *n, int *m);

float Float(char* text);

int PositiveInteger(char* text);

#endif //ASD_HELPERS_H
