#include <iostream>

using namespace std;

// Definições
#defin memorySpace 128

// Variáveis
double num[memorySpace];         // Vetor de números
char ope[memorySpace];           // Vetor de operadores
bool rep = true;        // Repetição primária
bool rep2 = false;      // Repetição secundária
int counterOpe = 0;     // Contador de operadores
int counterNum = 1;     // Contador de números
double res;             // Resultado final

// Funções
// Calculator: o input 'a' e 'b' são os números que serão calculados, o input 'c' é o operador que será usado para o cálculo (ex: '+', '-', '*', '/', '^', '[', ']', '|') e vai retornar o resultado do cálculo.
double calculator (double a, double b, char operation);

int main() {
    // Loop para reinicialização do software.
    while (rep) {
        cout << "------------------" << " = Calculator (Mem: 64 numbers) = " << "------------------" << endl;

        // Parte dedicada a resetar as memórias alocadas.
        for (int i = 0; i <= counterNum; i++) {
            num[i] = 0;
        }
        for (int i = 0; i <= counterOpe; i++) {
            ope[i] = 0;
        }

        // Parte inicial com interação do usuário: vai ocorrer obrigatoriamente.
        cout << "Insira um numero: ";
        cin >> num[0];
        cout << "Insira a operacao (+, -, *, /, %, ^, [, ], |, c): ";
        cin >> ope[0];
        if (ope[counterOpe] != '+' && ope[counterOpe] != '-' && ope[counterOpe] != '*' && ope[counterOpe] != '/' && ope[counterOpe] != '^' && ope[counterOpe] != '|' && ope[counterOpe] != '[' && ope[counterOpe] != ']' && ope[counterOpe] != 'c') {
            cout << "Erro: valor digitado nao corresponde a umas das operacoes";
            return 0;
        }
        cout << "Insira um outro numero: ";
        cin >> num[1];
        res = calculator (num[0], num[1], ope[0]);

        // Loop dedicado a verificação e a adicionar mais operações
        do{
            cout << "Deseja calcular mais uma operacao? (1 - Sim / 0 - Nao): ";
            cin >> rep2;

            // Parte com interação do usuário: vai ocorrer facultativamente dependendo do valor de 'rep2'.
            if (rep2) {
                counterOpe++;
                counterNum++;
                cout << "Insira uma outra operacao (+, -, *, /, %, ^, [, ], |, c): ";
                cin >> ope[counterOpe];
                if (ope[counterOpe] != '+' && ope[counterOpe] != '-' && ope[counterOpe] != '*' && ope[counterOpe] != '/' && ope[counterOpe] != '^' && ope[counterOpe] != '|' && ope[counterOpe] != '[' && ope[counterOpe] != ']' && ope[counterOpe] != 'c') {
                    cout << "Erro: valor digitado nao corresponde a umas das operacoes";
                    return 0;
                }
                cout << "Insira um numero: ";
                cin >> num[counterNum];
                res = calculator (res, num[counterNum], ope[counterOpe]);
            }
        } while (rep2);

        // Parte final do sistema dedicado a apresentar as operações em ordem de execução e os resultados das operações.
        if (!rep2) {
            cout << "\n----------------------------------------------------------------------\n" << "Equacao em ordem de execucao: ";
            for (int i = 0; i <= counterNum; i++) {
                cout << num[i] << " ";
                if (i <= counterOpe) {
                    cout << ope[i] << " ";
                }
            }
            cout << "\nResultado final: " << res << "\n----------------------------------------------------------------------\n\n";

            // Parte dedicada a analisar se vai ser reinicializado o software.
            cout << "Deseja reiniciar a calculadora? (1 - Sim / 0 - Nao): ";
            cin >> rep;
            system ("cls");
            system ("pause");
            system ("cls");
        }
    }
    return 0;
}

double calculator (double a, double b, char operation) {
    double resul;
    double pot;
    double pi = 3.14;

    switch (operation) {
        case '+':
            resul = a + b;
            break;

        case '-':
            resul = a - b;
            break;

        case '*':
            resul = a * b;
            break;

        case '/':
            resul = a / b;
            break;

        case '^':
            pot = 1;
            for (int i = 1; i <= b; i++) {
                pot = pot * a;
            }
            resul = pot;
            break;

        case '[':
            if (a < 0) {
                a = a * -1;
            }
            if (b < 0) {
                b = b * -1;
            }
            resul = a + b;

        case ']':
            if (a < 0) {
                a = a * -1;
            }
            if (b < 0) {
                b = b * -1;
            }
            resul = a - b;

        case '|':
            if (a < 0) {
                a = a * -1;
            }
            if (b < 0) {
                b = b * -1;
            }
            resul = a * b;

        case 'c':
            resul = pi * (a * b);
            break;

        default:
            resul = a;
            break;
    }
    cout << "Resultado atual: " << resul << endl;
    return resul;
}
