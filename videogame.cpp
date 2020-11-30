#include "videogame.h"
#include <fstream>
#include <algorithm>

Videogame::Videogame() { } // constructor

void Videogame::agregarCivilizacion(const Civilizacion &c) { // sobrecarga
    civilizaciones.push_back(c);
}

void Videogame::mostrar() {

    cout << left;
    cout << setw(20) << "\tNombre ";
    cout << setw(11) << "Posicion X";
    cout << setw(20) << "Posicion Y";
    cout << "Puntuacion";
    cout << endl;

    /* Imprimimos la clase */
    for (size_t i = 0; i < civilizaciones.size(); i++) {
        Civilizacion &c = civilizaciones[i];
        cout << "\t" << c;
    }
}

void Videogame::respaldarCivilizaciones() {
    ofstream archivo("civilizaciones.txt", ios::out);

    if(archivo.is_open()) {

        for (size_t i = 0; i < civilizaciones.size(); i++){
            Civilizacion &c = civilizaciones[i];
            archivo << c.getNombre() << endl;
            archivo << c.getX() << endl;
            archivo << c.getY() << endl;
            archivo << c.getPuntuacion() << endl;
            c.respaldarAldeanos();
        }
    }
    archivo.close();
}

void Videogame::recuperarCivilizaciones() {
    ifstream archivo("civilizaciones.txt", ios::out);

    if(archivo.is_open()) {
        string tempString;
        int tempInt;
        float tempFloat;

        while(true) {
            Civilizacion c;

            getline(archivo, tempString); 
            if(archivo.eof()){
                break;
            }
            c.setNombre(tempString);

            getline(archivo, tempString); 
            tempInt = stoi(tempString);
            c.setX(tempInt);

            getline(archivo, tempString);
            tempInt = stoi(tempString);
            c.setY(tempInt);

            getline(archivo, tempString); 
            tempFloat = stof(tempString);               
            c.setPuntuacion(tempFloat);

            c.recuperarAldeanos();
            agregarCivilizacion(c);
        }
    }
    archivo.close();
}

void Videogame::insertar(const Civilizacion &c, size_t pos) {
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

size_t Videogame::size() {
    return civilizaciones.size(); // retorna tamaño de objeto
}

Civilizacion Videogame::front() {
    return civilizaciones.front(); // retorna el primer valor
}

Civilizacion Videogame::back() {
    return civilizaciones.back(); // retorna el ultimo valor
}

void Videogame::inicializar(const Civilizacion &c, size_t n) {
    civilizaciones = vector<Civilizacion>(n, c);
}

void Videogame::eliminar(const Civilizacion &c) {
    civilizaciones.erase(std::remove(civilizaciones.begin(), civilizaciones.end(), c), civilizaciones.end());
}

void Videogame::ordenarNombre() {
    sort(civilizaciones.begin(), civilizaciones.end());
}

void Videogame::ordenarX() {
    /* Ordenar = funcion lambda + atributo a ordenar */
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getX() < c2.getX();});
}

void Videogame::ordenarY() {
    /* Ordenar = funcion lambda + atributo a ordenar */
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion y1, Civilizacion y2){return y1.getY() < y2.getY();});
}

void Videogame::ordenarPuntuacion() {
    /* Ordenar = funcion lambda + atributo a ordenar */
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() < c2.getPuntuacion();});
}


Civilizacion* Videogame::buscar(const Civilizacion &c) {
    // vector<Civilizacion>::iterator
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if (it == civilizaciones.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}
