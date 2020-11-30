#include "aldeano.h"

/* Getters */

string Aldeano::getNombre() const {
    return nombre;
}

size_t Aldeano::getEdad() const {
    return edad;
}

string Aldeano::getGenero() const {
    return genero;
}

float Aldeano::getSalud() const {
    return salud;
}

/* Setters */

void Aldeano::setNombre(const string &nombre) {
    this->nombre = nombre;
}

void Aldeano::setEdad(const size_t &edad) {
    this->edad = edad;
}

void Aldeano::setGenero(const string &genero) {
    this->genero = genero;
}

void Aldeano::setSalud(const float &salud) {
    this->salud = salud;
}
