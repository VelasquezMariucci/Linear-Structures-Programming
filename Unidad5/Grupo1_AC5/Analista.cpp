#include "Analista.h"
#include "Registro.h"
#include "Usuario.h"

#include <iostream>
#include <vector>

// Constructor de la clase Analista
Analista::Analista(const std::string& nombre, const std::string& password, long telefono)
: Usuario(nombre, password, telefono, tiposUsuarios::Analista) // Llama al constructor base Usuario con tipo Analista
{
}

// Método para contar los accesos de manera recursiva
void Analista::contarAccesos(Registro* acceso)
{
    if (acceso == nullptr) {
        return; // Si no hay más registros, termina la recursión
    }

    // Muestra el nombre del usuario que ha accedido
    std::cout << "Usuario: " << acceso->getNombreUsuario() << " accedió a la aplicación." << std::endl;

    // Llamada recursiva para contar el siguiente acceso
    contarAccesos(acceso->getSiguienteAcceso());
}

// Método para buscar actividades sospechosas en los usuarios
void Analista::buscarActividadesSospechosas(std::vector<Usuario*>& usuarios)
{
    for (Usuario* u : usuarios) {
        // Obtiene la lista de actividades del usuario
        ListaEnlazada<Actividad>* actividades = u->getActividades();

        // Recorre las actividades del usuario
        for (int i = 0; i < actividades->getSize(); ++i) {
            Actividad& actividad1 = actividades->getElement(i); // Obtiene la actividad 1
            for (int j = i + 1; j < actividades->getSize(); ++j) {
                Actividad& actividad2 = actividades->getElement(j); // Obtiene la actividad 2
                // Compara las dos actividades y si son sospechosas, muestra el mensaje
                if (actividadSospechosa(actividad1, actividad2)) {
                    std::cout << "¡Actividad sospechosa detectada!" << std::endl;
                    std::cout << "Usuario: " << u->getNombre() << ", Actividad: " << actividad1.getDescripcion() << std::endl;
                    std::cout << "Fecha 1: " << actividad1.getFecha() << ", Fecha 2: " << actividad2.getFecha() << std::endl;
                }
            }
        }
    }
}

// Método privado para verificar si dos actividades son sospechosas (misma descripción y fecha)
bool Analista::actividadSospechosa(const Actividad& actividad1, const Actividad& actividad2)
{
    return actividad1.getDescripcion() == actividad2.getDescripcion() &&
           actividad1.getFecha() == actividad2.getFecha(); // Si ambas son iguales, se considera sospechosa
}
