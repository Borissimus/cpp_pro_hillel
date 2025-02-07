#include <QApplication>
#include <QTreeView>
#include "customfilesystemmodel.h"
#include "customdelegate.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QString directoryPath = "/home/user/Downloads"; // Вкажіть шлях до папки (замініть на свій)


    // Створення файлової моделі
    CustomFileSystemModel *model = new CustomFileSystemModel;
    model->setRootPath(directoryPath);
    model->setFilter(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs);
    model->setNameFilters(QStringList() << "*.txt" << "*.cpp");
    model->setNameFilterDisables(false);

    // Створення TreeView
    QTreeView *treeView = new QTreeView;
    treeView->setModel(model);
    treeView->setRootIndex(model->index(directoryPath));
    treeView->resize(800, 600);

    // Додаємо кастомний делегат
    CustomDelegate *delegate = new CustomDelegate(treeView);
    treeView->setItemDelegate(delegate);

    treeView->show();
    return app.exec();
}
