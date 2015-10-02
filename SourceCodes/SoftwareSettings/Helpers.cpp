#include "stdafx.h"
#include "Helpers.h"

namespace aux
{
    namespace helpers
    {

        QVariant QColorToQVariant( const QColor& color )
        {
            return color.name();
        }

        QColor QVariantToQColor( const QVariant& color )
        {
            return QColor( color.toString() );
        }
    }
}
