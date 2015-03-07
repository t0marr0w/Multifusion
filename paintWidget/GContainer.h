#ifndef __GCONTAINER__H__
#define __GCONTAINER__H__

#include <QVector>
#include "GObject.h"
#include "../interfaces/GObjectInterface.h"

/**
*	@file gcontainer.h ������ ���� �������� �������� ������, ������������ ���������,
*			������� ����� ��������� ��������� ����������� ��������. � ��� ����� � ����
*			����������, ��� ��� ���� ����� �������� ����������� ������ GObject. �������
*			�����������, �����������, �� ����������.
*/

/**
*		�����, ����������� ���������,
*	������� ����� ��������� ��������� ����������� ��������. � ��� ����� � ����
*	����������, ��� ��� ���� ����� �������� ����������� ������ GObject. �������
*	�����������, �����������, �� ����������.
*/
class GContainer:public GObject
{
	Q_OBJECT

	public:
		/*
		*	����������� ������ ��� ����������.
		*/

		/**
		 *  ����������� �������� �������
		 */
		virtual GObjectInterface* copyObject();

		/**
		*		���������� ��� ������, ������������ � ������ ����������,
		*	�� ��� �������.
		*
		*	@param index ������ �������, ��� �������� ���������� ������.
		*
		*	@return ��� ������.
		*/
		virtual QString objectName( int index ) const;

		/**
		*		������������� ��� ������, ������������ � ������ ����������,
		*	�� ��� �������.
		*
		*	@param index ������ �������, ��� �������� ���������� ������.
		*	@param name ����� ��� ������.
		*/
		virtual void setObjectName( int index, const QString &newName );

		/**
		*	���������� ���������� ��������, ��� ����������� � ������ ����������.
		*
		*	@return ���������� �������, ����������� � ������ ����������.
		*/
		virtual int countObjects() const;

		/**
		*	��������� ����� ������ � ���������.
		*
		*	@param o ����������� � ��������� ������.
		*	@param realChild ���� ������ �������� ��������� � true, �� ���
		*				������ ����������� ���������� ����� ����� � ����������� ������.
		*				��-��������� �� ����� �������� false.
		*
		*	@return ������ ������ ���������� ������ �������.
		*/
		virtual int add( GObject *o, bool realChild = false );

		/**
		*		"��������" ������ �� ����������. ��� ������ �� ���������,
		*	������ � ���������� �� ������ �� ������������.
		*
		*	@param index ������ "�����������" �������.
		*
		*	@return ��������� �� ���������� ������. ���� ������ ������ �� �����, � ��
		*		��� ������ � ������� ��������� new, �� ������ ����� ����� �������
		*		� ������� delete:
		*	@code
		*		delete containr->remove( 10 );
		*	@endcode
		*
		*	@warning ���� ������� � ���� �������� �� ����������, �� ������������ 0.
		*/
		virtual GObject* remove( int index );

		/**
		*		"��������" ����� ��� ������ �� ����������. ��� ��� ��������� � ��� ���������,
		*	������ �� ���������.
		*
		*	@return ������, ���������� ��� �������, ������� ����� ���������� � ���� ����������.
		*			� ��� ������, ���� � ���������� �� ���� �� ������ �������, ������������ ������ ������.
		*/
		virtual QVector< GObject* > removeAll();

		/**
		*	��������� �� ������� ���������� ������� ������ ������� ����������.
		*
		*	@param o ������, ������� ���������������� ���������/�� ��������� � ����������.
		*
		*	@return true, ���� � ���� ���������� ������ ������������.
		*/
		virtual bool isInside( GObject *o );

		/**
		*	���������� ������ �������, ������������ � ����������, �� ��������� �� ����.
		*
		*	@param o ��������� �� ������, ������ �������� ���������� ��������.
		*
		*	@return ������ �������. ��� -1, ���� ����� ������ � ���������� �� ������������.
		*/
		virtual int objectIndex( GObject *o );

		/**
		*	���������� ��������� �� ������, ����������� � ����������, �� ��� �������.
		*
		*	@param index ������ �������
		*
		*	@return ��������� �� ������ � ����������� ��������.
		*
		*	@warning ���� ������ � ����������� �������� ���, ����� ���������� 0.
		*/
		virtual GObject* object( int index );

		/**
		*		�������� ����� � ��������� �������� �� ���� ������� ���� ������ ����������.
		*	��� ����, �����������, �������� ������ ����������� �������.
		*
		*	@param index ������ �������.
		*
		*	@return ����� ������ ����� �������.
		*/
		virtual int moveDown( int index );

		/**
		*		�������� ����� � ��������� �������� �� ���� ������� ����� ������ ����������.
		*	��� ����, �����������, �������� ������ ����������� �������.
		*
		*	@param index ������ �������.
		*
		*	@return ����� ������ ����� �������.
		*/
		virtual int moveUp( int index );

		/**
		*		�������� ����� � ��������� �������� �� ����� ���� ������ ����������.
		*	��� ����, �����������, �������� ������ ����������� �������.
		*
		*	@param index ������ �������.
		*
		*	@return ����� ������ ����� �������.
		*/
		virtual int moveToFirst( int index );

