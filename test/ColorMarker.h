#pragma once

#include <QObject>
#include <QColor>
class ColorMarker : public QObject
{
	Q_OBJECT
	//define enum, usage: ${CLASSNAME}.${ENUMNAME}
	Q_ENUMS(GenerateAlgorithm)
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(QColor timeColor READ timeColor)
public:
	ColorMarker(QObject *parent = nullptr);
	~ColorMarker();

	enum GenerateAlgorithm {
		RandomRGB,
		RandomRed,
		RandomGreen,
		RandomBlue,
		LinearIncrease
	};

	Q_INVOKABLE GenerateAlgorithm algorithm()const { return m_algorithm; }
	Q_INVOKABLE void setAlgorithm(GenerateAlgorithm alg) { m_algorithm = alg; }

	QColor color()const { return m_currentColor; }
	void setColor(const QColor &clr) {
		m_currentColor = clr;
		emit colorChanged(m_currentColor);
	}
	QColor timeColor()const;
signals:
	void colorChanged(const QColor &color);
	void currentTime(const QString &strTime);

public slots:
	void start();
	void stop();

protected:
	void timerEvent(QTimerEvent *event);

private:
	GenerateAlgorithm	m_algorithm;
	QColor				m_currentColor;
	int					m_nColorTimer;
};
