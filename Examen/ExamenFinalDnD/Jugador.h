//
// Created by esvel on 21/01/2025.
//

#ifndef JUGADOR_H
#define JUGADOR_H
#include "Item.h"
#include "LinkedList.h"
#include <iostream>
#include <sstream>
#include "Habilidad.h"

class Jugador
{
private:
    int salud;
    LinkedList<Item>* listaObjetos;
    DynArray<Habilidad>* listaHabilidades;

    void delayPrint(std::string text)
    {
        std::cout << text;
    }
public:
    Jugador()
    {
        this->listaObjetos = new LinkedList<Item>();
        this->listaHabilidades = new DynArray<Habilidad>();
    };

    ~Jugador() = default;

    void addObjeto(Item objeto)
    {
        listaObjetos->append(objeto);
        std::ostringstream mensaje;
        mensaje << "Objeto anadido: " << objeto;
        delayPrint(mensaje.str());
    }

    void addHabilidad(Habilidad habilidad)
    {
        listaHabilidades->add(habilidad);
        std::ostringstream mensaje;
        mensaje << "habilidad anadido: " << habilidad;
        delayPrint(mensaje.str());
    }

    [[nodiscard]] LinkedList<Item>* get_lista_objetos() const
    {
        return listaObjetos;
    }

    [[nodiscard]] int get_salud() const
    {
        return salud;
    }

    void set_salud(int salud)
    {
        this->salud = salud;
    }

    [[nodiscard]] DynArray<Habilidad>* get_lista_habilidades() const
    {
        return listaHabilidades;
    }
};



#endif //JUGADOR_H
