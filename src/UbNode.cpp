#include <QPainter>
#include <QStyleOption>
#include <iostream>
#include "UbNode.h"
#include "UbLink.h"
#include "UbLinkController.h"
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>
#include <QToolTip>

namespace Uber {
	UbNode::UbNode( QGraphicsItem *parent ) :UbObject( parent ),
		m_NodeName("")
	{
		m_Height = 8;
		m_Width = 8;
		m_Color = QColor(153,135,141);
		constructPath();
		setAcceptHoverEvents( true ); 
		installEventFilter(UbLinkController::getInstance());
	}

	void UbNode::constructPath()
	{
		//QPath path;
		m_Path = QPainterPath();
		m_Path.addEllipse( -m_Width/2, -m_Height/2, m_Width, m_Height );
	}

	void UbNode::setName( QString name )
	{
		m_NodeName = name;
		setToolTip( m_NodeName );
	}

	const QString&	UbNode::getName() const 
	{ 
		return m_NodeName;
	}

	bool UbNode::link( UbNode* node )
	{
		//We can only link inlet to outlets
		bool res = false;
		if ( ( type() == InputNodeType ) && ( node->type() == OutputNodeType ) )
		{
			//qSharedPointerCast<UbOutletNode>(this)
			res = static_cast<UbInletNode*>(this)->getHandle().link( static_cast<UbOutletNode*>(node)->getHandle() );

		} else if ( ( type() == OutputNodeType ) && ( node->type() == InputNodeType ) )
		{
			res = static_cast<UbOutletNode*>(this)->getHandle().link( static_cast<UbInletNode*>(node)->getHandle() );
		}
		return res;
	}

	void UbNode::hoverMoveEvent ( QGraphicsSceneHoverEvent * event )
	{
		std::cout << " Hover is happening" << std::endl;
		QPointF pos = event->lastScreenPos();
		QToolTip::showText( QPoint(pos.x(),pos.y()), QString(m_NodeName) );

	}
	void UbNode::hoverLeaveEvent ( QGraphicsSceneHoverEvent * event )
	{
		std::cout << " Hover stopped happening" << std::endl;
	}
}