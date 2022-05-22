

#ifndef BILLBOARD_TECHNIQUE_H
#define	BILLBOARD_TECHNIQUE_H

#include "technique.h"
#include "math_3d.h"
/*интерфейс дл€ метода billboard. ќн требует только 3 параметра дл€ работы: 
комбинаци€ матрицы проекции, позици€ камеры в мировом пространстве и номер модул€ текстуры, 
к которому будет прив€зана текстура billboard.*/
class BillboardTechnique : public Technique 
{
public:
    
    BillboardTechnique();
 
    virtual bool Init();
    
    void SetVP(const Matrix4f& VP);
    void SetCameraPosition(const Vector3f& Pos);
    void SetColorTextureUnit(unsigned int TextureUnit);
    
private:

    GLuint m_VPLocation;
    GLuint m_cameraPosLocation;
    GLuint m_colorMapLocation;
};

#endif	/* BILLBOARD_TECHNIQUE_H */

