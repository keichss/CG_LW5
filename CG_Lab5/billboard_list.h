

#ifndef BILLBOARD_LIST_H
#define	BILLBOARD_LIST_H

#include <string>

#include "texture.h"
#include "billboard_technique.h"

class BillboardList
{
public:
    BillboardList();    
    ~BillboardList();
    
    bool Init(const std::string& TexFilename);
    
    void Render(const Matrix4f& VP, const Vector3f& CameraPos);

private:
    void CreatePositionBuffer();
    
    GLuint m_VB;
    Texture* m_pTexture;
    BillboardTechnique m_technique;
};
/*Класс BillboardList инкапсулирует все, что вам потребуется для генерации billboards. 
Функция класса Init() принимает как параметр имя файла, который содержит изображение, 
которое будет отображаться на billboard. Функция Render() вызывается из главного цикла рендера 
и заботится от установлении всех значений и рендере billboard. 
Этой функции нужны 2 параметра: комбинация матрицы проекции и позиция камеры в мировом пространстве.*/

#endif	/* BILLBOARD_LIST_H */

