#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LEN_NOTEBOOK 4

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

void aplicarDescuento(float precio, float* preciofinal);

int contarCaracteres(char* cadena, char caracter);

int sortNotebooks(eNotebook* list, int len);
void showNotebook(eNotebook computadora);
int printNotebooks(eNotebook* list, int len);


int main()
{

    //1. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y
    // devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main.

    float precio = 1000;
    float resultadoConDescuento;

    aplicarDescuento(precio, &resultadoConDescuento);

    printf("El precio del producto es: %.2f\n", precio);
    printf("El precio con descuento es de: %.2f\n", resultadoConDescuento);
    printf("\n\n");


    //2. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
    //y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena

    char array[]="Parcial de Programacion";
    printf("%s\n", array);
    printf("Se repite %d veces el caracter 'a' en la oracion.\n", contarCaracteres(array, 'a'));
    printf("\n\n");


    //3. Dada la estructura Notebook(id, procesador, marca, precio) generar una  función que
    //permita ordenar un array de dicha estructura por marca.Ante igualdad de marca
    //deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.

    eNotebook notebooks[LEN_NOTEBOOK] =
    {
        {0, "Ryzen 3", "AMD", 20000.50},
        {3, "Ryzen 5", "AMD", 10000},
        {4, "Pentium", "Intel", 5000.99},
        {5, "I3", "Intel", 15000.99}
    };

    printNotebooks(notebooks, LEN_NOTEBOOK);
    sortNotebooks(notebooks, LEN_NOTEBOOK);
    printNotebooks(notebooks, LEN_NOTEBOOK);

    return 0;
}

void aplicarDescuento(float precio, float* preciofinal)
{
    float resultado;
    resultado = (precio * 5) / 100;
    *preciofinal = precio - resultado;
}

int contarCaracteres(char* cadena, char caracter)
{
    int lenCadena = strlen(cadena);

    int contador = 0;

    for(int i = 0; i < lenCadena; i++)
    {
        if(cadena[i] == caracter)
        {
            contador++;
        }
    }
    return contador;
}


int sortNotebooks(eNotebook* list, int len)
{
    int error = -1;
    eNotebook auxNotebook;

    if(list!= NULL && len > 0)
    {
        for(int i = 0; i < len-1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(strcmp(list[i].marca, list[j].marca) > 0)
                {
                    auxNotebook = list[i];
                    list[i] = list[j];
                    list[j] = auxNotebook;
                }
                else if(strcmp(list[i].marca, list[j].marca) == 0 && list[i].precio < list[j].precio)
                {
                    auxNotebook = list[i];
                    list[i] = list[j];
                    list[j] = auxNotebook;
                }
            }
        }
        error = 0;

    }

    return error;
}


int printNotebooks(eNotebook* list, int len)
{
    if(list != NULL && len > 0 && len <= 10)
    {
        printf("  ID          Procedador        Marca          Precio\n");
        printf("------------------------------------------------------\n");
        for(int i = 0; i < len; i++)
        {
                showNotebook(list[i]);
        }
        printf("\n\n");
        return 0;
    }
    return -1;
}

void showNotebook(eNotebook unaNote)
{
    printf("%5d     %10s       %8s         $%4.2f\n",
           unaNote.id,
           unaNote.procesador,
           unaNote.marca,
           unaNote.precio
          );
}
