#pragma once

#include <QString>


namespace StyleSheetsGUI {

    const QString menuBarStyle(
            "QMenuBar{background-color: #161616; color: #DCE4FF; font-size: 16px; font-family: Consolas, 'Courier New', monospace; font-size: 16px;} "
            "QMenuBar::item::selected{background-color: #161616;  color: #4050ff;}"
            );

    const QString menuStyle(
            "QMenu{background-color: #161616; color: #DCE4FF; font-size: 16px; border: 1px solid #4050ff; font-family: Consolas, 'Courier New', monospace; font-size: 16px;}"
            "QMenu::item::selected{background-color: #161616; color: #4050ff;}"
            );

    const QString editorStyle(
            "QTextEdit{background-color: #262626; color: #A4B9FF; "
            "border-left: 1px solid  #161616; border-top: none; border-bottom: none; border-right: none; "
            "font-family: Consolas, 'Courier New', monospace; font-size: 16px;}"
            );

    const QString stackWidgetStyle(
            "QStackedWidget{border: none;"
            "background-color: transparent;}"
            );
    const QString widgetStyle(
            "QWidget{border: none;"
            "background-color: #161616;}"
            );

    const QString editorButtonStyle(
            "QPushButton{border: 1px solid #161616; background-color: #262626; color: white;"
            "font-family: Consolas, 'Courier New', monospace; font-size: 16px; border-top: none; border-right:none;} "
            "QPushButton::hover{border: none; background-color: #161616; color: white;}"
            );

    const QString currentEditorButtonStyle(
            "QPushButton{border: 1px solid #161616; background-color: #161616; color: #4050ff;"
            "font-family: Consolas, 'Courier New', monospace; font-size: 16px; border-top: none; border-right:none;} "
            "QPushButton::hover{border: none; background-color: #161616; color: #4050ff;}"
            );

}


namespace CPPFormat {



}

