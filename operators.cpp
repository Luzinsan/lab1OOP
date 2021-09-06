#include "Vector3D.h"
#define _USE_MATH_DEFINES
#include <math.h>


Vector3D operator+(Vector3D& A, Vector3D& B) 
{
	return Vector3D(A.m_x+B.m_x, A.m_y + B.m_y, A.m_z + B.m_z);
}

Vector3D operator-(Vector3D& A, Vector3D& B)
{
	return Vector3D(A.m_x - B.m_x, A.m_y - B.m_y, A.m_z - B.m_z);
}

Vector3D operator*(const Vector3D& A, const Vector3D& B)
{
	return Vector3D(A.m_y * B.m_z - A.m_z * B.m_y, A.m_z * B.m_x - A.m_x * B.m_z, A.m_x * B.m_y - A.m_y * B.m_x);
}


std::ostream& operator<<(std::ostream& out, const Vector3D& vec)
{
    out << "(" << vec.m_x << ", " << vec.m_y << ", " << vec.m_z << ")";
    return out;
}

/*std::ostream& operator<<(std::ostream& out, std::vector<double> vec)
{
    out << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")";
    return out;
}*/

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


double scalarProduct(const Vector3D& A, const Vector3D& B)
{
    return A.m_x * B.m_x + A.m_y * B.m_y + A.m_z * B.m_z;
}

double cos(const Vector3D& A, const Vector3D& B)
{
    return scalarProduct(A, B) / (A.module() * B.module());
}

double sin(const Vector3D& A, const Vector3D& B)
{
    return (A * B).module() / (A.module() * B.module());
}

double valAngle(const Vector3D& A, const Vector3D& B)
{
   // float angleA = atan2(A.m_y, A.m_x);
    //float angleB = atan2(B.m_y, B.m_x);
    //double angle = abs(angleA) > abs(angleB) ? angleA - angleB : angleB - angleA;
    double angle = atan2(A.m_y, A.m_x) - atan2(B.m_y, B.m_x);
    if (angle > M_PI) { angle -= 2 * M_PI; }
    else if (angle <= -M_PI) { angle += 2 * M_PI; }
    return angle * 180 / M_PI;
}