

#ifndef GBUFFER_H
#define	GBUFFER_H

#include <GL/glew.h>
/*Класс GBuffer содержит все текстуры, которые потребуются для deferred shading. 
У нас есть текстуры для аттрибутов вершин, и еще текстура для буффера глубины.
добавили итоговую текстуру в класс GBuffer для цвета*/
class GBuffer
{
public:

    enum GBUFFER_TEXTURE_TYPE {
            GBUFFER_TEXTURE_TYPE_POSITION,
            GBUFFER_TEXTURE_TYPE_DIFFUSE,
            GBUFFER_TEXTURE_TYPE_NORMAL,
            GBUFFER_NUM_TEXTURES
    };

    GBuffer();

    ~GBuffer();

    bool Init(unsigned int WindowWidth, unsigned int WindowHeight);

    void StartFrame();
    void BindForGeomPass();
    void BindForStencilPass();
    void BindForLightPass();
    void BindForFinalPass();

private:

    GLuint m_fbo;
    GLuint m_textures[GBUFFER_NUM_TEXTURES];
    GLuint m_depthTexture;
    GLuint m_finalTexture;
};

#endif	/* SHADOWMAPFBO_H */

