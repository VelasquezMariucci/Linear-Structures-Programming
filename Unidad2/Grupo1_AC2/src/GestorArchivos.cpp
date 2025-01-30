//
// Created by Grupo1 on 22/10/2024.
//

#include "GestorArchivos.h"

#include <filesystem>

GestorArchivos::GestorArchivos(const std::string& direccion): direccion(direccion)
{
    //primer proceso: inicializar vector de path de archivos.
    try
    {
        this->init();
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


void GestorArchivos::init()
{
    // Iterar por todos los archivos dentro del directorio.
    for (const auto& entry : std::filesystem::directory_iterator(direccion))
    {
        // Entrar solo cuando el archivo sea .txt
        if (entry.is_regular_file() && entry.path().extension() == ".txt")
        {
            // Salir y mostrar error si no se puede abrir.
            std::ifstream archivo(entry.path());
            if (!archivo.is_open())
            {
                std::cout << "Error al abrir el fichero" << std::endl;
                return;
            }

            pathArchivos.push_back(entry.path());
        }
    }
}


void GestorArchivos::mostrarListadoArchivos()
{
    int count = 1;

    std::cout << "----- Lista de Archivos -----" << std::endl;

    for (std::filesystem::path path : pathArchivos)
    {
        std::ifstream archivo(path);
        if (archivo.is_open())
        {
            std::string linea;
            if (std::getline(archivo, linea))
            {
                std::stringstream ss(linea);
                std::string primeraLinea;
                char ch;

                // Leer y guardar cada caracter hasta encontrar un delimitador.
                while (ss.get(ch))
                {
                    primeraLinea += ch;
                    if (ch == '.' || ch == ':' || ch == '\n')
                    {
                        break;
                    }
                }
                std::cout << "\t" << count << "): " << primeraLinea << std::endl;

                count++;
            }
        }
    }
    std::cout << "\n" << std::endl;
}


void GestorArchivos::mostrarArchivo(int indice)
{
    if (indice < 0 || indice > pathArchivos.size())
    {
        std::cout << "Error: Indice invalido." << std::endl;
        return;
    }

    std::cout << "----- Archivo Abierto -----" << std::endl;
    std::ifstream archivo(pathArchivos[indice]);
    if (archivo.is_open())
    {
        std::string linea;
        while (std::getline(archivo, linea))
        {
            std::cout << "\t" << linea << std::endl;
        }
        archivo.close();
        std::cout << "\n" << std::endl;
    }
    else
    {
        std::cout << "Error: Archivo no encontrado." << std::endl;
    }
}

void GestorArchivos::eliminarArchivo(int indice)
{
    if (indice < 0 || indice >= pathArchivos.size())
    {
        std::cout << "Error: Indice invalido." << std::endl;
        return;
    }

    std::filesystem::path fileToDelete = pathArchivos[indice];

    try
    {
        if (std::filesystem::remove(fileToDelete))
        {
            std::cout << "Archivo " << fileToDelete.filename() << " eliminado." << std::endl;
            pathArchivos.erase(pathArchivos.begin() + indice); // Remove from vector
        }
        else
        {
            std::cerr << "Error: no se pudo eliminar archivo." << std::endl;
        }
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void GestorArchivos::cargarArchivo(std::string ubicacion)
{
    std::filesystem::path path = ubicacion;

    if (!std::filesystem::exists(path) || !std::filesystem::is_regular_file(path))
    {
        std::cerr << "Error: El archivo no existe o es un archivo invalido." << std::endl;
        return;
    }

    // Nuevo path como target para el fichero a cargar
    std::filesystem::path nuevoDestino = direccion / path.filename();

    try
    {
        // Copiar el fichero
        std::filesystem::copy_file(path, nuevoDestino, std::filesystem::copy_options::overwrite_existing);
        std::cout << "File copied successfully to " << nuevoDestino << std::endl;
    }
    catch (const std::filesystem::filesystem_error& e)
    {
        std::cerr << "Error copying file: " << e.what() << std::endl;
    }
}
