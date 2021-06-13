/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRead;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionReset;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_7;
    QPushButton *pushButton_add_point;
    QPushButton *pushButton_clear_graph;
    QDoubleSpinBox *doubleSpinBox_x;
    QDoubleSpinBox *doubleSpinBox_y;
    QDoubleSpinBox *doubleSpinBox_z;
    QCustomPlot *plot;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QCheckBox *checkBox_connect_two_lines;
    QCheckBox *checkBox_buil_circle_in;
    QCheckBox *checkBox_built_figure;
    QCheckBox *checkBox_fill_area;
    QCheckBox *checkBox_buil_circle_out;
    QCheckBox *checkBox_point_cross;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QListWidget *listWidget_points;
    QDoubleSpinBox *doubleSpinBox_setz;
    QDoubleSpinBox *doubleSpinBox_setx;
    QDoubleSpinBox *doubleSpinBox_sety;
    QPushButton *pushButton_chage_point;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QLabel *label_out_radius;
    QLabel *label_in_radius;
    QLabel *label_4;
    QLabel *label_cross_point;
    QLabel *label_perimetr;
    QLabel *label_square;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_isCrossing;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_read_from_file;
    QPushButton *pushButton_save_to_file;
    QPushButton *pushButton_make2d;
    QMenuBar *menubar;
    QMenu *menuSave;
    QMenu *menuView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(846, 610);
        actionRead = new QAction(MainWindow);
        actionRead->setObjectName(QString::fromUtf8("actionRead"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(label_7, 0, 4, 1, 1);

        pushButton_add_point = new QPushButton(groupBox);
        pushButton_add_point->setObjectName(QString::fromUtf8("pushButton_add_point"));

        gridLayout_2->addWidget(pushButton_add_point, 0, 6, 1, 1);

        pushButton_clear_graph = new QPushButton(groupBox);
        pushButton_clear_graph->setObjectName(QString::fromUtf8("pushButton_clear_graph"));

        gridLayout_2->addWidget(pushButton_clear_graph, 0, 7, 1, 1);

        doubleSpinBox_x = new QDoubleSpinBox(groupBox);
        doubleSpinBox_x->setObjectName(QString::fromUtf8("doubleSpinBox_x"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(doubleSpinBox_x->sizePolicy().hasHeightForWidth());
        doubleSpinBox_x->setSizePolicy(sizePolicy2);
        doubleSpinBox_x->setStyleSheet(QString::fromUtf8(""));
        doubleSpinBox_x->setDecimals(1);
        doubleSpinBox_x->setMinimum(-99999.000000000000000);
        doubleSpinBox_x->setMaximum(99999.000000000000000);
        doubleSpinBox_x->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(doubleSpinBox_x, 0, 1, 1, 1);

        doubleSpinBox_y = new QDoubleSpinBox(groupBox);
        doubleSpinBox_y->setObjectName(QString::fromUtf8("doubleSpinBox_y"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_y->sizePolicy().hasHeightForWidth());
        doubleSpinBox_y->setSizePolicy(sizePolicy2);
        doubleSpinBox_y->setDecimals(1);
        doubleSpinBox_y->setMinimum(-99999.000000000000000);
        doubleSpinBox_y->setMaximum(99999.000000000000000);
        doubleSpinBox_y->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(doubleSpinBox_y, 0, 3, 1, 1);

        doubleSpinBox_z = new QDoubleSpinBox(groupBox);
        doubleSpinBox_z->setObjectName(QString::fromUtf8("doubleSpinBox_z"));
        sizePolicy2.setHeightForWidth(doubleSpinBox_z->sizePolicy().hasHeightForWidth());
        doubleSpinBox_z->setSizePolicy(sizePolicy2);
        doubleSpinBox_z->setDecimals(1);
        doubleSpinBox_z->setMinimum(-99999.000000000000000);
        doubleSpinBox_z->setMaximum(99999.000000000000000);
        doubleSpinBox_z->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(doubleSpinBox_z, 0, 5, 1, 1);


        gridLayout->addWidget(groupBox, 2, 1, 1, 1);

        plot = new QCustomPlot(centralwidget);
        plot->setObjectName(QString::fromUtf8("plot"));

        gridLayout->addWidget(plot, 0, 1, 2, 1);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        checkBox_connect_two_lines = new QCheckBox(tab);
        checkBox_connect_two_lines->setObjectName(QString::fromUtf8("checkBox_connect_two_lines"));

        gridLayout_3->addWidget(checkBox_connect_two_lines, 1, 0, 1, 1);

        checkBox_buil_circle_in = new QCheckBox(tab);
        checkBox_buil_circle_in->setObjectName(QString::fromUtf8("checkBox_buil_circle_in"));

        gridLayout_3->addWidget(checkBox_buil_circle_in, 8, 0, 1, 1);

        checkBox_built_figure = new QCheckBox(tab);
        checkBox_built_figure->setObjectName(QString::fromUtf8("checkBox_built_figure"));

        gridLayout_3->addWidget(checkBox_built_figure, 3, 0, 1, 1);

        checkBox_fill_area = new QCheckBox(tab);
        checkBox_fill_area->setObjectName(QString::fromUtf8("checkBox_fill_area"));

        gridLayout_3->addWidget(checkBox_fill_area, 6, 0, 1, 1);

        checkBox_buil_circle_out = new QCheckBox(tab);
        checkBox_buil_circle_out->setObjectName(QString::fromUtf8("checkBox_buil_circle_out"));

        gridLayout_3->addWidget(checkBox_buil_circle_out, 7, 0, 1, 1);

        checkBox_point_cross = new QCheckBox(tab);
        checkBox_point_cross->setObjectName(QString::fromUtf8("checkBox_point_cross"));

        gridLayout_3->addWidget(checkBox_point_cross, 2, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        listWidget_points = new QListWidget(tab_2);
        listWidget_points->setObjectName(QString::fromUtf8("listWidget_points"));

        gridLayout_4->addWidget(listWidget_points, 0, 0, 1, 3);

        doubleSpinBox_setz = new QDoubleSpinBox(tab_2);
        doubleSpinBox_setz->setObjectName(QString::fromUtf8("doubleSpinBox_setz"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(doubleSpinBox_setz->sizePolicy().hasHeightForWidth());
        doubleSpinBox_setz->setSizePolicy(sizePolicy4);
        doubleSpinBox_setz->setMinimum(-99999.000000000000000);
        doubleSpinBox_setz->setMaximum(999999.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_setz, 2, 2, 1, 1);

        doubleSpinBox_setx = new QDoubleSpinBox(tab_2);
        doubleSpinBox_setx->setObjectName(QString::fromUtf8("doubleSpinBox_setx"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_setx->sizePolicy().hasHeightForWidth());
        doubleSpinBox_setx->setSizePolicy(sizePolicy4);
        doubleSpinBox_setx->setMinimum(-99999.000000000000000);
        doubleSpinBox_setx->setMaximum(999999.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_setx, 2, 0, 1, 1);

        doubleSpinBox_sety = new QDoubleSpinBox(tab_2);
        doubleSpinBox_sety->setObjectName(QString::fromUtf8("doubleSpinBox_sety"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_sety->sizePolicy().hasHeightForWidth());
        doubleSpinBox_sety->setSizePolicy(sizePolicy4);
        doubleSpinBox_sety->setMinimum(-99999.000000000000000);
        doubleSpinBox_sety->setMaximum(999999.000000000000000);

        gridLayout_4->addWidget(doubleSpinBox_sety, 2, 1, 1, 1);

        pushButton_chage_point = new QPushButton(tab_2);
        pushButton_chage_point->setObjectName(QString::fromUtf8("pushButton_chage_point"));

        gridLayout_4->addWidget(pushButton_chage_point, 3, 0, 1, 3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_out_radius = new QLabel(tab_3);
        label_out_radius->setObjectName(QString::fromUtf8("label_out_radius"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_out_radius->sizePolicy().hasHeightForWidth());
        label_out_radius->setSizePolicy(sizePolicy5);
        label_out_radius->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_out_radius, 1, 1, 1, 1);

        label_in_radius = new QLabel(tab_3);
        label_in_radius->setObjectName(QString::fromUtf8("label_in_radius"));
        sizePolicy5.setHeightForWidth(label_in_radius->sizePolicy().hasHeightForWidth());
        label_in_radius->setSizePolicy(sizePolicy5);
        label_in_radius->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_in_radius, 2, 1, 1, 1);

        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_4, 2, 0, 1, 1);

        label_cross_point = new QLabel(tab_3);
        label_cross_point->setObjectName(QString::fromUtf8("label_cross_point"));
        sizePolicy5.setHeightForWidth(label_cross_point->sizePolicy().hasHeightForWidth());
        label_cross_point->setSizePolicy(sizePolicy5);
        label_cross_point->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_cross_point, 3, 1, 1, 1);

        label_perimetr = new QLabel(tab_3);
        label_perimetr->setObjectName(QString::fromUtf8("label_perimetr"));
        label_perimetr->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_perimetr, 5, 1, 1, 1);

        label_square = new QLabel(tab_3);
        label_square->setObjectName(QString::fromUtf8("label_square"));
        sizePolicy5.setHeightForWidth(label_square->sizePolicy().hasHeightForWidth());
        label_square->setSizePolicy(sizePolicy5);
        label_square->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_square, 4, 1, 1, 1);

        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy5.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy5);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_8, 5, 0, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy5.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy5);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_6, 4, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy5.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy5);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_5, 3, 0, 1, 1);

        label_isCrossing = new QLabel(tab_3);
        label_isCrossing->setObjectName(QString::fromUtf8("label_isCrossing"));
        sizePolicy5.setHeightForWidth(label_isCrossing->sizePolicy().hasHeightForWidth());
        label_isCrossing->setSizePolicy(sizePolicy5);
        label_isCrossing->setStyleSheet(QString::fromUtf8("background-color:red;"));
        label_isCrossing->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_isCrossing, 0, 0, 1, 2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout = new QVBoxLayout(tab_4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_read_from_file = new QPushButton(tab_4);
        pushButton_read_from_file->setObjectName(QString::fromUtf8("pushButton_read_from_file"));

        verticalLayout->addWidget(pushButton_read_from_file);

        pushButton_save_to_file = new QPushButton(tab_4);
        pushButton_save_to_file->setObjectName(QString::fromUtf8("pushButton_save_to_file"));

        verticalLayout->addWidget(pushButton_save_to_file);

        pushButton_make2d = new QPushButton(tab_4);
        pushButton_make2d->setObjectName(QString::fromUtf8("pushButton_make2d"));

        verticalLayout->addWidget(pushButton_make2d);

        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 3, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 846, 26));
        menuSave = new QMenu(menubar);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSave->menuAction());
        menubar->addAction(menuView->menuAction());
        menuSave->addAction(actionRead);
        menuSave->addAction(actionSave);
        menuSave->addSeparator();
        menuSave->addAction(actionExit);
        menuView->addAction(actionReset);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRead->setText(QCoreApplication::translate("MainWindow", "Read", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">y</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">x</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Z</span></p></body></html>", nullptr));
        pushButton_add_point->setText(QCoreApplication::translate("MainWindow", "Add point", nullptr));
        pushButton_clear_graph->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        checkBox_connect_two_lines->setText(QCoreApplication::translate("MainWindow", "Build two lines", nullptr));
        checkBox_buil_circle_in->setText(QCoreApplication::translate("MainWindow", "Build circle In", nullptr));
        checkBox_built_figure->setText(QCoreApplication::translate("MainWindow", "Build square", nullptr));
        checkBox_fill_area->setText(QCoreApplication::translate("MainWindow", "Paint area", nullptr));
        checkBox_buil_circle_out->setText(QCoreApplication::translate("MainWindow", "Built circle Out", nullptr));
        checkBox_point_cross->setText(QCoreApplication::translate("MainWindow", "Show crossing point", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Main", nullptr));
        pushButton_chage_point->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Points", nullptr));
        label_out_radius->setText(QString());
        label_in_radius->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "In radius", nullptr));
        label_cross_point->setText(QString());
        label_perimetr->setText(QString());
        label_square->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Perimetr", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Out radius", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Cross point", nullptr));
        label_isCrossing->setText(QCoreApplication::translate("MainWindow", "Not crossing", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Info", nullptr));
        pushButton_read_from_file->setText(QCoreApplication::translate("MainWindow", "Read from file", nullptr));
        pushButton_save_to_file->setText(QCoreApplication::translate("MainWindow", "Save to file", nullptr));
        pushButton_make2d->setText(QCoreApplication::translate("MainWindow", "Make all poits 2D", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Other", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
