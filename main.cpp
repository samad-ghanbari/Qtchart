#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtCharts/QtCharts>
#include <QPrinter>
#include <QPainter>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QtChart1", "Main");


    // print
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output.pdf");
    printer.setPageOrientation(QPageLayout::Portrait);
    printer.setPageSize(QPageSize::A4);

    QPainter painter(&printer);

    QChart *chart = new QChart();
    QBarSeries *series = new QBarSeries();
    QBarSet *set1 = new QBarSet("Class Grades");
    QBarSet *set2 = new QBarSet("Base Grades");

    *set1 << 10 << 15 <<20;
    *set2 << 12 << 18 << 16;

    series->append(set1);
    series->append(set2);

    chart->addSeries(series);



    QCategoryAxis *axisX = new QCategoryAxis();
    axisX->append("مستمر", 0);
    axisX->append("نهایی", 1);
    axisX->append("نیمسال", 2);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 20);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);



    QChartView *chartView = new QChartView(chart);
    chartView->show();
    chartView->render(&painter);

    painter.end();  // Finish painting


    return app.exec();
}
