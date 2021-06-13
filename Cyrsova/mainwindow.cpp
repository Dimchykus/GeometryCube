#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MakePlot();
    square = new Square();
    connect(ui->plot,SIGNAL(mouseDoubleClick(QMouseEvent*)),SLOT(on_plotDoubleClicked(QMouseEvent*)));
    connect(ui->plot,SIGNAL(mouseMove(QMouseEvent*)),SLOT(on_plotMouseMove(QMouseEvent*)));
    connect(ui->plot,SIGNAL(mousePress(QMouseEvent*)),SLOT(on_plotMousePress(QMouseEvent*)));
    ui->checkBox_fill_area->setCheckable(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MakePlot()
{
    //create elements
    figureLines = new QCPCurve(ui->plot->xAxis, ui->plot->yAxis);
    line1 = new QCPCurve(ui->plot->xAxis,ui->plot->yAxis);
    line2 = new QCPCurve(ui->plot->xAxis,ui->plot->yAxis);
    circleOut = new QCPItemEllipse(ui->plot);
    circleOut->topLeft->setCoords(0,0);
    circleOut->bottomRight->setCoords(0,0);
    circleIn = new QCPItemEllipse(ui->plot);
    circleIn->topLeft->setCoords(0,0);
    circleIn->bottomRight->setCoords(0,0);
    //interection
    ui->plot->setInteraction(QCP::iRangeDrag, true);
    ui->plot->setInteraction(QCP::iRangeZoom, true);
    ui->plot->addGraph();
    ui->plot->addGraph();
    // give the axes some labels:
    ui->plot->xAxis->setLabel("X");
    ui->plot->yAxis->setLabel("Y");
    //style

    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->plot->graph(0)->setPen( QPen(Qt::black, 1.5));
    ui->plot->graph(0)->setBrush(QBrush(QColor(255, 255, 255)));
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    ui->plot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);
    ui->plot->graph(1)->setLineStyle(QCPGraph::lsNone);
    ui->plot->graph(1)->setPen(QPen(QColor(255, 100, 0)));

    ui->plot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->plot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->plot->xAxis->setTickPen(QPen(Qt::white, 1));
    ui->plot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->plot->xAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->plot->yAxis->setSubTickPen(QPen(Qt::white, 1));
    ui->plot->xAxis->setTickLabelColor(Qt::white);
    ui->plot->yAxis->setTickLabelColor(Qt::white);

    ui->plot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridVisible(true);

    ui->plot->xAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->plot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->plot->setBackground(plotGradient);

    circleOut->setPen(QColor(255,255,255));
    circleIn->setPen(QColor(255,255,255));

    // set axes ranges, so we see all data:
    ui->plot->xAxis->setRange(-100, 100);
    ui->plot->yAxis->setRange(-100, 100);
    ui->plot->replot();
}

void MainWindow::Clear()
{
    //Очищення всіх даних
    square->ClearPoints();
    figureLines->setData(square->GetxVector(),square->GetyVector());
    line1->setData(square->GetxVector(),square->GetyVector());
    line2->setData(square->GetxVector(),square->GetyVector());
    on_checkBox_built_figure_stateChanged(ui->checkBox_built_figure->isChecked());
    TabWidgetPointUpdate();
    UpdateLines();
    InfoTabUpdate();
    UpdatePlot();
}

void MainWindow::UpdatePlot()
{
    //Оновлення графіку
    ui->plot->graph(0)->setData(square->GetxVector(),square->GetyVector());
    ui->plot->replot();
    ui->plot->update();
    TabWidgetPointUpdate();
    InfoTabUpdate();
}

void MainWindow::TabWidgetPointUpdate()
{
    //Вивід точок у TabWidget
    if(ui->tabWidget->currentIndex() == 1){
        ui->listWidget_points->clear();
        for (int i = 0; i < square->PointCount(); i++) {
            ui->listWidget_points->addItem(QString::number(square->GetPoint(i).get_x())+" - "+ QString::number(square->GetPoint(i).get_y()) +" - "+ QString::number(square->GetPoint(i).get_z()));
        }
    }
}

