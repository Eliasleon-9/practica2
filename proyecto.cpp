#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const size_t TAMANO = 5;

// Definicion de la estructura Libro con arrays
struct SLibro {
    int nISBN;
    string sTitulo;
    string sAutor;
    int nPublicacion;
    string sGenero; //genero
    double dPrecio; //precio
    int nPaginas; //paginas
};
// Definicion de la estructura Usuario
struct SUsuario {
    int nUserID;
    string sNombre;
    string sApellido;
    string sEmail;
    int nCelular; // celular
};
// Definicion de la estructura Bibliotecario
struct SBibliotecario {
    int nEmployeeID;
    string sNombre;
    string sApellido;
    string sEmail;
    double dSalario; // salario
};
// Funcion para no repetir titulos de libros
bool tituloRepetido(const string& titulo, const SLibro* libros, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        if (titulo == libros[i].sTitulo) {
            return true; // Si el titulo esta repetido
        }
    }
    return false; // Si el titulo no esta repetido
}
// Funcion para llenar la biblioteca con libros aleatorios
void llenar(SLibro *libros, int cantidad) {
    string listaTitulo[] = {"Programacion I", "Programacion II", "Programacion III", "Aprende Linux", "Aprende php", "Aprende Java", "Calculo I", "Calculo II", "Rebelion en la granja", "La Metamorfosis"};
	string listaAutor[] = {"Jorge Luis", "Gabriel Garcia ", "George Orwell", "Miguel de Cervantes", "J.K. Rowling", "Homero", "Mark Twain", "Antoine de Saint", "George Orwell", "Franz Kafka"};
	string listaGenero[] = {"Ficcion", "Novela", "Codigos", "Clasico", "Fantasia", "Misterio", "Aventura", "Infantil", "Fabula", "Terror"};

    for (int i = 0; i < cantidad; i++) {
        string tituloAleatorio;
        do {
            int indiceTitulo = rand() % 10; //generacion de numero randomico de 0 a 9
            tituloAleatorio = listaTitulo[indiceTitulo];
        } while (tituloRepetido(tituloAleatorio, libros, i)); // Verificar si el titulo esta repetido
        libros[i].nISBN = i + 1;
        libros[i].sTitulo = tituloAleatorio;
        int indiceAutor = rand() % 10;
        int indiceGenero = rand() % 10;
        libros[i].sAutor = listaAutor[indiceAutor];
        libros[i].nPublicacion = rand() % 25 + 1980; // Años entre 1980 y 2024
        libros[i].sGenero = listaGenero[indiceGenero]; // genero de libros
        libros[i].dPrecio = rand() % 300 + 50; // Precios entre 50 y 349
        libros[i].nPaginas = rand() % 500 + 100; // Paginas entre 100 y 599
    }
}
// Funcion para llenar los datos de usuario de manera aleatoria
void llenar(SUsuario *usuarios, int cantidad) {
    string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia"};
    string listaApellidos[] = {"Perez", "Gomez", "Rodriguez", "Martinez", "Lopez", "Gonzalez", "Sanchez", "Fernandez", "Garcia", "Torres"};
    for (int i = 0; i < TAMANO; i++) {
        usuarios[i].nUserID = i + 1;
        int indiceNombre = rand() % 10; //generacion de numero randomico de 0 a 9
        int indiceApellido = rand() % 10;
        usuarios[i].sNombre = listaNombres[indiceNombre];
        usuarios[i].sApellido = listaApellidos[indiceApellido];
        usuarios[i].sEmail = listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com";
        usuarios[i].nCelular = (rand() % 2 + 6) * 10000000 + rand() % 10000000; //numero de celular
    }
}
// Funcion para llenar los datos de bibliotecario de manera aleatoria
void llenar(SBibliotecario *bibliotecarios, int cantidad) {
    string listaNombres[] = {"Santiago", "Belen", "Luz", "Isabel", "Fabian", "Carla", "Sergio", "Gustavo", "Mario", "Melanie"};
    string listaApellidos[] = {"Leon", "Roca", "Justiniano", "Soliz", "Rivero", "Torrico", "Cuellar", "Tantani", "Rivas", "Roque"};
    for (int i = 0; i < TAMANO; i++) {
        bibliotecarios[i].nEmployeeID = i + 1;
        int indiceNombre = rand() % 10; //generacion de numero randomico de 0 a 9
        int indiceApellido = rand() % 10;
        bibliotecarios[i].sNombre = listaNombres[indiceNombre];
        bibliotecarios[i].sApellido = listaApellidos[indiceApellido];
        bibliotecarios[i].sEmail = listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com";
        bibliotecarios[i].dSalario = rand() % 1501 + 1500 ; // salario entre 1500 y 3000
    }
}
// Funcion para mostrar los libros
void mostrar(SLibro *libros, int inicio, int fin) {
    if (inicio < fin) {  //Condicion base
        if (inicio == 0) {
            cout << setw(2) << right << "ISBN" << setw(10) << "Titulo" << setw(24) << "Autor" << setw(24) << "Anio" << setw(13) << "Genero" << setw(15) << "Precio" << setw(10) << "Paginas" << endl;
        }
        cout << left << setw(8) << libros[inicio].nISBN << setw(25) << libros[inicio].sTitulo << setw(25) << libros[inicio].sAutor << setw(11) << libros[inicio].nPublicacion << setw(15) << libros[inicio].sGenero << setw(10) << libros[inicio].dPrecio << setw(10) << libros[inicio].nPaginas << endl;
        mostrar(libros, inicio + 1, fin); //Recursion
    }
}
// Funcion para mostrar los datos de los usuarios
void mostrar(SUsuario *usuarios, int inicio, int fin) {
    if (inicio < fin) { //Condicion base
        if (inicio == 0) {
            cout << setw(5) << right << "User ID" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Celular" << endl;
        }
        cout << left << setw(15) << usuarios[inicio].nUserID << setw(15) << usuarios[inicio].sNombre << setw(15) << usuarios[inicio].sApellido << setw(30) << usuarios[inicio].sEmail << setw(15) << usuarios[inicio].nCelular << endl;
        mostrar(usuarios, inicio + 1, fin); //Recursion
    }
}
// Funcion para mostrar los datos de los bibliotecarios
void mostrar(SBibliotecario *bibliotecarios, int inicio, int fin) {
    if (inicio < fin) { //Condicion base
        if (inicio == 0) {
            cout << setw(5) << right << "Employee ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Salario" << endl;
        }
        cout << left << setw(15) << bibliotecarios[inicio].nEmployeeID << setw(15) << bibliotecarios[inicio].sNombre << setw(15) << bibliotecarios[inicio].sApellido << setw(30) << bibliotecarios[inicio].sEmail << bibliotecarios[inicio].dSalario << "Bs" << endl;
        mostrar(bibliotecarios, inicio + 1, fin); //Recursion
    }
}
// Funcion para convertir una cadena a minusculas
string convertir(const string& cadena) {
    string resultado = cadena;
    for (char& c : resultado) {
        c = tolower(c);
    }
    return resultado;
}
// Funcion recursiva para buscar libros por titulo
void buscar(SLibro *libros, int inicio, int fin, const string& sTitulo) {
    if (inicio < fin) { //Condicion base
        string tituloMinuscula = convertir(libros[inicio].sTitulo);
        string sTituloMinuscula = convertir(sTitulo);
        size_t found = tituloMinuscula.find(sTituloMinuscula);
        if (inicio == 0) {
            cout << setw(2) << right << "ISBN" << setw(10) << "Titulo" << setw(24) << "Autor" << setw(24) << "Anio" << setw(13) << "Genero" << setw(15) << "Precio" << setw(10) << "Paginas" << endl;
        }
        if (found != string::npos) {
        cout << left << setw(8) << libros[inicio].nISBN << setw(25) << libros[inicio].sTitulo << setw(25) << libros[inicio].sAutor << setw(11) << libros[inicio].nPublicacion << setw(15) << libros[inicio].sGenero << setw(10) << libros[inicio].dPrecio << setw(10) << libros[inicio].nPaginas << endl;
        }
        buscar(libros, inicio + 1, fin, sTitulo);
    }
}
// Funcion recursiva para buscar usuarios por nombre, apellido o nombre completo
void buscar(SUsuario *usuarios, int inicio, int fin, const string& busqueda) {
    if (inicio < fin) {  // Condicion base
        //Convertir tanto la cadena de busqueda como los nombres en las estructuras a minusculas antes de comparar
        string nombreMinuscula = convertir(usuarios[inicio].sNombre);
        string apellidoMinuscula = convertir(usuarios[inicio].sApellido);
        string busquedaMinuscula = convertir(busqueda);
        // Si es la primera llamada, imprimir los títulos
        if (inicio == 0) {
            cout << setw(5) << right << "User ID" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Celular" << endl;
        }
        // Verifica si la busqueda coincide con el nombre, apellido o nombre completo
        if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos) {
            // Imprimir los datos del usuario
            cout << left << setw(15) << usuarios[inicio].nUserID << setw(15) << usuarios[inicio].sNombre << setw(15) << usuarios[inicio].sApellido << setw(30) << usuarios[inicio].sEmail << setw(15) << usuarios[inicio].nCelular << endl;
        }
        buscar(usuarios, inicio + 1, fin, busqueda);// Llamada recursiva con el siguiente usuario
    }
}

