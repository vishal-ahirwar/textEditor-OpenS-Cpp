//Copyright(c) 2022 Vishal Ahirwar. All rights reserved.
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<iostream>
#include<QFileDialog>
#include<QTextStream>
MainWindow::MainWindow(const std::string&title,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString(title.c_str()));
    QObject::connect(ui->actionopen,&QAction::triggered,[&]()->void{
        const auto file_path=QFileDialog::getOpenFileName(this,"Open File...");
        QFile file(file_path);
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            ui->src->setPlainText(stream.readAll());
        };

    });
    QObject::connect(ui->actionsave,&QAction::triggered,[&](){
        const auto file_path=QFileDialog::getSaveFileName(this,"Save File as");
        QFile file(file_path);
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            const auto src_text=ui->src->toPlainText();
            stream<<src_text;

        }
    });
    QObject::connect(ui->actioncreate,&QAction::triggered,[&]()->void{
        ui->src->appendPlainText(std::move(QString("Create Action Called!")));
    }
    );
    QObject::connect(ui->actionQuit,&QAction::triggered,[&](){
        std::exit(0);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

