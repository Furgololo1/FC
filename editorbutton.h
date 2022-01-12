#ifndef EDITORBUTTON_H
#define EDITORBUTTON_H

#include <QPushButton>


class EditorButton : public QPushButton
{

    int editorIndex = 0;

public:
    EditorButton(){}
    ~EditorButton(){}

    void SetEditorIndex(int i){    editorIndex = i;    }
    int GetEditorIndex(){   return editorIndex;     }


};

#endif // EDITORBUTTON_H
