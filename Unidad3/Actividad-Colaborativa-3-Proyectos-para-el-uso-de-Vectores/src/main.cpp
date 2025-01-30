#include <iostream>
#include "Album.h"
#include "DinarrayPEL.h"
#include "VectorPEL.h"
#include "Pelicula.h"

using std::cout, std::endl, std::cin, std::string;

// Variables estáticas para almacenar los álbumes de canciones y la librería de películas/series
static DinarrayPEL<Album>* albumes;
static VectorPEL<Pelicula>* libreria;

// Funcion de busqueda de musica en los albumes
void busquedaDeMusica()
{
    string userInput = ""; // Integer para la opcion que ingresará el usuario
    while (userInput != "0")
    {
        try
        {
            cout << "\n--- Buscar Musica ---\n";
            cout << "Seleccione un criterio de busqueda: \n";
            cout << "1) Titulo de Cancion\n";
            cout << "2) Nombre de Album\n";
            cout << "3) Artista o Grupo\n";
            cout << "4) Genero Musical\n";
            cout << "0) Salir\n";

            cin >> userInput;

            int opcion = std::stoi(userInput);

            string busqueda;    // Estado de la busqueda de la cancion (se reseteará cada vez que se encuentra una nueva cancion)
            bool encontrado = false;

            switch (opcion)
            {
            case 1: // Buscar por título de canción
                cout << "Ingrese el titulo de la cancion: ";
                cin.ignore();
                getline(cin, busqueda);    // Leemos el título de la canción
                for (auto& album : *albumes)    // Por cada album en la lista de albumes...
                {
                    for (auto& cancion : *album.getCaciones())    // Por cada cancion en el album...
                    {
                        if (cancion.getNombre() == busqueda)    // Comparamos el nombre de la cancion con el ingresado por el usuario
                        {
                            cancion.mostrarInfo(album.getNombre(), album.getAutor()->getNombre());    // // Mostramos información de la canción
                            encontrado = true;    // Cambiamos el estado de encontrado
                        }
                    }
                }
                break;

            case 2: // Buscar por álbum
                cout << "Ingrese el nombre del album: ";
                cin.ignore();
                getline(cin, busqueda);    // Leemos el título del album
                for (auto& album : *albumes)    // Por cada album en la lista de albumes...
                {
                    if (album.getNombre() == busqueda)    // Comparamos el nombre del album con el ingresado por el usuario
                    {
                        cout << "Album encontrado: " << album.getNombre() << endl;
                        cout << "Autor: " << album.getAutor()->getNombre() << endl;    // Imprimimos su informacion (nombre y autor)
                        encontrado = true;    // Cambiamos el estado de encontrado

                        cout << "Canciones en el album:\n";
                        for (auto& cancion : *album.getCaciones())    // Por cada cancion en el album...
                        {
                            cancion.mostrarInfo(album.getNombre(), album.getAutor()->getNombre());    // Ingresamos su informacion
                        }
                    }
                }
                break;

            case 3: // Buscar por artista o grupo
                cout << "Ingrese el nombre del artista o grupo: ";
                cin.ignore();
                getline(cin, busqueda);    // Leemos el artista ingresado
                for (auto& album : *albumes)    // Por cada album en la lista de albumes...
                {
                    if (album.getAutor()->getNombre() == busqueda)    // Comparamos el nombre del autor con el ingresado por el usuario
                    {
                        cout << "Album por " << busqueda << ": " << album.getNombre() << endl;    // Si son iguales, imprimimos los albumes creados por el autor...
                        encontrado = true;
                    }
                    for (auto& cancion : *album.getCaciones())    // Recorremos canciones para buscar artistas adicionales
                    {
                        for (auto& artista : *cancion.getArtistas())
                        {
                            if (artista.getNombre() == busqueda)
                            {
                                cancion.mostrarInfo(album.getNombre(), album.getAutor()->getNombre());    //Mostramos la informacion de las canciones
                                encontrado = true;
                            }
                        }
                    }
                }
                break;

            case 4: // Buscamos por genero musical
                cout << "Ingrese el genero musical: ";
                cin.ignore();
                getline(cin, busqueda);    // Leemos el genero ingresado
                for (auto& album : *albumes)    // Recorriendo los albumes...
                {
                    for (auto& cancion : *album.getCaciones())    // Y por cada cancion en el album
                    {
                        if (cancion.getGenero() == busqueda)    // Comparamos el genero de la cancion con el ingresado por el usuario
                        {
                            cancion.mostrarInfo(album.getNombre(), album.getAutor()->getNombre());    // Mostramos la informacion de las canciones
                            encontrado = true;
                        }
                    }
                }
                break;

            case 0: // Salimos de la busqueda de canciones
                cout << "Saliendo de la busqueda.\n";
                return;

            default:    // Notficamos que la opcion ingresada no es valida (fuera de rango)
                cout << "Opcion no valida.\n";
                break;
            }

            if (!encontrado)    // Si no se encuentra ninguna cancion se notificará al usuario
            {
                cout << "No se encontraron resultados para la busqueda.\n";
            }
        }
        catch (const std::invalid_argument&)
        {
            cin.clear();
            cout << "Entrada no valida." << endl;
        }
    }
}

