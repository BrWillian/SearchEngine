#include "tabelahash.h"
#include <random>
#include <string>
#include <cstring>

tabelahash::tabelahash()
{
    this->MAX_SIZE = 4096;
    tabela = new std::list<std::pair<documento*, std::string>>[MAX_SIZE];
}
tabelahash::tabelahash(int max_size)
{
    this->MAX_SIZE = max_size;
    tabela = new std::list<std::pair<documento*, std::string>>[MAX_SIZE];
}
int tabelahash::funchash(std::string palavra)
{
    int counter = 0;
    int i = 1;

    std::srand(time(NULL));

    for(char& c: palavra)
    {
        counter += i++ * static_cast<int>(c) + (std::rand() % MAX_SIZE);
    }

    int index = static_cast<int>(counter % MAX_SIZE);

    return index;
}
bool tabelahash::Insere(documento *doc, std::string palavra)
{   
    if(!(n_entradas == MAX_SIZE))
    {
        int index = funchash(palavra);

        tabela[index].push_back(std::make_pair(doc, palavra));
        n_entradas += 1;
        return true;
    }
    return false;
}
std::vector<std::pair<documento*, std::string>> tabelahash::busca(std::string palavra)
{
    int index = funchash(palavra);

    std::vector<std::pair<documento*, std::string>> tmp;

    for(auto it=tabela[index].begin(); it != tabela[index].end(); ++it)
    {
        if(palavra.compare(it->second) == 0)
        {
            tmp.push_back(std::make_pair(it->first, it->second));
        }
    }

    return tmp;
}
