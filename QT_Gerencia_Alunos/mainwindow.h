#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include<QFileDialog>
#include "aluno.h"
#include "turma.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Turma engenharia;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:
    void on_btn_insert_clicked();

    void on_btn_NameSort_clicked();

    void on_btn_GradeSort_clicked();

    bool carregar();

    bool salvar();

private:
    Ui::MainWindow *ui;
    void inserirAlunoNaTabela(Aluno aluno, int row);

};

#endif // MAINWINDOW_H
