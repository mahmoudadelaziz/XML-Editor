#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Load_B_clicked();

    void on_Detect_B_clicked();

    void on_Convert_B_clicked();

    void on_Format_B_clicked();

    void on_Save_B_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H