#include <iostream>
#include <iomanip>
#include <string>
#include <locale.h>
using namespace std;

const int MAX = 50;
const int DIAS = 5;

void inserirConsumo(string p[MAX], string s[DIAS], int q, float c[MAX][DIAS]) {
    for (int i = 0; i < q; i++) {
        cout << endl << "Informe o consumo do prédio [" << p[i] << "]:" << endl;
        for (int j = 0; j < DIAS; j++) {
            cout << endl << "Informe o consumo em kwh na " << s[j] << ": ";
            cin >> c[i][j];
        }
    }
}

void totalPredio(int q, float c[MAX][DIAS], float ctp[MAX]) {
    for (int i = 0; i < q; i++) {
        ctp[i] = 0;
        for (int j = 0; j < DIAS; j++) {
            ctp[i] += c[i][j];
        }
    }
}

void totalDia(int q, float c[MAX][DIAS], float ctd[DIAS]) {
    for (int j = 0; j < DIAS; j++) {
        ctd[j] = 0;
        for (int i = 0; i < q; i++) {
            ctd[j] += c[i][j];
        }
    }
}

void imprimirConsumo(int q, string p[MAX], float kwh, float cp[MAX]) {
    for (int i = 0; i < q; i++) {
        cout << endl << "Prédio: " << p[i] << endl;
        cout << "- Consumo total semanal = " << cp[i] << " kwh" << endl;
        cout << "- Média diária de consumo = " << cp[i] / 5.0 << " kwh" << endl;
        cout << "- Custo estimado = R$" << cp[i] * kwh << endl;
    }
}

void dadosTotal(float cp[MAX], int q, float ctd[DIAS], string p[MAX], string s[DIAS]) {
    float soma = 0;
    for(int i = 0; i < q; i++) {
        soma += cp[i];
    }
    cout << "\nConsumo total da UFVJM na semana = " << soma << " kwh" << endl;
    float maiorCdia = ctd[0];
    float maiorCpredio = cp[0];
    int posicao = 0;
    for(int j = 1; j < DIAS; j++) {
        if(ctd[j] > maiorCdia) {
            maiorCdia = ctd[j];
            posicao = j;
        }
    }
    cout << "\nDia com maior consumo = " << s[posicao] << endl;
    cout << "\nConsumo total nesse dia = " << maiorCdia << " kwh" << endl;
    posicao = 0;
    for(int i = 1; i < q; i++) {
        if(cp[i] > maiorCpredio) {
            maiorCpredio = cp[i];
            posicao = i;
        }
    }
    cout << "\nPrédio com maior consumo = " << p[posicao];
    cout << "\nConsumo semanal = " << maiorCpredio << " kwh" << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    cout << fixed << setprecision(2);

    string predios[MAX];
    string semana[DIAS] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta"};
    float consumo[MAX][DIAS];
    float consumoPorPredio[MAX];
    float consumoPorDia[DIAS];
    float valorKWH;
    int quantidade;

    do {
        cout << "Informe a quantidade de prédios que serão cadastrados: ";
        cin >> quantidade;
        if (quantidade > MAX)
            cout << endl << "A quantidade de prédios deve ser menor ou igual a 50!!" << endl;
    } while (quantidade > MAX);

    cin.ignore();

    for (int i = 0; i < quantidade; i++) {
        cout << endl << "Informe o nome do prédio " << i + 1 << ": ";
        getline(cin, predios[i]);
    }

    inserirConsumo(predios, semana, quantidade, consumo);
    totalPredio(quantidade, consumo, consumoPorPredio);
    totalDia(quantidade, consumo, consumoPorDia);

    cout << endl << "Informe o valor do kwh: R$";
    cin >> valorKWH;

    imprimirConsumo(quantidade, predios, valorKWH, consumoPorPredio);
    dadosTotal(consumoPorPredio, quantidade, consumoPorDia, predios, semana);
}