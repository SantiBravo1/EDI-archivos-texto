#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archivo;
    int cerrado;
    float valor;
    char nombre[58];
    int alumnos;
    int finalArchivo;
    float promedio;
    float sumaDeValores=0.0;
    float valorASumar;

    archivo=fopen("Calificaciones.txt", "w");

    printf("Dame el numero de alumnos: ");
    scanf("%d", &alumnos);

    for(int i=0; i<alumnos; i++)
    {
      printf("Dame un nombre: ");
      scanf("%s", nombre);

      printf("Dame un valor entero: ");
      scanf("%f", &valor);

      fprintf(archivo, "%s-%f\n", nombre, valor);
    }

    cerrado=fclose(archivo);

    if(cerrado==EOF)
        printf("El archivo no se cerro bien");

    archivo=fopen("Calificaciones.txt", "r");

    do{
        for(int j=0; j<alumnos; j++)
        {

          fscanf(archivo, "%s", nombre);
          fscanf(archivo, "%f", valor);

          valorASumar=valor;
          sumaDeValores=sumaDeValores+valorASumar;
        }

        finalArchivo=feof(archivo);
      }while(finalArchivo=!EOF);

    cerrado=fclose(archivo);

    if(cerrado==EOF)
        printf("El archivo no se cerro bien");

    promedio=sumaDeValores/alumnos;

    printf("Promedio es igual a: %f", promedio);

    return 0;
}
