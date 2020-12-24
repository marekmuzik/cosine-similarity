#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

/*Nahodne vygenerovani desetinneho cisla*/
double randomDouble(){
    //interval <-100,100>
    double min = -100;
    double max = 100;

    //nahodne generovani cisla v intevalu <0,1>
    double random = rand()/(double)RAND_MAX;
    //zvetseni cisla podle podminky intervalu <-100, 100>
    double scale = min + random * (max-min);
    //zaokrouhleni cisla na dve desetinna mista 
    scale = round(scale*100)/100;

    return scale;
}

/*Vytvoreni 2D pole*/
double** pole (int rowM, int columnN){

    //dynamicka alokace
    double** pole = (double **) malloc(rowM * sizeof(double *));
    for (int i = 0; i < rowM; i++){
        pole[i] = (double *) malloc(columnN * sizeof(double));
    }

    //vygenerovani nahodnych desetinnych cisel v poli
    for(int i = 0; i < rowM; i++){
        for(int j = 0; j < columnN; j++){
            pole[i][j] = randomDouble();
        }
    }
    
    //vypsani cisel v poli
    printf("\n%s \n", "2D array: ");
    for ( int i = 0; i < rowM; i++ ) {
        printf("%d => ", i);  
        
        for (int j = 0; j < columnN; j++ ) { 
            printf("%lf, ", pole[i][j]);
        }
        
        printf("\n");
   };
    printf("\n");

   return pole;
}

/*Vytvoreni 1D pole*/
double *desetinnaCisla (int columnN){

    //dynamicka alokace
    double *desetinnaCisla = malloc(columnN * sizeof(double));
    
    //vygenerovani nahodnych desetinnych cisel v poli
    for(int i = 0; i < columnN; i ++){
        desetinnaCisla[i] = randomDouble();
    }
    
    //vypsani cisel v poli
    printf("%s", "1D array: ");
    for(int i = 0; i < columnN; i++){
        printf("%lf, ", desetinnaCisla[i]);
    }
    printf("\n");

    return desetinnaCisla;
}

/*Vytvoreni 1D pole*/
char **barvy(int rowM){

    //dynamicka alokace
    char **barvy = (char**) malloc(rowM * 8 * sizeof(char*));
    
    //pridani barev do pole
    char **nahodneBarvy = (char**) malloc (5 * 8 * sizeof(char*));
    nahodneBarvy[0]="red";
    nahodneBarvy[1]="green";
    nahodneBarvy[2]="blue";
    nahodneBarvy[3]="white";
    nahodneBarvy[4]="black";
    
    //vygenerovani nahodnych barev do pole
    for(int i = 0; i<rowM; i++){
        int randomNumber = rand() % 5;
        barvy[i] = nahodneBarvy[randomNumber];
    }

    //vypsani nahodnych barev
    printf("\n\n%s \n","Colors of the rows:");
    for(int i = 0; i < rowM; i ++){
        printf("%d", i);
        printf(" %s ", "=>");
        printf("%s \n", barvy[i]);
    }
    printf("\n");

    return barvy;
}

/*uvolneni pameti pro 2D pole*/
void freePole(double *pole[], int rowM){
    for (int i = 0; i<rowM;i++){
        free(pole[i]);
    }

    free(pole);
    pole=NULL;
}

/*uvolneni pameti pro 2D pole barev*/
void freeBarvy(char *barvy[]){
    for(int i = 0; i < 5; i++){
        free(barvy[i]);
    }

    free(barvy);
    barvy=NULL;
}

/*uvolneni pameti pro 1D pole desetinnych cisel*/
void freeDesetinnaCisla(double desetinnaCisla[]){
    free(desetinnaCisla);
    desetinnaCisla=NULL;
}

/* funkce pocitajici kosinovou miru podobnosti */
void cosineSimilarity(double *pole [], double desetinnaCisla [], char *barvy [], int rowM, int columnN){

    double nejvyssiHodnota;
    int indexNejvyssiHodnoty = -1;
    double skalarniSoucin;
    double delkaVektoruA;
    double delkaVektoruB;
    double delkaVektoru;
    double cosineSimilarity;

    //vypocet kosinove podobnosti
    for (int i = 0; i < rowM; i++){
        for (int j = 0; j < columnN; j++){
            if(j != columnN-1){//pokud j neni posledni sloupec
                skalarniSoucin+= pole[i][j] * desetinnaCisla[j];
                delkaVektoruA += pole[i][j] * pole[i][j];
                delkaVektoruB += desetinnaCisla[j] * desetinnaCisla[j];
            }
            else{
                skalarniSoucin+= pole[i][j] * (desetinnaCisla[j]);
                delkaVektoruA +=  pole[i][j] * pole[i][j];
                delkaVektoruB += desetinnaCisla[j] * desetinnaCisla[j];
                delkaVektoru = sqrt(delkaVektoruA) * sqrt(delkaVektoruB);
                cosineSimilarity = skalarniSoucin/delkaVektoru;
                if(cosineSimilarity > nejvyssiHodnota || indexNejvyssiHodnoty == -1){//pokud je hodnota kosinove podobnosti vetsi nebo je rovna -1 (pocatecni hodnota)
                    nejvyssiHodnota = cosineSimilarity;
                    indexNejvyssiHodnoty = i;
                }
                //nulovani promennych pro uziti v dalsim radku
                skalarniSoucin = 0;
                delkaVektoruA = 0;
                delkaVektoruB = 0;
                delkaVektoruB = 0;
                cosineSimilarity = 0;
            }
        }
    }

    //vypis radku s nejvetsi kosinovou podobnosti
    printf("%s ", "Color of the row with highest cosine similarity is:");
    printf("%s ", barvy[indexNejvyssiHodnoty]);
    printf("\n\n");

    //volani funkci pro uvolneni pameti
    freePole(pole, rowM);
    freeBarvy(barvy);
    freeDesetinnaCisla(desetinnaCisla);
}

int main(){
    int rowM; //pocet radku
    int columnN; //pocet sloupcu

    //deklarace a inicializace promene casu
    int now = (int) time(NULL);
    srand(now);

    // prompt k zadani poctu radku M
    printf("How many elements in rows M do you need?\n");
    scanf("%d", &rowM);

    //prompt k zadani poctu sloupcu N
    printf("How many elements in columns N do you need?\n");
    scanf("%d", &columnN);

    //zavolani funkce pro vypocet kosinove podobnosti s parametry: 2D pole destinnych cisel, 1D pole desetinnych cisel, 2D pole barev, pocet radku a pocet sloupcu 
    cosineSimilarity(pole(rowM, columnN),desetinnaCisla(columnN),barvy(rowM),rowM, columnN);
    return 0;

}
