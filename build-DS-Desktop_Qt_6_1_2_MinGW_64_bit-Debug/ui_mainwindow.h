/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *Detect_B;
    QTextBrowser *Original;
    QTextBrowser *Edited;
    QPushButton *Convert_B;
    QPushButton *Load_B;
    QPushButton *Save_B;
    QPushButton *Format_B;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1414, 776);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Detect_B = new QPushButton(centralwidget);
        Detect_B->setObjectName(QString::fromUtf8("Detect_B"));
        Detect_B->setGeometry(QRect(230, 10, 201, 81));
        Original = new QTextBrowser(centralwidget);
        Original->setObjectName(QString::fromUtf8("Original"));
        Original->setGeometry(QRect(10, 130, 681, 531));
        Edited = new QTextBrowser(centralwidget);
        Edited->setObjectName(QString::fromUtf8("Edited"));
        Edited->setGeometry(QRect(710, 130, 681, 531));
        Convert_B = new QPushButton(centralwidget);
        Convert_B->setObjectName(QString::fromUtf8("Convert_B"));
        Convert_B->setGeometry(QRect(600, 10, 201, 81));
        Load_B = new QPushButton(centralwidget);
        Load_B->setObjectName(QString::fromUtf8("Load_B"));
        Load_B->setGeometry(QRect(100, 680, 191, 71));
        Save_B = new QPushButton(centralwidget);
        Save_B->setObjectName(QString::fromUtf8("Save_B"));
        Save_B->setGeometry(QRect(610, 680, 191, 71));
        Format_B = new QPushButton(centralwidget);
        Format_B->setObjectName(QString::fromUtf8("Format_B"));
        Format_B->setGeometry(QRect(960, 10, 201, 81));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 110, 181, 16));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(970, 110, 181, 21));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1414, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Detect_B->setText(QCoreApplication::translate("MainWindow", "Detect Errors", nullptr));
        Convert_B->setText(QCoreApplication::translate("MainWindow", "Convert to JSON", nullptr));
        Load_B->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        Save_B->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Format_B->setText(QCoreApplication::translate("MainWindow", "Format", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Original", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Edited", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
