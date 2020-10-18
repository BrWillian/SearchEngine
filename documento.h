#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <vector>
#include <string>
#include <iostream>

class documento
{
private:
    std::vector<std::pair<std::string, int>>conjunto_palavra;
    std::string nome_documento;
    void ler_documento();
public:
    std::string getNome();
    bool busca_palavra(std::string palavra, int *pos);
    std::vector<std::string>palavras();
    documento(std::string caminho);
    void get_ocorrencia(std::string palavra);
};

#endif // DOCUMENTO_H
