#include <iostream>
#include <string>
#include <documento.h>
#include <sstream>
#include <fstream>
#include <list>
#include <tabelahash.h>

#ifdef _WIN32
    #include <windows.h>

    void gotoxy( int x, int y )
    {
        COORD p = { x, y };
        SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
    }
#else
    #define gotoxy(x,y) cout<<"\033["<<y<<";"<<x<<"H";
#endif

using namespace std;

int main()
{

    string text;

    cout<<R"(                .88888.                             dP
               d8'   `88                            88
               88        .d8888b. .d8888b. .d8888b. 88 .d8888b.
               88   YP88 88'  `88 88'  `88 88'  `88 88 88ooood8
               Y8.   .88 88.  .88 88.  .88 88.  .88 88 88.  ...
                `88888'  `88888P' `88888P' `8888P88 dP `88888P'
                                                .88
                                            d8888P
)"<<endl;

    cout<<"                 +-----------------------------+ +----------+"<<endl;
    cout<<"                 |                             | |  Search  |"<<endl;
    cout<<"                 +-----------------------------+ +----------+"<<endl;


    gotoxy(20, 11);

    string t;
    vector<string> words;
    getline(cin,t);

    istringstream iss(t);
    string word;
    while(iss >> word) {
        words.push_back(word);
    }



    vector<documento*> *documentos = new vector<documento*>;

    std::fstream arquivo;
    string n;
    arquivo.open("entrada.txt");
    if(arquivo.is_open())
    {
        while(arquivo >> n)
        {
            if(n.length() > 1)
            {
                documento *obj = new documento(n);
                documentos->push_back(obj);
            }
        }
    }

    tabelahash *hash = new tabelahash;

    for(auto it=documentos->begin(); it!=documentos->end(); ++it)
    {
        for(const auto& p: (*it)->palavras())
        {
            hash->Insere((*it), p);
        }
    }

    gotoxy(0,20);

    cout << "\033[2J\033[1;1H";
    std::vector<std::vector<std::pair<documento*, std::string>>> resultado;

    for(auto &p: words)
    {
        resultado.push_back(hash->busca(p));
    }

    int npos = 0;

    for(auto it=resultado.begin(); it!=resultado.end(); ++it)
    {
        for(auto it2=it->begin(); it2!=it->end(); ++it2)
        {
            npos += 1;
            std::cout<<npos<<". "<<it2->first->getNome()<<std::endl;
            it2->first->get_ocorrencia(it2->second);
            std::cout<<"-----------------------"<<std::endl;
        }
    }
}
