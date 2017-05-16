#include <cstdlib>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int encrypt(char buf[]),decrypt(),var=0,temp[20],var2=0,cant =1,maxl=25,maxcant=8,vp=0,cct=0;
long int timee=0;
char letras[128]="abcdefghijklmnopqrstuvwyz",cad[20] = "a";//8 letras

int main(int argc, char *argv[])
{
    for(int i=0;i<20;i++){
            temp[i]=0;        
    }
    char test[128];
    cout<<"***********************************************"<<endl;
    cout<<"Crackeador de contraseñas creado por Lichi :P"<<endl;
    cout<<"***********************************************"<<endl;
    system("PAUSE");system("cls");
    cout<<"***********************************************"<<endl;
    cout<<"Ingrese palabra a encriptar.."<<endl;
    cout<<"***********************************************"<<endl;
    cin.getline(test,128);system("cls");
    cout<<"***********************************************"<<endl;
    cout<<"Palabra encriptada: "<<encrypt(test)<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<"Ingrese el numero encriptado.."<<endl;
    cout<<"***********************************************"<<endl;
    cin>>var;system("cls");
    cout<<"***********************************************"<<endl;
    cout<<"¿Usar cout? 1-si, 0-no (se trabaja mas rapido sin cout)"<<endl;
    cout<<"***********************************************"<<endl;
    cin>>var2;system("cls");
    cout<<"***********************************************"<<endl;
    cout<<"Ingrese cantidad maxima de caracteres a probar.."<<endl;
    cout<<"***********************************************"<<endl;
    cin>>maxcant;system("cls");
    cout<<"***********************************************"<<endl;
    cout<<"Seleccione el tipo de crackeo"<<endl;
    cout<<"1- Letras minusculas"<<endl;
    cout<<"2- Letras minusculas y numeros"<<endl;
    cout<<"3- Letras mayusculas"<<endl;
    cout<<"4- Letras mayusculas y numeros"<<endl;
    cout<<"5- Letras mayusculas, minusculas y numeros"<<endl;
    cout<<"6- Letras minusculas y mayusculas"<<endl;
    cout<<"7- Solo numeros"<<endl;
    cout<<"8- Ingresar caracteres manualmente"<<endl;
    cout<<"***********************************************"<<endl;
    cin>>vp;system("cls");
    
    if(vp==1)strcpy(letras,"abcdefghijklmopqrstuvwxyz");
    if(vp==2)strcpy(letras,"abcdefghijklmopqrstuvwxyz1234567890");
    if(vp==3)strcpy(letras,"ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if(vp==4)strcpy(letras,"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    if(vp==5)strcpy(letras,"abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    if(vp==6)strcpy(letras,"abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if(vp==7)strcpy(letras,"1234567890");
    if(vp==8){
              system("cls");
              cout<<"***********************************************"<<endl;
              cout<<"Escriba los caracteres sin espacios"<<endl;
              cout<<"***********************************************"<<endl;
              cin.getline(letras,128);
              
    }
    maxl=strlen(letras);
    timee=GetTickCount()/1000;
    system("cls");
    cout<<"Comenzando crackeo.."<<endl;
    decrypt();
    system("PAUSE");
    return EXIT_SUCCESS;
}

int decrypt(){
     while(1){
         for(int i=0;i<cant;i++){
            cad[i]=letras[temp[i]];     
         } 
         cct++;
         if(var2==1)cout<<cad<<endl;
         if(var==encrypt(cad)){
             system("cls");
             timee=GetTickCount()/1000-timee;
             //timee/=6;
             cout<<"***********************************************"<<endl;
             cout<<"Palabra desencriptada: "<<cad<<" (probadas "<<cct<<" contraseñas en "<<timee<<" segundos)"<<endl;
             cout<<"***********************************************"<<endl;
             return 1;
         }
         temp[0]++;
         if(temp[0]==maxl){
             for(int i=0;i<cant;i++){
                 if(temp[i]>=maxl&&i+1<cant){
                     temp[i+1]++;
                     cad[i]=letras[temp[i]];
                     temp[i]=0;
                 }
             }
             temp[0]=0;
         }
         if(temp[cant-1]==maxl-1){
                if(cant==maxcant){
                      system("cls");
                      timee=GetTickCount()/1000-timee;
                      cout<<"***********************************************"<<endl;
                      cout<<"No se logro desencriptar la palabra :("<<endl;
                      cout<<"Se probaron "<<cct<< "contraseñas en "<<timee<<" segundos."<<endl;
                      cout<<"***********************************************"<<endl;
                      return 1;
                }
                cout<<"No se obtubieron resultados con "<<cant<<" caracteres.."<<endl;
                for(int i=0;i<20;i++){
                temp[i]=0;        
                }
                cant++;
                cout<<"Probando con "<<cant<<" caracteres.."<<endl;                                         
         }
     }
}

int encrypt(char buf[])
{
    int length=strlen(buf),s1 = 1,s2 = 0,n;
    for (n=0; n<length; n++){
        s1 = (s1 + buf[n]) % 65521;
        s2 = (s2 + s1)     % 65521;
    }
    return (s2 << 16) + s1;
}
