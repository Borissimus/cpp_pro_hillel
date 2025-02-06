#ifndef CUSTOMFILESYSTEMMODEL_H
#define CUSTOMFILESYSTEMMODEL_H

#include <QFileSystemModel>
#include <QFileInfo>
#include <QObject>

class CustomFileSystemModel : public QFileSystemModel {
    Q_OBJECT
    Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath NOTIFY rootPathChanged)

public:
    explicit CustomFileSystemModel(QObject *parent = nullptr) : QFileSystemModel(parent) {
        setRootPath(QDir::homePath());
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (role == Qt::DisplayRole && index.column() == 0) {
            QFileInfo fileInfo = this->fileInfo(index);
            if (fileInfo.isDir()) {
                return QString("[DIR] %1").arg(fileInfo.fileName());
            } else {
                return QString("%1 (%2 KB)").arg(fileInfo.fileName()).arg(fileInfo.size() / 1024);
            }
        }
        return QFileSystemModel::data(index, role);
    }

    Q_INVOKABLE void setRootPath(const QString &path) {
        if (path != rootPath()) {
            QFileSystemModel::setRootPath(path);
            emit rootPathChanged();
        }
    }

signals:
    void rootPathChanged();
};

#endif // CUSTOMFILESYSTEMMODEL_H
