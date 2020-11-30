#ifndef VIDEOJGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>
#include <fstream>

class Videogame {

    std::string nombreUsuario;
    vector<Civilizacion> civilizaciones;

public:

    Videogame(); // constructor
    
    /** Funciones **/
    
    void mostrar();
    size_t size();
    Civilizacion front();
    Civilizacion back();

    /* Agregar */
    void agregarCivilizacion(const Civilizacion &c); // sobrecarga
    /* Insertar */
    void insertar(const Civilizacion &c, size_t pos);
    void inicializar(const Civilizacion &c, size_t n);
    /* Eliminar */
    void eliminar(const Civilizacion&);
    /* Respaldar y Recuperar */
    void respaldarCivilizaciones();
    void recuperarCivilizaciones();
    /* Ordenamientos */
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();

    Civilizacion* buscar(const Civilizacion &c);

    friend Videogame& operator<<(Videogame &v, const Civilizacion &c)
    {
        v.agregarCivilizacion(c);

        return v;
    }
};

#endif
