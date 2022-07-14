#include "Allocator.h"


int main()
{
    Allocator *graphical = new Allocator;
    graphical->PoolAlloc ( 2 ); // Cria 2 células de memória na Pool

    graphical->Pool[0].Alloc ( 4 ); // 4 bytes na primeira célula
    *graphical->Pool [ 0 ].base = 3301; //3301 na primera célula

    graphical->Pool [ 1 ].Alloc ( 4 ); // 4 bytes na segunda célula
    *graphical->Pool [ 1 ].base = 1337; //1337 na segunda célula


    graphical->Pool [ 0 ].Free ( ); // Desaloca cada célula individualmente
    graphical->Pool [ 1 ].Free ( );
    graphical->PoolFree ( ); // Desaloca a Pool de células
}

// ** Exemplo de uso **