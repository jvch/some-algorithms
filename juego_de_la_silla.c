/*
El juego de la silla

El juego de las sillas consiste en caminar alrededor de una fila de sillas mientras suena una pista
sonora. Cuando la pista sonora se detiene, debes sentarte cuanto antes en una silla antes de que te la
ganen. Estás practicando para el torneo mundial del juego de la silla y sabes que la estrategia ganadora
es siempre sentarte en la silla más cercana, sin importar si la silla te queda adelante o atrás.

Escribe un programa que lea las posiciones de las N sillas y que responda cuántos segundos te toma
llegar a la silla más cercana si actualmente te encuentras en la posición P y te mueves a un ritmo de
una unidad de distancia por segundo.
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int masCercano(int, int, int);

int encontrarCercano(int arr[], int n, int aux)
{
    if (aux <= arr[0])
        return abs(arr[0]-aux);
    if (aux >= arr[n - 1])
        return abs(arr[n - 1]-aux);
    int i = 0, j = n, med = 0;
    while (i < j) {
        med = (i + j) / 2;
        if (arr[med] == aux)
            return abs(arr[med]-aux);
        if (aux < arr[med]) {
            if (med > 0 && aux > arr[med - 1])
                return masCercano(arr[med - 1], arr[med], aux);
            j = med;
        }
        else {
            if (med < n - 1 && aux < arr[med + 1])
                return masCercano(arr[med], arr[med + 1], aux);
            i = med + 1;
        }
    }
    return arr[med];
}

int masCercano(int var1, int var2, int aux)
{
    if (aux - var1 >= var2 - aux)
        return var2-aux;
    else
        return aux-var1;
}

int main()
{
    int N, M;
    cin >> N;
    int arrN[N];
    for(int i=0; i<N; i++)
    {
        cin >> arrN[i];
    }
    int n = sizeof(arrN) / sizeof(arrN[0]);
    sort(arrN, arrN + n);
    cin >> M;
    int arrM[M];
    for(int i=0; i<M; i++)
    {
        cin >> arrM[i];
    }
    for (int i=0; i<M; i++)
    {
        cout << (encontrarCercano(arrN, n, arrM[i])) << endl;
    }
}
