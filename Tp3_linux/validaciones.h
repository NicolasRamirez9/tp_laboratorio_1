#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int getString(char* msg,char* msgE,int minimo,int maximo,int reintentos,char* resultado);
int getInt(char *msg, char *msgE, int minimo, int maximo, int reintentos, char *resultado);
int getFloat(char *msg, char *msgE, char minimo, char maximo, int reintentos, char *resultado);
int getName(char* pStr, char* msg, char* msgE,int minimo,int maximo,int reintentos);

int isValidint(char* cadena);
int isValidFloat (char* pStr);
int isValidName(char* cadena);

#endif // VALIDACIONES_H_INCLUDED
