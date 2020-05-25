#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream> 
#include <string.h>
#include <cstring>
#include <stdio.h> 
#include <cctype>

int palindrom(char* a);

void menu();

void kount(char* a);

void Chisloli(char* t);

void sort(char** a, int size);

void line(int a[], int n);

void output(char** a, int n);

int text(int len);

int min_word(int len);

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, len = 255;
    int namber = 1;
    while (namber != 0)
    {
        menu();
        cout << "Задание № ";
        cin >> namber;
        switch (namber)
        {
        case 1:
        {
            cout << "Считает количество символов в строке." << endl;
            cin.clear();
            cin.ignore();
            int i, n = 0;
            char* s = new char[100];
            cout << "Введите строку: ";
            cin.getline(s, 255);
            for (i = 0; s[i] != '\0'; i++) n++;
            cout << "Количество символов в строке: " << n << endl;
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "Составляет предложения из заранее подготовленных слов." << endl;
            cout << "Порядок слов: article, существительное, глагол, предлог, article и существительное. " << endl;
            cin.clear();
            cin.ignore();
            int articles, syhestvitelnoes, glagols, predlogs;

            char* article[100];
            {
                ifstream  fin("article.txt");
                if (!fin) {
                    cout << "Ошибка открытия файла" << endl;
                    exit;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL)
                    {
                        article[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }

                articles = n;
                cout << endl;
            }

            char* syhestvitelnoe[100];
            {
                ifstream  fin("syhestvitelnoe.txt");
                if (!fin)
                {
                    cout << "Ошибка открытия файла" << endl;
                    exit;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL) {
                        syhestvitelnoe[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }

                syhestvitelnoes = n;
            }

            char* glagol[100];
            {
                ifstream  fin("glagol.txt");
                if (!fin)
                {
                    cout << "Ошибка открытия файла" << endl;
                    exit;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL) {
                        glagol[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }

                glagols = n;
            }

            char* predlog[100];

            {
                ifstream  fin("predlog.txt");
                if (!fin)
                {
                    cout << "Ошибка открытия файла" << endl;
                    exit;
                }
                char* s = new char[100];
                int size = 0;
                int n;
                while (!fin.eof())
                {
                    fin.getline(s, 100, '\n');
                    char  seps[] = " ,;"; // Строка разделителей
                    char* token; // указатель на новой слово
                    token = strtok(s, seps);// находим первое слово
                    n = 0; //n - количество слов
                    while (token != NULL)
                    {
                        predlog[size] = token; size++;
                        token = strtok(NULL, seps); n++;// выделяем следующее слово
                    }
                }

                predlogs = n;
            }

            int N;
            cout << "Количество предложений = ";
            cin >> N;

            for (int i = 0; i < N; i++)
            {
                const int max_N = 256;
                char offer[max_N];
                sprintf(offer, "%s %s %s %s %s %s.", article[rand() % articles], syhestvitelnoe[rand() % syhestvitelnoes], glagol[rand() % glagols], predlog[rand() % predlogs], article[rand() % articles], syhestvitelnoe[rand() % syhestvitelnoes]);
                offer[0] = toupper(offer[0]);
                cout << offer << endl;
            }
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "Определяет является ли строка палиндромом." << endl;
            cin.clear();
            cin.ignore();
            int i;
            char* s = new char[100];
            cout << "При использовании Русского языка, программа будет выдовать не верные результаты," << endl;
            cout << "поэтому рекомендуется использовать латинский алфовит." << endl;
            cout << "Введите строку - ";
            cin.getline(s, 255);
            if (palindrom(s)) cout << "Строка является Палиндромом!" << endl;
            else cout << "Строка не является Палиндромом!" << endl;
            break;
        }
        case 4:
        {
            cout << "Считает количество слов в строке, а также количество предложений." << endl;
            cin.clear();
            cin.ignore();
            int i;
            char* s = new char[100];
            cout << "Введите строку: ";
            cin.getline(s, 255);
            kount(s);
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            cin.clear();
            cin.ignore();
            min_word(len);
            break;
        }
        case 7:
        {
            cin.clear();
            cin.ignore();
            text(len);
            break;
        }
        }
    }
}

void menu()
{
    cout << "1 - Задание 1" << endl;
    cout << "2 - Задание 2" << endl;
    cout << "3 - Задание 3" << endl;
    cout << "4 - Задание 4" << endl;
    cout << "5 - 6 вариант- 1 задание" << endl;
    cout << "6 - 6 вариант- 2 задание" << endl;
    cout << "7 - 6 вариант- 3 задание" << endl;
    cout << "0 - EXIT" << endl;
}
/*
Функция на вход получает символьный массив а.
Функция предназначена для проверки, является ли введенная строка палиндромом или нет.
Функция возвращает 1 или 0.
1 - строка является палиндромом.
0 - строа  не является палиндромом.
*/
int palindrom(char* a)
{
    char* b = new char[100];
    int n = strlen(a);
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (isalpha(a[i])) {
            b[k++] = tolower(a[i]);
        }
    }
    b[k] = '\0';


    bool t = 1;
    int j;
    for (int i = 0, j = strlen(b) - 1; i < j; i++, j--)
    {
        if ((b[i]) != b[j])
        {
            t = 0;

        }
    }
    return t;
}

/*
Функция на вход получает символьный массив а.
Функция используется для подсчёта количество слов и предложений в строке.
*/
void kount(char* a)
{
    int i;
    char* b = new char[100];
    strcpy(b, a);

    char  seps[] = " ,.;!?";
    char seps1[] = ".!?";
    char* token;
    token = strtok(b, seps);
    int n = 1;
    while (token != NULL) {
        token = strtok(NULL, seps); n++;
    }
    n--;
    cout << "Количество слов: " << n << endl;
    n = 0;
    for (i = 0; i < strlen(a); i++)
    {
        if (a[i] == '.' || a[i] == '!' || a[i] == '?') n++;
    }
    cout << "Количество предложений: " << n << endl;
}

/*
Функция на вход получает переменные n и c.
Переменная "n" считает количество слов в строке.
Переменная "c" считает количество строк в текстовом файле.
*/


/*
Функция на вход получает символьный массив t.
Функция предназначена для вроверки, является ли символ числом.
И если символ является числом, тогда записать его как вещественное число.
*/
void Chisloli(char* t)
{
    int n = 0, i;
    double c = 10;
    double f = 0;
    n = strlen(t);
    for (i = 0; i < n; i++)
    {
        if ((t[i] <= '9') && (t[i] >= '0'))  f = f * 10 + (t[i] - 48); // Вычитание по таблицу ASCII кода.
        if (t[i] == '.')
        {

            for (int j = i + 1; j < n; j++)
            {
                if ((t[j] <= '9') && (t[j] >= '0'))
                {
                    double d = (t[j] - 48) / c;;
                    f = f + d; c = c * 10;
                }
            }
            if (t[0] == '-') f = f * (-1);
            if (f != 0) printf("%.3f \n", f);
            return;
        }
    }
    if (t[0] == '-') f = f * (-1);
    if (f != 0) cout << f << endl;
}

void sort(char** a, int size)
{
    char  seps[] = " ";
    int* b = new int[size];
    for (int i = 0; i < size; i++)
    {
        if (isupper(a[i][0]))
        {
            a[i][0] = tolower(a[i][0]);
        }
        int t = a[i][0];
        b[i] = t;
        // cout << (char)t << endl;
         //cout << t << "  " << a[i] << endl;
    }
    line(b, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            if ((char)b[i] == a[j][0]) { cout << a[j] << endl; a[j] = seps; break; }
    }
}

void line(int a[], int n)
{
    int i, j, min, mink = 0, t;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                mink = j;
            }
        }
        if (a[i] > min)
        {
            t = a[i];
            a[i] = a[mink];
            a[mink] = t;
        }
    }
}
int min_word(int len)
{
    char  s[255], min[255];
    char* word;
    char del[] = " ?!.,\0";
    int l = 1;
    ifstream  fin("test.txt");
    if (!fin)
    {
        cout << "Файл не найден" << endl;
        return 1;
    }
    while (fin.getline(s, 255))
    {
        if (l == 3)
        {
            word = strtok(s, del);
            strcpy(min, word);
            while (word != NULL)
            {
                word = strtok(NULL, del);
                if (word != NULL)
                    if (strlen(word) < strlen(min))
                        strcpy(min, word);
            }
        }
        l++;
    }
    cout << "Самое короткое слово последней строки: " << min << endl;
}

