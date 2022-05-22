

#ifndef PARTICLE_SYSTEM_H
#define	PARTICLE_SYSTEM_H

#include <GL/glew.h>

#include "ps_update_technique.h"
#include "random_texture.h"
#include "billboard_technique.h"
#include "texture.h"
/*Класс системы частиц инкапсулирует всю механику взаимодействия буферов transform feedback. 
Один экземпляр этого класса создается приложением и инициализирует в мировых координатах пусковую частицу. 
В главном цикле рендера будет вызываться функция ParticleSystem::Render() с тремя входящими параметрами: 
время, прошедшшее с последнего вызова, в милисикундах, произвдение матриц обзора и проекции и позиция камеры 
в мировом пространстве.*/
class ParticleSystem
{
public:
    ParticleSystem();
    
    ~ParticleSystem();
    
    bool InitParticleSystem(const Vector3f& Pos);
    
    void Render(int DeltaTimeMillis, const Matrix4f& VP, const Vector3f& CameraPos);
    
private:
    
    void UpdateParticles(int DeltaTimeMillis);
    void RenderParticles(const Matrix4f& VP, const Vector3f& CameraPos);
    
    bool m_isFirst;
    unsigned int m_currVB;
    unsigned int m_currTFB;
    GLuint m_particleBuffer[2];
    GLuint m_transformFeedback[2];
    PSUpdateTechnique m_updateTechnique;
    BillboardTechnique m_billboardTechnique;
    RandomTexture m_randomTexture;
    Texture* m_pTexture;
    int m_time;
};

#endif	/* PARTICLE_SYSTEM_H */

