#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int STRLEN(char *);
void STRCPY(char *, char *);
char* STRDUP(char *);
char* STRLWR(char *);
char* STRUPR(char *);
void SWAP(char *, char *);
void STRREV(char *);
int STRCMP(char *, char *);
int STRICMP(char *, char *);
void STRCAT(char *, char *);
int STRSTR(char *, char *);
char* SUBSTR(char *, int, int);
void VietHoaKyTuDau(char *);
void XoaKyTu(char *, int);
void XoaKhoangTrangThua(char *);
void XuatCacTu(char *);