void MainWindow::InfoTabUpdate()
{
    //Вивід пощі перериметру радіусів у TabWidget
    if(ui->tabWidget->currentIndex() == 2){
        if(square->PointCount() == 4 && square->IsCrossing(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3)) == true)
        {
            Point crossing = square->CrossingPoint3D(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3));
            ui->label_cross_point->setText(QString::number(crossing.get_x()) + " - " + QString::number(crossing.get_y()) + " - " + QString::number(crossing.get_z()));
            ui->label_square->setText(QString::number(square->CalculateSquare()));
            ui->label_perimetr->setText(QString::number(square->CalculatePerimetr()));
            ui->label_isCrossing->setStyleSheet("background-color:green;color:white");
            ui->label_isCrossing->setText("Crossing");
            if(square->IsOutCircle(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3)))
            {
                 ui->label_out_radius->setText(QString::number(square->RadiusOut()));
            }else{
                ui->label_out_radius->setText("No radius");
            }
            if(square->IsInCircle(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3)))
            {
                ui->label_in_radius->setText(QString::number(square->RadiusIn()));
            }else{
                ui->label_in_radius->setText("No radius");
            }
        }else{
            ui->label_out_radius->setText("No radius");
            ui->label_in_radius->setText("No radius");
            ui->label_cross_point->setText("No intersection");
            ui->label_square->setText("No square");
            ui->label_perimetr->setText("No perimetr");
            ui->label_isCrossing->setStyleSheet("background-color:red;color:black");
            ui->label_isCrossing->setText("Not crossing");

        }
    }
}
void MainWindow::on_pushButton_add_point_clicked()
{
    //Додавання точки за допомогою спін боксів та кнопки Add
    square->AddPoint(ui->doubleSpinBox_x->value(), ui->doubleSpinBox_y->value(), ui->doubleSpinBox_z->value());
    UpdateLines();
    UpdatePlot();
}

void MainWindow::on_plotDoubleClicked(QMouseEvent *event)
{
    //При двойному кліці на графік додається нова точка
    QPoint point = event->pos();
    square->AddPoint(ui->plot->xAxis->pixelToCoord(point.x()), ui->plot->yAxis->pixelToCoord(point.y()));
    UpdateLines();
    UpdatePlot();
}

void MainWindow::on_plotMouseMove(QMouseEvent *event)
{
    //Зміна положення точки при рісі мишки якщо точка була раніше вибрана
    //Якщо точка є вирана то координати точки дорівнюють координатам мишки на графіку
    if(point_selected && iter > -1){
        QPoint point = event->pos();
        square->SetxPoint(iter, ui->plot->xAxis->pixelToCoord(point.x()));
        square->SetyPoint(iter, ui->plot->yAxis->pixelToCoord(point.y()));
        UpdateLines();
    }
    UpdateLines();
}

void MainWindow::on_plotMousePress(QMouseEvent *event)
{
    //Вибір точки на графіку
    if(point_selected){
        iter = -1;
        point_selected = false;
        return;
    }
    double x = ui->plot->xAxis->range().upper;
    int count = 0;
    while (x >= 10){
        x = x / 10;  //Вибір з певним радіусом
        count++;
    }
    count--;
    double radius = 0.05 + pow(10,count);
    QPoint point = event->pos();
    double mx = ui->plot->xAxis->pixelToCoord(point.x()), my = ui->plot->yAxis->pixelToCoord(point.y());
    for(int i = 0;i < square->PointCount(); i++){
         if(fabs(mx - square->GetPoint(i).get_x()) <= radius && fabs(my - square->GetPoint(i).get_y()) <= radius){
            iter = i;
            point_selected = true;   // Якщо точка є у вибраному радіусі то координати точки дорівнюють координатам мишки на графіку
         }
    }
    UpdateLines();
}

void MainWindow::on_pushButton_clear_graph_clicked()
{
    Clear();
    UpdateLines();
    UpdatePlot();
}

void MainWindow::on_checkBox_connect_two_lines_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked || arg1){
        if(square->PointCount() == 4)
        {
            //Побудова двох ліній
            QVector<double> v1; v1.append(square->GetPoint(0).get_x()); v1.append(square->GetPoint(1).get_x());
            QVector<double> v2; v2.append(square->GetPoint(0).get_y()); v2.append(square->GetPoint(1).get_y());
            line1->setData(v1,v2);
            v1.clear(); v2.clear();
            v1.append(square->GetPoint(2).get_x()); v1.append(square->GetPoint(3).get_x());
            v2.append(square->GetPoint(2).get_y()); v2.append(square->GetPoint(3).get_y());
            line2->setData(v1,v2);
        }
    }else{
        //Знищення ліній
        QVector<double> v1;
        QVector<double> v2;
        line1->setData(v1,v2);
        line2->setData(v1,v2);
    }
     UpdatePlot();
}

void MainWindow::on_checkBox_fill_area_stateChanged(int arg1)
{
     if(arg1 == Qt::Checked || arg1){
         //Замальовування площі чотирикутника
         figureLines->setBrush(QBrush(QColor(255, 69, 0, 95)));
         figureLines->setPen(QPen(QColor(102, 255, 51)));
     }else{
         figureLines->setBrush(QBrush(QColor(255, 255, 255, 0)));
     }
     UpdatePlot();
}

