#pragma once

#include "QString"
#include "QColor"

namespace aux
{
    namespace helpers
    {
        QVariant QColorToQVariant( const QColor&   color );
        QColor   QVariantToQColor( const QVariant& color );
    }
}