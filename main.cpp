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
    QBarSet *set1 = new QBarSet("کلاس");
    QBarSet *set2 = new QBarSet("پایه");
    QBarSet *set3 = new QBarSet("صمد قنبری");

    *set1 << 10 << 15 <<20;
    *set2 << 12 << 18 << 16;
    *set3 << 18 << 17 << 19;

    set1->setColor(QColor("gray"));
    set2->setColor(QColor("silver"));
    set3->setColor(QColor("darkgreen"));

    series->append(set1);
    series->append(set2);
    series->append(set3);

    chart->addSeries(series);



    // QCategoryAxis *axisX = new QCategoryAxis();
    // axisX->append("مستمر", 0);
    // axisX->append("نهایی", 1);
    // axisX->append("نیمسال", 2);
    // chart->addAxis(axisX, Qt::AlignBottom);
    // series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, 20);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);



    QChartView *chartView = new QChartView(chart);
    QPixmap bchart = chartView->grab();
    //chartView->resize(100,100);

    painter.drawPixmap(100, 100, 300, 300,bchart);

    painter.end();  // Finish painting


    return app.exec();
}
