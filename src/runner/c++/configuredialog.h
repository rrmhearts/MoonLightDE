/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXDE-Qt - a lightweight, Qt based, desktop toolset
 * http://razor-qt.org
 *
 * Copyright: 2010-2011 Razor team
 * Authors:
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef CONFIGUREDIALOG_H
#define CONFIGUREDIALOG_H

#include <QDialog>

namespace Ui {
    class ConfigureDialog;
}

class QSettings;

namespace LxQt {
    class SettingsCache;
}

class ConfigureDialog : public QDialog
{
    Q_OBJECT

public:
    enum Position {
        PositionTop,
        PositionCenter
    };


    explicit ConfigureDialog(QSettings *settings, const QString &defaultShortcut, QWidget *parent = 0);
    ~ConfigureDialog();

protected:
   // void closeEvent(QCloseEvent *event);

private:
    Ui::ConfigureDialog *ui;
    QSettings *mSettings;
    LxQt::SettingsCache *mOldSettings;
    QString mDefaultShortcut;

private slots:
    void shortcutChanged(const QString &text);
    void shortcutReset();
    void settingsChanged();
    void positionCbxChanged(int index);
    void monitorCbxChanged(int index);
    void resetSettings();
};

#endif // CONFIGUREDIALOG_H
