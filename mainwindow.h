#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "history_revisions.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_Undo_clicked();

    void on_Redo_clicked();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
    EditHistory text_editor;
};
#endif // MAINWINDOW_H
