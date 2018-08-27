#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTextStream>
#include "Math/fieldmatrix.h"

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

    FieldMatrix matrix(15, 15);
    // Row 1
    matrix.setField(Field(Field::Word, 3), 0, 0);
    // Row 2
    matrix.setField(Field(Field::None), 0, 1);
    matrix.setField(Field(Field::Word, 2), 1, 1);
    // Row 3
    matrix.setField(Field(Field::None), 0, 2);
    matrix.setField(Field(Field::None), 1, 2);
    matrix.setField(Field(Field::Word, 2), 2, 2);
    // Row 4
    matrix.setField(Field(Field::Letter, 2), 0, 3);
    matrix.setField(Field(Field::None), 1, 3);
    matrix.setField(Field(Field::None), 2, 3);
    matrix.setField(Field(Field::Word, 2), 3, 3);
    // Row 5
    matrix.setField(Field(Field::None), 0, 4);
    matrix.setField(Field(Field::None), 1, 4);
    matrix.setField(Field(Field::None), 2, 4);
    matrix.setField(Field(Field::None), 3, 4);
    matrix.setField(Field(Field::None), 4, 4);
    // Row 6
    matrix.setField(Field(Field::None, 0), 0, 5);
    matrix.setField(Field(Field::Letter, 3), 1, 5);
    matrix.setField(Field(Field::None, 0), 2, 5);
    matrix.setField(Field(Field::None, 0), 3, 5);
    matrix.setField(Field(Field::None, 0), 4, 5);
    matrix.setField(Field(Field::Letter, 3), 5, 5);
    // Row 7
    matrix.setField(Field(Field::None, 0), 0, 6);
    matrix.setField(Field(Field::None, 0), 1, 6);
    matrix.setField(Field(Field::Letter, 2), 2, 6);
    matrix.setField(Field(Field::None, 0), 3, 6);
    matrix.setField(Field(Field::None, 0), 4, 6);
    matrix.setField(Field(Field::None, 0), 5, 6);
    matrix.setField(Field(Field::Letter, 2), 6, 6);
    // Row 8
    matrix.setField(Field(Field::Word, 3), 0, 7);
    matrix.setField(Field(Field::None, 0), 1, 7);
    matrix.setField(Field(Field::None, 0), 2, 7);
    matrix.setField(Field(Field::None, 2), 3, 7);
    matrix.setField(Field(Field::None, 0), 4, 7);
    matrix.setField(Field(Field::None, 0), 5, 7);
    matrix.setField(Field(Field::None, 0), 6, 7);
    matrix.setField(Field(Field::Center), 7, 7);

    FieldMatrix topLeft = matrix.section(0, 0, 8, 8);
    topLeft.mirrorCopy(Matrix<Field>::LeftBottom);
    FieldMatrix top = matrix.section(0, 0, 15, 8);
    top.mirrorCopy(Matrix<Field>::VertLeft);
    matrix.mirrorCopy(Matrix<Field>::HorzTop);

    out << endl;
    out << matrix.toString();
    out << endl;

    return 1;  //app.exec();
}
