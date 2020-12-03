#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include "aldeano.h"
#include <list>
#include <fstream>

#define MAYOR_EDAD 60

class Civilizacion {
private:
    string nombre;
    int x, y;
    float puntuacion;
    list<Aldeano> aldeanos;

public:
    Civilizacion() { } // constructor
    Civilizacion(const string &nombre, const int &x, const int &y, const float &puntuacion) // sobrecarga
    : nombre(nombre), x(x), y(y), puntuacion(puntuacion) {} // delegacion de constructores

    /** Funciones **/

    void mostrar();
    /* Agregar */
    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);
    /* Eliminar */
    void eliminarNombre(const string &nombre);
    void eliminarEdad();
    void eliminarSalud(float salud);
    /* Ordenamientos */
    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();
    /* Buscar */
    Aldeano* buscar(const string &nombre);
    /* Respaldar y Recuperar */
    void respaldarAldeanos();
    void recuperarAldeanos();

    /** Getters **/

    string getNombre() const;
    int getX() const;
    int getY() const;
    float getPuntuacion() const;

    /** Setters **/

    void setNombre(const string &nombre);
    void setX(const int &x);
    void setY(const int &y);
    void setPuntuacion(const float &puntuacion);

    /* Salida del Modelo */
    friend ostream& operator<<(ostream &out, const Civilizacion &c) {

        out << left;
        out << setw(20) << c.nombre;
        out << setw(10) << c.x;
        out << setw(20) << c.y;
        out << setw(16) << c.puntuacion;
        out << endl;

        return out;
    }

    /* Entrada del Modelo */
    friend istream& operator>>(istream &in, Civilizacion &c) {

        cout << "\tNombre     : ";
        getline(cin, c.nombre);

        cout << "\tPosicion X : ";
        cin >> c.x;
        cin.ignore();

        cout << "\tPosicion Y : ";
        cin >> c.y;
        cin.ignore();

        cout << "\tPuntuacion : ";
        cin >> c.puntuacion;
        cin.ignore();

        return in;
    }

    /* Operadores Logicos */

    bool operator==(const Civilizacion& c) {
        return nombre == c.nombre;
    }

    bool operator==(const Civilizacion& c) const {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c) { // para metodo Ordenar()
        return nombre < c.nombre;
    }

    bool operator<(const Civilizacion& c) const { // para metodo Ordenar()
        return nombre < c.nombre;
    }
};

#endif
