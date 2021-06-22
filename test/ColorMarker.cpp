#include "ColorMarker.h"
#include <QTimerEvent>
#include <QDateTime>
ColorMarker::ColorMarker(QObject *parent/*=nullptr*/)
	: QObject(parent),
	m_algorithm(RandomRGB),
	m_currentColor(Qt::black),
	m_nColorTimer(0)
{
	qsrand(QDateTime::currentDateTime().toTime_t());
}

ColorMarker::~ColorMarker()
{
}

void ColorMarker::start()
{
	if (m_nColorTimer == 0)
	{
		m_nColorTimer = startTimer(1000);
	}
}

void ColorMarker::stop()
{
	if (m_nColorTimer > 0)
	{
		killTimer(m_nColorTimer);
		m_nColorTimer = 0;
	}
}
QColor ColorMarker::timeColor()const
{
	QTime time = QTime::currentTime();
	int r = time.hour();
	int g = time.minute() * 2;
	int b = time.second() * 4;
	return QColor::fromRgb(r, g, b);
}

void ColorMarker::timerEvent(QTimerEvent *event)
{
	if (event->timerId() == m_nColorTimer)
	{
		switch (m_algorithm)
		{
		case RandomRGB:
			m_currentColor.setRgb(qrand() % 255, qrand() % 255, qrand() % 255);
			break;
		case RandomRed:
			m_currentColor.setRed(qrand() % 255);
			break;
		case RandomGreen:
			m_currentColor.setGreen(qrand() % 255);
			break;
		case RandomBlue:
			m_currentColor.setBlue(qrand() % 255);
			break;
		case LinearIncrease:
		{
			int r = m_currentColor.red() + 10;
			int g = m_currentColor.green() + 10;
			int b = m_currentColor.blue() + 10;
			m_currentColor.setRgb(r % 255, g % 255, b % 255);
		}
		break;
		}
		emit colorChanged(m_currentColor);
		emit currentTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
	}
	else
	{
		QObject::timerEvent(event);
	}
}