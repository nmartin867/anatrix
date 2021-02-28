#ifndef ANATRIXWINDOW_H
#define ANATRIXWINDOW_H

#include <QWidget>
class AnaTrixBoard;

QT_BEGIN_NAMESPACE
class QLabel;
class QLCDNumber;
class QPushButton;
QT_END_NAMESPACE

class AnaTrixWindow : public QWidget
{
    Q_OBJECT

public:
    AnaTrixWindow(QWidget *parent = nullptr);
private:
    QLabel *createLabel(const QString &text);

    AnaTrixBoard *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};
#endif // ANATRIXWINDOW_H