void MainWindow::Swap(double x, double y)
{
    double temp = x;
    x = y;
    y = temp;
}

void MainWindow::on_checkBox_built_figure_stateChanged(int arg1)
{
    //форма чотириктника
    if(arg1 == Qt::Checked || arg1){
        if(square->PointCount() != 4){
            return;
        }
        square->SwapPoints(1,2);//свап точок, бо 0 і 1 це діагональ
        square->AddPoint(square->GetPoint(0));// додаємо першу точку у кінець
        figureLines->setData(square->GetxVector(),square->GetyVector());
        square->RemovePoint(square->PointCount()-1);//видаляймо останню
        square->SwapPoints(1,2);// щераз свап
        figureLines->setPen(QPen(QColor(102, 255, 51)));//колік ліній
        ui->checkBox_fill_area->setCheckable(true);//робимо активну анопу замалювання площі
    }else{
        QVector<double> v1;
        figureLines->setData(v1,v1);
        ui->checkBox_fill_area->setCheckable(false);
    }
    UpdatePlot();
}

void MainWindow::on_checkBox_buil_circle_out_stateChanged(int arg1)
{
    //Описане коло
    if((arg1 == Qt::Checked || arg1) && square->PointCount() == 4 && square->IsOutCircle(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3))){
        //знаходимо центр
        //здаходимо відстань від центра до будь якої точки
        //малюємо коло
            Point center = square->CircleOutCenter(square->GetPoint(0), square->GetPoint(2), square->GetPoint(2), square->GetPoint(1));
            double radius = square->DistanceBetweenPoints2D(center, square->GetPoint(0));
            qDebug()<<"circle "<<center.get_x()<<center.get_y()<<radius;
            if(isnan(center.get_x()) || isnan(center.get_y())){
                circleOut->topLeft->setCoords(0,0);
                circleOut->bottomRight->setCoords(0,0);
                return;
            }
            circleOut->topLeft->setCoords( center.get_x()-radius, center.get_y()+radius );
            circleOut->bottomRight->setCoords( center.get_x()+radius , center.get_y()-radius);
    }else{
        circleOut->topLeft->setCoords(0,0);
        circleOut->bottomRight->setCoords(0,0);
    }
    UpdatePlot();
}

void MainWindow::on_checkBox_buil_circle_in_stateChanged(int arg1)
{
    //побудова вписаного кола
    if((arg1 == Qt::Checked || arg1) && square->PointCount() == 4 && square->IsInCircle(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3))){
            //знаходимо центр
            //здаходимо відстань від центра до будь якої точки
            //малюємо коло
            qDebug()<<"in";
            Point center = square->CircleInCenter(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3));
            double radius = square->DistanceBetweenPointLine(center,square->GetPoint(0), square->GetPoint(3));
            qDebug()<<center.get_x()<<center.get_y()<<radius;
            if(isnan(center.get_x()) || isnan(center.get_y())){
                circleIn->topLeft->setCoords(0,0);
                circleIn->bottomRight->setCoords(0,0);
                return;
            }
            circleIn->topLeft->setCoords( center.get_x()-radius, center.get_y()+radius );
            circleIn->bottomRight->setCoords( center.get_x()+radius , center.get_y()-radius);
    }else{
        circleIn->topLeft->setCoords(0,0);
        circleIn->bottomRight->setCoords(0,0);
    }
    UpdatePlot();
}

void MainWindow::on_listWidget_points_itemDoubleClicked(QListWidgetItem *item)
{
    //видалення очки при подвійному кліці на точку в списку точок
    square->RemovePoint(ui->listWidget_points->currentRow());
    on_checkBox_built_figure_stateChanged(ui->checkBox_built_figure->isChecked());
    on_checkBox_connect_two_lines_stateChanged(ui->checkBox_connect_two_lines->isChecked());
    UpdateLines();
    UpdatePlot();
}

void MainWindow::on_checkBox_point_cross_stateChanged(int arg1)
{
    //точка перетину двох прямих
    if((arg1 == Qt::Checked || arg1)&& square->PointCount() == 4 && square->IsCrossing(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3)) == true){
        Point crossPoint = square->CrossingPoint3D(square->GetPoint(0), square->GetPoint(1), square->GetPoint(2), square->GetPoint(3));
        QVector<double> vec1, vec2;
        vec1.append(crossPoint.get_x());
        vec2.append(crossPoint.get_y());
        ui->plot->graph(1)->setData(vec1, vec2);

    }else{
        QVector<double> vec1, vec2;
        ui->plot->graph(1)->setData(vec1, vec2);
    }
    UpdatePlot();
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    //оновлення координа точок якщо відкрили список точок
    TabWidgetPointUpdate();
    InfoTabUpdate();
}

