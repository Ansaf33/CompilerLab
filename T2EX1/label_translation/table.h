#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>

extern int label[50];
extern char* address[50];

void add(char* label,int address);

int getAddress(char* label);


void printTable();

#endif
