#include <stdio.h>
#include <stdlib.h>

typedef struct
{

    int id;
    char marca[50];
    float cilindro;

} eAuto;

void mostrarAutos(eAuto* lista, int tam);
void mostrarAuto(eAuto* unAuto);


int main()
{

    int cant;

    eAuto auto1 = {1234,"Ford",1.6};
    eAuto auto2 = {1222,"Renault", 1.0};
    eAuto auto3 = {5555,"Peugeot",1.2};

    eAuto* lista =(eAuto*) malloc(3*sizeof(eAuto));


    *lista=auto1;
    *(lista +1)= auto2;
    *(lista+2)=auto3;


//mostrarAutos(lista, 3);


    FILE* f = fopen("./ autos.dat", "wb");

    if(f==NULL)
    {
        printf("No se pudo abrir archivo\n");
        exit(1);
    }

    while(!feof(f))
    {
        //cant = fread(lista + cont,sizeof(eAuto),1,f);

        if(cant <1)
        {
            if (feof(f)==0)
            {
                break;
            }
            else
            {
                printf("Se produjo un error al leer el archivo\n\n");
                break;
            }
        }

    }

    mostrarAutos(lista,cant);

//Se puede hacer de esta forma
//fwrite(lista, sizeof(eAuto), 3, f);

//O se puede hacer de esta forma
    for(int i=0; i<3; i++)
    {
        fwrite(lista + i, sizeof(eAuto), 1, f);
    }

    fclose(f);

    return 0;


    /*FILE* f;
    char cadena[]="mundo";

    f = fopen("./archivo.txt", "w");

    if(f==NULL){void mostrarAutos(eAuto* lista, int tam);

     printf("No se pudo subir el archivo\n");
     exit(1);

    }


    fprintf(f, "Hola %s", cadena);




    fclose(f);*/
}

void mostrarAuto(eAuto* unAuto)
{



    if(unAuto!=NULL)
    {
        printf("%d   %s  %.2f\n\n", unAuto->id, unAuto->marca, unAuto->cilindro);
    }


}
void mostrarAutos(eAuto* lista, int tam)
{

    printf("Id   Marca     Cilindrada\n\n");
    if (lista!=NULL&&tam>0)
    {

        for(int i=0; i<tam; i++)
        {
            mostrarAuto(lista+i);
        }
    }

}
