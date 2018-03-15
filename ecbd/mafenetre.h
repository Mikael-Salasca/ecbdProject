#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QString>
#include "charger_csv.h"
class MaFenetre : public QMainWindow
{
    Q_OBJECT // Macro OBLIGATOIRE
public slots :
    void setQuitter();
public :
    MaFenetre(QWidget *parent = 0);

private :
    QLabel *m_lab1, *m_lab2, *m_lab3;
    QPushButton *m_bou;
    QComboBox *m_com1,*m_com2, *m_com3;


    QString couleur;
    CVString m_vet;
    CMatString m_mat;
    void fillComboBox(int row, QLabel *labelnum, QComboBox *combonum);

};

#endif // MAFENETRE_H
