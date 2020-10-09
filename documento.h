#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <vector>
#include <string>

using namespace std;

class documento
{
private:
    int id_doc;
    vector<pair<int, string>>palavras;

public:
    void ler_documento(string caminho);
    documento();
};

#endif // DOCUMENTO_H
