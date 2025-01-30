#include <iostream>

#include "Dynarray.h"
#include "Jugador.h"
#include "Monster.h"

void delayPrint(std::string text)
{
    std::cout << text << std::endl;
}

void menuDeObjetos(Jugador& jugador)
{
    bool salir = false;

    while (!salir)
    {
        delayPrint("=== Menu de Objetos ===");

        for (int i = 0; i < jugador.get_lista_objetos()->getSize(); ++i) // revisar si devuelve referencia
        {
            const Item& objeto = jugador.get_lista_objetos()->at(i); // tambien aqui
            std::cout << i + 1 << ") " << objeto << std::endl;
        }

        delayPrint("0) Salir");

        int opcion;
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        if (opcion == 0)
        {
            salir = true;
        }
        else if (opcion > 0 && opcion <= jugador.get_lista_objetos()->getSize())
        {
            // Get the selected object
            const Item& seleccionado = jugador.get_lista_objetos()->at(opcion - 1);

            delayPrint("Has consumido: " + seleccionado.getNombre());
            // El uso de todos los objetos directamente asociado con curar, por lo cual no creo una funcion dentro de
            // Objeto para su consumo.
            jugador.set_salud(jugador.get_salud() + seleccionado.getEfecto());

            jugador.get_lista_objetos()->remove(seleccionado);
        }
        else
        {
            delayPrint("Opcion invalida. Intenta de nuevo.");
        }
    }
}

void menuHabilidades(Jugador& jugador)
{
    bool salir = false;

    while (!salir)
    {
        delayPrint("=== Menu de Habilidades ===");
        DynArray<Habilidad>* habilidades = jugador.get_lista_habilidades(); // revisar si devuelve puntero

        if (habilidades->getSize() == 0)
        {
            delayPrint("No tienes habilidades disponibles.");
            salir = true;
            continue;
        }

        delayPrint("Selecciona una habilidad para usar:");
        for (size_t i = 0; i < habilidades->getSize(); ++i)
        {
            std::cout << i + 1 << ". " << habilidades->get(i) << std::endl;
        }
        std::cout << habilidades->getSize() + 1 << ". Salir" << std::endl;

        int opcion = 0;
        std::cout << "Tu opcion: ";
        std::cin >> opcion;

        if (opcion >= 1 && opcion <= habilidades->getSize())
        {
            Habilidad habilidadSeleccionada = habilidades->get(opcion - 1);
            jugador.usar_habilidad(habilidadSeleccionada);
        }
        else if (opcion == habilidades->getSize() + 1)
        {
            salir = true;
        }
        else
        {
            delayPrint("Opcion no valida. Intenta de nuevo.");
        }
    }
}

void menuCombate(Jugador& jugador, DynArray<Monster> listaMonstruos)
{
    bool salir = false;
    std::srand(std::time(nullptr));
    // Asumiendo que la lista tiene 5 monstruos dentro, sino se puede cambiar por un 5 el listaMonstruos->getSize()
    int random_number = std::rand() % listaMonstruos->getSize();

    Monster* monster = listaMonstruos->get(random_number); // revisar si debe ser referencia
    std::ostringstream mensaje;
    mensaje << "Un " << monster->get_M_Name() << "ha salido!!!";
    delayPrint(mensaje.str());

    while (!salir)
    {
        delayPrint("=== Menu Combate ===");
        delayPrint("1) Atacar");
        delayPrint("2) Usar Habilidad");
        delayPrint("3) Menu de Objetos");
        delayPrint("4) Ver Estado del Combate");
        delayPrint("5) Huir");
        delayPrint("0) Salir");

        int opcion;
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 0:
            salir = true;
            break;

        case 1:
            delayPrint("Atacando al enemigo...");
            monster->setVida(monster->getVida() - jugador.get_armaEquipada().get_W_Atack());
            break;

        case 2:
            delayPrint("Usando habilidad...");
            menuHabilidades(jugador);
            break;

        case 3:
            delayPrint("Abriendo Menu de Objetos...");
            menuDeObjetos(jugador);
            break;

        case 4:
            delayPrint("Estado del combate.");
            delayPrint("Salud Monstruo: " + std::to_string(monster->get_vida()));
            delayPrint("Tu Salud: " + std::to_string(jugador.get_salud()));
            break;

        case 5:
            delayPrint("Intentando huir...");
            if (std::rand() % 2 == 0)
            {
                delayPrint("Has escapado con éxito!");
                salir = true;
            }
            else
            {
                delayPrint("No lograste escapar. El combate continúa.");
            }
            break;

        default:
            delayPrint("Opción inválida. Intenta de nuevo.");
            break;
        }

        if (!salir)
        {
            char continuar;
            delayPrint("El combate ha terminado. ¿Quieres seguir combatiendo? (s/n): ");
            std::cin >> continuar;

            if (continuar == 'n' || continuar == 'N')
            {
                salir = true;
            }
            else
            {
                delayPrint("Preparándote para el siguiente combate...");
            }
        }
    }
}

int main()
{
    int opcion = (22300950 % 2) + 1;

    std::cout << "Opcion: " << opcion << std::endl;

    // Ejercicio 2
    Jugador* jugador = new Jugador();

    Item* o1 = new Item("pocion Grande", 50);
    Item* o2 = new Item("Pocion Pequena", 25);

    jugador->addObjeto(*o1);
    jugador->addObjeto(*o2);

    std::cout << jugador << std::endl;
    std::cout << &jugador << std::endl;

    menuDeObjetos(*jugador);

    // Ejercicio 3:
    Habilidad* fireball = new Habilidad("Bola de Fuego", "Una explosión de fuego que quema a los enemigos.", 50);
    Habilidad* iceSpike = new Habilidad("Pico de Hielo", "Lanza un afilado fragmento de hielo hacia el enemigo.", 35);
    Habilidad* thunderStrike = new Habilidad("Golpe de Trueno", "Invoca un rayo que impacta al enemigo con fuerza.",
                                             45);
    jugador->addHabilidad(*fireball);
    jugador->addHabilidad(*iceSpike);
    jugador->addHabilidad(*thunderStrike);

    menuCombate(*jugador);

    // Liberar memoria
    delete fireball;
    delete iceSpike;
    delete thunderStrike;
    delete(o1);
    delete(o2);


    return 0;
}
