#include "anatrixpeice.h"
#include <QRandomGenerator>

void AnaTrixPeice::setRandomShape()
{
    setShape(AnaTrixShape(QRandomGenerator::global()->bounded(7) + 1));
}

void AnaTrixPeice::setShape(AnaTrixShape shape)
{
    static constexpr int coordsTable[8][4][2] = {
        { { 0, 0 },   { 0, 0 },   { 0, 0 },   { 0, 0 } }, // No Shape
        { { 0, -1 },  { 0, 0 },   { -1, 0 },  { -1, 1 } }, // Z
        { { 0, -1 },  { 0, 0 },   { 1, 0 },   { 1, 1 } },
        { { 0, -1 },  { 0, 0 },   { 0, 1 },   { 0, 2 } },
        { { -1, 0 },  { 0, 0 },   { 1, 0 },   { 0, 1 } },
        { { 0, 0 },   { 1, 0 },   { 0, 1 },   { 1, 1 } },
        { { -1, -1 }, { 0, -1 },  { 0, 0 },   { 0, 1 } },
        { { 1, -1 },  { 0, -1 },  { 0, 0 },   { 0, 1 } }
    };

    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 2; ++j)
            coords[i][j] = coordsTable[shape][i][j];
    }
    pieceShape = shape;
}

int AnaTrixPeice::minX() const
{
    int min = coords[0][0];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][0]);
    return min;
}

int AnaTrixPeice::maxX() const
{
    int max = coords[0][0];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][0]);
    return max;
}

int AnaTrixPeice::minY() const
{
    int min = coords[0][1];
    for (int i = 1; i < 4; ++i)
        min = qMin(min, coords[i][1]);
    return min;
}

int AnaTrixPeice::maxY() const
{
    int max = coords[0][1];
    for (int i = 1; i < 4; ++i)
        max = qMax(max, coords[i][1]);
    return max;
}

AnaTrixPeice AnaTrixPeice::rotatedLeft() const
{
    if (pieceShape == SquareShape)
        return *this;

    AnaTrixPeice result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, y(i));
        result.setY(i, -x(i));
    }

    return result;
}


AnaTrixPeice AnaTrixPeice::rotatedRight() const
{
    if (pieceShape == SquareShape)
        return *this;

    AnaTrixPeice result;
    result.pieceShape = pieceShape;
    for (int i = 0; i < 4; ++i) {
        result.setX(i, -y(i));
        result.setY(i, x(i));
    }
    return result;
}
