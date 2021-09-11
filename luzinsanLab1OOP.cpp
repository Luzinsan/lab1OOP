#include "Vector3D.h"
using namespace luzalex;

int main()
{
    setlocale(LC_ALL, "Russian");
    Vector3D A{1,2,3};
    std::cout << "Тестирование функций доступа к членам класса\n"
              <<"---> Сеттеры координат (Запись данных)\n";
    std::cin >> A;

    std::cout << "---> Геттеры координат (Чтение данных)\n"
        << "x = " << A.getX() << "; y = " << A.getY() << "; z = " << A.getZ() << std::endl
        << "Вычисление модуля(длины) вектора: " << A.module() << std::endl;


    Vector3D B;
    std::cout << "\nКопирование вектора " << A << " в вектор " << B << std::endl;
    std::cout << "Результат: " << A.copyVector(B) << std::endl;

    std::cout << "\nУмножение вектора на скаляр.\n"
              << "Введите скалярное значение: ";
    double scal;
    std::cin >> scal;
    std::cout << B << " * " << scal << " = ";
    B.mltpToScal(scal).print();

    std::cout << "\nНормирование вектора---> Результат: " << B.normVec() << std::endl;
    std::cout << "Длина: " << B.module() << std::endl;

    std::cout << "\nДвуместные операции над векторами А и B с получением нового вектора С \n"
        << "Сложение: " << A << " + " << B << " = " << A + B << std::endl
        << "Разность: " << A << " - " << B << " = " << A - B << std::endl
        << "Векторное произведение: [ " << A << ", " << B << "] = " << A * B << std::endl;


    std::cin >> B;
    std::cout << "\nДвуместные операции над векторами А и B с получением скалярных величин \n"
        << "Скалярное произведение: (" << A << ", " << B << ") = " << scalarProduct(A, B) << std::endl
        << "cos = "<< cos(A, B) << std::endl
        << "sin = " << sin(A, B) << std::endl
        << "Величина угла в градусах между векторами А и B в пределах [-180; 180]: " << valAngle(A, B) << std::endl;


    return 0;
}
