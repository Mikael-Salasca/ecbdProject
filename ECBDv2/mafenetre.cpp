#include "mafenetre.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>


MaFenetre::MaFenetre(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(1000,800);
    read_csv (m_mat, m_vet, "data.csv");


    title = new QLabel("Classification des patients - Prediction", this);
    title->setFixedWidth(500);
    title->setFont(QFont("Arial", 15, QFont::Bold, true));
    title->move(10, 10);

    labelname = new QLabel("Nom : ", this);
    labelname->setFont(QFont("Arial", 12, QFont::Bold, true));
    labelname->move(750, 30);

    nom = new QLineEdit(this);
    nom->move(labelname->x()+75, 30);

    labelprename = new QLabel("Prenom : ", this);
    labelprename->setFont(QFont("Arial", 12, QFont::Bold, true));
    labelprename->move(750, 65);

    prenom = new QLineEdit(this);
    prenom->move(labelprename->x()+75, 65);

    maladielabel = new QLabel("Maladie : ", this);
    maladielabel->setFont(QFont("Arial", 12, QFont::Bold, true));
    maladielabel->move(50, 700); // x,y

    maladieresult = new QLabel("Aucune", this);
    maladieresult->setFont(QFont("Arial", 12, QFont::Bold, true));
//    maladieresult->move(); // x,y
    maladieresult->setGeometry(maladieresult->x()+125, 700,100,100);

    m_bou = new QPushButton("Quitter", this); // int x, int y, int w, int h
    m_bou->setGeometry(850,700,80,40);

    predire = new QPushButton("Predire", this);
    predire->setGeometry(m_bou->x()-100,m_bou->y(),80,40);


    m_tablewidget = new QTableWidget(this);
    m_tablewidget->move(150,300);
    m_tablewidget->setMinimumSize(500,300);

    m_tablewidget->setRowCount(m_mat.size());
    m_tablewidget->setColumnCount(m_vet.size());

    for(unsigned i(0); i<m_mat.size() ;++i) {
        for(unsigned j(0); j<m_vet.size(); ++j) {
                m_tablewidget->setItem(i,j,new QTableWidgetItem(QString::fromUtf8(m_mat[i][j].c_str())));
            }
        }

        for(unsigned i(0);i<m_vet.size();++i)
        m_tablewidget->setHorizontalHeaderItem(i,new QTableWidgetItem(QString::fromUtf8(m_vet[i].c_str())));







    connect(m_bou, SIGNAL(clicked()), this, SLOT(setQuitter()));

    connect(predire, SIGNAL(clicked()), this, SLOT( predict() ));




    m_lab1 = new QLabel(getHeader(0),this);
    m_lab1->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_lab1->move(100,200);

    m_com1 = new QComboBox(this);
    m_com1->setGeometry(90,230,100,30); // int x, int y, int w, int h
    m_com1->addItem("NULL");
    m_com1->setCurrentIndex(0);
    setItems(0,m_com1);


    m_lab2 = new QLabel(getHeader(1),this);
    m_lab2->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_lab2->move(250,200);

    m_com2 = new QComboBox(this);
    m_com2->setGeometry(240,230,100,30);
    m_com2->addItem("NULL");
    m_com2->setCurrentIndex(0);
    setItems(1,m_com2);

    m_lab3 = new QLabel(getHeader(2),this);
    m_lab3->setFont(QFont("Arial", 12, QFont::Bold, true));
    m_lab3->move(400,200);

    m_com3 = new QComboBox(this);
    m_com3->setGeometry(390,230,100,30);
    m_com3->addItem("NULL");
    m_com3->setCurrentIndex(0);
    setItems(2,m_com3);


    string str = "Rhume";
    float score = 0;
    score = calcFreq(str,3);
    cout << score << endl;

}


void MaFenetre::setQuitter()
{
    exit(0);
}


QString MaFenetre::getHeader(int i) {

    // en-tête
    QString qs = QString::fromUtf8(m_vet[i].c_str());
    return qs;
}



void MaFenetre::setItems(int i, QComboBox *combo) {

    // items
    CVString myItems;

    for(unsigned j=0; j < m_mat.size(); j++)
    {
        string s = m_mat[j][i];
        if (std::find(myItems.begin(), myItems.end(), s) == myItems.end())
        {
            combo->addItem(QString::fromUtf8(s.c_str()));
            myItems.push_back(s);

        }



    }

}


float MaFenetre::calcFreq(string maladie, int col){
    float freq = 0;
    for (int i = 0 ; i < m_mat.size() ; ++i){
        if (m_mat[i][col] == maladie){
            ++freq;
        }
    }
    return freq/m_mat.size();
}


int MaFenetre::calcConf(string maladie) {








}

void MaFenetre::predict() {
//    string ss = "2/9";
//    maladieresult->setText(QString(ss.c_str()));
    string fievre = m_com1->currentText();
    string douleur = m_com2->currentText();
    string toux = m_com3->currentText();

    for (int i = 0 ; m_mat.size() ; ++i){

    }


}



