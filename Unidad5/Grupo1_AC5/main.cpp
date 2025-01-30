#include "ListaEnlazada.h"
#include "ListaRegistro.h"
#include "Usuario.h"
#include "Analista.h"
#include "Registro.h"
#include "ControlSeguridad.h"

#include <ctime>
#include <iomanip>
#include <string>

void contarAccesos(Registro* acceso)
{
    if (acceso == nullptr) {
        return;
    }

    std::cout << "Usuario: " << acceso->getNombreUsuario() << " accedió a la aplicación." << std::endl;

    contarAccesos(acceso->getSiguienteAcceso());
}

bool actividadSospechosa(const Actividad& actividad1, const Actividad& actividad2)
{
    // Verifica si las actividades son sospechosas comparando la descripción y la fecha
    return actividad1.getDescripcion() == actividad2.getDescripcion() &&
           actividad1.getFecha() == actividad2.getFecha(); // Comparación de fechas y descripciones
}

void buscarActividadesSospechosas(const std::vector<Usuario*>& usuarios)
{
    for (Usuario* u : usuarios) {
        ListaEnlazada<Actividad>* actividades = u->getActividades();

        for (int i = 0; i < actividades->getSize(); ++i) {
            Actividad& actividad1 = actividades->getElement(i);
            for (int j = i + 1; j < actividades->getSize(); ++j) {
                Actividad& actividad2 = actividades->getElement(j);
                if (actividadSospechosa(actividad1, actividad2)) {
                    std::cout << "¡Actividad sospechosa detectada!" << std::endl;
                    std::cout << "Usuario: " << u->getNombre() << ", Actividad: " << actividad1.getDescripcion() << std::endl;
                    std::cout << "Fecha 1: " << actividad1.getFecha() << ", Fecha 2: " << actividad2.getFecha() << std::endl;
                }
            }
        }
    }
}

std::vector<Usuario*> convertirAListaVector(ListaEnlazada<Usuario>* lista) {
    std::vector<Usuario*> vectorUsuarios;
    for (int i = 0; i < lista->getSize(); ++i) {
        vectorUsuarios.push_back(lista->getElementAddr(i));
    }
    return vectorUsuarios;
}

Usuario* findUsuarioByName(ListaEnlazada<Usuario>* usuarios, const std::string& nombre, int index = 0)
{
    if (index >= usuarios->getSize())
    {
        return nullptr;
    }

    if (usuarios->getElementAddr(index)->getNombre() == nombre)
    {
        return usuarios->getElementAddr(index);
    }

    return findUsuarioByName(usuarios, nombre, index + 1);
}

