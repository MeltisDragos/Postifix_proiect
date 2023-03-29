#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

char fp[100], st[100];
int vf = -1;
int st1[100], vf1 = -1, l = 0;


struct valori {

    char nume;
    int val;
}V[100];


void push_stiva(char st[], int x) {
    if (vf == 99) cout << "Error: Stack Overflow\n";
    else st[++vf] = x;
}
char pop_stiva(char st[]) {
    if (vf < 0) cout << " Error: stack Null\n";
    else return st[vf--];
}

void push_stiva1(int st1[], int x) {
    if (vf1 == 99) cout << "Error: Stack Overflow\n";
    else st1[++vf1] = x;
}
int pop_stiva1(int st1[]) {
    if (vf1 < 0) cout << " Error: stack Null\n";
    else return st1[vf1--];
}

using namespace std;

int operatie(int a, int b, char c) {

    switch (c) {

    case '*': return a*b; break;
    case '/': return a/b; break;
    case '+': return a+b; break;
    case '-': return a-b; break;

    }
}

int prioritate(char c) {

    switch (c) {

    case '(': return 0; break;
    case '*':
    case '/': return 1; break;
    case '+':
    case '-': return 2; break;
    }
}

int operatori(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') return 1;
    else if (c == '(') return 0;
}

char* conversie(char v[])
{
    int i, k = 0, lg;
    lg = strlen(v);
    for (i = 0; i < lg; i++) {
        if (v[i] == '+' || v[i] == '-' || v[i] == '*' || v[i] == '/' || v[i] == '(')
            if (vf == -1)
                push_stiva(st, v[i]);
            else if (prioritate(v[i]) >= prioritate(st[vf]) && v[i] != '(' && st[vf] != '(') {
                fp[k++] = pop_stiva(st);
                push_stiva(st, v[i]);
            }
            else push_stiva(st, v[i]);

        else if (v[i] != ')')
            fp[k++] = v[i];
        else {
            do
                fp[k++] = pop_stiva(st);
            while (operatori(st[vf]));
            vf--;
        }
    }
    while (vf >= 0)
        fp[k++] = pop_stiva(st);
    return fp;
}

int main() {
    char v[100], * p;
    int i;
    cin >> v;
    p = conversie(v);
    cout << p << endl;
    return 0;
}

