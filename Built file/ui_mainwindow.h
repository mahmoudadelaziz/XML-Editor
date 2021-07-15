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
#include <QtWidgets/QMainWindow>
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
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "XML Editor", nullptr));
        Detect_B->setText(QCoreApplication::translate("MainWindow", "Detect Errors", nullptr));
        Convert_B->setText(QCoreApplication::translate("MainWindow", "Convert to JSON", nullptr));
        Load_B->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
        Save_B->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Format_B->setText(QCoreApplication::translate("MainWindow", "Format", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
