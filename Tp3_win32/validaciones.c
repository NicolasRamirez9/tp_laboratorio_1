#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define EMPTY -1
#define FULL 1

int getString(char* msg,char* msgE,int minimo,int maximo,int reintentos,char* resultado)
{
    int ret = EMPTY;
    char bufferStr[400];
    if(msg != NULL && msgE != NULL && resultado != NULL && reintentos >=0 && maximo > minimo)
    {
        do
        {
            printf("\n%s",msg);
            fflush(stdin);// __fpurge(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr) >= minimo && strlen(bufferStr)<maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                ret = 0;
                break;
            }
            else
            {
                printf("\n%s",msgE);
            }
            reintentos --;
        }
        while(reintentos>0);
    }
    return ret;
}

int getInt(char *msg, char *msgE, int minimo, int maximo, int reintentos, char *resultado)
{
    char bufferStr[20];
    int ret = EMPTY;
    while(ret == EMPTY && reintentos > 0)
    {
        if(!getString(msg, msgE, minimo, maximo, reintentos, bufferStr)&&(resultado != NULL)&&(isValidint(bufferStr)))
        {
            strncpy(resultado,bufferStr,sizeof(bufferStr));
            ret = 0;
        }
        else
        {
            printf("%s",msgE);
            ret = EMPTY;
        }
    }
    return ret;
}

int getFloat(char *msg, char *msgE, char minimo, char maximo, int reintentos, char *resultado)
{
    char bufferStr[20];
    int ret = EMPTY;
    while(ret == EMPTY && reintentos > 0)
    {
        if(!getString(msg, msgE, minimo, maximo, reintentos, bufferStr)&&(isValidFloat(bufferStr)))
        {
            strncpy(resultado,bufferStr,sizeof(bufferStr));
            ret = 0;
        }
        else
        {
            printf("%s", msgE);
            ret = EMPTY;
        }
    }
    return ret;

}


int getName(char* pStr, char* msg, char* msgE,int minimo,int maximo,int reintentos)
{
    int ret = EMPTY;
    char bufferStr[4096];

    while(ret == EMPTY)
    {
        if(msg != NULL &&
           msgE != NULL &&
           pStr != NULL &&
           reintentos >=0 &&
           maximo > minimo)
        {
            if(!getString(msg, msgE, minimo, maximo, reintentos, bufferStr))
            {
                if(isValidName(bufferStr))
                {
                    strncpy(pStr, bufferStr, maximo);
                    ret = 0;
                    break;
                }
                else
                {
                    printf("%s",msgE);
                }
            }
        }
    }
    return ret;
}

int isValidint(char* cadena)
{
    int ret = FULL;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            ret = 0;
            break;
        }
    }
    return ret;
}

int isValidNumber(char* stringRecibido)     //podrìa necesitar parametros para validar max y min
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

int isValidFloat (char* pStr)
{
    int i=0;
    int contadorPuntos=0;
    while(pStr[i]!='\0')
    {
        if((pStr[i]<'0' || pStr[i]>'9')&&(pStr[i]!='.'))
        {

            return 0;
        }
        if(pStr[i]=='.')
        {
            contadorPuntos++;
            if(contadorPuntos>FULL)
            {
                return 0;
            }
        }
        i++;
    }
    return FULL;
}

int isValidName(char* cadena)
{
    int ret = EMPTY;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            ret = 0;
            break;
        }
    }
    return ret;
}
