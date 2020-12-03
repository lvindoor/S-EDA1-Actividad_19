#ifndef ALDEANO_H_INCLUDED
#define ALDEANO_H_INCLUDED

#include <iostream>
#include <iomanip>

using namespace std;

class Aldeano {
private:
    string nombre;
    size_t edad;
    string genero;
    float salud;
public:
    Aldeano() { } // constructor
    Aldeano(const string &nombre, size_t edad, string genero, float salud) // sobrecarga
    : nombre(nombre), edad(edad), genero(genero), salud(salud) {} // delegacion de constructores

    /* Getters */
    string getNombre() const;
    size_t getEdad() const;
    string getGenero() const;
    float getSalud() const;

    /* Setters */
    void setNombre(const string &nombre);
    void setEdad(const size_t &edad);
    void setGenero(const string &genero);
    void setSalud(const float &salud);

    /* Salida del Modelo */
    friend ostream& operator<<(ostream &out, const Aldeano &a){
        out << left ;
        out << setw(20) << a.nombre;
        out << setw(21) << a.edad;
        out << setw(15) << a.genero;
        out << setw(16) << a.salud;
        out << endl;
        return out;
    }

    /* Entrada del Modelo */
    friend istream& operator>>(istream &in, Aldeano &a){

        cout << "\tNombre   : ";
        getline(cin, a.nombre);

        cout << "\tEdad     : ";
        cin >> a.edad;
        cin.ignore();

        cout << "\tGenero   : ";
        getline(cin, a.genero);

        cout << "\tSalud    : ";
        cin >> a.salud;

        return in;
    }

    /* Operadores Logicos */

    bool operator==(const Aldeano& a) {
        return nombre == a.nombre;
    }

    bool operator==(const Aldeano& a) const {
        return nombre == a.nombre;
    }

    bool operator<(const Aldeano& a) const { // para metodo Ordenar()
        return nombre < a.nombre;
    }

};

#endif //ALDEANO_H_INCLUDED
