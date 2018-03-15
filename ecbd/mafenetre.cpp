#include "mafenetre.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>


MaFenetre::MaFenetre(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(800,600);
    m_bou = new QPushButton("Quitter", this);
    m_bou->setGeometry(600,400,80,40);

    connect(m_bou, SIGNAL(clicked()), this, SLOT(setQuitter()));
    //    connect(m_com, SIGNAL(currentIndexChanged(const QString &)),
    //            this, SLOT(setCouleur()));

    read_csv (m_mat, m_vet, "data.csv");
    fillComboBox(0,m_lab1,m_com1); // 1re colonne pour 1 combobox
    fillComboBox(1,m_lab2,m_com2); // 1re colonne pour 1 combobox
    fillComboBox(2,m_lab3,m_com3); // 1re colonne pour 1 combobox

}
void MaFenetre::setQuitter()
{
    exit(0);
}


void MaFenetre::fillComboBox(int i, QLabel *labelnum, QComboBox *combonum) {

    // en-tête
    QString qs = QString::fromUtf8(m_vet[i].c_str());
    labelnum = new QLabel(qs,this);
    labelnum->setFont(QFont("Arial", 12, QFont::Bold, true));
    labelnum->move(100,200);


    combonum = new QComboBox(this);
    combonum->setGeometry(300,150,100,30);

    // items
    combonum->addItem("NULL");
    combonum->setCurrentIndex(0);
    CVString myItems;
    for(unsigned j=0; j < m_mat.size(); j++)
    {
        string s = m_mat[j][i];
        if (std::find(myItems.begin(), myItems.end(), s) == myItems.end())
        {
            combonum->addItem(QString::fromUtf8(s.c_str()));
            myItems.push_back(s);

        }



}



}

