/*
* Copyright (C) 2007-2012 German Aerospace Center (DLR/SC)
*
* Created: 2012-08-02 Martin Siggel <Martin.Siggel@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
//////////////////////////////////////////////////////////////////////
//
// ISession_Text.h: interface for the ISession_Text class.
//
//////////////////////////////////////////////////////////////////////

#ifndef AFX_ISESSION_TEXT_H__A9B277C4_A69E_11D1_8DA4_0800369C8A03__INCLUDED_
#define AFX_ISESSION_TEXT_H__A9B277C4_A69E_11D1_8DA4_0800369C8A03__INCLUDED_
#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <AIS_InteractiveObject.hxx>

#include <TCollection_AsciiString.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Aspect_TypeOfText.hxx>
#include <Standard_Real.hxx>
#include <Standard_Integer.hxx>
#include <Quantity_Factor.hxx>
#include <Quantity_PlaneAngle.hxx>
#include <Handle_SelectMgr_Selection.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Standard_CString.hxx>
#include <SelectMgr_SelectableObject.hxx>

#if 0
#include <Handle_PrsMgr_PresentationManager2d.hxx>
#include <Handle_Graphic2d_GraphicObject.hxx>
class PrsMgr_PresentationManager2d;
class Graphic2d_GraphicObject;
#endif

class TCollection_AsciiString;
class SelectMgr_Selection;

DEFINE_STANDARD_HANDLE(ISession_Text,AIS_InteractiveObject)
class ISession_Text : public AIS_InteractiveObject  
{
public:
    ISession_Text();

    ISession_Text           (const TCollection_AsciiString& aText,
                             const Standard_Real            anX         = 0   ,
                             const Standard_Real            anY         = 0   ,
                             const Standard_Real            aZ          = 0   ,
                             const Aspect_TypeOfText        aType       = Aspect_TOT_SOLID,
                             const Quantity_PlaneAngle      anAngle     = 0.0 ,
                             const Standard_Real            aSlant      = 0.0 ,
                             const Standard_Integer         aColorIndex = 1   ,
                             const Standard_Integer         aFontIndex  = 1   ,
                             const Quantity_Factor          aScale      = 0.1   );
    ISession_Text
                            (const TCollection_AsciiString& aText, 
                             gp_Pnt&                        aPoint,
                             const Aspect_TypeOfText        aType       = Aspect_TOT_SOLID,
                             const Quantity_PlaneAngle      anAngle     = 0.0 ,
                             const Standard_Real            aSlant      = 0.0 ,
                             const Standard_Integer         aColorIndex = 1   ,
                             const Standard_Integer         aFontIndex  = 1   ,
                             const Quantity_Factor          aScale      = 0.1   );

    virtual ~ISession_Text();

    inline   Standard_Integer        NbPossibleSelection() const;
    inline   TCollection_ExtendedString GetText() const;
    inline   void                    SetText(const TCollection_ExtendedString& atext) ;
    inline   void                    GetCoord(Standard_Real& X, Standard_Real& Y, Standard_Real& Z) const ;
    inline   void                    SetCoord(const Standard_Real X, const Standard_Real Y, const Standard_Real Z=0);
    inline   Aspect_TypeOfText       GetTypeOfText() const;
    inline   void                    SetTypeOfText(const Aspect_TypeOfText aNewTypeOfText) ;
    inline   Standard_Real           GetAngle() const;
    inline   void                    SetAngle(const Standard_Real aNewAngle) ;
    inline   Standard_Real           GetSlant() const;
    inline   void                    SetSlant(const Standard_Real aNewSlant) ;
    inline   Standard_Integer        GetColorIndex() const;
    inline   void                    SetColorIndex(const Standard_Integer aNewColorIndex) ;
    inline   Standard_Integer        GetFontIndex() const;
    inline   void                    SetFontIndex(const Standard_Integer aNewFontIndex) ;
    inline   Quantity_Factor         GetScale() const;
    inline   void                    SetScale  (const Quantity_Factor aNewScale) ;


DEFINE_STANDARD_RTTI(ISession_Text)


protected:


private: 

     // Methods PRIVATE
     // 
     
     void Compute          (const Handle(PrsMgr_PresentationManager3d)& aPresentationManager,
                            const Handle(Prs3d_Presentation)& aPresentation,
                            const Standard_Integer aMode);
     void Compute          (const Handle(Prs3d_Projector)& aProjector,
                            const Handle(Prs3d_Presentation)& aPresentation);
     #if 0
     void Compute          (const Handle(PrsMgr_PresentationManager2d)& aPresentationManager,
                            const Handle(Graphic2d_GraphicObject)& aGrObj,
                            const Standard_Integer unMode = 0) ;
     #endif
     void ComputeSelection (const Handle(SelectMgr_Selection)& aSelection,
                            const Standard_Integer unMode) ;
     
     
      // Fields PRIVATE
      //
     TCollection_ExtendedString MyText    ; 
     Standard_Real           MyX          ;
     Standard_Real           MyY          ;
     Standard_Real           MyZ          ;
     Aspect_TypeOfText       MyTypeOfText ;
     Standard_Real           MyAngle      ;
     Standard_Real           MySlant      ;
     Standard_Integer        MyColorIndex ;
     Standard_Integer        MyFontIndex  ;
     Quantity_Factor         MyScale      ;


};

inline Standard_Integer ISession_Text::NbPossibleSelection() const 
{ 
    return 1; 
}

inline TCollection_ExtendedString ISession_Text::GetText() const 
{  
    return MyText ; 
}

inline void ISession_Text::SetText(const TCollection_ExtendedString& atext)
{  
    MyText = atext; 
}

inline void ISession_Text::GetCoord(Standard_Real& X, Standard_Real& Y, Standard_Real& Z) const 
{  
    X = MyX;  
    Y = MyY; 
    Z = MyZ;
}

inline void ISession_Text::SetCoord(const Standard_Real X, const Standard_Real Y, const Standard_Real Z)
{  
    MyX = X ;  
    MyY = Y ;  
    MyZ = Z ;
}

inline Aspect_TypeOfText ISession_Text::GetTypeOfText() const 
{  
    return MyTypeOfText; 
}

inline void ISession_Text::SetTypeOfText(const Aspect_TypeOfText aNewTypeOfText)
{  
    MyTypeOfText = aNewTypeOfText; 
}

inline Standard_Real ISession_Text::GetAngle() const 
{  
    return MyAngle; 
}

inline void ISession_Text::SetAngle(const Standard_Real aNewAngle)
{  
    MyAngle = aNewAngle; 
}

inline Standard_Real ISession_Text::GetSlant() const 
{  
    return MySlant; 
}

inline void ISession_Text::SetSlant(const Standard_Real aNewSlant)
{  
    MySlant = aNewSlant; 
}

inline Standard_Integer ISession_Text::GetColorIndex() const 
{  
    return MyColorIndex; 
}

inline void ISession_Text::SetColorIndex(const Standard_Integer aNewColorIndex)
{  
    MyColorIndex = aNewColorIndex; 
}

inline Standard_Integer ISession_Text::GetFontIndex() const 
{ 
    return MyFontIndex; 
}

inline void ISession_Text::SetFontIndex(const Standard_Integer aNewFontIndex)
{  
    MyFontIndex = aNewFontIndex; 
}

inline Quantity_Factor ISession_Text::GetScale() const 
{  
    return MyScale; 
}

inline void ISession_Text::SetScale(const Quantity_Factor aNewScale)
{  
    MyScale  = aNewScale; 
}

#endif // !defined(AFX_ISESSION_TEXT_H__A9B277C4_A69E_11D1_8DA4_0800369C8A03__INCLUDED_)