// Función de busqueda de películas/series en la librería
void busquedaDePeliculas()
{
    string userInput = "";
    while (userInput != "0")
    {
        try
        {
            cout << "\n--- Buscar Peliculas y Series ---\n";
            cout << "Seleccione un criterio de busqueda: \n";
            cout << "1) Titulo\n";
            cout << "2) Genero\n";
            cout << "3) Calidad (FHD/UHD)\n";
            cout << "4) Alquilar Pelicula o Serie\n";
            cout << "0) Salir\n";

               //    Integer para la opcion que ingresará el usuario
            cin >> userInput;

            int opcion = std::stoi(userInput);

            string busqueda;    // Estado de la busqueda de la pelicula (se reseteará cada vez que se encuentra la pelicula)
            bool encontrado = false;

            switch (opcion)
            {
            case 1:    // Busqueda por título de la pelicula
                cout << "Ingrese el titulo: ";
                cin.ignore();
                getline(cin, busqueda);    // Titulo como input del usuario
                for (auto& pelicula : *libreria)    // Recorremos la libreria
                {
                    if (pelicula.getTipoTitulo() == busqueda)    // Si coinciden los 2 titulos se printea la informacion de la pelicula
                    {
                        pelicula.mostrarInfo();
                        encontrado = true;
                    }
                }
                break;

            case 2:    // Busqueda por título de la pelicula
                cout << "Ingrese el genero: ";
                cin.ignore();
                getline(cin, busqueda);    // Genero como input del usuario
                for (auto& pelicula : *libreria)    // Recorremos la libreria
                {
                    if (pelicula.getGenero() == busqueda)    // Si coinciden los 2 generos se printea la informacion de las peliculas
                    {
                        pelicula.mostrarInfo();
                        encontrado = true;
                    }
                }
                break;

            case 3:    // Busqueda por calidad de la pelicula
                cout << "Ingrese la calidad (FHD/UHD): ";
                cin.ignore();
                getline(cin, busqueda);    // Calidad como input del usuario
                for (auto& pelicula : *libreria)    // Recorremos la libreria
                {
                    string calidad = pelicula.getCalidad() == FHD ? "FHD" : "UHD";
                    if (calidad == busqueda)    // Si coinciden los tipos de calidad se printea la informacion de las peliculas con dicha calidad
                    {
                        pelicula.mostrarInfo();
                        encontrado = true;
                    }
                }
                break;

            case 4:    // Alquiler de peliculas o series
                cout << "Ingrese el titulo para alquilar: ";
                cin.ignore();
                getline(cin, busqueda);    // Nombre como input del usuario
                for (auto& pelicula : *libreria)    // Recorremos la libreria
                {
                    if (pelicula.getTipoTitulo() == busqueda)
                    {
                        if (pelicula.isTarifaEstandar())    // Si los 2 titulos coinciden y necesita un pago adicional...
                        {
                            cout << "Alquilando '" << pelicula.getTipoTitulo()
                                 << "' por " << pelicula.getPrecioAlquiler() << " euros.\n";    // Se notificará al usuario...
                            pelicula.setTarifaEstandar(false);    // Y se cambiará permanentemente el estado de la pelicula/serie
                            cout << "Gracias por su compra.\n";
                            encontrado = true;
                        }
                        else
                        {
                            cout << "Este titulo esta disponible con tarifa estandar. Disfrutelo!\n";    // Sino se informa de que no necesita tarifa adicional
                            encontrado = true;
                        }
                    }
                }
                break;

            case 0:    // Salimos de la busqueda
                cout << "Saliendo de la busqueda.\n";
                return;

            default:    // Notficamos que la opcion ingresada no es valida (fuera de rango)
                cout << "Opcion no valida.\n";
                break;
            }

            if (!encontrado)    // Si no se encuentra ninguna peli o serie se notificará al usuario
            {
                cout << "No se encontraron resultados para la busqueda.\n";
            }
        }
        catch (const std::invalid_argument&)
        {
            cin.clear();
            cout << "Entrada no valida." << endl;
        }
    }
}

