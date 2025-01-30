//
// Created by jorge on 20/10/2024.
//

#include "UsuarioAdministrador.h"

//constructor de UsuarioAdministrador
UsuarioAdministrador::UsuarioAdministrador(const std::string& nombre, const std::string& ID,
                                           const std::string& username,
                                           const std::string& password)
{
    this->nombre = nombre;
    this->ID = ID;
    this->username = username;
    this->password = password;
}

//destructor
UsuarioAdministrador::~UsuarioAdministrador()
{
}

//metodo para dar de alta un usuario
void UsuarioAdministrador::altaUsuario(std::string* nombre, std::string* apellido)
{
}

//metodo para dar de baja un usuario
void UsuarioAdministrador::bajaUsuario(const std::string& ID)
{
}


//metodo para mostrar todos los usuarios
void UsuarioAdministrador::mostrarUsuarios(const std::list<UsuarioAdministrador>& listaAdministradores,
                                           const std::list<Profesor>& listaProfesores,
                                           const std::list<Estudiante>& listaEstudiantes)
{
    int count = 1;

    std::cout << "----- Administradores  -----" << std::endl;

    // Iterate over the list of estudiantes using const reference to avoid copying
    for (auto& a : listaAdministradores)
    {
        std::cout << "#" << count << " ID: " << a.getID() << " " << a.obtenerNombre() << std::endl;

        count++;
    }

    std::cout << "----- Profesores  -----" << std::endl;

    // Iterate over the list of estudiantes using const reference to avoid copying
    for (const auto p : listaProfesores)
    {
        std::cout << "#" << count << " ID: " << p.getID() << " " << p.obtenerNombre() << std::endl;

        count++;
    }

    std::cout << "----- Estudiantes  -----" << std::endl;

    // Iterate over the list of estudiantes using const reference to avoid copying
    for (const auto e : listaEstudiantes)
    {
        std::cout << "#" << count << " ID: " << e.getID() << " " << e.obtenerNombre() << std::endl;

        count++;
    }
}

void UsuarioAdministrador::eliminarUsuarioPorID(std::list<UsuarioAdministrador>& listaAdministradores,
                                                std::list<Profesor>& listaProfesores,
                                                std::list<Estudiante>& listaEstudiantes,
                                                const std::string& id)
{
    // Search and delete in the list of administrators
    for (auto it = listaAdministradores.begin(); it != listaAdministradores.end(); ++it)
    {
        if (it->getID() == id)
        {
            listaAdministradores.erase(it);
            std::cout << "Administrador con ID " << id << " ha sido eliminado." << std::endl;
            return;
        }
    }

    // Search and delete in the list of professors
    for (auto it = listaProfesores.begin(); it != listaProfesores.end(); ++it)
    {
        if (it->getID() == id)
        {
            listaProfesores.erase(it);
            std::cout << "Profesor con ID " << id << " ha sido eliminado." << std::endl;
            return;
        }
    }

    // Search and delete in the list of students
    for (auto it = listaEstudiantes.begin(); it != listaEstudiantes.end(); ++it)
    {
        if (it->getID() == id)
        {
            listaEstudiantes.erase(it);
            std::cout << "Estudiante con ID " << id << " ha sido eliminado." << std::endl;
            return;
        }
    }

    std::cout << "Ningun Usuario con ID " << id << " fue encontrado." << std::endl;
}


std::string UsuarioAdministrador::getUsername() const
{
    return username;
}

std::string UsuarioAdministrador::getPassword() const
{
    return password;
}

std::string UsuarioAdministrador::obtenerNombre() const
{
    return nombre;
}

std::string UsuarioAdministrador::getID() const
{
    return ID;
}

UsuarioAdministrador UsuarioAdministrador::crearUsuarioAdministrador()
{
    std::string nombre, ID, username, password;

    std::cout << "Ingresa el nombre del Administratdor: ";
    std::cin >> nombre;

    std::cout << "El ID del Administrador: ";
    std::cin >> ID;

    std::cout << "El Username del Administrador: ";
    std::cin >> username;

    std::cout << "El Password del Administrador: ";
    std::cin >> password;

    return UsuarioAdministrador(nombre, ID, username, password);
}

Profesor UsuarioAdministrador::crearProfesor()
{
    std::string nombre, ID, username, password;

    std::cout << "Ingresa el nombre del Profesor: ";
    std::cin >> nombre;

    std::cout << "El ID del Profesor: ";
    std::cin >> ID;

    std::cout << "El Username del Profesor: ";
    std::cin >> username;

    std::cout << "El Password del Profesor: ";
    std::cin >> password;

    return Profesor(nombre, ID, username, password, nullptr);
}

Estudiante UsuarioAdministrador::crearEstudiante()
{
    std::string nombre, ID, username, password;

    std::cout << "Ingresa el nombre del Estudiante: ";
    std::cin >> nombre;

    std::cout << "El ID del Estudiante: ";
    std::cin >> ID;

    std::cout << "El Username del Estudiante: ";
    std::cin >> username;

    std::cout << "El Password del Estudiante: ";
    std::cin >> password;

    return Estudiante(nombre, ID, username, password, nullptr);
}
