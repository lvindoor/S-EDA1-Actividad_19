#include "menu.h"

using namespace std;

Menu::Menu() { // inicializamos clase Menu
    opc = 0;
    continuarMenu = true;
}

void Menu::correr() {
    do {
        cout << endl;
        cout << "\t--------------------------------------------" << endl;
        cout << "\t                  MENU                     " << endl;
        cout << "\t--------------------------------------------" << endl << endl;
        cout << "\t1-. Nombre Usuario - " << c.getNombre() << endl;
        cout << "\t2-. Agregar Civilizacion" << endl;
        cout << "\t3-. Insertar" << endl;
        cout << "\t4-. Inicializar" << endl;
        cout << "\t5-. Primer Civilizacion" << endl;
        cout << "\t6-. Ultima Civilizacion" << endl;
        cout << "\t7-. Ordenar" << endl;
        cout << "\t8-. Eliminar" << endl;
        cout << "\t9-. Buscar" << endl;
        cout << "\t10-. Modificar" << endl;
        cout << "\t11-. Resumen" << endl;
        cout << "\t12-. Respaldar" << endl;
        cout << "\t13-. Recuperar" << endl;
        cout << "\t14-. Salir" << endl;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();


        if(opc!=SALIR) {
            avanza();
        }

        /* Evaluamos */
        switch(opc) {

        case NOMBRE_USUARIO: {
            cout << "\tIngrese el nombre de usuario : ";
            getline(cin,nombreUsuario); // guardamos
            c.setNombre(nombreUsuario); // agregamos a la actual civilización

        }
        break;

        case AGREGAR: {

            if(nombreUsuario == "") { // no se ha agregado nombre de usuario
                cin >> c; // pedimos datos y guardamos
                v.agregarCivilizacion(c); // agregamos al arreglo
            } else { // ya hay un nombre usuario
                /* Variables temporales */
                int tempInt;
                float tempFloat;
                /* Pedimos datos faltantes */
                cout << "\tPosicion X : ";
                cin >> tempInt;
                c.setX(tempInt);
                cin.ignore();
                cout << "\tPosicion Y : ";
                cin >> tempInt;
                c.setY(tempInt);
                cin.ignore();
                cout << "\tPuntuacion : ";
                cin >> tempFloat;
                c.setPuntuacion(tempFloat);
                cin.ignore();
                v.agregarCivilizacion(c); // agregamos al arreglo
                nombreUsuario = ""; // limpiamos el nombre de usuario
            }

        }
        break;

        case INSERTAR:
            size_t p; // creamos una variable posición

            cout << "\tPosicion a insertar : ";
            cin >> p; cin.ignore();
            cin >> c; // pedimos datos y guardamos
            cout << endl;

            if (p >= v.size()) { // ¿Posición valida?
                cout << "\tposicion no valida" << endl;
            } else {
                v.insertar(c,p); // insertamos en p
            }
            break;

        case INICIALIZAR:
            size_t n; // creamos una variable de tamaño

            cout << "\tDimension de vector : ";
            cin >> n; cin.ignore(); // guardamos el nuevo tamaño
            cout << endl << "\t  Inicializando con ... " << endl << endl;
            cin >> c; // guardamos la cadena a inicializar
            cout << endl;

            v.inicializar(c,n); // declaramos el cambio en el vector
            break;

        case PRIMERA:
            cout << "\tLa primera civilizacion es: " << endl;
            if(v.size()>0) {
                cout << "\t" << v.front(); // traemos la primera civilizacion
            } else {
                cout << "\tNo hay civilizaciones" << endl;
            }
            break;

        case ULTIMA:
            cout << "\tLa ultima civilizacion es: " << endl;
            if(v.size()>0) {
                cout  << "\t" << v.back(); // traemos la ultima civilizacion
            } else {
                cout << "\tNo hay civilizaciones" << endl;
            }
            break;

        case ORDENAR: {

            int opc; // creamos una opcion para el submenu
            bool continueProgram = true; // comenzamos el submenu ciclico

            do {

                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t               ORDENACIONES POR              " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Nombre Usuario " << endl;
                cout << "\t2-. Posicion en X" << endl;
                cout << "\t3-. Posicion en Y" << endl;
                cout << "\t4-. Puntuacion" << endl;
                cout << "\t5-. Regresar" << endl;
                cout << endl << "\topcion : ";
                cin >> opc; cin.ignore();
                cout << endl;

                /* Evaluamos */
                switch(opc) {
                    case ORDENAR_NOMBRE:
                        v.ordenarNombre();
                        break;
                    case ORDENAR_X:
                        v.ordenarX();
                        break;
                    case ORDENAR_Y:
                        v.ordenarY();
                        break;
                    case ORDENAR_PUNTUACION:
                        v.ordenarPuntuacion();
                        break;
                    case ORDENAR_REGRESAR:
                        continueProgram = false;
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                        break;
                }

                cout << endl << "\tDesea seguir modificando (S/N) : ";
                if(cin.get() != 'S') {
                    continueProgram = false;
                }

                if(continueProgram) {
                    cout << endl << "\tPresione entrar para continuar ..." << endl;
                    cin.get();
                    system(CLEAN_SCREEN);
                    cout << endl << endl;
                }
            } while(continueProgram);
        }
        break;

        case ELIMINAR: {

            cout << "\tEscriba el nombre de la civilizacion a borrar..." << endl << endl;
            cout << "\tNombre : ";
            getline(cin,nombreUsuario); // pedimos la civilizacion
            c.setNombre(nombreUsuario); // agregamos al modelo
            cout << endl;

            Civilizacion *busqueda = v.buscar(c); // buscamos

            if(busqueda==nullptr) {
                cout << "\tNo encontrado" << endl;
            } else {
                v.eliminar(*busqueda); // eliminamos en p
            }
        }
        break;

        case BUSCAR: {
                cout << "\tEscriba el nombre de la civilizacion a buscar..." << endl << endl;
                cout << "\tNombre : ";
                getline(cin,nombreUsuario); // pedimos la civilizacion
                c.setNombre(nombreUsuario); // agregamos al modelo
                cout << endl;

                Civilizacion *busqueda = v.buscar(c); // buscamos

                if(busqueda==nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t!Encontrado¡" << endl << endl;
                    cout << "\t" << *busqueda << endl;
                    avanza(); // limpiamos
                    subMenu(*busqueda); // mandamos al submenu con la c encontrada
                }
            }
            break;

        case MODIFICAR: {

            int opc; // creamos una opcion para el submenu
            bool continueProgram = true; // comenzamos el submenu ciclico

            do {

                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t                   MODIFICAR               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\tEscriba el nombre de la civilizacion a buscar. " << endl << endl;

                cout << "\tNombre : ";
                getline(cin,nombreUsuario); // pedimos la civilizacion
                c.setNombre(nombreUsuario); // agregamos al modelo

                Civilizacion *busqueda = v.buscar(c); // hacemos una busqueda

                if(busqueda == nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *busqueda << endl << endl; // imprimimos el lo que tiene el puntero
                    /* Variables temporales */
                    string tempString;
                    int tempInt;
                    float tempFloat;

                    cout << "\tEscoga el campo a Modificar" << endl << endl;
                    cout << "\t1.- Nombre" << endl;
                    cout << "\t2.- Ubicacion en X" << endl;
                    cout << "\t3.- Ubicacion en Y" << endl;
                    cout << "\t4.- Puntuacion" << endl;
                    cout << "\t5.- Regresar" << endl << endl;
                    cout << "\tOpcion : ";
                    cin >> opc;
                    cout << endl;
                    cin.ignore();

                    switch(opc) {
                        case MODIFICAR_NOMBRE:
                            cout << "\tNombre : ";
                            getline(cin, tempString);
                            busqueda->setNombre(tempString);
                            break;
                        case MODIFICAR_X:
                            cout << "\tUbicacion en x : ";
                            cin >> tempInt;
                            busqueda->setX(tempInt);
                            break;
                        case MODIFICAR_Y:
                            cout << "\tUbicacion en y : ";
                            cin >> tempInt;
                            busqueda->setX(tempInt);
                            break;
                        case MODIFICAR_PUNTUACION:
                            cout << "\tPuntuacion : ";
                            cin >> tempFloat;
                            busqueda->setPuntuacion(tempFloat);
                            break;
                        case MODIFICAR_REGRESAR:
                            continueProgram = false;
                            break;
                        default:
                            cout << "\tNo existe tal opcion" << endl;
                            cin.ignore();
                    }

                    cout << endl << "\tDesea seguir modificando (S/N) : ";
                    if(cin.get() != 'S') {
                        continueProgram = false;
                    }

                    if(continueProgram) {
                        cout << endl << "\tPresione entrar para continuar ..." << endl;
                        cin.get();
                        system(CLEAN_SCREEN);
                        cout << endl << endl;
                    }
                }
            } while(continueProgram);
        }
        break;

        case MOSTRAR:
            v.mostrar(); // mostramos
            break;

        case RESPALDAR:
            v.respaldarCivilizaciones(); // respaldamos
            break;

        case RECUPERAR:
            v.recuperarCivilizaciones(); // recuperamos
            break;

        case SALIR:
            continuarMenu = false; // cerramos ciclo
            break;

        default:
            cout << "\tOpcion Invalida" << endl;
            break;
        }

        if(continuarMenu) {
            avanza();
        }

    } while(continuarMenu);
}

