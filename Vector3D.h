#pragma once
#include <iostream>

class Vector3D
{
private:
    double m_x, m_y, m_z;

public:
    //����������� ��� ������ uniform ������������� 1) ����-������� �� ��������� ��� 2) ������� � ����������������� ����������
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0): m_x{ x }, m_y{ y }, m_z{ z }
    { std::cout << "Constructor - Done\n"; }

    //����������
    ~Vector3D(){ std::cout << "Destructor - Done\n"; }

    //������ ���������� x
    double getX() const;
    //������ ���������� y
    double getY() const;
    //������ ���������� z
    double getZ() const;

    //������ ��������� �������
    Vector3D& setItems(double x = 0, double y = 0, double z = 0);

    //���������� ������ �������
    double module() const;

    //����������� ������� - ���������� ���������� ������
    Vector3D& copyVector(Vector3D& toVec);

    //��������� ������� �� ������
    Vector3D& mltpToScal(double scal);

    //������������ �������
    Vector3D& normVec();

    //������������� ������� ���������� ���������+ ��� ��������� ��������
    friend Vector3D operator+(Vector3D& A, Vector3D& B);

    //������������� ������� ���������� ���������- ��� ��������� ��������
    friend Vector3D operator-(Vector3D& A, Vector3D& B);

    //������������� ������� ���������� ���������* ��� ���������� ������������ ��������� ��������
    friend Vector3D operator*(const Vector3D& A, const Vector3D& B);

    //������������� �������, ������������ ��������� ������������ ���� ��������� ��������
    friend double scalarProduct(const Vector3D& A, const Vector3D& B);

    //������������� �������, ������������ ������� ���� ���� ��������� ��������
    friend double cos(const Vector3D& A, const Vector3D& B);

    //������������� �������, ������������ ����� ���� ���� ��������� ��������
    friend double sin(const Vector3D& A, const Vector3D& B);

    //������������� �������, ������������ �������� ���� ����� ����� ���������� ���������
    friend double valAngle(const Vector3D& A, const Vector3D& B);

    friend std::ostream& operator<<(std::ostream& out, const Vector3D& vec);

    friend std::istream& operator>>(std::istream& in, Vector3D& vec);

    Vector3D& print();
};