import QtQuick
import QtCharts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("BAR chart")


    Rectangle{
        anchors.fill: parent
        color: "skyblue"
    }

    ChartView {
        title: "عملکرد دانش‌آموز"
        anchors.fill: parent
        legend.alignment: Qt.AlignBottom
        antialiasing: true

        BarSeries {
            id: mySeries
            axisX: BarCategoryAxis { categories: ["نهایی", "نیمسال", "مستمر" ] }
            BarSet { label: "صمد قنبری"; values: [ 3, 4, 6] }
            BarSet { label: "کلاس"; values: [ 2,  20, 7] }
            BarSet { label: "پایه"; values: [  13, 18, 8] }
        }
    }
}
