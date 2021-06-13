#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qcustomplot.h"
#include "square.h"
#include "point.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void MakePlot();//створення графіка

    void Clear();//Очищення графіка

    void UpdatePlot();//Оновлення графіка

    void TabWidgetPointUpdate();

    void InfoTabUpdate();

    void on_pushButton_add_point_clicked();

    void on_plotDoubleClicked(QMouseEvent *event);

    void on_plotMouseMove(QMouseEvent*);

    void on_pushButton_clear_graph_clicked();

    void on_plotMousePress(QMouseEvent*);

    void Swap(double, double);

    void on_checkBox_connect_two_lines_stateChanged(int arg1);

    void on_checkBox_fill_area_stateChanged(int arg1);

    void on_checkBox_built_figure_stateChanged(int arg1);

    void on_checkBox_buil_circle_out_stateChanged(int arg1);

    void on_listWidget_points_itemDoubleClicked(QListWidgetItem *item);

    void on_checkBox_point_cross_stateChanged(int arg1);

    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_save_to_file_clicked();

    void on_pushButton_read_from_file_clicked();

    void on_actionRead_triggered();

    void on_actionSave_triggered();

    void on_actionReset_triggered();

    void on_pushButton_chage_point_clicked();

    void on_listWidget_points_itemClicked(QListWidgetItem *item);

    void on_checkBox_buil_circle_in_stateChanged(int arg1);

    void on_pushButton_make2d_clicked();

    void closeEvent(QCloseEvent *event);

    void UpdateLines();
private:
    Ui::MainWindow *ui;
    bool point_selected = false;
    int iter = -1;
    //Фігури для фідображення кадрата, кола
    Square *square;
    QCPCurve *figureLines = nullptr; //
    QCPCurve *line1 = nullptr;
    QCPCurve *line2 = nullptr;
    QCPItemEllipse *circleOut;
    QCPItemEllipse *circleIn;
};
#endif // MAINWINDOW_H