		/**
		*		�������� ����� � ��������� �������� �� ����� ��� ������ ����������.
		*	��� ����, �����������, �������� ������ ����������� �������.
		*
		*	@param index ������ �������.
		*
		*	@return ����� ������ ����� �������.
		*/
		virtual int moveToLast( int index );

		/**
		*		�������� ����� � ��������� �������� �� ��������� ����� ������ ����������.
		*	��� ����, �����������, �������� ������ ����������� �������.
		*
		*	@param index ������ �������.
		*
		*	@return ����� ������ ����� �������.
		*/
		virtual int move( int index, const int to );

		/*
		*	�������, �� ����� �� ��������...
		*/

		/**
		*	���������� ��� ������� ����������.
		*
		*	@return ��� ������� ����������.
		*/
		virtual QString objectName() const
		{
			return GObjectInterface::objectName();
		}

		/**
		*	������������ ����� ��� ������ ����������.
		*
		*	@param name ����� ���.
		*/
		virtual void setObjectName( const QString &name )
		{
			GObjectInterface::setObjectName( name );
		}

		/*
		*	������, ����������� ��������� GObjectInterface.
		*/

		/**
		 * ������� ��� ����� ����� frame
		 * @param frame, ���� ����� -1 ������� ��������� ��� �����
		 */
		virtual void deleteFrames( int frame );

		/**
		*	������� ���� � ��������� �������, ���� ���� ���� ����������.
		*
		*	@param frame ����� ���������� �����.
		*/
		virtual void deleteFrame( int position );

		/**
		*	��������� ���� �� �������.
		*
		*	@param position - ������� �� ���������;
		*/
		virtual void addFrame( int position, bool visible);

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ����������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� �������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameBefore( int frame, int pasteTo );

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ���������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� ������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameAfter( int frame, int pasteTo );


		/**
		*	���������� ��� �������������� ����� ������� (!!!) �� ��������, ����������� � ����������.
		*
		*	@return ��� �������������� �����.
		*/
		virtual GObject::GLinesType type() const;

		/**
		*	���������� true, ���� � ������ ������ ������ ����� �������������.
		*
		*	@return true, ���� � ������ ������ ������ ����� �������������.
		*/
		virtual bool isEditable() const;

		/**
		*	���������� true, ���� ������ �������� �����������.
		*
		*	@return true, ���� ������ �������� �����������.
		*/
		virtual bool isContainer() const;

		/**
		*	��������� �������� ������������ ������.
		*
		*	@return �������� ������������(�� 0 �� 255%).
		*/
		virtual int getAlpha();

		/**
		*	����� ������������ ������.
		*
		*	@param _alpha �������� ������������(�� 0 �� 255).
		*/
		virtual void setAlpha( int _alpha );

		/**
		*	���������� true, ���� ������ � ������ ������ ����������.
		*
		*	@return true, ���� ������ � ������ ������ ����������
		*/
		virtual bool isBlocked() const;

		/**
		*	������������� ���������� �������.
		*
		*	@param blocked ���������� �������.
		*/
		virtual void setBlocked( bool blocked );

		/**
		*		��������� �� ���������� ������, ����������� � ����������, � �������� ��������.
		*
		*	@param index ������ �������, ��� �������� ���������� ������.
		*
		*	@return true, ���� ������ ���������� � false � ��������� ������.
		*/
		virtual bool isObjectBlocked( int index ) const;

		/**
		*		������������� ���������� �������, ������������ � ����������, � �������� ��������.
		*
		*	@param index ������ �������, ��� �������� ���������� ������.
		*	@param visible ���������� �������.
		*/
		virtual void setObjectBlocked( int index, bool blocked );

		/**
		*		��������� �� ��������� ������, ����������� � ����������, � �������� ��������.
		*
		*	@param index ������ �������, ��� �������� ���������� ������.
		*
		*	@return true, ���� ������ ����� ������ � false � ��������� ������.
		*/
		virtual bool isObjectVisible( int index ) const;

		/**
		*		������������� ��������� �������, ������������ � ����������, � �������� ��������.
		*
		*	@param index ������ �������, ��� �������� ���������� ������.
		*	@param visible ��������� �������.
		*/
		virtual void setObjectVisible( int index, bool visible );

		/**
		*	���������� true, ���� ������ � ������ ������ ����� ������ �� ������.
		*
		*	@return true, ���� ������ � ������ ������ ����� ������ �� ������.
		*/
		virtual bool isVisible() const;

		/**
		*	������������� ��������� �������.
		*
		*	@param visible ��������� �������.
		*/
		virtual void setVisible( bool visible );

		/**
		*	���������� ��������� �� ������, ������� �������� ������ �����.
		*
		*	@param p ��������� �����, �� ������� ���������� ���������� ������.
		*
		*	@return ��������� �� ������, ������� �������� ������ �����.
		*
		*	@warning ���� �� ���� ������ � ���������� �� �������� ��� �����,
		*		�� ����� ��������� 0.
		*/
		virtual GObject* contains( const QPoint &p );

