#include<iostream>
#include<string>
#include<regex>
#include<cstdlib>
#include<ctime>

using namespace std;

string filtrarCaracteres(string asciiCode, regex patron){
    string passFilter = "";
    smatch coincidencias;
    while (regex_search(asciiCode, coincidencias, patron))
    {
        passFilter+=coincidencias.str();
        asciiCode = coincidencias.suffix().str();
    }

    return passFilter;
    
}

string randomCaracteres(string cadenas){
    int random;
    string cadenaAleatoria;
    for (int i = 0; i < cadenas.size(); i++)
    {
        random = rand()%cadenas.size();
        cadenaAleatoria+=cadenas[random];
    }
    return cadenaAleatoria;
    
}

string mayusculas(string asciiCode, int size)
{   
    string Solomayusculas = "";
    string mayusculas = "";
    regex patronMayusculas("[A-Z]"); 
    int random;

    Solomayusculas = filtrarCaracteres(asciiCode, patronMayusculas);
    mayusculas = randomCaracteres(Solomayusculas);
     
    return mayusculas.substr(0,size);
    
}

string minusculas(string asciiCode, int size)
{
    string soloMinusculas = "";
    string minusculas = "";
    regex patronMinusculas("[a-z]");

    soloMinusculas = filtrarCaracteres(asciiCode, patronMinusculas);
    minusculas = randomCaracteres(soloMinusculas);    
    return minusculas.substr(0,size);
}

string numeros(string asciiCode, int size)
{

    string soloNumeros = "";
    string numeros = "";    
    regex patronNumeros ("[0-9]");

    soloNumeros = filtrarCaracteres(asciiCode, patronNumeros);
    numeros = randomCaracteres(soloNumeros);
    return numeros.substr(0, size);
}

string simbolos(string asciiCode, int size)
{   
    string soloSimbolos = "";
    string simbolos = "";
    regex patronSimbolos("\\W");

    soloSimbolos = filtrarCaracteres(asciiCode, patronSimbolos);
    simbolos = randomCaracteres(soloSimbolos);
    return simbolos.substr(0,size);
}
string campechana(string asciiCode, int size)
{
    string campechana = "";
    campechana = randomCaracteres(asciiCode);

    return campechana.substr(0,size);
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int opcion;
    string password;
    string ascciCode;
    int size;
    cout << "\t\nGENERADOR DE CONTRASENIAS" << endl;        
    cout << "\t1.Mayusculas" << endl; 
    cout << "\t2.Minusculas" << endl;        
    cout << "\t3.Numeros" << endl;        
    cout << "\t4.Simbolos" << endl;        
    cout << "\t5.Campechana" << endl;        
    cout << "\t\nEscoge una opcion: "; cin >> opcion;

    for (int i = 33; i < 126; i++)
    {
        ascciCode += static_cast<char>(i);
    }
    // cout << ascciCode;
    


    switch (opcion)
    {
    case 1:
        cout << "\tEscoge la longitud de tu contrasenia: ";cin >> size;
        cout << "Tu contrasenia es: " << endl;
        password = mayusculas(ascciCode, size);
        cout <<password<< endl;
        break;
    case 2:

        cout << "\tEscoge la longitud de tu contrasenia: ";cin >> size;
        cout << "Tu contrasenia es: " << endl;
        password = minusculas(ascciCode, size);
        cout <<password<< endl;
        break;
    case 3:

        cout << "\tEscoge la longitud de tu contrasenia: ";cin >> size;
        cout << "Tu contrasenia es: " << endl;
        password = numeros(ascciCode, size);
        cout <<password<< endl;
        break;
    case 4:

        cout << "\tEscoge la longitud de tu contrasenia: ";cin >> size;
        cout << "Tu contrasenia es: " << endl;
        password = simbolos(ascciCode, size);
        cout <<password<< endl;
        break;
    case 5:

        cout << "\tEscoge la longitud de tu contrasenia: ";cin >> size;
        cout << "Tu contrasenia es: " << endl;
        password = campechana(ascciCode, size);
        cout <<password<< endl;
        break;
    default:
        cout << "Opcion no valida !!" << endl;
        break;
    
    }


    return 0;
}
