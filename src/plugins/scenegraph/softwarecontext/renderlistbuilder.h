/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Quick 2D Renderer module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef RENDERLISTBUILDER_H
#define RENDERLISTBUILDER_H

#include <private/qsgadaptationlayer_p.h>

QT_BEGIN_NAMESPACE

namespace SoftwareContext {

class AbstractSoftwareRenderer;

class RenderListBuilder : public QSGNodeVisitorEx
{
public:
    RenderListBuilder(AbstractSoftwareRenderer *renderer);

    bool visit(QSGTransformNode *) override;
    void endVisit(QSGTransformNode *) override;
    bool visit(QSGClipNode *) override;
    void endVisit(QSGClipNode *) override;
    bool visit(QSGGeometryNode *) override;
    void endVisit(QSGGeometryNode *) override;
    bool visit(QSGOpacityNode *) override;
    void endVisit(QSGOpacityNode *) override;
    bool visit(QSGImageNode *) override;
    void endVisit(QSGImageNode *) override;
    bool visit(QSGPainterNode *) override;
    void endVisit(QSGPainterNode *) override;
    bool visit(QSGRectangleNode *) override;
    void endVisit(QSGRectangleNode *) override;
    bool visit(QSGGlyphNode *) override;
    void endVisit(QSGGlyphNode *) override;
    bool visit(QSGNinePatchNode *) override;
    void endVisit(QSGNinePatchNode *) override;
    bool visit(QSGRootNode *) override;
    void endVisit(QSGRootNode *) override;

private:
    bool addRenderableNode(QSGNode *node);

    AbstractSoftwareRenderer *m_renderer;
};

}

QT_END_NAMESPACE

#endif // RENDERLISTBUILDER_H
