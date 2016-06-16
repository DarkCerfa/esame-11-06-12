#include <iostream>
#include <fstream>
using namespace std;
struct occorrenza{
int num;
char parola[50];
occorrenza* succ;
}a;
typedef occorrenza* lista;
bool estrazione_ordinato(lista&,occorrenza&);
void inserisci_ordinato(lista&,occorrenza&);
bool div(char [],char[]);
void Stampa_lista(lista&);
int main(){
lista inizio=0;
char nomefile[20];
cout<<"inserisci il nome di input"<<endl;
cin>>nomefile;
fstream input;
input.open(nomefile,ios::in);
while(input.good()){
    input>>a.parola;//mi carico parola per parola dal file
   if(estrazione_ordinato(inizio,a))// con questo comando mi controllo se il file esiste estraendolo dalla lista
   {
       a.num++;//
       inserisci_ordinato(inizio,a);// se esiste aumenta il numero di occorrenza(a.num++)e reinserisce la parola
   }
   else{
    a.num=1;//se non esiste inserisce 1 come occorrenza e
    inserisci_ordinato(inizio,a);//inserisce la parola nella lista
   }
}
input.close();
Stampa_lista(inizio);//stampa la lista
return 0;
}

void inserisci_ordinato(lista& p0,occorrenza& a){
lista p = 0, q, r;
for (q=p0; q!=0 && q->num > a.num; q = q->succ)//la lista va ordinata in ordine decrescente
 p = q;
r = new occorrenza;
*r=a;
r->succ = q;
// controlla se si deve inserire in testa
if (q == p0) p0 = r;
 else p->succ= r;
}

bool estrazione_ordinato(lista& p0,occorrenza& a){
lista p, q;
for (q = p0; q!=0 && div(q->parola,a.parola); q=q->succ)
 p = q;
if (q == 0) return false;
if (q == p0) p0 = q->succ;
 else p->succ = q->succ;
a = *q;
delete q;
return true;
}

bool div (char vet1[],char vet2[]){//questa funzione controlla se la parola è diversa scorrendo il due vettori di parole con un ciclo while
int i=0;
while((vet1[i]!='\0')&&(vet2[i]!='\0')&&(vet1[i]==vet2[i]))//queste tre condizioni controllano se la lettera non è \0 oppure le lettere sono uguali controllando cosi la diversità delle parole
    i++;
if ((vet1[i]=='\0')&&(vet2[i]=='\0'))return false;//se le parole sono uguali ritorna false
else return true;//altrimenti ritorna True
}

void Stampa_lista(lista&p0){
lista p=p0;
while(p!='\0'){
    cout<<p->num<<" "<<p->parola<<endl;
    p=p->succ;
}
}
