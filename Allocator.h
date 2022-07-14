#pragma once

class Allocator {
public:
    struct Cell {
        bool reserved = false;
        size_t size;
        unsigned int* base;
        bool Alloc ( const size_t szData );
        bool Free ( );
    };

    bool PoolAlloc ( const size_t szPages = 1 );
    bool PoolFree ( );
    Allocator::Cell* Pool;
};


bool Allocator::PoolAlloc ( const size_t szPages ) {

    if ( !szPages ) return 0;

    const size_t szPool = sizeof ( Allocator::Cell );

    this->Pool = ( Allocator::Cell* )new char [ szPool * szPages ];

    return this->Pool ? true : false;
}

bool Allocator::Cell::Alloc ( const size_t szData ) {
    if ( !szData ) return 0;
    this->reserved = true;
    this->size = szData;
    this->base = ( unsigned int* )new char [ szData ];
    return true;
}

bool Allocator::PoolFree ( ) {
    delete this->Pool;
    return true;
}

bool Allocator::Cell::Free ( ) {
    delete this->base;
    return true;
}
