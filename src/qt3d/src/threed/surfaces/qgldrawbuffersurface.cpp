/****************************************************************************
**
** Copyright (c) 2011-2014 Microsoft Mobile and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtQuick3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qgldrawbuffersurface_p.h"

QT_BEGIN_NAMESPACE

QPaintDevice *QGLDrawBufferSurface::device() const
{
    return m_surface->device();
}

bool QGLDrawBufferSurface::activate(QGLAbstractSurface *prevSurface)
{
    if (!m_surface->activate(prevSurface))
        return false;
#if defined(GL_BACK_LEFT) && defined(GL_BACK_RIGHT)
    glDrawBuffer(m_buffer);
#endif
    return true;
}

void QGLDrawBufferSurface::deactivate(QGLAbstractSurface *nextSurface)
{
    m_surface->deactivate(nextSurface);
}

QRect QGLDrawBufferSurface::viewportGL() const
{
    return m_surface->viewportGL();
}

QT_END_NAMESPACE
