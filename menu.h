#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>

#include "civilizacion.h"
#include "videogame.h"

#ifdef _WIN32
#define CLEAN_SCREEN "cls"
#else
#define CLEAN_SCREEN "clear"
#endif // _WIN32

/* Opciones Menu */
enum {
    NOMBRE_USUARIO = 1,
    AGREGAR,
    INSERTAR,
    INICIALIZAR,
    PRIMERA,
    ULTIMA,
    ORDENAR,
    ELIMINAR,
    BUSCAR,
    MODIFICAR,
    MOSTRAR,
    RESPALDAR,
    RECUPERAR,
    SALIR
};

/* Opciones Sub-Menu -> Ordenar Civilizacion */

enum {
    ORDENAR_NOMBRE = 1,
    ORDENAR_X,
    ORDENAR_Y,
    ORDENAR_PUNTUACION,
    ORDENAR_REGRESAR
};

/* Opciones Sub-Menu -> Modificar Civilizacion */

enum {
    MODIFICAR_NOMBRE = 1,
    MODIFICAR_X,
    MODIFICAR_Y,
    MODIFICAR_PUNTUACION,
    MODIFICAR_REGRESAR
};

/* Opciones Sub-Menu -> Elegir Civilizacion */
enum {
    AGREGAR_ALDEANO = 1,
    ELIMINAR_ALDEANO,
    CLASIFICAR_ALDEANO,
    BUSCAR_ALDEANO,
    MODIFICAR_ALDEANO,
    MOSTRAR_ALDEANOS,
    REGRESAR
};

/* Opciones Sub-Menu -> Agregar Aldeano */
enum {
    AGREGAR_ALDEANO_INICIO = 1,
    AGREGAR_ALDEANO_FINAL
};

/* Opciones Sub-Menu -> Eliminar Aldeano */
enum {
    ELIMINAR_ALDEANO_NOMBRE = 1,
    ELIMINAR_ALDEANO_SALUD,
    ELIMINAR_ALDEANO_EDAD
};

/* Opciones Sub-Menu -> Clasificar Aldeano */
enum {
    CLASIFICAR_ALDEANO_NOMBRE = 1,
    CLASIFICAR_ALDEANO_SALUD,
    CLASIFICAR_ALDEANO_EDAD
};

/* Opciones Sub-Menu -> Modificar */
enum {
    MODIFICAR_ALDEANO_NOMBRE = 1,
    MODIFICAR_ALDEANO_EDAD,
    MODIFICAR_ALDEANO_SALUD
};

class Menu {
private:
    Videogame v;
    vector<Civilizacion> civilizaciones; // creamos la lista de vectores
    Civilizacion c; // creamos el objeto como aux
    Aldeano a; // creamos el objeto como aux
    size_t opc; // opcion menu
    string nombreUsuario; // variable para nombre de usuario -> civilizacion
    bool continuarMenu; // bandera para continuar con el menu

    /* Metodos privados */
    void avanza(); // limpia pantalla
    void subMenu(Civilizacion &c); // submenu

public:
    Menu(); // constructor
    void correr(); // funci�n del menu principal

};

#endif