// Cargamos los datos iniciales (álbumes y películas/series)
void loadData()
{
    // Creamos artistas
    ArtistaOGrupo* feid = new ArtistaOGrupo("Feid");
    ArtistaOGrupo* pirlo = new ArtistaOGrupo("Pirlo");
    ArtistaOGrupo* ATL_Jacob = new ArtistaOGrupo("ATL Jacob");

    // Por cada cancion creada le asignamos uno o mas autores
    Cancion* cincuentaPalos = new Cancion("50 PALOS", "Reggaeton");
    cincuentaPalos->getArtistas()->add(*feid);
    
    Cancion* cualEsEsa = new Cancion("CUAL ES ESA", "Urbano");
    cualEsEsa->getArtistas()->add(*feid);
    cualEsEsa->getArtistas()->add(*pirlo);

    Cancion* luna = new Cancion("LUNA", "Trap");
    luna->getArtistas()->add(*feid);
    luna->getArtistas()->add(*ATL_Jacob);

    // Albumes a los cuales le añadimos las canciones creadas
    albumes = new DinarrayPEL<Album>();
    Album* a1 = new Album("FERXXOCALIPSIS", feid);
    a1->getCaciones()->add(*cincuentaPalos);
    a1->getCaciones()->add(*cualEsEsa);
    a1->getCaciones()->add(*luna);
    albumes->add(*a1);

    // LIbreria de Peliculas/Series
    libreria = new VectorPEL<Pelicula>();
    libreria->push_back(Pelicula("Avengers Endgame", "Accion", UHD, true, 4.99));
    libreria->push_back(Pelicula("Suits", "Drama", FHD, false));
    libreria->push_back(Pelicula("Moby Dick", "Adventuras", FHD, false));
    libreria->push_back(Pelicula("300", "Accion", FHD, true, 7.99));
    libreria->push_back(Pelicula("Arcane", "Animacion", UHD, false));
}

// Opciones iniciales del programa
void login() {
    string userInput;    // Input del usuario
    while (userInput != "0") {    // Despues de cada busqueda, seguirá preguntandole al usuario que quiere hacer
        try
        {
            cout << "\nQue deseas hacer?: " << endl;
            cout << "0) Salir " << endl;
            cout << "1) Buscar Musica " << endl;
            cout << "2) Buscar Peliculas y Series " << endl;

            cin >> userInput;

            int opcion = std::stoi(userInput);

            if (opcion == 1)
            {
                busquedaDeMusica();    // Empezamos la busqueda de musica
            }
            else if (opcion == 2)
            {
                busquedaDePeliculas();    // Empezamos la busqueda de peliculas/series
            }
            else if (opcion == 0)
            {
                cout << "Adios!" << endl;    // Si imprimimos 0, el programa terminará
            }
            else
            {
                cout << "Opcion no valida." << endl;    // El programa controlará las entradas que no sean 0, 1 o 2 u otros valores
            }
        }
        catch (const std::invalid_argument&)
        {
            cout << "Entrada no valida." << endl;
        }
    }
};

int main()
{
    // Inicializamos el main con la carga de datos de la aplicacion y el login 
    loadData();
    login();
    return 0;
}

