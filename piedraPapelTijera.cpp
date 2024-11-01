#include<iostream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>

using namespace std;

class Tittle{
    private:
    int option;
    int count = 0;

    public:
    int menu(){
        do
        {
            cout << "\t\tJUEGO DE PIEDRA, PAPEL o TIJERA\n" << endl;
            cout << "\t\t1.Jugador vs Pc" << endl;
            cout << "\t\t2.Jugador vs Jugador" << endl;
            cout << "\t\t3. Salir" << endl;
            cout << "\t\nEscoge una opcion: ";cin >> option;
            count ++;
            
        } while (option < 1 || option > 3);

        if (option == 3 && count  == 1) cout << "\n\tJUEGO TERMINADO!!" << endl;

        return option;
    }
};

class Game{
    private:
    Tittle option;
    int op;    
    int gameOp;
    int value;
    public:

    int gameMenu(){
        do
        {
        cout << "\n\t1. PIEDRA" << endl;
        cout << "\t2. PAPEL" << endl;
        cout << "\t3. TIJERA\n" << endl;
        cout << "\t\tEscoge una opcion: ";cin >> gameOp;
        } while (op < 1 || op > 3);
        if (gameOp == 1)
        {
            cout << "\nEscogiste piedra!!" << endl;
        }
        else if(gameOp == 2)
        {
            cout << "\nEscogiste papel!!" << endl;
        }

        else
        {
            cout << "\nEscogiste Tijeras!!" << endl;
        }
        
        
        
        return gameOp;
    }

    int playerVsPc(){
        srand(time(NULL));
        cout << "\n\tPC pensando..." << endl;
        cout.flush();
        sleep(2);
        value = rand()%3+1;
        if (value == 1)
        {
            cout << "Pc tiro PIEDRA";
        }
        else if (value == 2)
        {
            cout << "Pc tiro PAPEL";
        }
        else
        {
            cout << "Pc tiro TIJERAS";
        }
        return value;
    }

    void winner(){

        int player = gameMenu();
        int pc = playerVsPc();
//loses jugador
        if ((player == 1 && pc == 2) || (player == 2 && pc == 3)||(player == 3 && pc == 1))
        {
            cout << "\t\nGano la pc!!";
        }
        else if ((player == 1 && pc == 3) || (player == 2 && pc == 1) || (player == 3 && pc ==2))
        {
            cout << "\t\nGano el jugador!!";
        }
        else if ((player == 1 && pc == 1) || (player == 2 && pc == 2))
        {
            cout << "\nEmpate!!" << endl;
        }
        else
        {
            cout << "\nEmpate" << endl;
        }
        
        
         

    }


    void loop(){
        op = option.menu();
        int n;
        int m;
        switch (op)
        {
        case 1:
            cout << "JUGADOR VS PC" << endl;
                  winner();
            break;
        
        default:
            break;
        }
    }

};

class StartGame{
    public:
        Game init;
    void init2(){
        init.loop();
    }
};

int main(int argc, char const *argv[])
{

    StartGame gameU;
    gameU.init2();
    
    return 0;
}
