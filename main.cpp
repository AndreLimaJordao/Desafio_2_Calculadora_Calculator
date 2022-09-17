#include <iostream>

using namespace std;

// Variáveis
int num[64];
char ope[64];
bool rep = true;
bool rep2 = false;
int counterOpe = 0;
int counterNum = 1;
long long int res;

// Funções
long long int calculator (long long int a, long long int b, char operation) {
    long long int resul;
    long long int pot;

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

        case '%':
            resul = a % b;
            break;

        default:
            resul = a;
            break;
    }
    cout << "Resultado atual: " << resul << endl;
    return resul;
}

int main() {
    while (rep) {
        cout << "------------------" << " = Calculator (Mem: 64 numbers) = " << "------------------" << endl;
        for (int i = 0; i <= counterNum; i++) {
            num[i] = 0;
        }
        for (int i = 0; i <= counterOpe; i++) {
            ope[i] = 0;
        }
        cout << "Insira um numero inteiro: ";
        cin >> num[0];
        cout << "Insira a operacao (+, -, *, /, %, ^): ";
        cin >> ope[0];
        if (ope[0] != '+' && ope[0] != '-' && ope[0] != '*' && ope[0] != '/' && ope[0] != '%' && ope[0] != '^') {
            cout << "Erro: valor digitado nao corresponde a umas das operacoes";
            return 0;
        }
        cout << "Insira um outro numero inteiro: ";
        cin >> num[1];
        res = calculator (num[0], num[1], ope[0]);

        do{
            cout << "Deseja calcular mais uma operacao? (1 - Sim / 0 - Nao): ";
            cin >> rep2;

            if (rep2) {
                counterOpe++;
                counterNum++;
                cout << "Insira uma outra operacao (+, -, *, /, %, ^): ";
                cin >> ope[counterOpe];
                if (ope[counterOpe] != '+' && ope[counterOpe] != '-' && ope[counterOpe] != '*' && ope[counterOpe] != '/' && ope[counterOpe] != '%' && ope[counterOpe] != '^') {
                    cout << "Erro: valor digitado nao corresponde a umas das operacoes";
                    return 0;
                }
                cout << "Insira um numero inteiro: ";
                cin >> num[counterNum];
                res = calculator (res, num[counterNum], ope[counterOpe]);
            }
        } while (rep2);

        if (!rep2) {
            cout << "\n----------------------------------------------------------------------\n" << "Equacao em ordem de execucao: ";
            for (int i = 0; i <= counterNum; i++) {
                cout << num[i] << " ";
                if (i <= counterOpe) {
                    cout << ope[i] << " ";
                }
            }
            cout << "\nResultado final: " << res << "\n----------------------------------------------------------------------\n\n";
            cout << "Deseja reiniciar a calculadora? (1 - Sim / 0 - Nao): ";
            cin >> rep;
            system ("cls");
        }
    }
    return 0;
}
