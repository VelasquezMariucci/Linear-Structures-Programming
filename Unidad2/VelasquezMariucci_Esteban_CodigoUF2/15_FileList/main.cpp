#include <iostream>

#include "File.h"
#include "ObjectList.h"

/*Crear una clase “Archivo” que encapsule un puntero a un archivo. La clase
“ListaDeObjetos” debe utilizar esta clase para almacenar una lista de
archivos. La clase Archivo debe abrir el archivo en su constructor y cerrarlo
en su destructor.*/

int main()
{
    ObjectList<File> list(10);

    File* file1 = new File("../data/file.txt");
    File* file2 = new File("../data/file2.txt");

    list.add(*file1);
    list.add(*file2);

    std::cout << list << std::endl;

    return 0;
}
