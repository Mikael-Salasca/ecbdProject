#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QString>
#include <QLineEdit>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>


#include "charger_csv.h"
class MaFenetre : public QMainWindow
{
    Q_OBJECT // Macro OBLIGATOIRE
public slots :
    void setQuitter();
    void predict();


public :
    MaFenetre(QWidget *parent = 0);

private :
    QLabel *m_lab1, *m_lab2, *m_lab3, *labelname, *labelprename, *title,
    *maladielabel, *maladieresult;
    QPushButton *m_bou, *predire;
    QComboBox *m_com1,*m_com2, *m_com3;
    QLineEdit *nom, *prenom;
    QTableWidget *m_tablewidget;

    QString couleur;
    CVString m_vet;
    CMatString m_mat;
    QString getHeader(int row);
    void setItems(int row, QComboBox *combo); 
    float calcFreq(string maladie);
    float calcFreq(string maladie, string sympt, int col);
    vector<string> getMaladies();

    float calcConf(string maladie, string sympt, int col);




};

#endif // MAFENETRE_H
