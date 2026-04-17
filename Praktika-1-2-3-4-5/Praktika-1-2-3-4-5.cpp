
#include <iostream>
using namespace std;
#include <iomanip>
#include <locale>

void  GenerateMatrix(int** mat, int N)
{
    srand(time(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = rand() % 67 - 33 ;
        }
    }
}

void PrintMatrix(int** mat, int N)
{
    cout << "--- Матриця " << N << "x" << N << " ---" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(6) << mat[i][j];
        }
        cout << endl << endl;
    }
}


double average(int** mat, int N)
{
    double suma = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (mat[i][j] > 0)
            {
                suma += mat[i][j];
                count++;
            }
        }
    }
    if (count > 0) {
        return suma / count;
    }
    else {
        return 0;
    }
}


void ProcessSectors(int** mat, int N, double avg)
{
    int countSector3 = 0;
    int countSector8 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (j >= i && i + j > N - 1) {
                if (mat[i][j] > 0) { 
                    countSector3++;
                }
            }

            if (i > j) {
                countSector8++;
                mat[i][j] = (int)avg; 
            }
        }
    }

    cout << "Кількість натуральних чисел у Секторі 3 = " << countSector3 << endl;
    cout << "Кількість елементів у Секторі 8 = " << countSector8 << endl;
}





int main()
{
    setlocale(LC_ALL, "Ukrainian");
    int N;
    cout << "Введіть розмір матриці =)";
    cin >> N;
    int** matrix = new int* [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    GenerateMatrix(matrix, N);
    PrintMatrix(matrix, N);
    double averige = average(matrix, N);
    cout << "Середнє арифметичне додатних чисел " << averige << endl << endl;

    ProcessSectors(matrix, N, averige);
    cout << "Матриця ПІСЛЯ обробки секторів"<< endl;
    PrintMatrix(matrix, N);
    return 0;
}