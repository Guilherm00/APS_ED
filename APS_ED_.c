#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else
void getch() { getchar(); }
#endif

#define TAM 30
int run = 10;

int vo[TAM];
int vcr[TAM];
int vdc[TAM];
int vq[TAM];
int vb[TAM];
int vs[TAM];
int arr[TAM];

double tmq = 0;
double tmb = 0;
double tms = 0;

void printV(int* v) {
    for(int i = 0; i < TAM; i++) {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void clonaV(int* origem, int* destino) {
    for (int i = 0; i < TAM; i++) {
        destino[i] = origem[i];
    }
}

void QuickSort(int *v, int tamanho) {
    if(tamanho <= 1) {
        return;
    } else {
        int x = v[0];
        int a = 1;
        int b = tamanho - 1;

        do {
            while((a < tamanho) && (v[a] <= x)) {
                a++;
            }
            while(v[b] > x) {
                b--;
            }
            if(a < b) { 
                int temp = v[a];
                v[a] = v[b];
                v[b] = temp;
                a++;
                b--;
            }
        } while(a <= b);

        v[0] = v[b];
        v[b] = x;

        QuickSort(v, b);
        QuickSort(&v[a], tamanho - a);
    }
}

void SelectionSort(int* v, int tamanho) {
    int i, j, min;
    for (i = 0; i < (tamanho - 1); i++) {
        min = i;
        for(j = (i + 1); j < tamanho; j++) {
            if (v[j] < v[min]) {
                min = j;
            }
        }
        if (i != min) {
            int swap = v[i];
            v[i] = v[min];
            v[min] = swap;
        }
    }
}

void BubbleSort(int* v, int tamanho) {
    int i;
    int trocou;
    int limite = tamanho;
    do {
        limite--;
        trocou = 0;
        for(i = 0; i < limite; i++) {
            if(v[i] > v[i+1]) {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                trocou = 1;
            }
        }
    } while (trocou);
}

void selectionSortDecrescenteAux(int* v) {
    clonaV(v, arr);
    for(int i = 0; i < TAM - 1; i++) {
        int indiceMaior = i;
        for(int j = i + 1; j < TAM; j++) {
            if(arr[j] > arr[indiceMaior]) {
                indiceMaior = j;
            }
        }
        if(indiceMaior != i) {
            int temp = arr[i];
            arr[i] = arr[indiceMaior];
            arr[indiceMaior] = temp;
        }
    }
    clonaV(arr, vdc);
}

void selectionSortCrescenteAux(int* v) {
    clonaV(v, arr);
    for(int i = 0; i < TAM - 1; i++) {
        int indiceMenor = i;
        for(int j = i + 1; j < TAM; j++) {
            if(arr[j] < arr[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if(indiceMenor != i) {
            int temp = arr[i];
            arr[i] = arr[indiceMenor];
            arr[indiceMenor] = temp;
        }
    }
    clonaV(arr, vcr);
}

void resultPrint(char* label, double tcr, double tdc, double tvo) {
    printf("========================================\n");
    printf("%s: \n", label);
    printf("========================================\n");
    printf("Media Vetor Crescente: %.4f ms\n", (tcr / run));
    printf("Media Vetor Decrescente: %.4f ms\n", (tdc / run));
    printf("Media Vetor Aleatorio: %.4f ms\n", (tvo / run));
    printf("-----------------------------------\n\n");
}

void runBubbleSort() {
    clock_t t;
    
    double tcr = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vcr, vb);
        t = clock();
        BubbleSort(vb, TAM);
        tcr += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }
    
    double tdc = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vdc, vb);
        t = clock();
        BubbleSort(vb, TAM);
        tdc += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }
    
    double tvo = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vo, vb);
        t = clock();
        BubbleSort(vb, TAM);
        tvo += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }

    tmb = tcr + tdc + tvo;
    resultPrint("Ordenacao BubbleSort", tcr, tdc, tvo);
}

void runSelectionSort() {
    clock_t t;
    
    double tcr = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vcr, vs);
        t = clock();
        SelectionSort(vs, TAM);
        tcr += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }
    
    double tdc = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vdc, vs);
        t = clock();
        SelectionSort(vs, TAM);
        tdc += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }
    
    double tvo = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vo, vs);
        t = clock();
        SelectionSort(vs, TAM);
        tvo += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }

    tms = tcr + tdc + tvo;
    resultPrint("Ordenacao SelectionSort", tcr, tdc, tvo);
}

void runQuickSort() {
    clock_t t;
    
    double tcr = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vcr, vq);
        t = clock();
        QuickSort(vq, TAM);
        tcr += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }
    
    double tdc = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vdc, vq);
        t = clock();
        QuickSort(vq, TAM);
        tdc += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }
    
    double tvo = 0;
    for (int i = 0; i < run; i++) {
        clonaV(vo, vq);
        t = clock();
        QuickSort(vq, TAM);
        tvo += ((double)(clock() - t) / CLOCKS_PER_SEC) * 1000.0;
    }

    tmq = tcr + tdc + tvo;
    resultPrint("Ordenacao QuickSort", tcr, tdc, tvo);
}

void Ger() {
    srand(time(NULL));
    
    for(int i = 0; i < TAM; i++) {
        vo[i] = rand() % 100;
    }

    printf("Gerando e preparando vetores...\n");
    selectionSortCrescenteAux(vo);
    selectionSortDecrescenteAux(vo);

    printf("Vetor Aleatorio: "); printV(vo);
    printf("Vetor Crescente: "); printV(vcr);
    printf("Vetor Decrescente: "); printV(vdc);
    
    printf("\nPressione Enter para iniciar os testes...");
    getchar();
    
    printf("\n--- INICIANDO TESTES ---\n");

    runBubbleSort();
    runSelectionSort();
    runQuickSort();

    printf("=================================================================\n");
    printf("Execucao concluida. Total de rodadas por caso: %d\n", run);
    printf("=================================================================\n");
    
    printf("\nResumo do Tempo TOTAL (soma de todos os cenarios):\n");
    printf("QuickSort:     %.4f ms\n", tmq);
    printf("SelectionSort: %.4f ms\n", tms);
    printf("BubbleSort:    %.4f ms\n", tmb);
}

int main() {
    Ger();

    printf("\n------------------------------------\n");
    printf("Pressione qualquer tecla para encerrar...\n");
    getch();
    return 0;
}
