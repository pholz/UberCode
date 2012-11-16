#include <exception>
#include "UbBundleBlock.h"
#include "UbInletNode.h"
#include "UbOutletNode.h"
#include "UbMultiInletNode.h"
#include "app/_2RealEngine.h"

using namespace _2Real;
using namespace _2Real::app;
using namespace std;

namespace Uber {

	UbBundleBlock::UbBundleBlock(QGraphicsItem *parent,  _2Real::app::BundleHandle handle, QString blockName)
		:UbAbstractBlock(parent)
	{
		try
		{
			m_BlockHandle = handle.createBlockInstance( blockName.toStdString() );
			m_BlockHandle.setUpdateRate( 30 );
			m_BlockHandle.setup();
			m_BlockHandle.start();
			m_BlockId = QString::fromUtf8( m_BlockHandle.getIdAsString().c_str() );
		}
		catch ( Exception &e )
		{
			cout << e.message() << " " << e.what() << endl;
		}
		arrangeNodes();
	}

	UbBundleBlock::UbBundleBlock( QGraphicsItem *parent,  QString blockInstanceId )
		:UbAbstractBlock(parent)
	{
		Engine::BlockHandles blockHandles = Engine::instance().getCurrentBlocks();
		Engine::BlockHandleIterator iter = blockHandles.begin();
		for ( ; iter!= blockHandles.end(); ++iter )
		{
			if ( iter->getIdAsString() == blockInstanceId.toUtf8().constData() )
			{
				std::cout << "found " << std::endl;
				break;
			}
		}

		if ( iter != blockHandles.end() )
		{
			m_BlockHandle	= *iter;
			m_BlockId = QString::fromUtf8( m_BlockHandle.getIdAsString().c_str() );
		} else
		{
			throw std::exception("Cannot find any block instance with the specified Id.");
		}
		arrangeNodes();
	}

	UbBundleBlock::~UbBundleBlock(void)
	{

	}

	void UbBundleBlock::arrangeNodes()
	{
		qreal nodeSpacing = 4;

		try
		{
			int inletIdx   = 0;
			int outletIdx  = 0;

			//Create Inlets
			BlockInfo::InletInfos inlets = m_BlockHandle.getBlockInfo().inlets;
			for(auto it = inlets.begin(); it != inlets.end(); it++)
			{
				_2Real::app::InletHandle handle = m_BlockHandle.getInletHandle(it->name);
				if ( handle.isMultiInlet() )
				{
					UbMultiInletNodeRef node(new UbMultiInletNode(this,handle));
					QPointF pos = QPointF(-m_Width/2.f, -m_Height/2.f) + QPointF( node->getWidth()/2,node->getHeight()/2 ) + QPointF(m_CornerRadius, m_CornerRadius);
					node->setPos( pos + inletIdx*(node->getWidth()+nodeSpacing)*QPointF(1.f, 0.f));
					m_Inlets.push_back(node);
				} else
				{
					UbInletNodeRef node(new UbInletNode(this, handle));
					QPointF pos = QPointF(-m_Width/2.f, -m_Height/2.f) + QPointF( node->getWidth()/2,node->getHeight()/2 ) + QPointF(m_CornerRadius, m_CornerRadius);
					node->setPos( pos + inletIdx*(node->getWidth()+nodeSpacing)*QPointF(1.f, 0.f));
					m_Inlets.push_back(node);
				}
				//m_Inputs.append( node );

				inletIdx++;
			}

			//Create Outlets
			BlockInfo::OutletInfos outlets = m_BlockHandle.getBlockInfo().outlets;
			for(auto it = outlets.begin(); it != outlets.end(); it++)
			{
				UbOutletNodeRef node( new UbOutletNode(this, m_BlockHandle.getOutletHandle(it->name)));
				//m_Outputs.append( node );
				QPointF pos = -QPointF(-m_Width/2.f, -m_Height/2.f) - QPointF( node->getWidth()/2,node->getHeight()/2 ) - QPointF(m_CornerRadius, m_CornerRadius);
				node->setPos( pos - outletIdx*(node->getWidth()+nodeSpacing)*QPointF(1.f, 0.f));
				m_Outlets.push_back(node);
				outletIdx++;
			}
		}
		catch(Exception& e)
		{
			cout << e.message() << e.what() << std::endl;
		}
	}

	QVector<UbNodeRef> UbBundleBlock::getInlets()
	{
		return m_Inlets;
	}

	QVector<UbNodeRef> UbBundleBlock::getOutlets()
	{
		return m_Outlets;
	}
}