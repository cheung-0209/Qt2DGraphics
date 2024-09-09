/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "drawwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLine;
    QAction *actionRectangle;
    QAction *actionEllipse;
    QAction *actionPolygon;
    QAction *actionFill;
    QAction *actionSelect;
    QAction *actionDelete;
    QAction *actionMove;
    QAction *actionChangeColor;
    QAction *actionCalculateArea;
    QAction *actionCalculateLength;
    QAction *actionNewCanvas;
    QAction *actionOpenCanvas;
    QAction *actionSaveCanvas;
    QWidget *centralwidget;
    DrawWidget *widget;
    QMenuBar *menubar;
    QMenu *menuShapes;
    QMenu *menuEdit;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName("actionLine");
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName("actionRectangle");
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName("actionEllipse");
        actionPolygon = new QAction(MainWindow);
        actionPolygon->setObjectName("actionPolygon");
        actionFill = new QAction(MainWindow);
        actionFill->setObjectName("actionFill");
        actionSelect = new QAction(MainWindow);
        actionSelect->setObjectName("actionSelect");
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName("actionMove");
        actionChangeColor = new QAction(MainWindow);
        actionChangeColor->setObjectName("actionChangeColor");
        actionCalculateArea = new QAction(MainWindow);
        actionCalculateArea->setObjectName("actionCalculateArea");
        actionCalculateLength = new QAction(MainWindow);
        actionCalculateLength->setObjectName("actionCalculateLength");
        actionNewCanvas = new QAction(MainWindow);
        actionNewCanvas->setObjectName("actionNewCanvas");
        actionOpenCanvas = new QAction(MainWindow);
        actionOpenCanvas->setObjectName("actionOpenCanvas");
        actionSaveCanvas = new QAction(MainWindow);
        actionSaveCanvas->setObjectName("actionSaveCanvas");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new DrawWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(6, 6, 16, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuShapes = new QMenu(menubar);
        menuShapes->setObjectName("menuShapes");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuShapes->menuAction());
        menubar->addAction(menu->menuAction());
        menuShapes->addAction(actionLine);
        menuShapes->addAction(actionRectangle);
        menuShapes->addAction(actionEllipse);
        menuShapes->addAction(actionPolygon);
        menuEdit->addAction(actionSelect);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionMove);
        menuEdit->addAction(actionChangeColor);
        menu->addAction(actionCalculateArea);
        menu->addAction(actionCalculateLength);
        menu_2->addAction(actionNewCanvas);
        menu_2->addAction(actionOpenCanvas);
        menu_2->addAction(actionSaveCanvas);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\344\272\214\347\273\264\347\237\242\351\207\217\345\233\276\345\275\242\347\273\230\345\210\266\347\263\273\347\273\237", nullptr));
        actionLine->setText(QCoreApplication::translate("MainWindow", "\347\233\264\347\272\277", nullptr));
        actionRectangle->setText(QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242", nullptr));
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "\346\244\255\345\234\206", nullptr));
        actionPolygon->setText(QCoreApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242", nullptr));
        actionFill->setText(QCoreApplication::translate("MainWindow", "\347\237\251\345\275\242(\346\273\241)", nullptr));
        actionSelect->setText(QCoreApplication::translate("MainWindow", "\351\200\211\344\270\255", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        actionMove->setText(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250", nullptr));
        actionChangeColor->setText(QCoreApplication::translate("MainWindow", "\346\224\271\350\211\262", nullptr));
        actionCalculateArea->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\351\235\242\347\247\257", nullptr));
        actionCalculateLength->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\351\225\277\345\272\246", nullptr));
        actionNewCanvas->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        actionOpenCanvas->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        actionSaveCanvas->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuShapes->setTitle(QCoreApplication::translate("MainWindow", "\347\273\230\345\210\266", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\345\261\236\346\200\247", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
