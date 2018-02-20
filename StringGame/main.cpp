#include <iostream>

using namespace std;

char * recursivef(char *s){
    bool kontrol = false;
    int i=0;
    char c = s[i];
    if(c=='\0'){ //end of string kontrolü
        cout << "Bos kume.";
        return s;
    }
    while(c!='\0'){
        char c1=s[i+1];
        if(c==c1&&i==0){
            s=&s[i+2]; //s'in yeni point ettiği adres
            kontrol = true;
        }
        else if(c==c1){
            kontrol = true;
            while(s[i]!='\0'){
                s[i]=s[i+2];
                i++;
            }
            s[i]='\0'; //döngüden çıktıktan sonra end of string ataması gerçekleştirmemiz gerekiyor.
        }
        i++;
        c=s[i];
    }
    if(kontrol==false){
        cout << "Sonuc: ";
        return s;
    }
    else
        return recursivef(s);
}

int main(int argc, char **argv)
{
    char c[100];
    cout << "Lutfen bir string giriniz (Orn: abbcddae): ";
    cin >> c;
    cout << recursivef(c) << endl;
}
