#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QToolBox>

#include <QGridLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

#include <QSqlTableModel>
#include "database.h"
#include "tablemodel.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    bool flagDB;
    QString txtAll[25];
    QString txt[26];
    QString tmpCurrentPath;

    QWidget* page;
    QGridLayout* layout;

    QLabel* textLabel;
    QTextEdit* textEdit;

    void checkDefaultDB();

    ~MainWindow();

private slots:
    void on_pushButtonOpenDB_clicked();
    void on_pushButtonSaveDB_clicked();
    void on_pushButtonResetDB_clicked();

    void on_pushButtonClear_clicked();

private:
    Ui::MainWindow *ui;
    DataBase    *db;
    TableModel  *model;

private:
    void writeDB();
    void readDB();
    void updateUI();
    void createUI();
};
#endif // MAINWINDOW_H
