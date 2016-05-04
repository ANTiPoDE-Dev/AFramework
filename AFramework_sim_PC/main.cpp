#include <iostream>

#include "ACore.h"
#include "AString.h"

using namespace std;
using namespace AFramework;

ostream & operator<<(ostream & out, const AString & str){

    for(uint32 i = 0; i < str.size(); i++){
        out << str[i];
    }
    return out;
}

int main()
{
    System::init(1500);
    {
    AString p = "giuseppe/salvo/danilo/piergiovanni";
    AStringList * v = p.split('/');

    if(p.good()){

        while(v->hasNext()){

            cout << v->next() << endl;
        }
    }else{

        switch (p.lastError()){
            case AError::NoMemory:
                cout << "NoMemory" << endl;
                break;
            case AError::OutOfRange:
                cout << "OutOfRange" << endl;
                break;
            default:
                cout << "Unknown" << endl;
                break;
            }
        }
    }
    System::kill();
    return 0;
}
