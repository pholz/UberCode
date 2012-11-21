#pragma once
#include <QGraphicsSceneMouseEvent>
#include <QPoint>
#include "UbObject.h"
#include "UbTypes.h"
#include "UbNode.h"
#include <QPropertyAnimation>

namespace Uber {
	class UbAbstractBlock :public UbObject
	{
	public:

		enum { Type = AbstractBlockType };

		UbAbstractBlock( QGraphicsItem *parent );
		virtual ~UbAbstractBlock( void );

		virtual int						type() const { return Type; }
		UbNodeRef						getNodeUnderMouse();
		/*UbNodeRef						getNodeAtPosition(QPointF p);*/
	protected:
		
		virtual void					constructPath();
		virtual void					arrangeNodes() = 0;
		virtual void					mousePressEvent ( QGraphicsSceneMouseEvent * e )
		{
			//TODO: QT dragging seems to have glitches. Not sure if its a QT bug or not.
			m_CurrentPoint = m_PreviousPoint =  e->scenePos();  
		}

		virtual void					mouseMoveEvent ( QGraphicsSceneMouseEvent * e )
		{
			m_CurrentPoint = e->scenePos();
			QPointF diff = m_CurrentPoint - m_PreviousPoint;
			setPos(pos() + diff );
			m_PreviousPoint = m_CurrentPoint;
		}

		QVector<UbNodeRef>				m_Inlets;
		QVector<UbNodeRef>				m_Outlets;
		int								m_CornerRadius;
	private:
		QPointF							m_CurrentPoint;
		QPointF							m_PreviousPoint;
		QPropertyAnimation*				m_PropertyAnimation;
	};
}