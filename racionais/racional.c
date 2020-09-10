
#include "racionalLib.h"
#include <stdbool.h>

Racional *reduzir(Racional *r1)
{
    int num = r1->numerador;
    int deno = r1->denominador;
    int aux = 2;
    int divs = 1;
    bool a = true, b = true;
    while ((a && b) || (aux < num) || (aux < deno))
    {
        if ((num / aux) * aux == num)
        {
            num = num / aux;
            a = true;
        }
        else
        {
            a = false;
            aux++;
        }
        if ((deno / aux) * aux == deno)
        {
            deno = deno / aux;
            b = true;
        }
        else
        {
            b = false;
            aux++;
        }
        if (a && b)
        {
            divs = divs * aux;
        }
    }
    r1->numerador = r1->numerador / divs;
    r1->denominador = r1->denominador / divs;
    return r1;
}
Racional *init(int numerador, int denominador)
{
    Racional *result = NULL;
    if (denominador != 0)
    {
        result = (Racional *)malloc(sizeof(Racional));
        result->numerador = numerador;
        result->denominador = denominador;
    }
    return (result);
}
void destroy(Racional *p)
{
    free(p);
}
Racional *add(Racional *r1, Racional *r2)
{
    Racional *result = (Racional *)malloc(sizeof(Racional));
    result->denominador = r1->denominador * r2->denominador;
    result->numerador = (r1->numerador * r2->denominador) + (r1->denominador * r2->numerador);
    return reduzir(result);
}

Racional *subtract(Racional *r1, Racional *r2)
{
    Racional *result = (Racional *)malloc(sizeof(Racional));
    result->denominador = r1->denominador * r2->denominador;
    result->numerador = (r1->numerador * r2->denominador) - (r1->denominador * r2->numerador);
    return reduzir(result);
}
Racional *multiply(Racional *r1, Racional *r2)
{
    Racional *result = (Racional *)malloc(sizeof(Racional));
    result->denominador = r1->denominador * r2->denominador;
    result->numerador = r1->numerador * r2->numerador;
    return reduzir(result);
}
Racional *divide(Racional *r1, Racional *r2)
{
    Racional *result = (Racional *)malloc(sizeof(Racional));
    result->denominador = r1->denominador * r2->numerador;
    result->numerador = r1->numerador * r2->denominador;
    return reduzir(result);
}