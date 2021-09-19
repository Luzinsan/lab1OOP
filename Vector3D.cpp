#include "Vector3D.h"
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#include <math.h>

namespace luMath
{
    int Vector3D::m_idVector3D = 1;

    Vector3D::Vector3D(double x, double y, double z) : m_x{ x }, m_y{ y }, m_z{ z }, m_id{ m_idVector3D++ }
    {  std::cout << "Constructor - Vector ¹" << m_id << std::endl; }

    Vector3D::~Vector3D() { std::cout << "Destructor - Vector ¹" << m_id << std::endl; }

    double Vector3D::getX() const { return m_x; };
    double Vector3D::getY() const { return m_y; };
    double Vector3D::getZ() const { return m_z; };

    const Vector3D& Vector3D::setX(double x) { m_x = x; return *this; };
    const Vector3D& Vector3D::setY(double y) { m_y = y; return *this; };
    const Vector3D& Vector3D::setZ(double z) { m_z = z; return *this; };

    double Vector3D::module() const { return sqrt(m_x * m_x + m_y * m_y + m_z * m_z); }

    const Vector3D& Vector3D::copyVector(const Vector3D& fromVec)
    {
        m_x = fromVec.m_x;
        m_y = fromVec.m_y;
        m_z = fromVec.m_z;
        return *this;
    }
    
    const Vector3D& Vector3D::normVec()
    {
        double moduleVec = module();
        m_x /= moduleVec;
        m_y /= moduleVec;
        m_z /= moduleVec;
        return *this;
    }


    Vector3D operator+(const Vector3D& A, const Vector3D& B) { return Vector3D(A.m_x + B.m_x, A.m_y + B.m_y, A.m_z + B.m_z); }
    Vector3D operator-(const Vector3D& A, const Vector3D& B) { return Vector3D(A.m_x - B.m_x, A.m_y - B.m_y, A.m_z - B.m_z); }

    Vector3D operator*(const Vector3D& A, const Vector3D& B)
    {
        return Vector3D(A.m_y * B.m_z - A.m_z * B.m_y,
                        A.m_z * B.m_x - A.m_x * B.m_z,
                        A.m_x * B.m_y - A.m_y * B.m_x);
    }
    Vector3D operator*(const Vector3D& A, const double k) { return Vector3D(A.m_x * k, A.m_y * k, A.m_z * k); }


    std::ostream& operator<<(std::ostream& out, const Vector3D& vec)
    {
        out << "Vector ¹"<< vec.m_id <<" (" << vec.m_x << ", " << vec.m_y << ", " << vec.m_z << ")";
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


    double scalarProduct(const Vector3D& A, const Vector3D& B) { return A.m_x * B.m_x + A.m_y * B.m_y + A.m_z * B.m_z; }
    double cos(const Vector3D& A, const Vector3D& B) { return scalarProduct(A, B) / (A.module() * B.module()); }
    double sin(const Vector3D& A, const Vector3D& B) { return (A * B).module() / (A.module() * B.module()); }

    double valAngle(const Vector3D& A, const Vector3D& B) { return atan2((A*B).module(), scalarProduct(A, B)) * 180 / M_PI; }

}

#endif
