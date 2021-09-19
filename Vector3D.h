#pragma once
#include <iostream>

namespace luMath
{
    class Vector3D
    {
    private:
        double m_x, m_y, m_z;
        static int m_idVector3D;
        int m_id;

    public:
        //Конструктор для инициализации 1) нуль-вектора по умолчанию или 2) вектора с пользовательскими значениями
        Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

        //Деструктор
        ~Vector3D();

        //Геттер координаты x
        double getX() const;
        //Геттер координаты y
        double getY() const;
        //Геттер координаты z
        double getZ() const;

        //Сеттер координаты x
        const Vector3D& setX(double x = 0);
        //Сеттер координаты y
        const Vector3D& setY(double y = 0);
        //Сеттер координаты z
        const Vector3D& setZ(double z = 0);

        //Вычисление модуля вектора
        double module() const;
        //Копирование вектора - возвращает вызываемый экземпляр
        const Vector3D& copyVector(const Vector3D& fromVec);
        //Перегрузка оператора* для умножения вектора на скаляр
        friend Vector3D operator*(const Vector3D& A, const double k);
        //Нормирование вектора
        const Vector3D& normVec();
       

        //Сложение трёхмерных векторов
        friend Vector3D operator+(const Vector3D& A, const Vector3D& B);
        //Разность для трёхмерных векторов
        friend Vector3D operator-(const Vector3D& A, const Vector3D& B);
        //Векторное произведение трёхмерных векторов
        friend Vector3D operator*(const Vector3D& A, const Vector3D& B);

        //Скалярное произведение трёхмерных векторов
        friend double scalarProduct(const Vector3D& A, const Vector3D& B);
        //Косинус угла между трёхмерными векторами
        friend double cos(const Vector3D& A, const Vector3D& B);
        //Синус угла между трёхмерными векторами
        friend double sin(const Vector3D& A, const Vector3D& B);
        //Значение угла между трёхмерными векторами
        friend double valAngle(const Vector3D& A, const Vector3D& B);

        //Вывод в консоль трёхмерного вектора
        friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);
        //Ввод данных через консоль в инициализированный трёхмерный вектор
        friend std::istream& operator>>(std::istream& in, Vector3D& vec);
    };
}
