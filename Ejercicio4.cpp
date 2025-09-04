#include <iostream>
#include <string>
using namespace std;

// Estructura para almacenar datos del libro
struct Libro
{
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

// Solicitar datos del libro
Libro SolicitarDatos()
{
    Libro libro;

    cout << "\n======= REGISTRAR LIBRO =======\n";
    cout << "Ingrese el titulo del libro: ";
    getline(cin, libro.titulo);

    cout << "Ingrese el autor del libro: ";
    getline(cin, libro.autor);

    cout << "Ingrese el anio de publicacion: ";
    cin >> libro.anio;
    cin.ignore();

    //Al momento de registrar, el libro esta disponible
    libro.disponible = true;
    return libro;
}

// Funcion para mostrar todos los libros
void MostrarLibros(const Libro libros[], int cantidad)
{
    cout << "\n======= TODOS LOS LIBROS =======\n";
    for (int i = 0; i < cantidad; i++)
    {
        cout << "\nTitulo: " << libros[i].titulo
            << "\nAutor: " << libros[i].autor
            << "\nAnio: " << libros[i].anio
            << "\nEstado: " << (libros[i].disponible ? "Disponible" : "Prestado")
            << "\n----------------------------------\n";
    }
}

// Funcion para mostrar solo los disponibles
void MostrarDisponibles(const Libro libros[], int cantidad)
{
    cout << "\n======= LIBROS DISPONIBLES =======\n";
    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].disponible)
        {
            cout << "\nTitulo: " << libros[i].titulo
                << "\nAutor: " << libros[i].autor
                << "\nAnio: " << libros[i].anio
                << "\n----------------------------------\n";
        }
    }
}

// Funcion para prestar libro
void PrestarLibro(Libro libros[], int cantidad, string titulo)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (libros[i].titulo == titulo)
        {
            if (libros[i].disponible)
            {
                libros[i].disponible = false;
                cout << "El libro \"" << titulo << "\" ha sido prestado exitosamente.\n";
            }
            else
            {
                cout << "El libro \"" << titulo << "\" ya esta prestado.\n";
            }
            return;
        }
    }
    cout << "No se encontro el libro con ese titulo.\n";
}

int main()
{
    Libro libros[10]; //Se define el maximo del arreglo, 10 libros
    int cantidad = 0;
    int opcion;
    bool continuar = true;

    do
    {
        cout << "\n--- MENU BIBLIOTECA ---\n";
        cout << "1. Registrar libro\n";
        cout << "2. Mostrar todos los libros\n";
        cout << "3. Mostrar libros disponibles\n";
        cout << "4. Prestar libro\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            if (cantidad < 10)
            {
                libros[cantidad] = SolicitarDatos();
                cantidad++;
            }
            else
            {
                cout << "Maxima cantidad de libros almacenada.\n";
            }
            break;
        case 2:
            MostrarLibros(libros, cantidad);
            break;
        case 3:
            MostrarDisponibles(libros, cantidad);
            break;
        case 4:
        {
            string titulo;
            cout << "Ingrese el titulo del libro a prestar: ";
            getline(cin, titulo);
            PrestarLibro(libros, cantidad, titulo);
            break;
        }
        case 5:
            continuar = false;
            cout << "Nos vemos.\n";
            break;
        default:
            cout << "Ingrese una opcion valida :D.\n";
        }

    } while (continuar);

    return 0;
}