void Menu::subMenu(Civilizacion &c) {

    size_t opc = 0; // opcion menu - local
    bool continuarMenu = true; // bandera para continuar con el menu - local
    /* Variables temporales */
    string tempString;
    size_t tempInt;
    float tempFloat;

    do {
        cout << endl;
        cout << "\t--------------------------------------------" << endl;
        cout << "\t                  MENU                     " << endl;
        cout << "\t--------------------------------------------" << endl << endl;
        cout << "\t1-. Agregar Aldeano" << endl;
        cout << "\t2-. Eliminar Aldeano" << endl;
        cout << "\t3-. Clasificar Aldeanos" << endl;
        cout << "\t4-. Buscar Aldeano" << endl;
        cout << "\t5-. Modificar Aldeano" << endl;
        cout << "\t6-. Mostrar Aldeanos" << endl;
        cout << "\t7-. Regresar" << endl;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();

        if(opc!=REGRESAR or opc!=BUSCAR_ALDEANO) {
            avanza();
        }

        /* Evaluamos */
        switch(opc) {
            case AGREGAR_ALDEANO: {
                size_t opc; // opcion local
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t              AGREGAR ALDEANO               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Agregar Inicio" << endl;
                cout << "\t2-. Agregar Final" << endl;
                cout << endl << "\topcion : ";
                cin >> opc; cin.ignore();
                cout << endl;
                cin >> a; cin.ignore(); // capturamos el aldeano

                /* Evaluamos */
                switch(opc) {
                    case AGREGAR_ALDEANO_INICIO:
                        c.agregarInicio(a); // insertamos al inicio
                        break;
                    case AGREGAR_ALDEANO_FINAL:
                        c.agregarFinal(a); // insertamos al final
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                }
            }
            break;

            case ELIMINAR_ALDEANO: {
                size_t opc; // creamos una opcion para el submenu - local
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t            ELIMINAR ALDEANO                " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Nombre " << endl;
                cout << "\t2-. Edad     -> Mayor a 60" << endl;
                cout << "\t3-. Salud    -> Escoger" << endl << endl;
                cout << "\topcion : ";
                cin >> opc; cin.ignore();
                cout << endl << endl;
                /* Evaluamos */
                switch(opc) {
                    case ELIMINAR_ALDEANO_NOMBRE:
                        cout << "\tEscriba el nombre del aldeano a borrar..." << endl << endl;
                        cout << "\tNombre : ";
                        getline(cin,tempString); // pedimos el nombre
                        c.eliminarNombre(tempString); // eliminamos por nombre
                        break;
                    case ELIMINAR_ALDEANO_EDAD:
                        c.eliminarEdad(); // eliminamos por edad
                        break;
                    case ELIMINAR_ALDEANO_SALUD:
                        cout << "\tEscriba la salud promedio del aldeano a borrar..." << endl << endl;
                        cout << "\tSalud : ";
                        cin >> tempFloat; cin.ignore();
                        c.eliminarSalud(tempFloat); // eliminamos por salud
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                }
            }
            break;

            case CLASIFICAR_ALDEANO: {
                size_t opc; // creamos una opcion para el submenu - local
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t               CLASIFICACIONES              " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Nombre   -> ascendente" << endl;
                cout << "\t2-. Edad     -> descendente" << endl;
                cout << "\t3-. Salud    -> descendente" << endl;
                cout << endl << "\topcion : ";
                cin >> opc; cin.ignore();
                /* Evaluamos */
                switch(opc) {
                    case CLASIFICAR_ALDEANO_NOMBRE:
                        c.ordenarNombre();
                        break;
                    case CLASIFICAR_ALDEANO_EDAD:
                        c.ordenarEdad();
                        break;
                    case CLASIFICAR_ALDEANO_SALUD:
                        c.ordenarSalud();
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                }
            }
            break;

            case BUSCAR_ALDEANO: {
                Aldeano* busqueda;
                cout << "\tEscriba el nombre del aldeano a buscar..." << endl << endl;
                cout << "\tNombre : ";
                getline(cin,tempString); // pedimos la nombre
                busqueda = c.buscar(tempString); // agregamos al modelo
                cout << endl;
                if(busqueda == nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *busqueda << endl;
                }
            }
            break;

            case MODIFICAR_ALDEANO: {
                size_t opc; // creamos una opcion para el submenu - local
                Aldeano* busqueda;
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t            MODIFICAR ALDEANO               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\tEscriba el nombre del aldeano a buscar..." << endl << endl;
                cout << "\tNombre : ";
                getline(cin,tempString); // pedimos nombre
                busqueda = c.buscar(tempString); // agregamos al modelo
                cout << endl;
                if(busqueda == nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *busqueda << endl;
                    cout << "\tEscoga el campo a Modificar" << endl << endl;
                    cout << "\t1.- Nombre" << endl;
                    cout << "\t2.- Edad" << endl;
                    cout << "\t3.- Salud" << endl << endl;
                    cout << "\topcion : ";
                    cin >> opc; cin.ignore();
                    cout << endl;
                    avanza();
                    switch(opc) {
                        case MODIFICAR_ALDEANO_NOMBRE:
                            cout << "\tNombre   : ";
                            getline(cin, tempString);
                            busqueda->setNombre(tempString);
                            break;
                        case MODIFICAR_ALDEANO_EDAD:
                            cout << "\tEdad     : ";
                            cin >> tempInt;
                            busqueda->setEdad(tempInt);
                            break;
                        case MODIFICAR_ALDEANO_SALUD:
                            cout << "\tSalud   : ";
                            cin >> tempFloat;
                            busqueda->setSalud(tempFloat);
                            break;
                        default:
                        cout << "\tOpcion Invalida" << endl;
                    }
                }
            }
            break;

            case MOSTRAR_ALDEANOS: {
                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t           TODOS LOS ALDEANOS               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                c.mostrar(); // mandamos los aldeanos de la civilizacion
            }
            break;

            case REGRESAR: {
                continuarMenu = false;
            }
            break;

            default: {
                cout << "\tOpcion Invalida" << endl;
            }
        }

        if(continuarMenu) {
            avanza();
        }

    } while(continuarMenu);
}

void Menu::avanza() { // Limpia pantalla y avanza
    cout << endl << "\tPresione entrar para continuar ..." << endl;
    cin.get();
    system(CLEAN_SCREEN);
    cout << endl << endl;
}
