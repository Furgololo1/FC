#pragma once

#include <QString>


namespace StyleSheetsGUI {

    const QString windowStyle(
            "QMainWindow{border: none; background-color: #262626; }"
            );

    const QString menuBarStyle(
            "QMenuBar{background-color: #161616; color: #DCE4FF; font-size: 16px; font-family: Consolas, 'Courier New', monospace; font-size: 16px;} "
            "QMenuBar::item::selected{background-color: #161616;  color: #318AFF;}"
            );

    const QString menuStyle(
            "QMenu{background-color: #161616; color: #DCE4FF; font-size: 16px; border: 1px solid #318AFF; font-family: Consolas, 'Courier New', monospace; font-size: 16px;}"
            "QMenu::item::selected{background-color: #161616; color: #318AFF;}"
            );

    const QString editorStyle(
            "QPlainTextEdit{background-color: #262626; color: #EAF8F8; "
            "border: 1px solid #318AFF; }"
            "QScrollBar:vertical {"
             "    border: none;"
                 "background: #262626;"
                 "width: 15px;"
                 "margin: 22px 0 22px 0;"
             "}"
             "QScrollBar::handle:vertical {"
                 "background: #318AFF;"
                 "min-height: 20px;"
             "}"
             "QScrollBar::add-line:vertical {"
                 "border: 1px solid #318AFF;"
                 "background: #262626;"
                 "height: 20px;"
                 "subcontrol-position: bottom;"
                 "subcontrol-origin: margin;"
             "}"
            "QScrollBar::sub-line:vertical {"
                 "border: 1px solid #318AFF;"
                 "background: #262626;"
                 "height: 20px;"
                 "subcontrol-position: top;"
                 "subcontrol-origin: margin;"
             "}"
             "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {"
                 "border: 2px solid #262626;"
                 "width: 3px;"
                 "height: 3px;"
                 "background: transparent;"
             "}"

             "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
                 "background: none;"
             "}"
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
            "QPushButton{border: 1px solid #161616; background-color: #161616; color: #318AFF;"
            "font-family: Consolas, 'Courier New', monospace; font-size: 16px; border-top: none; border-right:none;} "
            "QPushButton::hover{border: none; background-color: #161616; color: #318AFF;}"
            );

    const QString lineNumberStyle(
            "QLabel{ border-top: 1px solid  #318AFF; border-bottom: none; border-right: none; border-left: none;"
            "background-color: #161616; color: white;}"
            );

}


namespace CPPFormat {



}

/*QComboBox QAbstractItemView::item {
    height: 25px;
}

QListView::item {
    background: white;
}

QListView::item:hover {
    background: #BDD7FD;
}

QComboBox::drop-down {
    subcontrol-origin: padding;
    subcontrol-position: top right;
    width: 20px;

    border-left-width: 1px;
    border-left-color: darkgray;
    border-left-style: solid;
    border-top-right-radius: 3px;
    border-bottom-right-radius: 3px;
}

QComboBox::down-arrow {
    image: url(:/images/images/CBArrow.png);
}

QComboBox {
    border: 1px solid gray;
    border-radius: 3px;
    padding: 1px 2px 1px 2px; # For the text content in the combo box
    min-width: 9em; # The minimum width of the combo box
}
*/

