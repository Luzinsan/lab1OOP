#include "Vector3D.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace luzalex 
{

    Vector3D const operator+(const Vector3D& A, const Vector3D& B)
    {
        return Vector3D(A.m_x + B.m_x, A.m_y + B.m_y, A.m_z + B.m_z);
    }

    const Vector3D operator-(const Vector3D& A, const Vector3D& B)
    {
        return Vector3D(A.m_x - B.m_x, A.m_y - B.m_y, A.m_z - B.m_z);
    }

    Vector3D const operator*(const Vector3D& A, const Vector3D& B)
    {
        return Vector3D(A.m_y * B.m_z - A.m_z * B.m_y,
            A.m_z * B.m_x - A.m_x * B.m_z,
            A.m_x * B.m_y - A.m_y * B.m_x);
    }


    std::ostream& operator<<(std::ostream& out, const Vector3D& vec)
    {
        out << "(" << vec.m_x << ", " << vec.m_y << ", " << vec.m_z << ")";
        return out;
    }


    std::istream& operator>>(std::istream& in, Vector3D& vec)
    {
        std::cout << "x = ";
        in >> vec.m_x;
        std::cout << "y = ";
        in >> vec.m_y;
        std::cout << "z = ";
        in >> vec.m_z;
        std::cout << std::endl;

        return in;
    }


    const double scalarProduct(const Vector3D& A, const Vector3D& B)
    { return A.m_x * B.m_x + A.m_y * B.m_y + A.m_z * B.m_z; }

    const double cos(const Vector3D& A, const Vector3D& B)
    { return scalarProduct(A, B) / (A.module() * B.module()); }

    const double sin(const Vector3D& A, const Vector3D& B)
    { return (A * B).module() / (A.module() * B.module()); }

    const double valAngle(const Vector3D& A, const Vector3D& B)
    { return atan2(sin(A, B), cos(A, B)) * 180 / M_PI; }
}
