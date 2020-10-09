#include "documento.h"
#include <iostream>
#include <fstream>

documento::documento()
{

}
void documento::ler_documento(string caminho)
{
    ifstream arquivo;
    try{
        arquivo.open(caminho);
        if(arquivo.is_open())
        {
            string strtmp;
            string palavra = "";
            vector<string>str;
            while(!arquivo.eof())
            {
               getline(arquivo, strtmp);

               for(int i=0; i<strtmp.length(); i++)
               {
                   if(strtmp[i] != ' ')
                   {
                       palavra += strtmp[i];
                       //cout<<palavra<<endl;
                   }else
                   {
                       str.push_back(palavra);
                       palavra = "";
                   }
               }
            }

            for(auto it = str.begin(); it != str.end(); ++it)
            {
                cout<<*it<<endl;
            }

        }else
        {
            throw "Erro ao abrir o arquivo!";
        }
    }catch (const char* error)
    {
        cerr << error << '\n' ;
    }
}