int text(int len)
{
    int l, count = 0;
    const int n = 255;
    char line[n];
    char min[n];
    char seps[] = " .,!?";
    char* word;
    char t[255];
    ifstream  fin("test2.txt");
    if (!fin)
    {
        cout << "Файл не найден" << endl;
        return 1;
    }
    while (fin.getline(line, n))
    {
        int i = 0;
        while (line[i] == ' ' && line[i] != '\0')
        {
            i++;
        }
        l = 0;
        while (line[i] != '\0') {
            if (line[i] != ' ' && l == 0 && line[i] != '-')
            {
                l = 1;
                count++;
            }
            else
                if (line[i] == ' ')
                    l = 0;
            i++;
        }
        char** b = new char* [count];
        for (i = 0; i < count; i++)
        {
            b[i] = new char[n];
        }
        i = 0;
        word = strtok(line, seps);
        while (word != NULL)
        {
            strcpy(b[i], word);
            word = strtok(NULL, seps);
            i++;
        }
        output(b, count);
        cout << endl;
        for (int i = 0; i < count; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                if (strlen(b[j]) > strlen(b[j - 1]))
                {
                    strcpy(t, b[j]);
                    strcpy(b[j], b[j - 1]);
                    strcpy(b[j - 1], t);
                }
            }
        }
        cout << "Слова, упорядоченные по убыванию их длины " << endl;
        output(b, count - 1);
        cout << endl;
    }
    cout << endl;
}
void output(char** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        {
            cout << a[i] << endl;
        }
    }
}
