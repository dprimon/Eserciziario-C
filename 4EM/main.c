#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Viaggi{
    char dst[21];
    char dt[11];
    int mtr;
    char tp;
};

struct Viaggi vgg[100];
char lct[21];
FILE *pvgg;
int nv;

void chilometrieffettuati();
void data();
void costototale();
void caricafile();

int main(){
    pvgg=fopen("Viaggi.txt","w");
    if(pvgg==NULL)
        printf("\n Il file Viaggi.txt non pu� essere aperto\n");
    else
        caricafile();
    fclose(pvgg);
    pvgg=fopen("Viaggi.txt","r");
    printf("\n Inserire la destinazione di cui si vuole sapere le informazioni\n");
    scanf("%s", lct);
    chilometrieffettuati();
    fclose(pvgg);
}

void caricafile(){
    int ff=1;
    char destinazione[21];
    char data[11];
    int metri;
    char tp;
    while(ff==1){
        printf("\n inserire destinazione\n");
        scanf("%s", destinazione);
        printf("\n inserire data del formato GG/MM/AAAA\n");
        scanf("%s", data);
        printf("\n inserire la distanza in metri\n");
        scanf("%d",&metri);
        printf("\n inserire il tipo di viaggio R per ritorno e A per andata\n");
        scanf("%c",&tp);
        fprintf(pvgg,"%s %s %d %c\n",destinazione, data, metri, tp);
        printf("\n Inserire 1 per continuare 2 per terminare\n");
        scanf("%d",&ff);
    }
}

void chilometrieffettuati(){
    nv=0;
    float klm=0;
    while(fscanf(pvgg,"%s %s %d &c", vgg[nv].dst,vgg[nv].dt,&vgg[nv].mtr,&vgg[nv].tp)!=EOF)
        nv++;
    int i;
    i=0;
    while(i<nv){
        if((vgg[i].tp='A')&&(strcmp(vgg[i].dst,lct)==0))
            klm=klm+vgg[i].mtr;
        i++;
    }
    klm=klm/1000;
    printf("\n I kilometri effettuati verso la localit� sono %.2f",klm);
}

void data(){
   char max[21]="fd";
   int i=0;
   //max="fd";
   while(i<nv){
       if((strcmp(vgg[i].dst,lct)==0)&&(strcmp(max,vgg[i].dt)==-1))
            strcpy(max,vgg[i].dt);
       i++;
   }
   printf("\n la data dell'ultimo viaggio verso la localt� selezionata � %s",max);
}

void costototale(){
    int i;
    float costotot=0;
    while(i<nv){
        costotot=costotot+5+0.1*(vgg[i].mtr/1000);
        i++;
    }
    printf("\n il costo totale dei viaggi � %f",costotot);
}