		/**
		*	���������� ������� ������� ������� � �������� (������� ����).
		*
		*	@return ������� ������� ������� � �������� (������� ����).
		*/
		virtual qreal frame() const;

		/**
		*	������������ ������� ���� ��� �������.
		*
		*	@param f ��������������� ����.
		*/
		virtual void setFrame( qreal f );

		/**
		*	���������� ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*
		*	@return ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*/
		virtual int countFrames() const;

		/**
		*	���������� ���������� ��������������, � ������� ������ ������ ������.
		*
		*	@return ���������� ��������������, � ������� ������ ������ ������.
		*/
		virtual QRectF boundingRect();

		/**
		*	������� ����� �� � ������� �� �������.
		*
		*	@param index ������ ��������� �����.
		*
		*	@return true, ���� ����� ���� �������.
		*/
		virtual bool deletePoint( int index );

		/**
		*	��������� ����� ����� � ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPoint( const QPoint &p );

		/**
		*	��������� ����� ����� � ������, �� ��������� ��������� ��������� ������ ������� -
		*		�.�. ����� ������ ����������� � ����� ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPointToEnd( const QPoint &p );

		/**
		*	���������� ����������� ������� �������.
		*
		*	@param dx �������� �� ��� X.
		*	@param dy �������� �� ��� Y.
		*/
		virtual void move( qreal dx, qreal dy );

		/**
		*	���������� ��������������� �������.
		*
		*	@param sx ����������� ��������������� �� ��� X.
		*	@param sy ����������� ��������������� �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ ��������������.
		*/
		virtual void scale( qreal sx, qreal sy, const QPointF &scaleCenter );

		/**
		*	���������� ����������� ����� ��������� ����� �������.
		*
		*	@param sx ����������� ������ �� ��� X.
		*	@param sy ����������� ������ �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ �����
		*					(�.�., ����������, �����, ������� �� ���������� �����).
		*/
		virtual void sheare( qreal sx, qreal sy, const QPointF &shearPoint );

		/**
		*	���������� �������� ������.
		*
		*	@param angle ����, �� ������� ������������ �������.
		*	@param center �����, ������ ������� ������������ �������.
		*/
		virtual void rotate( qreal angle, const QPointF &center );

		/**
		*	���������� ��� �����, �� ������� ������� ������ ������.
		*
		*	@return �����, �� ������� ������� ������ ������.
		*/
		virtual QPolygonF points(int frame);

		/**
		*	���������� ���� �� ����� ������ �� ����� �����.
		*
		*	@param index ������ ������������ �����.
		*	@param newPosition ����� ��������� �����.
		*/
		virtual void movePoint( int index, const QPointF &newPosition );

		/**
		*	��������� ���� �� ������ ����� �������, ��� �� �������� ��� ��������� �����.
		*
		*	@param frame ����������� ����.
		*/
		virtual void cloneFrameToAll( int frame );

		/**
		*	���������� ��� � ��������� ����� �������.
		*
		*	@return ��� � ��������� ����� �������.
		*/
		virtual QPen pen() const;

		/**
		*	���������� ��� � ��������� ������� �������.
		*
		*	@return ��� � ��������� ������� �������.
		*/
		virtual QBrush brush() const;

		/**
		*	������������� ��� � ��������� ����� �������.
		*
		*	@param p ��� � ��������� ����� �������.
		*/
		virtual void setPen( const QPen &p );

		/**
		*	������������� ��� � ��������� ������� �������.
		*
		*	@param p ��� � ��������� ������� �������.
		*/
		virtual void setBrush( const QBrush &b );

		/**
		*	��������� ������ �� �����������.
		*
		*	@return true, ���� ������ ��������.
		*/
		virtual bool isClosed() const;

		/**
		*	������������� ����������� ������.
		*
		*	@param closed ����������� ������.
		*/
		virtual void setClosed( bool closed );

		/**
		*	������������ ������� ���� ������.
		*
		*	@param p ��, ���� ����� ������������ ���������.
		*/
		virtual void paint( QPainter &p );

		/**
		*	������������.
		*/
		GContainer();

		/**
		*	����������.
		*/
		virtual ~GContainer();

		/**
		*	��������� ���� ������ ������� � �����.
		*
		*	@param stream �����, � ������� ����������� ������.
		*/
		virtual void save( QDataStream &stream ) const;

		/**
		*	������ ���� ������ ������� �� ������.
		*
		*	@param stream �����, �� �������� ���������� ������.
		*/
		virtual void load( QDataStream &stream );

	protected:
		QVector< GObject* > objects;

		int countVisibleObjects() const;

		friend class PaintWidget;
};

/**
*		�������� ������������� ��������� �� ����� ������ � ��������� ��
*	GContainer.
*
*	@param o ��������� �� ��������� ������.
*
*	@return �������������� ��������, ���� ��� ��������, � 0 � ��������� ������.
*/
template < class T > inline GContainer* GCONTAINER( T *o )
{
	return qobject_cast< GContainer* >( o );
}

#endif /* __GCONTAINER__H__ */
