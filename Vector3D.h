#pragma once
#include <iostream>

class Vector3D
{
private:
    double m_x, m_y, m_z;

public:
    //Конструктор для списка uniform инициализации 1) нуль-вектора по умолчанию или 2) вектора с пользовательскими значениями
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0): m_x{ x }, m_y{ y }, m_z{ z }
    { std::cout << "Constructor - Done\n"; }

    //Деструктор
    ~Vector3D(){ std::cout << "Destructor - Done\n"; }

    //Геттер координаты x
    double getX() const;
    //Геттер координаты y
    double getY() const;
    //Геттер координаты z
    double getZ() const;

    //Сеттер координат вектора
    Vector3D& setItems(double x = 0, double y = 0, double z = 0);

    //Вычисление модуля вектора
    double module() const;

    //Копирование вектора - возвращает копируемый вектор
    Vector3D& copyVector(Vector3D& toVec);

    //Умножение вектора на скаляр
    Vector3D& mltpToScal(double scal);

    //Нормирование вектора
    Vector3D& normVec();

    //Двужественная функция перегрузки оператора+ для трёхмерных векторов
    friend Vector3D operator+(Vector3D& A, Vector3D& B);

    //Двужественная функция перегрузки оператора- для трёхмерных векторов
    friend Vector3D operator-(Vector3D& A, Vector3D& B);

    //Двужественная функция перегрузки оператора* для векторного произведения трёхмерных векторов
    friend Vector3D operator*(const Vector3D& A, const Vector3D& B);

    //Дружественная функция, возвращающая скалярное произведение друх трёхмерных векторов
    friend double scalarProduct(const Vector3D& A, const Vector3D& B);

    //Дружественная функция, возвращающая косинус угла друх трёхмерных векторов
    friend double cos(const Vector3D& A, const Vector3D& B);

    //Дружественная функция, возвращающая синус угла друх трёхмерных векторов
    friend double sin(const Vector3D& A, const Vector3D& B);

    //Дружественная функция, возвращающая величину угла между друмя трёхмерными векторами
    friend double valAngle(const Vector3D& A, const Vector3D& B);

    friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);

    friend std::istream& operator>>(std::istream& in, Vector3D& vec);

    Vector3D& print();
};