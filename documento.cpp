#include "documento.h"
#include <fstream>
#include <string>

documento::documento(std::string caminho)
{
    nome_documento = caminho;

    this->ler_documento();
}
std::string documento::getNome()
{
    return nome_documento;
}
void documento::ler_documento()
{
    std::fstream arquivo;
    std::string palavra;
    int t;
    arquivo.open(nome_documento);
    if(arquivo.is_open())
    {
        while(arquivo >> palavra)
        {
            std::string palavratmp = "";
            if(!(isdigit(palavra[0])))
            {
                for(auto& c: palavra)
                {
                    c = std::tolower(c);
                    if (!(ispunct(c) && c != '-'))
                    {
                        palavratmp += c;
                    }
                }
                if(palavratmp.length() > 2)
                {
                    if(busca_palavra(palavratmp, &t))
                    {
                        conjunto_palavra[t].second += 1;
                        continue;
                    }
                    conjunto_palavra.push_back(std::make_pair(palavratmp, 1));
                }
            }
        }
    }
}
bool documento::busca_palavra(std::string palavra, int *pos)
{
    for(auto it = conjunto_palavra.begin(); it!=conjunto_palavra.end(); it++ ){
        if(it->first == palavra)
        {
            *pos = it - conjunto_palavra.begin();
            return true;
        }
    }
    return false;
}
std::vector<std::string> documento::palavras()
{
    std::vector<std::string> tmp;

    for(const auto& p: conjunto_palavra)
    {
        tmp.push_back(p.first);
    }
    return tmp;
}
void documento::get_ocorrencia(std::string palavra)
{
    for(auto it = conjunto_palavra.begin(); it!=conjunto_palavra.end(); it++ ){
        if(it->first == palavra)
        {
            std::cout<<it->first<<" ocorreu: "<<it->second<<" vezes."<<std::endl;
        }
    }
}
