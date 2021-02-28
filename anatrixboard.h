#ifndef ANATRIXBOARD_H
#define ANATRIXBOARD_H


#include <QBasicTimer>
#include <QFrame>
#include <QLabel>
#include <QPointer>

#include "anatrixpeice.h"

class AnaTrixBoard : public QFrame
{
    Q_OBJECT

public:
    explicit AnaTrixBoard(QWidget *parent = nullptr);
    void setNextPieceLabel(QLabel *label);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void start();
    void pause();

signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    enum { BoardWidth = 10, BoardHeight = 22 };

      AnaTrixShape &shapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }
      int timeoutTime() { return 1000 / (1 + level); }
      int squareWidth() { return contentsRect().width() / BoardWidth; }
      int squareHeight() { return contentsRect().height() / BoardHeight; }
      void clearBoard();
      void dropDown();
      void oneLineDown();
      void pieceDropped(int dropHeight);
      void removeFullLines();
      void newPiece();
      void showNextPiece();
      bool tryMove(const AnaTrixPeice &newPiece, int newX, int newY);
      void drawSquare(QPainter &painter, int x, int y, AnaTrixShape shape);
      void drawGridLines(QPainter &painter);

      QBasicTimer timer;
      QPointer<QLabel> nextPieceLabel;
      bool isStarted;
      bool isPaused;
      bool isWaitingAfterLine;
      AnaTrixPeice curPiece;
      AnaTrixPeice nextPiece;
      int curX;
      int curY;
      int numLinesRemoved;
      int numPiecesDropped;
      int score;
      int level;
      AnaTrixShape board[BoardWidth * BoardHeight];
};

#endif // ANATRIXBOARD_H
