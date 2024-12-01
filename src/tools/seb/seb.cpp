// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "seb.h"
#include "src/utils/screenshotsaver.h"
#include <QPainter>

Seb::Seb(QObject* parent)
  : AbstractActionTool(parent)
{}

bool Seb::closeOnButtonPressed() const
{
    return true;
}

QIcon Seb::icon(const QColor& background, bool inEditor) const
{
    Q_UNUSED(inEditor)
    return QIcon(iconPath(background) + "content-seb.svg");
}
QString Seb::name() const
{
    return tr("Seb");
}

CaptureTool::Type Seb::type() const
{
    return CaptureTool::TYPE_SEB;
}

QString Seb::description() const
{
    return tr("New Seb Creation");
}

CaptureTool* Seb::copy(QObject* parent)
{
    return new Seb(parent);
}

void Seb::pressed(CaptureContext& context) //process c'est quand on a des choses à traiter. Ici on est sur du click sur le bouton simplement
{
    emit requestAction(REQ_SEB);
    /*emit requestAction(REQ_CLEAR_SELECTION);
    context.request.addTask(CaptureRequest::COPY);
    emit requestAction(REQ_CAPTURE_DONE_OK);
    emit requestAction(REQ_CLOSE_GUI);*/
}
