#ifndef GRAPHICS_PLANE_H
#define GRAPHICS_PLANE_H

#include "Geometry.h"

class Plane : public Geometry {
public:
    Plane(const Vector3& origin, const Vector3& normal, Material* mat):
        normal(normal), origin(origin), material(mat) {}

    virtual bool hit(const Ray& r, const float t_min, const float t_max, HitRecord& rec) const
    {
        const float denom = -dot(normal, r.direction());
        if(denom > 1e-6)
        {
            const float t = dot(normal, r.origin() - origin) / denom;
            if(t_min < t && t < t_max)
            {
                rec.t            = t;
                rec.point_at_t   = r.point_at_t(rec.t);
                rec.normal       = normal;
                rec.material_ptr = material;
                return true;
            }
            return false;
        }
        return false;
    }
    Vector3   normal;
    Vector3   origin;
    Material* material;
};

#endif
