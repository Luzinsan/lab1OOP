#pragma once
#include <iostream>

namespace luzalex
{
    class Vector3D
    {
    private:
        double m_x, m_y, m_z;
        static int m_idVector3D;
        int m_id;

    public:
        //Конструктор для списка uniform инициализации 1) нуль-вектора по умолчанию или 2) вектора с пользовательскими значениями
        Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) : m_x{ x }, m_y{ y }, m_z{ z }, m_id{ m_idVector3D++ }
        {  std::cout << "Constructor - Done " << m_id << std::endl; }

        //Деструктор
        ~Vector3D() { std::cout << "Destructor - Done " << m_id << std::endl; }

        //Геттер координаты x
        const double getX() const;
        //Геттер координаты y
        const double getY() const;
        //Геттер координаты z
        const double getZ() const;

        //Сеттер координат вектора
        const Vector3D& setItems(double x = 0, double y = 0, double z = 0);
        //Вычисление модуля вектора
        const double module() const;
        //Копирование вектора - возвращает целевой вектор
        const Vector3D& copyVector(Vector3D& toVec) const;
        //Умножение вектора на скаляр
        const Vector3D& mltpToScal(const double scal);
        //Перегрузка оператора* для умножения вектора на скаляр
        const Vector3D& operator*(const double scal);
        //Нормирование вектора
        const Vector3D& normVec();
        //Вывод в консоль трёхмерного вектора
        const Vector3D& print() const;

        //Дружественная функция перегрузки оператора+ для трёхмерных векторов
        friend const Vector3D operator+(const Vector3D& A, const Vector3D& B);
        //Дружественная функция перегрузки оператора- для трёхмерных векторов
        friend const Vector3D operator-(const Vector3D& A, const Vector3D& B);
        //Дружественная функция перегрузки оператора* для векторного произведения трёхмерных векторов
        friend const Vector3D operator*(const Vector3D& A, const Vector3D& B);
        //Дружественная функция, возвращающая скалярное произведение друх трёхмерных векторов
        friend const double scalarProduct(const Vector3D& A, const Vector3D& B);
        //Дружественная функция, возвращающая косинус угла между двумя трёхмерными векторами
        friend const double cos(const Vector3D& A, const Vector3D& B);
        //Дружественная функция, возвращающая синус угла между двумя трёхмерными векторами
        friend const double sin(const Vector3D& A, const Vector3D& B);
        //Дружественная функция, возвращающая величину угла между друмя трёхмерными векторами
        friend const double valAngle(const Vector3D& A, const Vector3D& B);
        //Дружественная функция перегрузки оператора<< для вывода в консоль трёхмерных векторов
        friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);
        //Дружественная функция перегрузки оператора>> для ввода через консоль трёхмерных векторов
        friend std::istream& operator>>(std::istream& in, Vector3D& vec);
    };
}
