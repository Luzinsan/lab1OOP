#include "Vector3D.h"


namespace luzalex 
{

    int Vector3D::m_idVector3D = 1;

    const double Vector3D::getX() const { return m_x; };
    const double Vector3D::getY() const { return m_y; };
    const double Vector3D::getZ() const { return m_z; };

    const Vector3D& Vector3D::setItems(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
        return *this;
    }

    const double Vector3D::module() const
    {
        return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
    }

    const Vector3D& Vector3D::copyVector(Vector3D& toVec) const
    {
        toVec.m_x = m_x;
        toVec.m_y = m_y;
        toVec.m_z = m_z;
        return toVec;
    }
    const Vector3D& Vector3D::mltpToScal(const double scal)
    {
        m_x *= scal;
        m_y *= scal;
        m_z *= scal;
        return *this;
    }
    const Vector3D& Vector3D::operator*(const double scal)
    {
        m_x *= scal;
        m_y *= scal;
        m_z *= scal;
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

    const Vector3D& Vector3D::print() const
    {
        std::cout << "Vector(" << m_x << ", " << m_y << ", " << m_z << ")\n";
        return *this;
    }
}