void MainWindow::on_pushButton_save_to_file_clicked()
{
    //збереження точок у файл
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Save coorditates"), "E://Unifersity//2 year/Cyrsova/build-Cyrsova-Desktop_Qt_5_15_1_MinGW_64_bit-Debug//", tr("Image Files (*.txt)"));
    std::ofstream file;
    try{
    file.open(fileName.toUtf8().constData());
    if(!file){
        throw -1;
    }
    file << *square;
    }catch(int i){

         QMessageBox::information(this,"Error to save point data", "Select another .txt file and try one more time");
        qDebug() << "Error open file to save points";
        return;

    }

}

void MainWindow::on_pushButton_read_from_file_clicked()
{
    //зчитування точок з файлу
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Read coorditates"), "E://Unifersity//2 year/Cyrsova/build-Cyrsova-Desktop_Qt_5_15_1_MinGW_64_bit-Debug//", tr("Image Files (*.txt)"));
    std::ifstream file;

    try {
         file.open(fileName.toUtf8().constData());
         if(!file){
             //Якщо файл не вдалось відкрити
             qDebug() << "Error open file to save points";
             throw -1;
         }
    }  catch (int i) {
        QMessageBox::information(this,"Error to open file", "Select another .txt file and try one more time");
        return;

    }
    try{
        int status = file >> *square;//зчитування
        if(status != 0){
            throw status;
        }
    }catch(int i){
        if(i == -1){
        QMessageBox::information(this,"Error to read point", "Check points in .txt file for it's formatation");
        }else if(i == -2){
            QMessageBox::information(this,"Error to read point", "File is empty. Select another file.");

        }
    }

    //оновлення графіку та всіх даних
    UpdateLines();
    UpdatePlot();
}

void MainWindow::on_actionRead_triggered()
{
    //зчитування з меню
    on_pushButton_read_from_file_clicked();
}

void MainWindow::on_actionSave_triggered()
{
    //збереження через меню
    on_pushButton_save_to_file_clicked();
}

void MainWindow::on_actionReset_triggered()
{
    //скинути полощення графіку на 0,0
    ui->plot->xAxis->setRange(-100, 100);
    ui->plot->yAxis->setRange(-100, 100);
    UpdatePlot();
}

void MainWindow::on_pushButton_chage_point_clicked()
{
    //змінити координати точки
    int pos = ui->listWidget_points->currentRow();
    if(pos >= 0){
        square->SetxyzPoint(pos,ui->doubleSpinBox_setx->value(),ui->doubleSpinBox_sety->value(),ui->doubleSpinBox_setz->value());
    }
    TabWidgetPointUpdate();
}

void MainWindow::on_listWidget_points_itemClicked(QListWidgetItem *item)
{
    //при натисненні на точку у списку
    int pos = ui->listWidget_points->currentRow();
    ui->doubleSpinBox_setx->setValue(square->GetPoint(pos).get_x());
    ui->doubleSpinBox_sety->setValue(square->GetPoint(pos).get_y());
    ui->doubleSpinBox_setz->setValue(square->GetPoint(pos).get_z());
}

void MainWindow::on_pushButton_make2d_clicked()
{
    //проектування точок на площину
    for(int i = 0;i<square->PointCount();i++){
        square->SetzPoint(i,0);
    }

}

void MainWindow::closeEvent(QCloseEvent *event)  // show prompt when user wants to close app
{
    if (QMessageBox::No == QMessageBox::warning(this, qApp->applicationName(), "Are you sure you want to quit?", QMessageBox::Yes,QMessageBox::No))
    {
        event->ignore();
    } else {
        event->accept();
    }
}

void MainWindow::UpdateLines()
{
    on_checkBox_built_figure_stateChanged(ui->checkBox_built_figure->isChecked());
    on_checkBox_connect_two_lines_stateChanged(ui->checkBox_connect_two_lines->isChecked());
    on_checkBox_point_cross_stateChanged(ui->checkBox_point_cross->isChecked());
    on_checkBox_buil_circle_out_stateChanged(ui->checkBox_buil_circle_out->isChecked());
    on_checkBox_buil_circle_in_stateChanged(ui->checkBox_buil_circle_in->isChecked());
    on_checkBox_fill_area_stateChanged(ui->checkBox_fill_area->isChecked());
}
