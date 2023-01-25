#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

// Variables
float a, b, c, d;
string e, f, g, h;
int count = 0;
float exec;

// Container
string cardSign[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
float cardValue[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
vector<string> solutions;

// Declaration of Void and Function
void manualInput();
// input manual oleh user

void randomInput();
// input dengan random generator

bool checkInput(string input);
// pengecekan validitas input

float strToFloat(string x);
// typecasting string ke float

void twoSameNumbers(float p, float q, float r, float s);
// variasi jika ada sepasang kartu dengan angka yang sama

void doubleTwoSameNumbers(float p, float q, float r, float s);
// variasi jika terdapat 2 pasang kartu dengan angka yang sama

void threeSameNumbers(float p, float q, float r, float s);
// variasi jika terdapat 3 kartu dengan angka yang sama

void noSameNumbers(float p, float q, float r, float s);
// variasi jika tidak ada angka yang sama

void countIf24(float a, float b, float c, float d);
// menghitung jika jumlah hasil operasi adalah 24

void is24(float a, float b, float c, float d);
// mengecek apakah hasil suatu operasi adalah 24

float combinationOfCalculation(float a, float b, int sign);
// hasil kombinasi dari semua operasi terhadap keempat angka

string flagToOperator(int flag);
// mengubah integer flag sebagai penanda menjadi operator

void counter(float a, float b, float c, float d, int i, int j, int k);
// menghitung solusi

void printResult(float a, float b, float c, float d, int i, int j, int k);
// print-out solusi ke layar

void saveToFile(string filename);
// menyimpan solusi ke dalam masukan file

// Main Program
int main(){
    string userChoice;
    string saveOrNo;
    string filename;

    cout << "Hello, welcome to make it 24 Card Game!" << endl;
    
    // memilih input
    bool loop = true;
    while (loop == true){
        cout << "How would you like to input your card value?" << endl;
        cout << "1. Manual" << endl;
        cout << "2. Random" << endl;
        cout << "Your choice is: ";
        cin >> userChoice;
        cout << endl;
        if (userChoice == "1"){
            manualInput();
            loop = false;
        } else if (userChoice == "2"){
            randomInput();
            loop = false;
        } else{
            cout << "Invalid input! Please enter again" << endl;
        }
    }
    // konversi kartu ke valuenya
    a = strToFloat(e);
    b = strToFloat(f);
    c = strToFloat(g);
    d = strToFloat(h);

    clock_t start = clock(); // untuk menghitung waktu eksekusi

    // variasi angka input
    if ((a == b) && (a != c) && (a != d) && (c != d)){ // aacd
        twoSameNumbers(a, b, c, d);
    }
    if ((a == c) && (a != b) && (a != d) && (b != d)){ // abad
        twoSameNumbers(a, c, b, d);
    }
    if ((a == d) && (a != b) && (a != c) && (b != c)){ // abca
        twoSameNumbers(a, d, b, c);
    }
    if ((b == c) && (b != a) && (b != d) && (a != d)){ // abbd
        twoSameNumbers(b, c, a, d);
    }
    if ((b == d) && (b != a) && (b != c) && (a != c)){ // abcb
        twoSameNumbers(b, d, a, c);
    }
    if ((c == d) && (c != a) && (c != b) && (a != b)){ // abcc
        twoSameNumbers(c, d, a, b);
    }
    if ((a == b) && (c == d) && (a != c)){ // aacc
        doubleTwoSameNumbers(a, b, c, d);
    }
    if ((a == c) && (b == d) && (a != b)){ // abab
        doubleTwoSameNumbers(a, c, b, d);
    }
    if ((a == d) && (b == c) && (a != b)){ // abba
        doubleTwoSameNumbers(a, d, b, c);
    }
    if ((a == b) && (a == c) && (a != d)){ // aaad
        threeSameNumbers(a, b, c, d);
    }
    if ((a == b) && (a == d) && (a != c)){ // aaca
        threeSameNumbers(a, b, d, c);
    }
    if ((a == c) && (a == d) && (a != b)){ // abaa
        threeSameNumbers(a, d, c, b);
    }
    if ((b == c) && (b == d) && (a != b)){ // abbb
        threeSameNumbers(d, b, c, a);
    }
    if ((a == b) && (c == d) && (a == c)){ // aaaa
        countIf24(a, b, c, d);
        cout << count << " solution(s) found" << endl;
        cout << endl;
        is24(a, b, c, d);
    }
    if ((a != b) && (a != c) && (a != d) && (b != c) && (b != d) && (c != d)){ // abcd
        noSameNumbers(a, b, c, d);
    }

    exec = (float)(clock() - start)/CLOCKS_PER_SEC; // akhir waktu eksekusi
    cout << endl << "Execution time is " << exec << endl;
    
    // save to file
    loop = true;
    while (loop == true){
        cout << "Would you like to save solutions into file?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Your choice is: ";
        cin >> saveOrNo;
        cout << endl;
        if (saveOrNo == "1" || saveOrNo == "yes" || saveOrNo == "Yes" || saveOrNo == "YES" || saveOrNo == "y" || saveOrNo == "Y"){
            cout << "input your txt filename: ";
            cin >> filename;
            filename = filename + ".txt";
            saveToFile(filename);
            loop = false;
        } else if (saveOrNo == "2" || saveOrNo == "no" || saveOrNo == "No" || saveOrNo == "NO" || saveOrNo == "n" || saveOrNo == "N"){
            loop = false;
        } else{
            cout << "Invalid input! Please enter again" << endl;
        }
    }
    return 0;
}



// Implementation of Void and Function
void manualInput(){
    cout << "Input your 4 cards value: " << endl;
    cin >> e >> f >> g >> h;
    cout << endl;
}

void randomInput(){
    int idx1, idx2, idx3, idx4;

    srand(time(NULL));
    idx1 = (rand() % 13);
    idx2 = (rand() % 13);
    idx3 = (rand() % 13);
    idx4 = (rand() % 13);
    e = cardSign[idx1];
    f = cardSign[idx2];
    g = cardSign[idx3];
    h = cardSign[idx4];
    cout << "Your random cards: " << e << f << g << h << endl;
}

bool checkInput(string input){
    bool found = false;
    int idx = 0;

    while (!found && idx < 14){
        if (input == cardSign[idx]){
            found = true;
            return found;
        }
        idx++;
    }
    return found;
}

float strToFloat(string x){
    bool found = false;
    float convertResult;
    int idx = 0;

    while (!found && idx < 14){
        if (x == cardSign[idx]){
            convertResult = cardValue[idx];
            found = true;
            return convertResult;
        }
        idx++;
    }
    return stof(x);
}

void noSameNumbers(float p, float q, float r, float s){
    countIf24(p, q, r, s);
    countIf24(p, q, s, r);
    countIf24(p, r, q, s);
    countIf24(p, r, s, q);
    countIf24(p, s, q, r);
    countIf24(p, s, r, q);
    countIf24(q, p, r, s);
    countIf24(q, p, s, r);
    countIf24(q, r, p, s);
    countIf24(q, r, s, p);
    countIf24(q, s, p, r);
    countIf24(q, s, r, p);
    countIf24(r, p, q, s);
    countIf24(r, p, s, q);
    countIf24(r, q, p, s);
    countIf24(r, q, s, p);
    countIf24(r, s, p, q);
    countIf24(r, s, q, p);
    countIf24(s, p, q, r);
    countIf24(s, p, r, q);
    countIf24(s, q, p, r);
    countIf24(s, q, r, p);
    countIf24(s, r, p, q);
    countIf24(s, r, q, p);
    cout << count << " solution(s) found" << endl;
    cout << endl;
    is24(p, q, r, s);
    is24(p, q, s, r);
    is24(p, r, q, s);
    is24(p, r, s, q);
    is24(p, s, q, r);
    is24(p, s, r, q);
    is24(q, p, r, s);
    is24(q, p, s, r);
    is24(q, r, p, s);
    is24(q, r, s, p);
    is24(q, s, p, r);
    is24(q, s, r, p);
    is24(r, p, q, s);
    is24(r, p, s, q);
    is24(r, q, p, s);
    is24(r, q, s, p);
    is24(r, s, p, q);
    is24(r, s, q, p);
    is24(s, p, q, r);
    is24(s, p, r, q);
    is24(s, q, p, r);
    is24(s, q, r, p);
    is24(s, r, p, q);
    is24(s, r, q, p);
}

void twoSameNumbers(float p, float q, float r, float s){
    countIf24(p, p, r, s);
    countIf24(r, p, p, s);
    countIf24(p, r, p, s);
    countIf24(r, p, s, p);
    countIf24(p, r, s, p);
    countIf24(s, r, p, p);
    countIf24(r, s, p, p);
    countIf24(p, s, r, p);
    countIf24(s, p, r, p);
    countIf24(p, p, s, r);
    countIf24(s, p, p, r);
    countIf24(p, s, p, r);
    cout << count << " solution(s) found" << endl;
    cout << endl;
    is24(p, p, r, s);
    is24(r, p, p, s);
    is24(p, r, p, s);
    is24(r, p, s, p);
    is24(p, r, s, p);
    is24(s, r, p, p);
    is24(r, s, p, p);
    is24(p, s, r, p);
    is24(s, p, r, p);
    is24(p, p, s, r);
    is24(s, p, p, r);
    is24(p, s, p, r);
}

void doubleTwoSameNumbers(float p, float q, float r, float s){
    countIf24(p, p, r, r);
    countIf24(r, p, p, r);
    countIf24(p, r, p, r);
    countIf24(r, p, r, p);
    countIf24(p, r, r, p);
    countIf24(r, r, p, p);
    cout << count << " solution(s) found" << endl;
    cout << endl;
    is24(p, p, r, r);
    is24(r, p, p, r);
    is24(p, r, p, r);
    is24(r, p, r, p);
    is24(p, r, r, p);
    is24(r, r, p, p);
}

void threeSameNumbers(float p, float q, float r, float s){
    countIf24(p, p, p, s);
    countIf24(p, p, s, p);
    countIf24(p, s, p, p);
    countIf24(s, p, p, p);
    cout << count << " solution(s) found" << endl;
    cout << endl;
    is24(p, p, p, s);
    is24(p, p, s, p);
    is24(p, s, p, p);
    is24(s, p, p, p);
}

void countIf24(float a, float b, float c, float d){
    int i, j, k;

    for (i = 1; i <= 4; i++){
        for (j = 1; j <= 4; j++){
            for (k = 1; k <= 4; k++){
                counter(a, b, c, d, i, j, k);
            }
        }
    }
}

void is24(float a, float b, float c, float d){
    int i, j, k;

    for (i = 1; i <= 4; i++){
        for (j = 1; j <= 4; j++){
            for (k = 1; k <= 4; k++){
                printResult(a, b, c, d, i, j, k);
            }
        }
    }
}

float combinationOfCalculation(float x, float y, int flag){
    switch(flag){
        case 1:
            return (x+y);
            break;
        case 2:
            return (x*y);
            break;
        case 3:
            return (x-y);
            break;
        case 4:
            return (x/y);
            break;
    }
}

string flagToOperator(int flag){
    switch(flag){
        case 1:
            return "+";
            break;
        case 2:
            return "*";
            break;
        case 3:
            return "-";
            break;
        case 4:
            return "/";
            break;
    }
    return 0;
}

void counter(float a, float b, float c, float d, int i, int j, int k){
    float result;

    result = combinationOfCalculation(combinationOfCalculation(a, b, i), combinationOfCalculation(c, d, k), j);
    // operasi kurung: (a + b) + (c + d)
    if (result > 23.99999 && result < 24.00001){
        count++;
    }

    result = combinationOfCalculation(combinationOfCalculation(combinationOfCalculation(a, b, i), c, j), d, k);
    // operasi kurung: ((a + b) + c) + d
    if (result > 23.99999 && result < 24.00001){
        count++;
    }

    result = combinationOfCalculation(combinationOfCalculation(a, combinationOfCalculation(b, c, j), i), d, k);
    // operasi kurung: (a + (b + c)) + d
    if (result > 23.99999 && result < 24.00001){
        count++;
    }

    result = combinationOfCalculation(a, combinationOfCalculation(combinationOfCalculation(b, c, j), d, k), i);
    // operasi kurung: a + ((b + c) + d)
    if (result > 23.99999 && result < 24.00001){
        count++;
    }

    result = combinationOfCalculation(a, combinationOfCalculation(b, combinationOfCalculation(c, d, k), j), i);
    // operasi kurung: a + (b + (c + d))
    if (result > 23.99999 && result < 24.00001){
        count++;
    }
}

void printResult(float a, float b, float c, float d, int i, int j, int k){
    float result;

    result = combinationOfCalculation(combinationOfCalculation(a, b, i), combinationOfCalculation(c, d, k), j);
    // operasi kurung: (a + b) + (c + d)
    if (result > 23.99999 && result < 24.00001){
        cout << "(" << a << " " << flagToOperator(i) << " " << b << ") " <<
                flagToOperator(j) << " (" << c << " " << flagToOperator(k) << " " << d << ")" << endl;
        solutions.push_back("(" + to_string((int)a) + " " + flagToOperator(i) + " " + to_string((int)b) + ") " +
                flagToOperator(j) + " (" + to_string((int)c) + " " + flagToOperator(k) + " " + to_string((int)d) + ")");
    }

    result = combinationOfCalculation(combinationOfCalculation(combinationOfCalculation(a, b, i), c, j), d, k);
    // operasi kurung: ((a + b) + c) + d
    if (result > 23.99999 && result < 24.00001){
        cout << "((" << a << " " << flagToOperator(i) << " " << b << ") " <<
                flagToOperator(j) << " " << c << ") " << flagToOperator(k) << " " << d << endl;
        solutions.push_back("((" + to_string((int)a) + " " + flagToOperator(i) + " " + to_string((int)b) + ") " +
                flagToOperator(j) + " " + to_string((int)c) + ") " + flagToOperator(k) + " " + to_string((int)d));
    }

    result = combinationOfCalculation(combinationOfCalculation(a, combinationOfCalculation(b, c, j), i), d, k);
    // operasi kurung: (a + (b + c)) + d
    if (result > 23.99999 && result < 24.00001){
        cout << "(" << a << " " << flagToOperator(i) << " (" << b << " " <<
                flagToOperator(j) << " " << c << ")) " << flagToOperator(k) << " " << d << endl;
        solutions.push_back("(" + to_string((int)a) + " " + flagToOperator(i) + " (" + to_string((int)b) + " " +
                flagToOperator(j) + " " + to_string((int)c) + ")) " + flagToOperator(k) + " " + to_string((int)d)); 
    }

    result = combinationOfCalculation(a, combinationOfCalculation(combinationOfCalculation(b, c, j), d, k), i);
    // operasi kurung: a + ((b + c) + d)
    if (result > 23.99999 && result < 24.00001){
        cout << a << " " << flagToOperator(i) << " ((" << b << " " << flagToOperator(j) <<
                " " << c << ") " << flagToOperator(k) << " " << d << ")" << endl;
        solutions.push_back(to_string((int)a) + " " + flagToOperator(i) + " ((" + to_string((int)b) + " " + flagToOperator(j) +
                " " + to_string((int)c) + ") " + flagToOperator(k) + " " + to_string((int)d) + ")");
    }

    result = combinationOfCalculation(a, combinationOfCalculation(b, combinationOfCalculation(c, d, k), j), i);
    // operasi kurung: a + (b + (c + d))
    if (result > 23.99999 && result < 24.00001){
        cout << a << " " << flagToOperator(i) << " (" << b << " " << flagToOperator(j) <<
                " (" << c << " " << flagToOperator(k) << " " << d << "))" << endl;
        solutions.push_back(to_string((int)a) + " " + flagToOperator(i) + " (" + to_string((int)b) + " " + flagToOperator(j) +
                " (" + to_string((int)c) + " " + flagToOperator(k) + " " + to_string((int)d) + "))");
    }
}

void saveToFile(string filename){
    ofstream output("../test/" + filename);
    
    if (output.is_open()){
        output << count << " solution(s) found" << "\n";
        for (int i=0; i<solutions.size(); i++){
            output << solutions.at(i) << "\n";
        }
        output << "Execution time is " << exec;
    }
    output.close();
    cout << "File berhasil disimpan" << endl;
}