void menuUsuario(Usuario& usuario, ListaEnlazada<Usuario>* usuarios, ListaRegistro& listaAccesos, bool& salirDelPrograma)
{
    bool cerrarSesion = false;
    bool continuar = true;

    while (!cerrarSesion && continuar)
    {
        int opcion;
        std::cout << "\nMenu" << std::endl;
        std::cout << "1. Buscar Registro" << std::endl;

        // Modificar el acceso a differentes funciones dependiendo del tipo de usuario
        if (usuario.getTipoUsuario() == Supervisor)
        {
            std::cout << "2. Agregar Actividad" << std::endl;
        }
        else if (usuario.getTipoUsuario() == Regular)
        {
            std::cout << "2. Ver Actividades" << std::endl;
        }
        else if (usuario.getTipoUsuario() == Analista)
        {
            std::cout << "2. Opciones de Analista" << std::endl; // Nueva opción para Analista
        }

        std::cout << "3. Cerrar Sesion" << std::endl;
        std::cout << "0. Salir" << std::endl;
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1: {
            std::string nombre, fecha;
            std::cout << "Ingrese el nombre del usuario que accedió a la aplicación: ";
            std::cin >> nombre;
            std::cout << "Ingrese la fecha de acceso: ";
            std::cin >> fecha;

            bool encontrado = listaAccesos.buscarRegistro(listaAccesos.getHead(), nombre, fecha);

            std::cout << (encontrado ? "Acceso encontrado." : "Acceso no encontrado.") << std::endl;
            break;
        }
        case 2: {
                // Asignar actividades a usuarios
            if (usuario.getTipoUsuario() == Supervisor) {
                std::string nombre, desc, fecha;
                std::cout << "Ingresar el nombre del Usuario objetivo: ";
                std::cin >> nombre;

                Usuario* u_Objetivo = findUsuarioByName(usuarios, nombre);

                if (u_Objetivo) {
                    std::cout << "Ingresar la descripcion de la actividad que quieres asignar: ";
                    std::cin >> desc;

                    std::cout << "Ingresar la fecha de la actividad (DD/MM/YYYY): ";
                    std::cin >> fecha;

                    u_Objetivo->agregarActividad(desc, fecha);
                    std::cout << "Actividad asignada.\n";
                } else {
                    std::cout << "Usuario no encontrado.\n";
                }
            } else if (usuario.getTipoUsuario() == Regular) {
                // vista de actividades por usuarios regulares
                if (usuario.getActividades()->getSize() != 0) {
                    usuario.getActividades()->printList();
                } else {
                    std::cout << usuario.getNombre() << ", no tienes actividades pendientes.\n";
                }
            } else if (usuario.getTipoUsuario() == Analista) {
                bool continuarAnalista = true;
                while (continuarAnalista) {
                    std::cout << "\nAcciones disponibles para Analista:" << std::endl;
                    std::cout << "1. Ver registros de acceso." << std::endl;
                    std::cout << "2. Buscar actividades sospechosas." << std::endl;
                    std::cout << "3. Volver al menú anterior." << std::endl;
                    std::cout << "Ingrese opción: ";
                    int opcionAnalista;
                    std::cin >> opcionAnalista;

                    switch (opcionAnalista) {
                    case 1:
                        std::cout << "\nContando accesos por usuario..." << std::endl;
                        contarAccesos(&(listaAccesos.getHead()->data));
                        break;
                    case 2:
                        std::cout << "\nBuscando actividades sospechosas..." << std::endl;
                        buscarActividadesSospechosas(convertirAListaVector(usuarios));
                        break;
                    case 3:
                        continuarAnalista = false;
                        std::cout << "Volviendo al menú anterior..." << std::endl;
                        break;
                    default:
                        std::cout << "\nOpción no válida. Intente de nuevo." << std::endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:
            // Log out para habilitar cambios de usuarios y poder visualizar
            // las actividades asignadas. 
            cerrarSesion = true;
            std::cout << "Cerrando sesión...\n";
            break;
        case 0:
            continuar = false;
            std::cout << "Saliendo... " << std::endl;
            exit(0);
            break;
        default:
            std::cout << "Opción no válida. Intenta de nuevo." << std::endl;
            break;
        }
    }
}

std::string obtenerHora()
{
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* tiempoLocal = std::localtime(&tiempoActual);

    int horas = tiempoLocal->tm_hour;
    int minutos = tiempoLocal->tm_min;

    std::string horaFormateada = (horas < 10 ? "0" : "") + std::to_string(horas) + ":" + (minutos < 10 ? "0" : "") +
        std::to_string(minutos);

    return horaFormateada;
}

void logIn(ListaEnlazada<Usuario>* usuarios, ListaRegistro& listaAccesos, ControlSeguridad& seguridad)
{
    bool salirDelPrograma = false;

    while (!salirDelPrograma)
    {
        bool isLogged = false;

        while (!isLogged)
        {
            try
            {
                std::string username, password = "", telefono = "";
                std::cout << "Username: ";
                std::cin >> username;

                // Obtén el nivel de seguridad actual
                std::string nivelActual = seguridad.obtenerNivelActual();

                // Solicitar datos según el nivel de seguridad
                if (nivelActual == "medio" || nivelActual == "alto")
                {
                    std::cout << "Password: ";
                    std::cin >> password;
                }
                if (nivelActual == "alto")
                {
                    std::cout << "Telefono: ";
                    std::cin >> telefono;
                }

                bool isUsuario = false;
                for (int i = 0; i < usuarios->getSize(); i++)
                {
                    Usuario user = usuarios->getElement(i);
                    if (username == user.getNombre() &&
                        (nivelActual == "bajo" || password == user.getPassword()) &&
                        (nivelActual != "alto" || telefono == std::to_string(user.getTelefono())))
                    {
                        // Verificación completada
                        seguridad.verificarIdentidad(username, password, telefono);

                        // Registrar acceso y abrir menú de usuario
                        std::string hora = obtenerHora();
                        Registro* registro = new Registro(user.getNombre(), hora);
                        int index = 0;
                        listaAccesos.ingresaRegistro(listaAccesos.getHead(), registro, index);

                        menuUsuario(user, usuarios, listaAccesos, salirDelPrograma);

                        if (!salirDelPrograma)
                        {
                            isLogged = false;
                        }

                        isUsuario = true;
                        break;
                    }
                }

                if (!isUsuario)
                {
                    std::cout << "Error en la verificación. Usuario no encontrado o datos incorrectos.\n";
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << "Excepcion: " << e.what() << std::endl;
            }
        }
    }
}

void inicializarSeguridadAleatoria(ControlSeguridad& seguridad)
{
    std::string niveles[] = {"bajo", "medio", "alto"};
    int nivelRandom = rand() % 3; // Genera un índice aleatorio entre 0 y 2
    seguridad.cambiarNivel(niveles[nivelRandom]);
    std::cout << "Nivel de seguridad inicial: " << niveles[nivelRandom] << std::endl;
}

int main()
{
    // Semilla para números aleatorios
    srand(time(nullptr));

    // Inicializar seguridad
    ControlSeguridad seguridad;
    inicializarSeguridadAleatoria(seguridad);

    ListaEnlazada<Usuario>* listaUsuarios = new ListaEnlazada<Usuario>();


    Usuario* jorge = new Usuario("Jorge", "1", 671328911, Regular);
    Usuario* german = new Usuario("German", "2", 645610989, Regular);
    Usuario* esteban = new Usuario("Esteban", "3", 605187476, Supervisor);
    Usuario* ricardo = new Usuario("Ricardo", "4", 648135669, Analista);
    listaUsuarios->insert_Tail(*jorge);
    listaUsuarios->insert_Tail(*german);
    listaUsuarios->insert_Tail(*esteban);
    listaUsuarios->insert_Tail(*ricardo);



    ListaRegistro listaAccesos;
    Registro* regJorge = new Registro("Jorge", "14:10");
    Registro* regEsteban = new Registro("Esteban", "08:45");
    Registro* regRicardo = new Registro("Ricardo", "11:30");

    int index = 0;
    listaAccesos.insert_Head(*regJorge);
    listaAccesos.ingresaRegistro(listaAccesos.getHead(), regEsteban, index);
    listaAccesos.ingresaRegistro(listaAccesos.getHead(), regRicardo, index);
    esteban->agregarActividad("Revisión de informes", "12/01/2025");
    esteban->agregarActividad("Revisión de informes", "12/01/2025");  // Actividad sospechosa (duplicada)
    esteban->agregarActividad("Reunión con clientes", "12/01/2025");
    ricardo->agregarActividad("Análisis de seguridad", "12/01/2025");
    ricardo->agregarActividad("Análisis de seguridad", "12/01/2025");

    // Ejecutar el sistema
    logIn(listaUsuarios, listaAccesos, seguridad);

    return 0;
}
