/*PREMESSA.
Una pagina WEB è un file di testo (UTF-8 o ISO8859) contenente dei “tag”. I “tag” sono sequenze
di caratteri compresi fra il carattere ‘<’ ed il carattere ‘>’, essi compresi.
Scrivere un programma htmltotxt che prende una pagina WEB e produce il file di testo
costituito dalla pagina WEB senza i tag.
Il programma dovrebbe essere mandato in esecuzione come un comando del sistema operativo,
prendendo al primo argomento la pagina WEB e a secondo argomento il file di testo da produrre.
Ad esempio, si consideri il file HTML in figura, denominato provahtml.
Il comando
htmltotxt provahtml provatesto
applicato al seguente file provahtml
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
char caratt;
bool flag=true;
fstream input,output;
input.open("provahtml.txt",ios::in);
output.open("htmltotxt.txt",ios::out);
while(input.get(caratt)){
    if(caratt=='<')flag=false;
    if(caratt=='>')flag=true;
    if(flag==true&&caratt!='>'){
        output<<caratt;
    }
}
    return 0;
}

