#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionSalvar, SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionCarregar, SIGNAL(triggered()), this, SLOT(carregar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::atualizarEstatisticas()
{
    ui->lbl_avg->setText(QString::number(engenharia.mediaDaTurma(),'f',2));
    ui->lbl_highest->setText(QString::number(engenharia.maiorNota(),'f',2));
    ui->lbl_lowest->setText(QString::number(engenharia.menorNota(),'f',2));

    QString color = engenharia.mediaDaTurma() < 70 ? "red" : "black";
    ui->lbl_avg->setStyleSheet("color: "+color);

}

void MainWindow::inserirAlunoNaTabela(Aluno aluno, int row)
{
    ui->tbl_data->setItem(row,0,new QTableWidgetItem(aluno.getNome()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(aluno.getMedia())));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem(aluno.getStatus()));
}

bool MainWindow::carregar()
{
    qDebug() << "carregar\n";
    QString nome = QFileDialog::getOpenFileName(this, "Lista de Notas", "", "(*.txt)");
    QFile file(nome);
    if(!file.open(QIODevice::ReadOnly))
        return false;
    QTextStream in(&file);
    QString aux;
    int row = 0;
    while(in.readLineInto(&aux)){
        QString nome, media;
        float media_aux;
        Aluno auxiliar;
        int i=0;
        qDebug() << aux << "\n";
        while(aux[i]!=',')
            nome+=aux[i++];
        qDebug() << nome << "\n";
        i++;
        while(i<aux.size())
            media+=aux[i++];
        media_aux = media.toFloat();
        //qDebug() << media_aux << " " << nome << "\n";
        auxiliar.setNome(nome);
        auxiliar.setMedia(media_aux);
        int qnt_row = ui->tbl_data->rowCount();
        ui->tbl_data->insertRow(qnt_row);
        inserirAlunoNaTabela(auxiliar, row++);
    }

    file.close();
    return true;
}

bool MainWindow::salvar()
{
    qDebug() << "salvar\n";
    QString nome = QFileDialog::getSaveFileName(this, "Lista de Notas", "", "(*.txt)");
    QFile file(nome);
    if(!file.open(QIODevice::WriteOnly))
        return false;
    QTextStream out(&file);
    for (int i=0; i<engenharia.size(); i++)
        out << engenharia[i].getNome() << "," << engenharia[i].getMedia() << "\n";
    file.close();
    return true;
}

void MainWindow::on_btn_insert_clicked()
{

    if(ui->le_nameInput->text().size() != 0 && ui->le_avgInput->text().size() != 0){
        Aluno aluno;
        aluno.setNome(ui->le_nameInput->text());
        aluno.setMedia(ui->le_avgInput->text().toFloat());

        int qnt_row = ui->tbl_data->rowCount();
        ui->tbl_data->insertRow(qnt_row);

        inserirAlunoNaTabela(aluno, qnt_row);

        ui->le_nameInput->clear();
        ui->le_avgInput->clear();

        engenharia.inserirAluno(aluno);
        atualizarEstatisticas();
    }
}

void MainWindow::on_btn_NameSort_clicked()
{
    ui->tbl_data->clearContents();

    engenharia.ordenarPorNome();
    for(int i = 0; i<engenharia.size(); i++){
        inserirAlunoNaTabela(engenharia[i], i);
    }
}

void MainWindow::on_btn_GradeSort_clicked()
{
    ui->tbl_data->clearContents();
    engenharia.ordenarPorMedia();
    for(int i = 0; i<engenharia.size();i++){
        inserirAlunoNaTabela(engenharia[i],i);
    }
}
