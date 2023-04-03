/*
//2d Реализовать чтение ID3v1 MP3-файла. Будьте внимательны, не все MP3-файлы
//содержат заполненный ID3 - тег. d. Год
#include <iostream>
#include <fstream>
#include <array>
#include <string>
int main()
{
    setlocale(LC_ALL, "RUS");
    std::fstream file;
    file.open("1.mp3", std::ios::binary||std::ios::in);
    if(!file.is_open()){
        std::cout << "Файл не открывается" << "\n";
        return - 1;
    }
    char ID3_tag[128];
    int offset = 48;
    file.seekg(-128, std::ios::end);
    file.read(ID3_tag, 128);
    file.close();
    for (int i = 0; i< 128; i++){
        std::cout << ID3_tag[i];
    }
    std::cout << "\n";
    return 0;
}
*/

/*
//3h Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
//считывать из файла in.txt.
#include <iostream>
#include <fstream>
#include <cmath>
double func(double x, int c) {
    double y = 0;
    double pow_x = 1;
    int fact = 1;
    int sign = 1;

    for (int i = 1; i <= c; i++) {
        y += sign * pow_x / fact;
        pow_x *= x;
        fact *= (2 * i) * (2 * i - 1);
        sign *= -1;
    }
    return y;
}
int main() {
    double x0, xn, step;
    int c;
    std::ifstream fin("in.txt");
    fin >> x0 >> xn >> step >> c;
    fin.close();
    std::ofstream fout("out.txt");
    for (double x = x0; x <= xn; x += step) {
        fout << x << ", " << func(x, c) << std::endl;
    }
    fout.close();
    return 0;
}
*/


#include <iostream>
#include <fstream>
int main() {
    setlocale(LC_ALL, "RUS");
    double x, y;
    int command;
    std::ofstream fout("flight_data.txt", std::ios::app);
    if (!fout.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    std::cout << "Введите координаты и команду(10 – взлёт, 20 – посадка, 50 – полёт, 60 – набрать высоту, 70 снизить высоту):" << std::endl;
    std::cin >> x >> y >> command;
    fout << x << "," << y << "," << command << std::endl;
    fout.close();
    return 0;
}