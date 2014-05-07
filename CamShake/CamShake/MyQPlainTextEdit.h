#include <QtWidgets/QPlainTextEdit>

class MyQPlainTextEdit: public QPlainTextEdit
{
public:
	QString m_str;
	MyQPlainTextEdit(QWidget *parent = 0)
	{
		this->setParent(parent);
	}
	void keyPressEvent(QKeyEvent *e)
	{
		if (e->modifiers() == (Qt::ControlModifier) && e->key() == Qt::Key_S)
		{
			m_str = "Ctrl+S";
		}
		else if (e->modifiers() == (Qt::ControlModifier) && e->key() == Qt::Key_N)
		{
			m_str = "Ctrl+N";
		}
		else if(e->key() == Qt::Key_Left)
		{
			m_str = "Left";
		}
		else if(e->key() == Qt::Key_Right)
		{
			m_str = "Right";
		}
		else if(e->key() == Qt::Key_Up)
		{
			m_str = "Up";
		}
		else if(e->key() == Qt::Key_Down)
		{
			m_str = "Down";
		}
		else
		{
			m_str = e->text();
		}
		this->setPlainText(m_str);
	}	
};