// Funcion recursiva para buscar bibliotecarios por nombre, apellido o nombre completo
void buscar(SBibliotecario *bibliotecarios, int inicio, int fin, const string& busqueda) {
    if (inicio < fin) {  //Condicion base
       //Convertir tanto la cadena de busqueda como los nombres en las estructuras a minusculas antes de comparar
        string nombreMinuscula = convertir(bibliotecarios[inicio].sNombre);
        string apellidoMinuscula = convertir(bibliotecarios[inicio].sApellido);
        string busquedaMinuscula = convertir(busqueda);

        if (inicio == 0){
            cout << setw(5) << right << "Employee ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Salario" << endl;
        }
        // Verifica si la busqueda coincide con el nombre, apellido o nombre completo
        if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos) {
        cout << left << setw(15) << bibliotecarios[inicio].nEmployeeID << setw(15) << bibliotecarios[inicio].sNombre << setw(15) << bibliotecarios[inicio].sApellido << setw(30) << bibliotecarios[inicio].sEmail << bibliotecarios[inicio].dSalario << "Bs" << endl;
        }
        buscar(bibliotecarios, inicio + 1, fin, busqueda); // Llamada recursiva con el siguiente bibliotecario
    }
}
// Menu para mostrar los listados
void menuListados(SLibro *libros, SUsuario *usuarios, SBibliotecario *bibliotecarios) { 
    int opcionListados;
    do {
        cout << "\nSubmenu de Listados:" << endl;
        cout << "1. Listado de Libros" << endl;
        cout << "2. Listado de Usuarios" << endl;
        cout << "3. Listado de Bibliotecarios" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionListados;

        switch (opcionListados) {
            case 1:
                mostrar(libros, 0, TAMANO);
                break;
            case 2:
                mostrar(usuarios, 0, TAMANO);
                break;
            case 3:
                mostrar(bibliotecarios, 0, TAMANO);
                break;
            case 0:
                cout << "Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionListados != 0);
}
// Menu para realizar busquedas
void menuBusqueda(SLibro *libros, SUsuario *usuarios, SBibliotecario *bibliotecarios) {
    int opcionBusqueda;
    do {
        cout << "\nSubmenu de Busqueda:" << endl;
        cout << "1. Busqueda de Libro" << endl;
        cout << "2. Busqueda de Usuario" << endl;
        cout << "3. Busqueda de Bibliotecario" << endl;
        cout << "0. Volver al Menu Principal" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionBusqueda;

        switch (opcionBusqueda) {
            case 1:
                {
                string titulo;
                cout << "Ingrese el titulo del libro que desea buscar: ";
                cin.ignore();  // Limpia el buffer de entrada antes de leer la entrada del usuario
                getline(cin, titulo);  // Lee la entrada del usuario y almacena el titulo en la variable 'titulo'
                cout << "\nResultados de la busqueda:" << endl;
                buscar(libros, 0, TAMANO, titulo);  // Llama a la función 'buscar' para buscar el libro con el titulo ingresado
                }
                break;
            case 2:
                {
                string sBusqueda;
                cout << "Ingrese el nombre, apellido o nombre completo: ";
                cin.ignore();
                getline(cin, sBusqueda);
                cout << "\nResultados de la busqueda:" << endl;
                buscar(usuarios, 0, TAMANO, sBusqueda);
                }
                break;
            case 3:
                {
                string sBusqueda;
                cout << "Ingrese el nombre, apellido o nombre completo: ";
                cin.ignore();
                getline(cin, sBusqueda);
                cout << "\nResultados de la busqueda:" << endl;
                buscar(bibliotecarios, 0, TAMANO, sBusqueda);
                }
                break;
            case 0:
                cout << "Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    } while (opcionBusqueda != 0);
}
// Menu principal
void menuPrincipal(SLibro *libros, SUsuario *usuarios, SBibliotecario *bibliotecarios) {
    int opcionPrincipal;
    do {
        cout << "\nMenu Principal:" << endl;
        cout << "1. Llenar Datos" << endl;
        cout << "2. Listados" << endl;
        cout << "3. Busqueda" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcionPrincipal;

        switch (opcionPrincipal) {
            case 1:
                llenar(libros, TAMANO);
                llenar(usuarios, TAMANO);
                llenar(bibliotecarios, TAMANO);
                cout << "Datos llenados exitosamente." << endl;
                break;
            case 2:
                menuListados(libros, usuarios, bibliotecarios);
                break;
            case 3:
                menuBusqueda(libros, usuarios, bibliotecarios);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcionPrincipal != 0);
}
int main() {
    srand(time(nullptr));
    SLibro libros[TAMANO]; // array de libros
    SUsuario usuarios[TAMANO]; // array de usuarios
    SBibliotecario bibliotecarios[TAMANO]; //array de bibliotecarios

    menuPrincipal(libros, usuarios, bibliotecarios);
    return 0;
}
