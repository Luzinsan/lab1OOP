#include "Vector3D.h"
#include <math.h>


double Vector3D::getX() const { return m_x; };

double Vector3D::getY() const { return m_y; };

double Vector3D::getZ() const { return m_z; };

Vector3D& Vector3D::setItems(double x, double y, double z)
{
    m_x = x;
    m_y = y;
    m_z = z;
    return *this;
}

double Vector3D::module() const
{
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

Vector3D& Vector3D::copyVector(Vector3D& toVec)
{
    toVec.m_x = m_x;
    toVec.m_y = m_y;
    toVec.m_z = m_z;
    return *this;
}

Vector3D& Vector3D::mltpToScal(double scal)
{
    m_x *= scal;
    m_y *= scal;
    m_z *= scal;
    return *this;
}

Vector3D& Vector3D::normVec()
{
    double moduleVec = module();
    m_x /= moduleVec;
    m_y /= moduleVec;
    m_z /= moduleVec;
    return *this;
}

Vector3D& Vector3D::print()
{
    std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
    return *this;
}
