#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Undo_clicked() {
    text_editor.undo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(text_editor.getText().c_str());
    ui->textEdit->blockSignals(false);
}

void MainWindow::on_Redo_clicked() {
    text_editor.redo();
    ui->textEdit->blockSignals(true);
    ui->textEdit->setPlainText(text_editor.getText().c_str());
    ui->textEdit->blockSignals(false);
}

void MainWindow::on_textEdit_textChanged() {
    text_editor.replace(ui->textEdit->toPlainText().toStdString(), 0, text_editor.getText().length());
}

