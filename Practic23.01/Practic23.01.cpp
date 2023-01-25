#include <iostream>

using namespace std;

/*
добавить строку в конец двумерного массива
*/

char** GeneralFunc(char** str, int& row, bool begin, bool end, int index = -1) {
    row++;

    char** newstr = new char* [row];

    cout << "Enter string: ";
    char* subStr = new char[256];
    gets_s(subStr, 255);

    if (str) {
        //коприрование строк из str в newstr
        for (int i = begin, j = 0; i < row - end; i++) {
            newstr[i] = new char[strlen(str[j])+1];
            if (i != index) {
                strcpy_s(newstr[i], strlen(str[j]) + 1, str[j]);
                j++;
            }
        }
    }

    int i;
    if (!begin && !end && index >= 0) i = index;
    else if (begin) i = 0;
    else if (end) i = row - 1;

    newstr[i] = new char[strlen(subStr) + 1];
    strcpy_s(newstr[i], strlen(subStr) + 1, subStr);

    delete[]subStr;
    if (!str) delete[]str;
    return newstr;
}

char** AddEnd(char** str, int& row) {
    return GeneralFunc(str, row, 0, 1);
}

/*
добавить строку в начало двумерного массива
*/
char** AddBegin(char** str, int& row) {
    return GeneralFunc(str, row, 1, 0);
}
/*
добавить строку в указанную позицию
*/
char** Insert(char** str, int& row, int index) {
    return GeneralFunc(str, row, 0, 0, index);
}

int main()
{
    /*
    //создание двумерного динамического массива
    int** arr = new int* [3];
    for (int i = 0; i < 3; i++) {
        arr[i] = new int[5];
    }

    arr[2][1];

    //удаление
    for (int i = 0; i < 3; i++) {
        delete[]arr[i];
    }
    delete[]arr;*/
    
    /*int i, j;

    int m1, m2 = 5;
    int k = m2;

    cout << "ROW = "; cin >> m1;

    int** pArr = new int* [m1];
    for (int i = 0; i < m1; i++, k--) {
        pArr[i] = new int[k];
    }
    for (i = 0, k = m2; i < m1; i++, k--) {
        for (j = 0; j < k; j++ ) {
            pArr[i][j] = 5;
            cout << pArr[i][j] << " ";
        }
        cout << endl;
    }*/

    /*for (i = 0; i < m1; i++) {
        delete[]pArr[i];
    }
    delete[]pArr;*/

    /*int*** p = new int** [3];
    for (int i = 0; i < 3; i++) {
        p[i] = new int* [5];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            p[i][j] = new int[10];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 10; k++) {
                cout << p[i][j][k];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            delete[]p[i][j];
        }
        delete[]p[i];
    }
    delete[]p;*/

    /*char** str = new char* [3];
    str[0] = new char[6]{ "Hello" };
    str[1] = new char[2]{ " " };
    str[2] = new char[6]{ "world" };

    cout << str[0] << str[1] << str[2];*/

    char** str = nullptr;
    int row = 0; 
    str = AddBegin(str, row);
    str = AddEnd(str, row);
    str = AddBegin(str, row);
    str = Insert(str, row, 1);
    str = Insert(str, row, 3);
    
    cout << str[0] << endl << str[1] << endl << str[2] << endl << str[3] << endl << str[4];
}
