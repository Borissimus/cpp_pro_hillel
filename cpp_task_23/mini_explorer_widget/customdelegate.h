#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>

class CustomDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    explicit CustomDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyledItemDelegate::paint(painter, option, index); // Викликаємо стандартне малювання

        painter->save();
        if (index.column() == 0) {
            if (index.data(Qt::DisplayRole).toString().startsWith("[DIR]")) {
                painter->setPen(Qt::blue); // Синій для папок
            } else {
                painter->setPen(Qt::darkGreen); // Темно-зелений для файлів
            }
            painter->drawText(option.rect, Qt::AlignLeft | Qt::AlignVCenter, index.data(Qt::DisplayRole).toString());
        }
        painter->restore();
    }
};

#endif // CUSTOMDELEGATE_H
