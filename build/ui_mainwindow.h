/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "imageLabel/qimagelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QImageLabel *label;
    QPushButton *captureBtn;
    QPushButton *openFileBtn;
    QLabel *label_mousePos;
    QPushButton *lastBtn;
    QPushButton *refreshBtn;
    QRadioButton *radioButton_org;
    QRadioButton *radioButton_diff;
    QRadioButton *radioButton_readFile;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(787, 572);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QImageLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 640, 480));
        label->setFrameShape(QFrame::Box);
        captureBtn = new QPushButton(centralWidget);
        captureBtn->setObjectName(QStringLiteral("captureBtn"));
        captureBtn->setGeometry(QRect(660, 10, 89, 25));
        openFileBtn = new QPushButton(centralWidget);
        openFileBtn->setObjectName(QStringLiteral("openFileBtn"));
        openFileBtn->setGeometry(QRect(660, 50, 101, 25));
        label_mousePos = new QLabel(centralWidget);
        label_mousePos->setObjectName(QStringLiteral("label_mousePos"));
        label_mousePos->setGeometry(QRect(660, 90, 111, 41));
        label_mousePos->setFrameShape(QFrame::Box);
        lastBtn = new QPushButton(centralWidget);
        lastBtn->setObjectName(QStringLiteral("lastBtn"));
        lastBtn->setGeometry(QRect(660, 140, 89, 25));
        refreshBtn = new QPushButton(centralWidget);
        refreshBtn->setObjectName(QStringLiteral("refreshBtn"));
        refreshBtn->setGeometry(QRect(660, 180, 89, 25));
        radioButton_org = new QRadioButton(centralWidget);
        radioButton_org->setObjectName(QStringLiteral("radioButton_org"));
        radioButton_org->setGeometry(QRect(660, 230, 112, 23));
        radioButton_org->setChecked(false);
        radioButton_diff = new QRadioButton(centralWidget);
        radioButton_diff->setObjectName(QStringLiteral("radioButton_diff"));
        radioButton_diff->setGeometry(QRect(660, 260, 112, 23));
        radioButton_readFile = new QRadioButton(centralWidget);
        radioButton_readFile->setObjectName(QStringLiteral("radioButton_readFile"));
        radioButton_readFile->setGeometry(QRect(660, 300, 112, 23));
        radioButton_readFile->setChecked(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 787, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        captureBtn->setText(QApplication::translate("MainWindow", "\346\213\215\347\205\247", Q_NULLPTR));
        openFileBtn->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\345\203\217\346\226\207\344\273\266", Q_NULLPTR));
        label_mousePos->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        lastBtn->setText(QApplication::translate("MainWindow", "\344\270\213\344\270\200\345\274\240", Q_NULLPTR));
        refreshBtn->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\350\203\214\346\231\257", Q_NULLPTR));
        radioButton_org->setText(QApplication::translate("MainWindow", "\345\216\237\345\233\276", Q_NULLPTR));
        radioButton_diff->setText(QApplication::translate("MainWindow", "\345\216\273\350\203\214\346\231\257\345\233\276", Q_NULLPTR));
        radioButton_readFile->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
