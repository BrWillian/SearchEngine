#ifndef TABELAHASH_H
#define TABELAHASH_H
#include <documento.h>
#include <list>


class tabelahash
{
public:
    tabelahash();
    tabelahash(int max_size);

    bool TabelaCheia();
    bool Insere(documento *doc, std::string palavra);
    std::vector<std::pair<documento*, std::string>> busca(std::string palavra);
    int funchash(std::string palavra);

private:
    std::list<std::pair<documento*, std::string>> *tabela;
    unsigned int n_entradas = 0;
    int MAX_SIZE;


};

#endif // TABELAHASH_H
