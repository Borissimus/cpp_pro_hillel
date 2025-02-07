#ifndef CUSTOMFILESYSTEMMODEL_H
#define CUSTOMFILESYSTEMMODEL_H

#include <QFileSystemModel>
#include <QFileInfo>

class CustomFileSystemModel : public QFileSystemModel {
    Q_OBJECT

public:
    explicit CustomFileSystemModel(QObject *parent = nullptr) : QFileSystemModel(parent) {}

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && index.column() == 0) {
            QFileInfo fileInfo = this->fileInfo(index);
            if (fileInfo.isDir()) {
                return QString("[DIR] %1").arg(fileInfo.fileName()); // Папки з префіксом [DIR]
            } else {
                return QString("%1 (%2 KB)").arg(fileInfo.fileName()).arg(fileInfo.size() / 1024); // Файли з розміром
            }
        }
        return QFileSystemModel::data(index, role);
    }
};

#endif // CUSTOMFILESYSTEMMODEL_H
