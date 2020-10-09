#include <iostream>
#include <string>
#include <documento.h>

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
    cin>>text;

    cout<<text<<endl;

    documento *obj = new documento;

    obj->ler_documento("entrada.txt");


}
