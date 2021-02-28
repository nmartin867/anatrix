#ifndef ANATRIXPEICE_H
#define ANATRIXPEICE_H

enum AnaTrixShape {
    NoShape,
    ZShape,
    SShape,
    LineShape,
    TShape,
    SquareShape,
    LShape,
    MirroredLShape
};

class AnaTrixPeice
{
public:
    AnaTrixPeice() { setShape(NoShape); }

    void setRandomShape();
    void setShape(AnaTrixShape shape);

    AnaTrixShape shape() const { return pieceShape; }
    int x(int index) const { return coords[index][0]; }
    int y(int index) const { return coords[index][1]; }
    int minX() const;
    int maxX() const;
    int minY() const;
    int maxY() const;
    AnaTrixPeice rotatedLeft() const;
    AnaTrixPeice rotatedRight() const;

private:
    void setX(int index, int x) { coords[index][0] = x; }
    void setY(int index, int y) { coords[index][1] = y; }

    AnaTrixShape pieceShape;
    int coords[4][2];
};

#endif // ANATRIXPEICE_H
