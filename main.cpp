#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextStream>
#include "Math/matrix.cpp"
#include "Gameboard/field.h"

int main(int argc, char *argv[])
{
    /*
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    */
    QTextStream out(stdout);

    Matrix<Field> matrix(15, 15);
    // Row 1
    matrix.setField(Field(3, 0), 0, 0);
    // Row 2
    matrix.setField(Field(0, 0), 0, 1);
    matrix.setField(Field(2, 0), 1, 1);
    // Row 3
    matrix.setField(Field(0, 0), 0, 2);
    matrix.setField(Field(0, 0), 1, 2);
    matrix.setField(Field(2, 0), 2, 2);
    // Row 4
    matrix.setField(Field(0, 2), 0, 3);
    matrix.setField(Field(0, 0), 1, 3);
    matrix.setField(Field(0, 0), 2, 3);
    matrix.setField(Field(2, 0), 3, 3);
    // Row 5
    matrix.setField(Field(0, 0), 0, 4);
    matrix.setField(Field(0, 0), 1, 4);
    matrix.setField(Field(0, 0), 2, 4);
    matrix.setField(Field(0, 0), 3, 4);
    matrix.setField(Field(2, 0), 4, 4);
    // Row 6
    matrix.setField(Field(0, 0), 0, 5);
    matrix.setField(Field(0, 3), 1, 5);
    matrix.setField(Field(0, 0), 2, 5);
    matrix.setField(Field(0, 0), 3, 5);
    matrix.setField(Field(0, 0), 4, 5);
    matrix.setField(Field(0, 3), 5, 5);
    // Row 7
    matrix.setField(Field(0, 0), 0, 6);
    matrix.setField(Field(0, 0), 1, 6);
    matrix.setField(Field(0, 2), 2, 6);
    matrix.setField(Field(0, 0), 3, 6);
    matrix.setField(Field(0, 0), 4, 6);
    matrix.setField(Field(0, 0), 5, 6);
    matrix.setField(Field(0, 2), 6, 6);
    // Row 8
    matrix.setField(Field(3, 0), 0, 7);
    matrix.setField(Field(0, 0), 1, 7);
    matrix.setField(Field(0, 0), 2, 7);
    matrix.setField(Field(0, 2), 3, 7);
    matrix.setField(Field(0, 0), 4, 7);
    matrix.setField(Field(0, 0), 5, 7);
    matrix.setField(Field(0, 0), 6, 7);
    matrix.setField(Field(true), 7, 7);

    Matrix<Field> topLeft = matrix.section(0, 0, 8, 8);
    topLeft.mirrorCopy(Matrix<Field>::LeftBottom);
    Matrix<Field> top = matrix.section(0, 0, 15, 8);
    top.mirrorCopy(Matrix<Field>::VertLeft);
    matrix.mirrorCopy(Matrix<Field>::HorzTop);

    out << endl;
    out << matrix.toString();
    out << endl;

    return 1;  //app.exec();
}
